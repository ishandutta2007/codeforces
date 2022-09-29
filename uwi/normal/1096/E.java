//package educational.round57;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int mod = 998244353;
		int[][] fif = enumFIF(10005, mod);
//		{
//			for(int P = 1;P <= 15;P++){
//				for(int n = 1;n <= 15;n++){
//					for(int K = 0;K <= (P-1)*n;K++){
//						if(D(P, n, K, mod, fif) != DN(P, n, K, mod)){
//							tr(P, n, K, D(P, n, K, mod, fif), DN(P, n, K, mod));
//						}
//					}
//				}
//			}
//			if(true)return;
//		}
		int n = ni(), S = ni(), R = ni();
		// p1=x some y>x
		// p1=x, #q=x
		if(n == 1){
			out.println(1);
			return;
		}
		
		long all = 0;
		long less = 0;
		int[] invs = enumInvs(100005, mod);
		for(int i = R;i <= S;i++){
			all += C(S-i+n-2, n-2, mod, fif);
			if(i == 0){
				if(S == 0){
					less += invl(n, mod);
				}
				continue;
			}
			
			for(int t = 0;S-i-t*i >= 0 && n-1-t >= 0;t++){
//				tr(i, t, n-1-t, S-i-t*i, D(i, n-1-t, S-i-t*i, mod, fif));
				less += D(i, n-1-t, S-i-t*i, mod, fif) * invs[t+1] % mod * C(n-1, t, mod, fif);
				less %= mod;
			}
		}
		less %= mod;
		all %= mod;
//		tr(less, all);
		out.println(less*invl(all, mod)%mod);
	}
	
	long DN(int P, int n, int K, int mod)
	{
		if(K < 0)return 0;
		long[] h = new long[K+1];
		h[0] = 1;
		if(P > 0){
			for(int i = 0;i < n;i++){
				for(int j = K-P;j >= 0;j--){
					h[j+P] -= h[j];
					if(h[j+P] < 0)h[j+P] += mod;
				}
				for(int j = 0;j < K;j++){
					h[j+1] += h[j];
					h[j+1] %= mod;
				}
			}
		}
		return h[K];
	}
	
	long D(int P, int n, int K, int mod, int[][] fif)
	{
		if(n == 0 && K == 0)return 1;
		assert 0 <= K && K <= (P-1)*n;
		// Sum_{r=0..floor(k/3)} (-1)^r*binomial(n, r)*binomial(k-3*r+n-1, n-1)).
		long ret = 0;
		for(int i = K/P;i >= 0;i--){
			ret = -ret + (long)C(n, i, mod, fif) * C(n+K-P*i-1, n-1, mod, fif);
			ret %= mod;
		}
		if(ret < 0)ret += mod;
//		tr("D", P, n, K, ret);
		return ret;
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

	
	public static int[] enumInvs(int n, int mod) {
		int[] inv = new int[n + 1];
		inv[1] = 1;
		for (int i = 2; i <= n; i++) {
			inv[i] = (int) (inv[mod % i] * (long) (mod - mod / i) % mod);
		}
		return inv;
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

	
	
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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