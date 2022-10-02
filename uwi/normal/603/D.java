//package round334;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class D4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long[][] co = new long[n][];
		for(int i = 0;i < n;i++){
			int a = ni(), b = ni(), c = ni();
			long[] leg = leg(0, 0, a, b, -c);
			co[i] = leg;
		}
		out.println(countColinear(co));
	}
	
	long countColinear(long[][] co)
	{
		int n = co.length;
		long ret = 0;
		Random gen = new Random();
		long x = gen.nextLong();
		long y = gen.nextLong();
		long[] all = new long[n-1];
		for(int i = 0;i < n;i++){
			int p = 0;
			int cent = 0;
			for(int j = i+1;j < n;j++){
				// n2/d2-n1/d1=(n2*d1-d2*n1)
				long xnum = co[j][0]*co[i][2]-co[i][0]*co[j][2];
				long ynum = co[j][1]*co[i][2]-co[i][1]*co[j][2];
				if(xnum == 0 && ynum == 0){
					cent++;
					continue;
				}
				if(xnum < 0 || xnum == 0 && ynum < 0){
					xnum = -xnum;
					ynum = -ynum;
				}
				{
					long g = gcd(Math.abs(ynum), Math.abs(xnum));
					xnum /= g;
					ynum /= g;
				}
				all[p++] = xnum*x^ynum*y;
			}
			Arrays.sort(all, 0, p);
			assert cent <= 2;
			ret += (long)cent*p;
			long same = 0;
			for(int j = 0;j < p;j++){
				if(j == 0 || all[j] != all[j-1]){
					same = 0;
				}
				ret += same;
				same++;
			}
		}
		return ret;
	}
	
	
	// ax+by+c=0
	// (b,-a)
	// (a,b)
	// (px+t*a,py+t*b)
	// a(px+t*a)+b*(py+t*b)+c=0
	// t(a^2+b^2)+a*px+b*py+c=0
	
	
	public static long[] leg(long px, long py, long a, long b, long c)
	{
		long num = -(a*px+b*py+c);
		long den = a*a+b*b;
		long xnum = px*den + num * a;
		long ynum = py*den + num * b;
		return new long[]{xnum, ynum, den};
	}
	
	public static long gcd(long a, long b) {
		while (b > 0) {
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
	
	public static void main(String[] args) throws Exception { new D4().run(); }
	
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