import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D11264_4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] s = ns().toCharArray();
		int n = s.length;
		int mod = 998244353;
		
		int[] os = new int[n+1];
		int[] qs = new int[n+1];
		{
			int o = 0, q = 0;
			for(int i = 0;i < n;i++) {
				char c = s[i];
				if(c == '(') {
					o++;
				}else if(c == '?') {
					q++;
				}
				os[i+1] = o;
				qs[i+1] = q;
			}
		}
		
		int[] rcs = new int[n+1];
		int[] rqs = new int[n+1];
		{
			int o = 0, q = 0;
			for(int i = n-1;i >= 0;i--) {
				char c = s[i];
				if(c == ')') {
					o++;
				}else if(c == '?') {
					q++;
				}
				rcs[i] = o;
				rqs[i] = q;
			}
		}
		
		long[] p2 = enumPows(2, n+5, mod);
		
		int[][] fif = enumFIF(1000005, mod);
		
		int Q = 0;
		for(char c : s) {
			if(c == '?')Q++;
		}
		
		long[] dq = new long[n+1];
		for(int i = 1;i <= n;i++) {
			dq[i] = dq[i-1] + C(Q, i-1, mod, fif);
			if(dq[i] >= mod)dq[i] -= mod;
		}
		long[] dqm1 = new long[n+1];
		for(int i = 1;i <= n;i++) {
			dqm1[i] = dqm1[i-1] + C(Q-1, i-1, mod, fif);
			if(dqm1[i] >= mod)dqm1[i] -= mod;
		}
		
		// (x+1)^q*x^o|e>=D - ((x+1)^q'*x^o'|e>=D) * (2 or 1)
		// s[i] == '(' -> (x+1)^q*x^o|e==D
		// (x+1)^q*x^o|e>=D, (x+1)^rq*x^rc|e>=D
		
		// f(x,i) = (x+1)^q*x^o
		// g(x,i) = (x+1)^rq*x^rc
		// g(x,i) = x^n*(1/x+1)^rq*(1/x)^rc
		// g(x,i) = x^(n-rq-rc)*(x+1)^rq
		
		// f(x,i)|D-1 * g(x,i)|>=D|x=1
		// f(x,i) * ~g(x,i)|<=D-1+n-D
		
		
		
		long ans = 0;
		for(int i = 0;i < n;i++) {
			if(s[i] == ')')continue;
			int e = n-rqs[i+1]-rcs[i+1]+os[i];
			int xe = rqs[i+1] + qs[i];
			// (x+1)^xe*x^e | <= n-1
			long C = 0;
			if(e >= n) {
			}else if(e + xe <= n-1) {
				C += p2[xe];
			}else {
				C += xe == Q ? dq[n-1-e+1] : dqm1[n-1-e+1];
			}
			ans += C;
		}
		ans %= mod;
		out.println(ans);
	}
	
	public static long C(int n, int r, int mod, int[][] fif) {
		if (n < 0 || r < 0 || r > n)
			return 0;
		return (long) fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod;
	}

	
	public static int[][] enumFIF(int n, int mod) {
		int[] f = new int[n + 1];
		int[] invf = new int[n + 1];
		f[0] = 1;
		for (int i = 1; i <= n; i++) {
			f[i] = (int) ((long) f[i - 1] * i % mod);
		}
		long a = f[n];
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
		invf[n] = (int) (p < 0 ? p + mod : p);
		for (int i = n - 1; i >= 0; i--) {
			invf[i] = (int) ((long) invf[i + 1] * (i + 1) % mod);
		}
		return new int[][] { f, invf };
	}

	
public static long[] enumPows(int a, int n, int mod)
{
	a %= mod;
	long[] pows = new long[n+1];
	pows[0] = 1;
	for(int i = 1;i <= n;i++)pows[i] = pows[i-1] * a % mod;
	return pows;
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
	
	public static void main(String[] args) throws Exception { new D11264_4().run(); }
	
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