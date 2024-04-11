//package round305;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int m = ni();
		int h1 = ni(), a1 = ni();
		int x1 = ni(), y1 = ni();
		
		long t1 = 0, c1 = -1, aa1 = -1;
		{
			long cur = h1;
			int[] v = new int[m];
			Arrays.fill(v, -1);
			for(int i = 0;i < m+1;i++){
				if(v[(int)cur] != -1){
					t1 = v[(int)cur];
					c1 = i-v[(int)cur];
					aa1 = v[a1];
					break;
				}
				v[(int)cur] = i;
				cur = (x1 * cur + y1)%m;
			}
		}
		int h2 = ni(), a2 = ni();
		int x2 = ni(), y2 = ni();
		
		long t2 = 0, c2 = -1, aa2 = -1;
		{
			long cur = h2;
			int[] v = new int[m];
			Arrays.fill(v, -1);
			for(int i = 0;i < m+1;i++){
				if(v[(int)cur] != -1){
					t2 = v[(int)cur];
					c2 = i-v[(int)cur];
					aa2 = v[a2];
					break;
				}
				v[(int)cur] = i;
				cur = (x2 * cur + y2)%m;
			}
		}
//		tr(t1, c1, aa1);
//		tr(t2, c2, aa2);
		
		if(aa1 == -1 || aa2 == -1){
			out.println(-1);
			return;
		}
		
		if(aa1 < t1){
			if(aa2 < t2){
				out.println(aa1 == aa2 ? aa1 : -1);
			}else{
				if(aa1 >= aa2 && (aa1-aa2)%c2 == 0){
					out.println(aa1);
				}else{
					out.println(-1);
				}
			}
		}else{
			if(aa2 < t2){
				if(aa2 >= aa1 && (aa2-aa1)%c1 == 0){
					out.println(aa2);
				}else{
					out.println(-1);
				}
			}else{
				long ret = crt(c1, aa1 % c1, c2, aa2 % c2);
				if(ret == -1){
					out.println(-1);
				}else{
					long cc = (long)c1 / gcd(c1, c2) * c2;
					while(ret < aa1 || ret < aa2){
						ret += cc;
					}
					out.println(ret);
				}
			}
		}
	}
	
	public static long[] exgcd(long a, long b)
	{
		if(a == 0 || b == 0)return null;
		int as = Long.signum(a);
		int bs = Long.signum(b);
		a = Math.abs(a); b = Math.abs(b);
		long p = 1, q = 0, r = 0, s = 1;
		while(b > 0){
			long c = a / b;
			long d;
			d = a; a = b; b = d % b;
			d = p; p = q; q = d - c * q;
			d = r; r = s; s = d - c * s;
		}
		return new long[]{a, p * as, r * bs};
	}

	
	public static long crt(long p, long m, long q, long n)
	{
		long[] apr = exgcd(p, q);
		if((n - m) % apr[0] != 0)return -1;
		long mod = p * (q / apr[0]);
		long a = (apr[1] * ((n - m) / apr[0]) * p + m) % mod;
		if(a < 0)a += mod;
		return a;
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
	
	public static void main(String[] args) throws Exception { new A().run(); }
	
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