//package test10;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]][2];
		for(int i = 0;i < from.length;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			g[to[i]][p[to[i]]][1] = w[i];
		}
		return g;
	}
	
	void solve()
	{
		int I = Integer.MAX_VALUE / 2;
		int n = ni(), K = ni();
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		int[] w = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			w[i] = i;
		}
		int[][] g = packU(n, from, to);
		int[][][] wg = packWU(n, from, to, w);
		
		int minans = 9999999;
		int minr = -1;
		for(int r = 0;r < n;r++){
			int[][] pars = parents3(g, r);
			int[] par = pars[0], ord = pars[1];
			int[][] dp = new int[n][n+1];
			int[] des = new int[n];
			for(int i = n-1;i >= 0;i--){
				des[ord[i]]++;
				if(i > 0)des[par[ord[i]]] += des[ord[i]];
			}
			
			for(int i = n-1;i >= 0;i--){
				int cur = ord[i];
				int[] ldp = new int[2];
				ldp[0] = 0;
				ldp[1] = g[cur].length-(i == 0 ? 0 : 1);
				
				int sum = 1;
				for(int e : g[cur]){
					if(par[cur] != e){
						int[] nldp = Arrays.copyOf(ldp, sum+des[e]+1);
						Arrays.fill(nldp, ldp.length, nldp.length, I);
						for(int j = 1;j <= sum;j++){
							for(int k = 1;k <= des[e];k++){
								nldp[j+k] = Math.min(nldp[j+k], ldp[j] + dp[e][k] - 1);
							}
						}
						ldp = nldp;
						sum += des[e];
					}
				}
//				if(r == 0)tr(cur, ldp);
				dp[cur] = ldp;
			}
			if(dp[r][K] < minans){
				minans = dp[r][K];
				minr = r;
			}
//			tr(dp[r][K]);
		}
		
		out.println(minans);
		{
			int r = minr;
			int[][] pars = parents3(g, r);
			int[] par = pars[0], ord = pars[1];
			int[][] dp = new int[n][n+1];
			int[][][] ep = new int[n][n+1][];
			int[] des = new int[n];
			for(int i = n-1;i >= 0;i--){
				des[ord[i]]++;
				if(i > 0)des[par[ord[i]]] += des[ord[i]];
			}
			
			for(int i = n-1;i >= 0;i--){
				int cur = ord[i];
				int[] ldp = new int[2];
				ldp[0] = 0;
				ldp[1] = g[cur].length-(i == 0 ? 0 : 1);
				int[][] lep = new int[2][];
				lep[0] = new int[0];
				lep[1] = new int[ldp[1]];
				int p = 0;
				for(int[] e : wg[cur]){
					if(par[cur] != e[0]){
						lep[1][p++] = e[1];
					}
				}
				
				int sum = 1;
				int st = 0;
				for(int e : g[cur]){
					if(par[cur] != e){
						int[] nldp = Arrays.copyOf(ldp, sum+des[e]+1);
						int[][] nlep = Arrays.copyOf(lep, sum+des[e]+1);
						Arrays.fill(nldp, ldp.length, nldp.length, I);
						for(int j = 1;j <= sum;j++){
							for(int k = 1;k <= des[e];k++){
								int v = ldp[j] + dp[e][k] - 1;
								if(v < nldp[j+k]){
									nldp[j+k] = v;
									nlep[j+k] = new int[lep[j].length + ep[e][k].length-1];
									int q = 0;
									for(int l = 0;l < lep[j].length;l++){
										if(lep[j][l] != wg[cur][st][1])nlep[j+k][q++] = lep[j][l];
									}
									for(int l = 0;l < ep[e][k].length;l++){
										nlep[j+k][q++] = ep[e][k][l];
									}
								}
							}
						}
						ldp = nldp;
						lep = nlep;
						sum += des[e];
					}
					st++;
				}
//					if(r == 0)tr(cur, ldp);
				dp[cur] = ldp;
				ep[cur] = lep;
//				tr(i, dp[cur], ep[cur]);
			}
			for(int j = 0;j < ep[r][K].length;j++){
				if(j > 0)out.print(" ");
				out.print(ep[r][K][j]+1);
			}
			out.println();
		}
	}
	
	public static int[][] parents3(int[][] g, int root) {
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);

		int[] depth = new int[n];
		depth[0] = 0;

		int[] q = new int[n];
		q[0] = root;
		for(int p = 0, r = 1;p < r;p++){
			int cur = q[p];
			for(int nex : g[cur]){
				if(par[cur] != nex){
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
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
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
	
	public static void main(String[] args) throws Exception { new D3().run(); }
	
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}