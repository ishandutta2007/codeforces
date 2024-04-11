//package educational.round01;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class CRe {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long[][] co = new long[n][];
		for(int i = 0;i < n;i++) {
			co[i] = new long[] {ni(), ni(), i+1};
		}
		Arrays.sort(co, compArgl);

		long bnum = -1;
		long bden = 0;
		int arg = -1;
		for(int i = 0;i < n;i++) {
			int j = (i+1)%n;
			long sig = Long.signum(dot(co[i], co[j]));
			long num = dot(co[i], co[j])*dot(co[i], co[j])*sig;
			long den = dot(co[i], co[i])*dot(co[j], co[j]);
			
			// bnum*den < num*bden
			if(comp(bnum, bden, num, den) < 0) {
				bnum = num; bden = den;
				arg = i;
			}
		}
		out.println(co[arg][2] + " " + co[(arg+1)%n][2]);
	}
	
	long comp(long an, long ad, long bn, long bd)
	{
		double bal = (double)an*bd-(double)bn*ad;
		if(Math.abs(bal) > 1e18)return (int)Math.signum(bal);
		
		return an*bd-bn*ad;
	}
	
	public static long dot(long[] a, long[] b){ return a[0]*b[0]+a[1]*b[1]; }

	
	public static Comparator<long[]> compArgl = new Comparator<long[]>(){
		public int compare(long[] a, long[] b)
		{
			long ax = a[0], ay = a[1];
			long bx = b[0], by = b[1];
			int za = ay > 0 || ay == 0 && ax > 0 ? 0 : 1;
			int zb = by > 0 || by == 0 && bx > 0 ? 0 : 1;
			if(za != zb)return za - zb;
			if(ay*bx-ax*by != 0)return Long.signum(ay*bx-ax*by);
			return Long.signum((ax*ax+ay*ay)-(bx*bx+by*by));
		}
	};

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new CRe().run(); }
	
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