//package ecr94;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] lr = new int[n][];
		for(int i = 0;i < n;i++){
			lr[i] = new int[]{ni(), ni()};
		}
		
		boolean[] touch = new boolean[n];
		int[][] ng = new int[m][];
		for(int i = 0;i < m;i++){
			ng[i] = new int[]{ni()-1, ni()-1};
			touch[ng[i][0]] = true;
			touch[ng[i][1]] = true;
		}
		
		int[] f = new int[n];
		int[] nfs = new int[1<<m];
		for(int i = 0;i < 1<<m;i++){
			for(int j = 0;j < m;j++){
				if(i<<~j<0){
					if(++f[ng[j][0]] == 1)nfs[i]++;
					if(++f[ng[j][1]] == 1)nfs[i]++;
				}
			}
			for(int j = 0;j < m;j++){
				if(i<<~j<0){
					f[ng[j][0]] = f[ng[j][1]] = 0;
				}
			}
		}
		
		int[][] es = new int[2*n][];
		for(int i = 0;i < n;i++){
			es[i] = new int[]{lr[i][0], i};
			es[i+n] = new int[]{lr[i][1]+1, i};
		}
		Arrays.sort(es, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		
		boolean[] isin = new boolean[n];
		int p = 0;
		int nin = 0;
		long ans = 0;
		int mod = 998244353;
		int[][] fif = enumFIF(350000, mod);
		int[] co = new int[2*m+1];
		co[0] = 1;
		for(int K = 1;K <= n;K++){
			boolean recon = false;
			while(p < 2*n && es[p][0] <= K){
				if(isin[es[p][1]]){
					nin--;
				}else{
					nin++;
				}
				isin[es[p][1]] ^= true;
				if(touch[es[p][1]]){
					recon = true;
				}
				p++;
			}
			if(recon){
				co = reconstruct(ng, isin, nfs);
			}
			
			long lans = 0;
			for(int i = 0;i <= 2*m;i++){
				lans += C(nin-i, K-i, mod, fif) * co[i];
			}
			lans %= mod;
			
			ans += lans;
		}
		ans %= mod;
		if(ans < 0)ans += mod;
		
		out.println(ans);
	}
	
	int[] reconstruct(int[][] ng, boolean[] isin, int[] nfs)
	{
		int m = ng.length;
		int[] ret = new int[2*m+1];
		
		int ptn = 0;
		for(int j = 0;j < m;j++){
			if(isin[ng[j][0]] && isin[ng[j][1]]){
				ptn |= 1<<j;
			}
		}
		
		for(int i = ptn;i >= 0;i--){ i &= ptn; 
			ret[nfs[i]] += (Integer.bitCount(i) & 1) == 0 ? 1 : -1;
		} // include i=0
		return ret;
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
	
	public static void main(String[] args) throws Exception { new G().run(); }
	
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