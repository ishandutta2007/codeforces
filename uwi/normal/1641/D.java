//package round773;
import java.io.*;
import java.util.*;

public class D4 {
	InputStream is;
	FastWriter out;
	String INPUT = "";
	Random gen = new Random();
	long M = gen.nextLong();

	static class Datum
	{
		int[] a;
		int w;

		public Datum(int[] a, int w) {
			this.a = a;
			this.w = w;
		}
	}
	
	void solve()
	{
		int n = ni();
		m = ni();
		Datum[] ds = new Datum[n];
		for(int i = 0;i < n;i++) {
			ds[i] = new Datum(na(m), ni());
			Arrays.sort(ds[i].a);
		}
		Arrays.sort(ds, Comparator.comparingInt(x -> x.w));

		List<LongHashMapWithoutDeletion> maps = new ArrayList<>();
		for(int i = 0;i <= m;i++)maps.add(new LongHashMapWithoutDeletion());

		long[][] hey = new long[n][1<<m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < 1<<m;j++){
				long x = 0;
				for(int k = 0;k < m;k++){
					if(j<<~k<0){
						x = x * M + ds[i].a[k];
					}
				}
				hey[i][j] = x;
			}
		}

		for(int i = 0;i < n;i++){
			add(maps, hey[i], 1);
		}

		long ans = Long.MAX_VALUE;
		int r = n-1;
		for(int l = 0;l < r+1;l++) {
			while (cross(maps, hey[l]) < r - l + 1) {
				add(maps, hey[r], -1);
				r--;
			}
			if(l < r+1 && r+1 < n){
				ans = Math.min(ans, ds[l].w + ds[r+1].w);
			}
			add(maps, hey[l], -1);
		}
		out.println(ans == Long.MAX_VALUE ? -1 : ans);
	}

	int m;

	void add(List<LongHashMapWithoutDeletion> maps, long[] hey, int v)
	{
		for(int j = 1;j < 1<<m;j++){
			int len = Integer.bitCount(j);
			maps.get(len).inc(hey[j], v);
		}
	}

	long cross(List<LongHashMapWithoutDeletion> maps, long[] hey)
	{
		long ret = 0;
		for(int j = 1;j < 1<<m;j++){
			int len = Integer.bitCount(j);
			ret += maps.get(len).get(hey[j]) * (len%2*2-1);
		}
		return ret;
	}

	public static class LongHashMapWithoutDeletion {
		int[] first;
		int[] next;
		long[] keys;
		int[] vals;
		int size;
		int scale;

		public LongHashMapWithoutDeletion() {
			scale = 1;
			keys = new long[1 << scale];
			vals = new int[1 << scale];
			first = new int[1 << scale];
			next = new int[1 << scale];
			size = 0;
			Arrays.fill(first, -1);
			Arrays.fill(next, -1);
		}

		public void rehash() {
			scale++;
			keys = Arrays.copyOf(keys, 1 << scale);
			vals = Arrays.copyOf(vals, 1 << scale);
			first = new int[1 << scale];
			next = new int[1 << scale];
			Arrays.fill(first, -1);
			Arrays.fill(next, -1);
			for (int i = 0; i < 1 << scale - 1; i++) {
				int h = h(keys[i]) & (1 << scale) - 1;
				next[i] = first[h];
				first[h] = i;
			}
		}

		public void put(long key, int val) {
			int h = h(key) & (1 << scale) - 1;
			int ind = search(h, key);
			if (ind >= keys.length) {
				rehash();
				h = h(key) & (1 << scale) - 1;
			}
			if (ind < size) {
				vals[ind] = val;
			} else {
				keys[ind] = key;
				vals[ind] = val;
				next[ind] = first[h];
				first[h] = ind;
				size++;
			}
		}

		public void inc(long key, int val) {
			int h = h(key) & (1 << scale) - 1;
			int ind = search(h, key);
			if (ind >= keys.length) {
				rehash();
				h = h(key) & (1 << scale) - 1;
			}
			if (ind < size) {
				vals[ind] += val;
			} else {
				keys[ind] = key;
				vals[ind] = val;
				next[ind] = first[h];
				first[h] = ind;
				size++;
			}
		}

		public boolean containsKey(long key) {
			int h = h(key) & (1 << scale) - 1;
			int ind = search(h, key);
			return ind < size;
		}

		public int get(long key) {
			int h = h(key) & (1 << scale) - 1;
			int ind = search(h, key);
			return ind >= size ? 0 : vals[ind];
		}

		private int search(int h, long key) {
			for (int f = first[h]; f != -1; f = next[f]) {
				if (keys[f] == key) return f;
			}
			return size;
		}

		private int h(long x) {
			x ^= x >>> 33;
			x *= 0xff51afd7ed558ccdL;
			x ^= x >>> 33;
			x *= 0xc4ceb9fe1a85ec53L;
			x ^= x >>> 33;
			return (int) (x ^ x >>> 32);
		}
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
	
	public static void main(String[] args) throws Exception { new D4().run(); }
	
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