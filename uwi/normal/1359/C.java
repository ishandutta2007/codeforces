//package ecr88;
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
		// h
		// h/2+c/2
		// 2h/3+c/3
		for(int T = ni();T > 0;T--){
			go();
		}
	}
	
	void go()
	{
		long h = ni(), c = ni(), t = ni();
		if(t >= h){
			out.println(1);
			return;
		}
		if(2*t <= h+c){
			out.println(2);
			return;
		}
		// ((a+1)h+ac)/(2a+1) >= t
		// (a+1)h+ac >= t(2a+1)
		// a(h+c-2t) >= t-h
		// a(2t-h-c) <= h-t
		//  <= (h-t)/(2t-h-c)
		long amax = (h-t) / (2*t-h-c);
		long[] am = new long[]{(amax+1)*h+amax*c, 2*amax+1};
		long[] amt = sub(am, new long[]{t, 1});
		assert amt[0] >= 0;
		
		long[] ai = new long[]{(amax+2)*h+(amax+1)*c, 2*(amax+1)+1};
		long[] ait = sub(new long[]{t, 1}, ai);
		assert ait[0] >= 0;
		if(compare(amt, ait) <= 0){
			out.println(2*amax+1);
		}else{
			out.println(2*amax+3);
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

	
	void run() throws Exception
	{
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