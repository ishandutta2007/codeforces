//package tinkoff2017.e;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] trap = new int[2][];
		for(int i = 0;i < 2;i++){
			trap[i] = na(2);
		}
		int[][] mouse = new int[n][];
		for(int i = 0;i < n;i++){
			mouse[i] = na(4);
		}
		
		// tx1 < mx+vx*t < tx2
		long[] min = {0L, 1L};
		long[] max = {1L, 0L};
		for(int[] m : mouse){
			for(int u = 0;u < 2;u++){
				{
					long[] res = calc(-m[2+u], -(trap[0][0+u]-m[0+u]));
					if(res[2] == 2){
					}else if(res[2] == 3){
						out.println(-1);
						return;
					}else if(res[2] == 1){
						if(compare(min, res) < 0)min = res;
					}else{
						if(compare(max, res) > 0)max = res;
					}
				}
				{
					long[] res = calc(m[2+u], trap[1][0+u]-m[0+u]);
					if(res[2] == 2){
					}else if(res[2] == 3){
						out.println(-1);
						return;
					}else if(res[2] == 1){
						if(compare(min, res) < 0)min = res;
					}else{
						if(compare(max, res) > 0)max = res;
					}
				}
			}
		}
		if(compare(min, max) < 0){
			out.printf("%.14f\n", min[0]/(double)min[1]);
		}else{
			out.println(-1);
		}
	}
	
	// ax <= b
	static long[] calc(long a, long b)
	{
		if(a == 0){
			if(b > 0){
				return new long[]{0, 0, 2};
			}else{
				return new long[]{0, 0, 3};
			}
		}else if(a > 0){
			return reduce(new long[]{b, a, 0});
		}else{
			return reduce(new long[]{b, a, 1});
		}
	}
	
	public static long[] reduce(long[] f)
	{
		if(f[1] == 0) { // n/0
			f[0] = 1;
		}else if(f[0] == 0) { // 0/n
			f[1] = 1;
		}else {
			if(f[1] < 0) { // -a/-b ->a/b
				f[0] = -f[0];
				f[1] = -f[1];
			}
			long a = Math.abs(f[0]), b = f[1];
			while (b > 0) {
				long c = a;
				a = b;
				b = c % b;
			}
			f[0] /= a;
			f[1] /= a;
		}
		return f;
	}
	
	public static long[] add(long[] a, long[] b){ return reduce(new long[]{a[0]*b[1]+a[1]*b[0], a[1]*b[1]}); }
	public static long[] sub(long[] a, long[] b){ return reduce(new long[]{a[0]*b[1]-a[1]*b[0], a[1]*b[1]}); }
	public static long[] mul(long[] a, long[] b){ return reduce(new long[]{a[0]*b[0], a[1]*b[1]}); }
	public static long[] div(long[] a, long[] b){ return reduce(new long[]{a[0]*b[1], a[1]*b[0]}); }
		
	public static int compare(long[] a, long[] b){return Long.signum(a[0] * b[1] - a[1] * b[0]);}
	
	public static long[] min(long[] a, long[] b){ return compare(a, b) <= 0 ? a : b; }
	public static long[] max(long[] a, long[] b){ return compare(a, b) >= 0 ? a : b; }
	
	public static int lowerBound(long[][] es, int p, long[] r)
	{
		int low = -1, high = p;
		while(high-low > 1){
			int h = high+low>>>1;
			if(Long.compare(r[0]*es[h][1], r[1]*es[h][0]) <= 0){
				high = h;
			}else{
				low = h;
			}
		}
		return high;
	}
	
	public static Comparator<long[]> comp = (a, b) -> Long.signum(a[0]*b[1]-a[1]*b[0]);

	
	// v*t >= a
	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < 4*(n+1); i++) {
//			sb.append(gen.nextInt(200000)-100000 + " ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}