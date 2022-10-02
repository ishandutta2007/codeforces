//package round183;
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
		long n = ni(), m = ni();
		long x = ni(), y = ni();
		long a = ni(), b = ni();
		long g = gcd(a, b);
		a /= g; b /= g;
		long r = Math.min(n/a, m/b);
		a *= r; b *= r;
		
		long min = Long.MAX_VALUE;
		long[] id = null;
		{
			long x1 = 0, y1 = 0;
			if(x1<=x && x<=x1+a && y1<=y && y<=y1+b && x1 >= 0 && x1+a <= n && y1 >= 0 && y1+b <= m){
				long d = (long)(2*x-(2*x1+a))*(2*x-(2*x1+a))+(2*y-(2*y1+b))*(2*y-(2*y1+b));
				long[] nid = new long[]{x1, y1, x1+a, y1+b};
				if(d < min || (d == min && comp(id, nid))){
					min = d; id = nid;
				}
			}
		}
		{
			long x1 = 0, y1 = m-b;
			if(x1<=x && x<=x1+a && y1<=y && y<=y1+b && x1 >= 0 && x1+a <= n && y1 >= 0 && y1+b <= m){
				long d = (long)(2*x-(2*x1+a))*(2*x-(2*x1+a))+(2*y-(2*y1+b))*(2*y-(2*y1+b));
				long[] nid = new long[]{x1, y1, x1+a, y1+b};
				if(d < min || (d == min && comp(id, nid))){
					min = d; id = nid;
				}
			}
		}
		{
			long x1 = n-a, y1 = 0;
			if(x1<=x && x<=x1+a && y1<=y && y<=y1+b && x1 >= 0 && x1+a <= n && y1 >= 0 && y1+b <= m){
				long d = (long)(2*x-(2*x1+a))*(2*x-(2*x1+a))+(2*y-(2*y1+b))*(2*y-(2*y1+b));
				long[] nid = new long[]{x1, y1, x1+a, y1+b};
				if(d < min || (d == min && comp(id, nid))){
					min = d; id = nid;
				}
			}
		}
		{
			long x1 = n-a, y1 = m-b;
			if(x1<=x && x<=x1+a && y1<=y && y<=y1+b && x1 >= 0 && x1+a <= n && y1 >= 0 && y1+b <= m){
				long d = (long)(2*x-(2*x1+a))*(2*x-(2*x1+a))+(2*y-(2*y1+b))*(2*y-(2*y1+b));
				long[] nid = new long[]{x1, y1, x1+a, y1+b};
				if(d < min || (d == min && comp(id, nid))){
					min = d; id = nid;
				}
			}
		}
		for(long y1 = y-b/2-1;y1 <= y-b/2+1;y1++){
			long x1 = 0;
			if(x1<=x && x<=x1+a && y1<=y && y<=y1+b && x1 >= 0 && x1+a <= n && y1 >= 0 && y1+b <= m){
				long d = (long)(2*x-(2*x1+a))*(2*x-(2*x1+a))+(2*y-(2*y1+b))*(2*y-(2*y1+b));
				long[] nid = new long[]{x1, y1, x1+a, y1+b};
				if(d < min || (d == min && comp(id, nid))){
					min = d; id = nid;
				}
			}
		}
		for(long y1 = y-b/2-1;y1 <= y-b/2+1;y1++){
			long x1 = n-a;
			if(x1<=x && x<=x1+a && y1<=y && y<=y1+b && x1 >= 0 && x1+a <= n && y1 >= 0 && y1+b <= m){
				long d = (long)(2*x-(2*x1+a))*(2*x-(2*x1+a))+(2*y-(2*y1+b))*(2*y-(2*y1+b));
				long[] nid = new long[]{x1, y1, x1+a, y1+b};
				if(d < min || (d == min && comp(id, nid))){
					min = d; id = nid;
				}
			}
		}
		for(long x1 = x-a/2-1;x1 <= x-a/2+1;x1++){
			long y1 = 0;
			if(x1<=x && x<=x1+a && y1<=y && y<=y1+b && x1 >= 0 && x1+a <= n && y1 >= 0 && y1+b <= m){
				long d = (long)(2*x-(2*x1+a))*(2*x-(2*x1+a))+(2*y-(2*y1+b))*(2*y-(2*y1+b));
				long[] nid = new long[]{x1, y1, x1+a, y1+b};
				if(d < min || (d == min && comp(id, nid))){
					min = d; id = nid;
				}
			}
		}
		for(long x1 = x-a/2-1;x1 <= x-a/2+1;x1++){
			long y1 = m-b;
			if(x1<=x && x<=x1+a && y1<=y && y<=y1+b && x1 >= 0 && x1+a <= n && y1 >= 0 && y1+b <= m){
				long d = (long)(2*x-(2*x1+a))*(2*x-(2*x1+a))+(2*y-(2*y1+b))*(2*y-(2*y1+b));
				long[] nid = new long[]{x1, y1, x1+a, y1+b};
				if(d < min || (d == min && comp(id, nid))){
					min = d; id = nid;
				}
			}
		}
		for(long x1 = x-a/2-1;x1 <= x-a/2+1;x1++){
			for(long y1 = y-b/2-1;y1 <= y-b/2+1;y1++){
				if(x1<=x && x<=x1+a && y1<=y && y<=y1+b && x1 >= 0 && x1+a <= n && y1 >= 0 && y1+b <= m){
					long d = (long)(2*x-(2*x1+a))*(2*x-(2*x1+a))+(2*y-(2*y1+b))*(2*y-(2*y1+b));
					long[] nid = new long[]{x1, y1, x1+a, y1+b};
					if(d < min || (d == min && comp(id, nid))){
						min = d; id = nid;
					}
				}
			}
		}
		
		out.println(
				id[0] + " " +
				id[1] + " " +
				id[2] + " " +
				id[3]
				);
	}
	
	boolean comp(long[] a, long[] b){
		if(a == null)return true;
		if(b[0] < a[0])return true;
		if(b[0] > a[0])return false;
		if(b[1] < a[1])return true;
		return false;
	}
	
	public static long gcd(long a, long b) {
		while (b > 0){
			long c = a;
			a = b;
			b = c % b;
		}
		return a;
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