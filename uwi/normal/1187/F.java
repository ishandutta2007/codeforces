//package educational.round67;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	public static int[] uniq(int[] a)
	{
		int n = a.length;
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i == 0 || a[i] != a[i-1])a[p++] = a[i];
		}
		return Arrays.copyOf(a, p);
	}

	
	int inter(int a, int b, int c, int d)
	{
		return Math.max(0, Math.min(b, d) - Math.max(a, c) + 1);
	}
	
	void solve()
	{
		int n = ni();
		int[] L = na(n);
		int[] R = na(n);
		int mod = 1000000007;
		
		long E = 1;
		long E2 = 1;
		long olde = 0;
		long oldd = 0;
		
		// E(x') = (sum E(x))/L + 1/L - (1/(KL) if intersects)
		// E(x'^2) = (sum E(x^2))/L + 2(sum E(x))/L + 1/L - ((2E(i)+1)/KL if intersects)
		// 
		for(int i = 1;i < n;i++){
			long it = inter(L[i-1], R[i-1], L[i], R[i]);
			long D = invl((long)(R[i-1]-L[i-1]+1)*(R[i]-L[i]+1)%mod, mod);
			long NE = E + 1
					- it * D;
			NE %= mod;
			if(NE < 0)NE += mod;
			
			long len3 = 0;
			long minus = 0;
			if(i-2 >= 0){
				long l3 = Math.max(Math.max(L[i-2], L[i-1]), L[i]);
				long r3 = Math.min(Math.min(R[i-2], R[i-1]), R[i]);
				len3 = Math.max(r3-l3+1, 0);
			}
			
			minus = len3 * (((olde + 1) * invl(R[i-1]-L[i-1]+1, mod) - oldd) % mod) +
					(it - len3) * (olde + 1) % mod * invl(R[i-1]-L[i-1]+1, mod) % mod;
			long NE2 = E2 + 2 * E -  2 * minus % mod * invl(R[i]-L[i]+1, mod) % mod
					+ 1 - it * D;
			NE2 %= mod;
			if(NE2 < 0)NE2 += mod;
			olde = E;
			oldd = D;
			E = NE;
			E2 = NE2;
//			tr(E, E2, guessFrac(E, mod), guessFrac(E2, mod));
		}
		out.println(E2);
	}
	
	public static long[] guessFrac(long n, int mod)
	{
		long min = mod;
		long argnum = -1, argden = 0;
		for(int den = 1;den <= 200000;den++){
			long num = n*den%mod;
			if(num*2 >= mod)num -= mod;
			if(Math.abs(num) + den < min){
				min = Math.abs(num) + den;
				argnum = num;
				argden = den;
			}
		}
		return argden == 0 ? null : new long[]{argnum, argden};
	}
	
	public static long invl(long a, long mod) {
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
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
	
	public static void main(String[] args) throws Exception { new F2().run(); }
	
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