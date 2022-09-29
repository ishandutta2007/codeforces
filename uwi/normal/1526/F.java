//package round723;

import java.io.*;
import java.util.*;

public class F {
	InputStream is;
	FastWriter out;
	String INPUT = "";

	static boolean debug = false;
//	Random gen = new Random(114521);
//	public static int[] shuffle(int n, Random gen){ int[] a = new int[n]; for(int i = 0;i < n;i++)a[i] = i; for(int i = 0;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }
	public static int[] q;// = shuffle(20, gen);

	int ct;

	void solve()
	{
//		assert q[0] < q[1];
		for(int T = ni();T > 0;T--){
			go();
			ni();
		}
	}

	int get(int a, int b, int c)
	{
		if(debug){
			int[] o = {Math.abs(q[a] - q[b]), Math.abs(q[b] - q[c]), Math.abs(q[c] - q[a])};
			Arrays.sort(o);
			if(++ct > 2*q.length+420){
				assert false;
			}
			return o[1];
		}

		out.println("? " + (a+1) + " " + (b+1) + " " + (c+1));
		out.flush();
		return ni();
	}

	void go()
	{
		int n = ni();
		int[] ds = new int[n];
		for(int i = 2;i < n;i++){
			ds[i] = get(0, 1, i);
		}

		int min = n+5;
		int mf = 0;
		int max = -1;
		for(int i = 2;i < n;i++){
			max = Math.max(max, ds[i]);
			if(ds[i] < min){
				min = ds[i];
				mf = 1;
			}else if(ds[i] == min){
				mf++;
			}
		}
		int cha;
		if(min == 1){
			assert 1 <= mf && mf <= 2;
			if(mf == 2){
				cha = 1;
			}else if(max == n-3) {
				cha = 1;
			}else{
				cha = 2;
				// ABx..
				// ..AxB..
			}
		}else {
			cha = mf == 1 ? 2*min : 2 * min - 1;
		}
//		tr(cha, min, mf);

		if(max >= cha + 2){
			List<Integer> amax = new ArrayList<>();
			List<Integer> amax2 = new ArrayList<>();
			for(int i = 2;i < n;i++){
				if(ds[i] == max){
					amax.add(i);
				}
				if(ds[i] == max-1){
					amax2.add(i);
				}
			}
			if(amax.size() == 2){
				assert amax2.size() == 2;
				for(int i = 0;i < 2;i++){
					for(int j = 0;j < 2;j++){
						if(get(amax.get(i), amax2.get(j), 0) == (n-cha-1)/2-1){
							// i:min, j:min+1
							frommin(amax.get(i), amax2.get(j), n);
							return;
						}
					}
				}
			}else if(amax2.size() == 2){
				for(int j = 0;j < 2;j++){
					if(get(amax.get(0), amax2.get(j), 0) == (n-cha-2)/2){
						// i:min, j:min+1
						frommin(amax.get(0), amax2.get(j), n);
						return;
					}
				}
				for(int j = 0;j < 2;j++){
					if(get(amax.get(0), amax2.get(j), 1) == (n-cha-2)/2){
						// i:max, j:max-1
						frommax(amax.get(0), amax2.get(j), n);
						return;
					}
				}
			}
			if(get(amax.get(0), amax2.get(0), 0) < get(amax.get(0), amax2.get(0), 1)){
				frommin(amax.get(0), amax2.get(0), n);
			}else{
				frommax(amax.get(0), amax2.get(0), n);
			}
			return;
		}

		assert cha >= 4;
		List<Integer> d1 = new ArrayList<>();
		List<Integer> d2 = new ArrayList<>();
		for(int i = 2;i < n;i++){
			if(ds[i] == cha-1)d1.add(i);
			if(ds[i] == cha-2)d2.add(i);
		}
		int nei = -1;
		out:
		for(int u : d1){
			for(int v : d2){
				if(get(u, v, 0) == 1){
					// 0 u v
					nei = u;
					break out;
				}
			}
		}
//		tr(d1, d2, cha);
		assert nei != -1;

		int[][] bu = new int[n+1][2];
		int[] bp = new int[n+1];
		for(int i = 2;i < n;i++){
			if(ds[i] < cha){
				bu[ds[i]][bp[ds[i]]++] = i;
			}
		}
		int[] from0 = new int[n];
		Arrays.fill(from0, Integer.MIN_VALUE);
		from0[0] = 0;
		from0[1] = cha;
		for(int i = 1;i < cha;i++){
			if(bp[i] == 0)continue;
			if(bp[i] == 1){
				from0[bu[i][0]] = cha/2;
			}else{
				assert bp[i] == 2;
				int g = nei == bu[i][0] ? 0 : get(0, nei, bu[i][0]);
				from0[bu[i][0]] = g + 1;
				from0[bu[i][1]] = cha - (g + 1);
			}
		}

		int[] es = new int[n];
		for(int i = 2;i < n;i++){
			if(ds[i] >= cha){
				es[i] = get(0, nei, i);
				if(es[i] <= cha-1){
					from0[i] = -es[i];
				}else{
					bu[es[i]][bp[es[i]]++] = i;
				}
			}
		}
		int nei2 = -1;
		for(int i = 0;i < n;i++){
			if(from0[i] == 2){
				nei2 = i;
			}
		}
		assert nei2 != -1;

		int dir = 0;
		for(int i = cha;i <= n;i++){
			if(bp[i] == 0)continue;
			if(dir == 1){
				assert bp[i] == 1;
				from0[bu[i][0]] = es[bu[i][0]] + 1;
				continue;
			}else if(dir == -1){
				assert bp[i] == 1;
				from0[bu[i][0]] = -es[bu[i][0]];
				continue;
			}
			int g = get(nei, nei2, bu[i][0]);
			if(g < es[bu[i][0]]){
				from0[bu[i][0]] = es[bu[i][0]] + 1;
				if(bp[i] == 2){
					from0[bu[i][1]] = -es[bu[i][0]];
				}else{
					dir = 1;
				}
			}else{
				from0[bu[i][0]] = -es[bu[i][0]];
				if(bp[i] == 2){
					from0[bu[i][1]] = es[bu[i][0]] + 1;
				}else{
					dir = -1;
				}
			}
		}

		int gmin = 0;
		for(int v : from0){
			gmin = Math.min(gmin, v);
		}
//		tr(from0);
		assert gmin != Integer.MIN_VALUE;
		out.print("! ");
		for(int i = 0;i < n;i++){
			out.print(from0[i] - gmin + 1 + " ");
		}
		out.println();
		out.flush();
	}


	void frommin(int a, int b, int n)
	{
		int[] ans = new int[n];
		ans[a] = 0;
		ans[b] = 1;
		for(int i = 0;i < n;i++){
			if(i == a || i == b)continue;
			ans[i] = get(a, b, i) + 1;
		}
		out.print("! ");
		for(int i = 0;i < n;i++){
			out.print(ans[i] + 1 + " ");
		}
		out.println();
		out.flush();
	}

	void frommax(int a, int b, int n)
	{
		int[] ans = new int[n];
		ans[a] = n-1;
		ans[b] = n-2;
		for(int i = 0;i < n;i++){
			if(i == a || i == b)continue;
			ans[i] = n-get(a, b, i) - 2;
		}
		out.print("! ");
		for(int i = 0;i < n;i++){
			out.print(ans[i] + 1 + " ");
		}
		out.println();
		out.flush();
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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