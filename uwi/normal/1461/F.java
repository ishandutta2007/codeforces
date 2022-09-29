//package round689;

import java.io.*;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class F4 {
	InputStream is;
	FastWriter out;
	String INPUT = "";

	void solve()
	{
		int n = ni();
		int[] a = na(n);
		char[] s = ns().toCharArray();
		Arrays.sort(s);
		int asm = 0;
		for(char c : s){
			asm |= 1<<"+-*".indexOf(c);
		}
		if(asm == 3){
			asm = 1;
		}
		if(asm == 7){
			asm = 5;
		}
		if(Integer.bitCount(asm) == 1){
			int rem = n-1;
			for(int v : a){
				out.print(v);
				if(--rem >= 0){
					out.print(s[0]);
				}
			}
			out.println();
			return;
		}
		// asm=5 or 6
		if(asm == 6){
			int z = n;
			for(int i = 0;i < n;i++){
				if(a[i] == 0){
					z = i;
					break;
				}
			}
			for(int i = 0;i < n;i++){
				out.print(a[i]);
				if(i < n-1){
					out.print(i+1 == z ? "-" : "*");
				}
			}
			out.println();
			return;
		}

		// asm=5
		int[][] items = new int[n][];
		int p = 0;
		int I = 1000000;
		// 5 (26) 5 (26) 5

		// A b C d E
		// ACE
		// A+b+CE
		// AC+d+E
		// A+b+C+d+E

		// 3 3 3 3 3
		// 27
		// 15

		for(int i = 0;i < n;){
			if(a[i] < 2){
				int j = i;
				while(j < n && a[j] == a[i])j++;
				items[p++] = new int[]{a[i], j-i, '+'};
				i = j;
			}else{
				int j = i;
				while(j < n && a[j] >= 2)j++;
				int pr = 1;
				for(int k = i;k < j;k++){
					pr = pr * a[k];
					if(pr > I)pr = I;
				}
				items[p++] = new int[]{pr, j-i};
				i = j;
			}
		}
		items = Arrays.copyOf(items, p);

		for(int i = 0;i < p;){
			int j = i;
			while(j < p && items[j][0] != 0)j++;
			// [i,j)
			long II = Long.MAX_VALUE / I;
			long prod = 1;
			for(int k = i;k < j;k++){
				if(k == i || k == j-1 && items[k][0] == 1)continue;
				prod = Math.min(II, prod * items[k][0]);
			}
			if(prod >= II){
				for(int k = i;k < j;k++) {
					if (items[k][0] == 1) {
						if (k == i || k == j - 1) {
							items[k][2] = '+';
						} else {
							items[k][2] = '*';
						}
					}
				}
			}else{
				long[] dp = new long[j-i+1];
				String[] arg = new String[j-i+1];
				arg[0] = "";
				for(int k = 1;k < j-i+1;k++){
					long lmax = items[k-1+i][0] == 1 ? dp[k-1] + items[k-1+i][1] : -1;
					long pro = 1;
					int larg = k-1;
					for(int l = k-1;l >= 0;l--){
						pro = pro * items[l+i][0];
						long v = dp[l] + pro;
						if(v > lmax){
							lmax = v;
							larg = l;
						}
					}
					StringBuilder sb = new StringBuilder(arg[larg]);
					sb.append("+");
					for(int u = larg+1;u < k;u++){
						sb.append("*");
					}
					arg[k] = sb.toString();
					dp[k] = lmax;
				}
				arg[j-i] += "+";

				for(int k = 1;k <= j-i;k++){
					if(items[i+k-1][0] == 1) {
						items[i + k - 1][2] = arg[j-i].charAt(k - 1) == '+' && arg[j-i].charAt(k) == '+' ? '+' : '*';
					}
				}
			}

			i = j+1;
		}

		char[] os = new char[n];
		int q = 0;
		for(int i = 0;i < p;i++){
			if(items[i][0] == 0){
				for(int j = 0;j < items[i][1]-1;j++){
					os[q++] = '*';
				}
				os[q++] = '+';
			}else if(items[i][0] >= 2){
				for(int j = 0;j < items[i][1]-1;j++){
					os[q++] = '*';
				}
				if(i+1 < p && items[i+1][0] == 1 && items[i+1][2] == '*') {
					os[q++] = '*';
				}else{
					os[q++] = '+';
				}
			}else{
				for(int j = 0;j < items[i][1]-1;j++){
					os[q++] = (char)items[i][2];
				}
				if(i+1 < p && items[i+1][0] >= 2 && items[i][2] == '*') {
					os[q++] = '*';
				}else{
					os[q++] = '+';
				}
			}
		}

		char[] h = new char[2*n-1];
		for(int i = 0;i < n;i++){
			h[2*i] = (char)('0'+a[i]);
//			out.print(a[i]);
			if(i < n-1){
//				out.print(os[i]);
				h[2*i+1] = os[i];
			}
		}
		out.println(new String(h));
	}

	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new FastWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F4().run(); }
	
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}

	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}

	private long[] nal(int n)
	{
		long[] a = new long[n];
		for(int i = 0;i < n;i++)a[i] = nl();
		return a;
	}

	private char[][] nm(int n, int m) {
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}

	private int[][] nmi(int n, int m) {
		int[][] map = new int[n][];
		for(int i = 0;i < n;i++)map[i] = na(m);
		return map;
	}

	private int ni() { return (int)nl(); }

	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}

		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}

	public static class FastWriter
	{
		private static final int BUF_SIZE = 1<<13;
		private final byte[] buf = new byte[BUF_SIZE];
		private final OutputStream out;
		private int ptr = 0;

		private FastWriter(){out = null;}

		public FastWriter(OutputStream os)
		{
			this.out = os;
		}

		public FastWriter(String path)
		{
			try {
				this.out = new FileOutputStream(path);
			} catch (FileNotFoundException e) {
				throw new RuntimeException("FastWriter");
			}
		}

		public FastWriter write(byte b)
		{
			buf[ptr++] = b;
			if(ptr == BUF_SIZE)innerflush();
			return this;
		}

		public FastWriter write(char c)
		{
			return write((byte)c);
		}

		public FastWriter write(char[] s)
		{
			for(char c : s){
				buf[ptr++] = (byte)c;
				if(ptr == BUF_SIZE)innerflush();
			}
			return this;
		}

		public FastWriter write(String s)
		{
			s.chars().forEach(c -> {
				buf[ptr++] = (byte)c;
				if(ptr == BUF_SIZE)innerflush();
			});
			return this;
		}

		private static int countDigits(int l) {
			if (l >= 1000000000) return 10;
			if (l >= 100000000) return 9;
			if (l >= 10000000) return 8;
			if (l >= 1000000) return 7;
			if (l >= 100000) return 6;
			if (l >= 10000) return 5;
			if (l >= 1000) return 4;
			if (l >= 100) return 3;
			if (l >= 10) return 2;
			return 1;
		}

		public FastWriter write(int x)
		{
			if(x == Integer.MIN_VALUE){
				return write((long)x);
			}
			if(ptr + 12 >= BUF_SIZE)innerflush();
			if(x < 0){
				write((byte)'-');
				x = -x;
			}
			int d = countDigits(x);
			for(int i = ptr + d - 1;i >= ptr;i--){
				buf[i] = (byte)('0'+x%10);
				x /= 10;
			}
			ptr += d;
			return this;
		}

		private static int countDigits(long l) {
			if (l >= 1000000000000000000L) return 19;
			if (l >= 100000000000000000L) return 18;
			if (l >= 10000000000000000L) return 17;
			if (l >= 1000000000000000L) return 16;
			if (l >= 100000000000000L) return 15;
			if (l >= 10000000000000L) return 14;
			if (l >= 1000000000000L) return 13;
			if (l >= 100000000000L) return 12;
			if (l >= 10000000000L) return 11;
			if (l >= 1000000000L) return 10;
			if (l >= 100000000L) return 9;
			if (l >= 10000000L) return 8;
			if (l >= 1000000L) return 7;
			if (l >= 100000L) return 6;
			if (l >= 10000L) return 5;
			if (l >= 1000L) return 4;
			if (l >= 100L) return 3;
			if (l >= 10L) return 2;
			return 1;
		}

		public FastWriter write(long x)
		{
			if(x == Long.MIN_VALUE){
				return write("" + x);
			}
			if(ptr + 21 >= BUF_SIZE)innerflush();
			if(x < 0){
				write((byte)'-');
				x = -x;
			}
			int d = countDigits(x);
			for(int i = ptr + d - 1;i >= ptr;i--){
				buf[i] = (byte)('0'+x%10);
				x /= 10;
			}
			ptr += d;
			return this;
		}

		public FastWriter write(double x, int precision)
		{
			if(x < 0){
				write('-');
				x = -x;
			}
			x += Math.pow(10, -precision)/2;
			//		if(x < 0){ x = 0; }
			write((long)x).write(".");
			x -= (long)x;
			for(int i = 0;i < precision;i++){
				x *= 10;
				write((char)('0'+(int)x));
				x -= (int)x;
			}
			return this;
		}

		public FastWriter writeln(char c){
			return write(c).writeln();
		}

		public FastWriter writeln(int x){
			return write(x).writeln();
		}

		public FastWriter writeln(long x){
			return write(x).writeln();
		}

		public FastWriter writeln(double x, int precision){
			return write(x, precision).writeln();
		}

		public FastWriter write(int... xs)
		{
			boolean first = true;
			for(int x : xs) {
				if (!first) write(' ');
				first = false;
				write(x);
			}
			return this;
		}

		public FastWriter write(long... xs)
		{
			boolean first = true;
			for(long x : xs) {
				if (!first) write(' ');
				first = false;
				write(x);
			}
			return this;
		}

		public FastWriter writeln()
		{
			return write((byte)'\n');
		}

		public FastWriter writeln(int... xs)
		{
			return write(xs).writeln();
		}

		public FastWriter writeln(long... xs)
		{
			return write(xs).writeln();
		}

		public FastWriter writeln(char[] line)
		{
			return write(line).writeln();
		}

		public FastWriter writeln(char[]... map)
		{
			for(char[] line : map)write(line).writeln();
			return this;
		}

		public FastWriter writeln(String s)
		{
			return write(s).writeln();
		}

		private void innerflush()
		{
			try {
				out.write(buf, 0, ptr);
				ptr = 0;
			} catch (IOException e) {
				throw new RuntimeException("innerflush");
			}
		}

		public void flush()
		{
			innerflush();
			try {
				out.flush();
			} catch (IOException e) {
				throw new RuntimeException("flush");
			}
		}

		public FastWriter print(byte b) { return write(b); }
		public FastWriter print(char c) { return write(c); }
		public FastWriter print(char[] s) { return write(s); }
		public FastWriter print(String s) { return write(s); }
		public FastWriter print(int x) { return write(x); }
		public FastWriter print(long x) { return write(x); }
		public FastWriter print(double x, int precision) { return write(x, precision); }
		public FastWriter println(char c){ return writeln(c); }
		public FastWriter println(int x){ return writeln(x); }
		public FastWriter println(long x){ return writeln(x); }
		public FastWriter println(double x, int precision){ return writeln(x, precision); }
		public FastWriter print(int... xs) { return write(xs); }
		public FastWriter print(long... xs) { return write(xs); }
		public FastWriter println(int... xs) { return writeln(xs); }
		public FastWriter println(long... xs) { return writeln(xs); }
		public FastWriter println(char[] line) { return writeln(line); }
		public FastWriter println(char[]... map) { return writeln(map); }
		public FastWriter println(String s) { return writeln(s); }
		public FastWriter println() { return writeln(); }
	}

	public void trnz(int... o)
	{
		for(int i = 0;i < o.length;i++)if(o[i] != 0)System.out.print(i+":"+o[i]+" ");
		System.out.println();
	}

	// print ids which are 1
	public void trt(long... o)
	{
		Queue<Integer> stands = new ArrayDeque<>();
		for(int i = 0;i < o.length;i++){
			for(long x = o[i];x != 0;x &= x-1)stands.add(i<<6|Long.numberOfTrailingZeros(x));
		}
		System.out.println(stands);
	}

	public void tf(boolean... r)
	{
		for(boolean x : r)System.out.print(x?'#':'.');
		System.out.println();
	}

	public void tf(boolean[]... b)
	{
		for(boolean[] r : b) {
			for(boolean x : r)System.out.print(x?'#':'.');
			System.out.println();
		}
		System.out.println();
	}

	public void tf(long[]... b)
	{
		if(INPUT.length() != 0) {
			for (long[] r : b) {
				for (long x : r) {
					for (int i = 0; i < 64; i++) {
						System.out.print(x << ~i < 0 ? '#' : '.');
					}
				}
				System.out.println();
			}
			System.out.println();
		}
	}

	public void tf(long... b)
	{
		if(INPUT.length() != 0) {
			for (long x : b) {
				for (int i = 0; i < 64; i++) {
					System.out.print(x << ~i < 0 ? '#' : '.');
				}
			}
			System.out.println();
		}
	}

	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}