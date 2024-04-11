//package round382;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		int mod = 1000000007;
		
		long[][][] dp = new long[n][K+2][K+2]; // close black, far white
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			if(cur != 0 && g[cur].length == 1){
				dp[cur][K+1][1] = 1;
				dp[cur][0][0] = 1;
			}else{
				long[][] fars = new long[K+2][K+2];
				for(int c = 1;c <= K+1;c++){
					for(int f = 0;f <= K+1;f++){
						long mul = 1;
						for(int e : g[cur]){
							if(par[cur] == e)continue;
							// #c >= c, #f <= f
							long s = 0;
							for(int j = c-1;j <= K+1;j++){
								for(int k = 0;k <= f;k++){
									s += dp[e][j][k];
									if(s >= mod)s -= mod;
								}
							}
							mul = mul * s % mod;
						}
						fars[c][f] = mul;
					}
				}
//				tr(fars);
				for(int c = 0;c <= K+1;c++){
					for(int f = K+1;f >= 1;f--){
						fars[c][f] -= fars[c][f-1];
						if(fars[c][f] < 0)fars[c][f] += mod;
					}
				}
				for(int f = K+1;f >= 0;f--){
					for(int c = 1;c <= K;c++){
						fars[c][f] -= fars[c+1][f];
						if(fars[c][f] < 0)fars[c][f] += mod;
					}
				}
//				tr(fars);
				
				// not put
				for(int c = 1;c <= K+1;c++){
					for(int f = K-1;f >= 0;f--){
//						if(fars[c][f] > 0)tr("MOV", c, f, fars[c][f], c, f+1);
						if(c+f <= K){
							dp[cur][c][0] += fars[c][f];
							if(dp[cur][c][0] >= mod)dp[cur][c][0] -= mod;
						}else{
							dp[cur][c][f+1] += fars[c][f];
							if(dp[cur][c][f+1] >= mod)dp[cur][c][f+1] -= mod;
						}
					}
				}
				// put
				for(int c = 1;c <= K+1;c++){
					for(int f = 0;f <= K;f++){
						dp[cur][0][0] += fars[c][f];
						if(dp[cur][0][0] >= mod)dp[cur][0][0] -= mod;
					}
				}
//				tr("dd", dp[cur]);
			}
//			for(int c = 0;c <= K+1;c++){
//				for(int f = 0;f <= K;f++){
//					if(dp[cur][c][f] != 0){
//						tr(cur, c, f, dp[cur][c][f]);
//					}
//				}
//			}
		}
		long ret = 0;
		for(int c = 0;c <= K;c++){
			ret += dp[0][c][0];
		}
		out.println(ret%mod);
	}
	
	public static int[][] parents3(int[][] g, int root) {
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);

		int[] depth = new int[n];
		depth[0] = 0;

		int[] q = new int[n];
		q[0] = root;
		for (int p = 0, r = 1; p < r; p++) {
			int cur = q[p];
			for (int nex : g[cur]) {
				if (par[cur] != nex) {
					q[r++] = nex;
					par[nex] = cur;
					depth[nex] = depth[cur] + 1;
				}
			}
		}
		return new int[][] { par, q, depth };
	}

	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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