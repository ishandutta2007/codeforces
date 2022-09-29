//package bubblecup9f;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), c0 = ni(), c1 = ni();
		if(c0 > c1){
			int d = c0;c0 = c1; c1 = d;
		}
		if(c0 == 0){
			out.println((long)c1*(n-1));
			return;
		}
		
		long low = -1, high = 100000000000000000L;
		while(high - low > 1){
			long h = high+low>>1; // sup of split node's cost
			long eled = 0;
			for(long nc1 = 0;h-nc1*c1 >= 0;nc1++){
				long nc0 = (h-nc1*c1)/c0;
				// C(nc1+0,nc1)+C(nc1+1,nc1)+...+(nc1+nc0,nc0) # eliminated nodes
				// C(nc1+nc0+1,nc0+1)
				eled += roughC(nc1+nc0+1,nc1+1,18);
				if(eled > n-1)break;
			}
			if(eled >= n-1){
				high = h;
			}else{
				low = h;
			}
		}
		tr(high);
		
		{
			long ret = (long)(c0+c1)*(n-1); // # branch
			long eled = 0;
			for(long nc1 = 0;low-nc1*c1 >= 0;nc1++){
				long nc0 = (low-nc1*c1)/c0;
				// C(nc1+0,nc1)+C(nc1+1,nc1)+...+(nc1+nc0,nc1) # eliminated nodes
				// C(nc1+nc0+1,nc1+1)
				long val = roughC(nc1+nc0+1,nc1+1,18);
				eled += val;
				// none 0
				// C(nc1+0,nc1)*nc1*c1+C(nc1+1,nc1)*(c0+nc1*c1)+...+(nc1+nc0,nc1)*(nc0*c0+nc1*c1) # eliminated nodes
				// C(nc1+nc0+1,nc1+1)-C(nc1+k,nc1+1)
				// nc0*C(nc1+nc0+1,nc1+1)-C(nc1+nc0+1,nc1+1+1)
				// c1*val*nc1 + c0*(val*(nc0+1)-val)
				ret += c1*nc1*val + c0*(nc0*val-roughC(nc1+nc0+1,nc1+2,18));
			}
			long rem = n-1-eled;
			ret += rem * (low+1);
			out.println(ret);
		}
	}
	
	public static long roughC(long n, long r, double lim)
	{
		if(n < r || r < 0 || n < 0)return 0;
		if(r > n/2)r = n - r;
		if(r == 0)return 1;
		double logc = (n+0.5)*Math.log10(n)+(-r-0.5)*Math.log10(r)+(-n+r-0.5)*Math.log10(n-r)-Math.log10(2*Math.PI)/2;
		if(logc >= lim)return Long.MAX_VALUE/2;
		long x = 1;
		for(int i = 0;i < r;i++) {
			x *= n-i;
			x /= i+1;
		}
		return x;
	}

	
	
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new B2().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
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