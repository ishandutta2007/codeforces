//package round366;
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
//		int[] f = new int[2];
//		for(int i = 0;i < 16;i++){
//			int a = i>>>3&1, b = i>>>2&1, c = i>>>1&1, d = i>>>0&1;
////			f[(a|b)^((b^1)|c)^(c|(d^1))^(a^1)]++;
////			f[(a|b)^((b^1)|c)^(a^1)]++;
//			f[(a|b)^(a^1)]++;
////			f[(a^1)]++;
//		}
		
		int mod = 1000000007;
		int n = ni(), m = ni();
		int[] from = new int[n];
		int[] to = new int[n];
		int[] w = new int[n];
		int[][] xnf = new int[n][];
		
		int[] ff = new int[n];
		int[] tt = new int[n];
		int p = 0;
		int q = 0;
		for(int i = 0;i < n;i++){
			int L = ni();
			xnf[i] = na(L);
			if(L >= 2 && Math.abs(xnf[i][0]) != Math.abs(xnf[i][1])){
				from[p] = Math.abs(xnf[i][0]);
				to[p] = Math.abs(xnf[i][1]);
				w[p] = i;
				p++;
			}else{
				ff[q] = Math.abs(xnf[i][0]);
				tt[q] = i;
				q++;
			}
		}
		int[][] xg = packD(m+1, ff, tt, q);
		
		int[][][] g = packWU(m+1, from, to, w, p);
		
		long[] gdp = new long[]{1, 0};
		boolean[] ved = new boolean[m+1];
		for(int i = 1;i <= m;i++){
			if(ved[i])continue;
			if(g[i].length == 1){
//				tr("start", i);
				int pre = -1;
				long[][] dp = new long[2][2]; // result last
				dp[0][0] = 1; dp[0][1] = 1;
				for(int cur = i;;){
					ved[cur] = true;
					dp = one(xg[cur], xnf, dp, mod);
//					tr(dp, cur);
					
					if(pre != -1 && g[cur].length == 1)break;
					int ind = 0;
					int nex = g[cur][0][0]; ind = 0;
					if(nex == pre){
						nex = g[cur][1][0];
						ind = 1;
					}
					int eid = g[cur][ind][1];
					int cocur = -1, conex = -1;
					for(int z = 0;z < 2;z++){
						if(xnf[eid][z] == -cur)cocur = 1;
						if(xnf[eid][z] == cur)cocur = 0;
						if(xnf[eid][z] == -nex)conex = 1;
						if(xnf[eid][z] == nex)conex = 0;
					}
					assert cocur != -1;
					assert conex != -1;
					
					{
						long[][] ndp = new long[2][2];
						for(int r = 0;r < 2;r++){
							for(int z = 0;z < 2;z++){
								for(int y = 0;y < 2;y++){// y->z
									int val = (y^cocur) | (z^conex);
									ndp[r^val][z] += dp[r][y];
									if(ndp[r^val][z] >= mod)ndp[r^val][z] -= mod;
								}
							}
						}
						dp = ndp;
					}
					
					pre = cur;
					cur = nex;
				}
				// 6 2
				// 6 2
				// 6 10
				// 72+72+360+40
				// TTT TF=T
				// TTF FF=F
				// TFT TT=F
				// TFF TT=F
				// FFF TT=F
				// FFT TT=F
				// FTF TF=T
				// FTT TT=F
//				tr(dp);
				long[] gndp = new long[]{0, 0};
				for(int z = 0;z < 2;z++){
					for(int y = 0;y < 2;y++){
						gndp[y^z] += gdp[y] * (dp[z][0]+dp[z][1]);
						gndp[y^z] %= mod;
					}
				}
				gdp = gndp;
			}else if(g[i].length == 0){
				ved[i] = true;
				int[] lto = new int[]{0, 0};
				for(int u : xg[i]){
					int[] x = xnf[u];
					for(int z = 0;z < 2;z++){
						int res = 0;
						for(int v = 0;v < x.length;v++){
							if(x[v] > 0){
								res |= z;
							}else{
								res |= z^1;
							}
						}
						lto[z] ^= res;
					}
				}
				long[] gndp = new long[]{0, 0};
				for(int z = 0;z < 2;z++){
					for(int y = 0;y < 2;y++){
						gndp[y^lto[z]] += gdp[y];
						gndp[y^lto[z]] %= mod;
					}
				}
				gdp = gndp;
			}
		}
		for(int i = 1;i <= m;i++){
			if(ved[i])continue;
//			tr("start", i);
			long[] trans = new long[2];
			for(int first = 0;first < 2;first++){
				long[][] dp = new long[2][2]; // result last
				dp[0][first] = 1;
				int pre = -1;
				for(int cur = i;;){
					if(pre != -1 && cur == i)break;
					dp = one(xg[cur], xnf, dp, mod);
					
					int ind = 0;
					int nex = g[cur][0][0]; ind = 0;
					if(nex == pre){
						nex = g[cur][1][0];
						ind = 1;
					}
					int eid = g[cur][ind][1];
					int cocur = -1, conex = -1;
					for(int z = 0;z < 2;z++){
						if(xnf[eid][z] == -cur)cocur = 1;
						if(xnf[eid][z] == cur)cocur = 0;
						if(xnf[eid][z] == -nex)conex = 1;
						if(xnf[eid][z] == nex)conex = 0;
					}
					assert cocur != -1;
					assert conex != -1;
					
					{
						long[][] ndp = new long[2][2];
						for(int r = 0;r < 2;r++){
							for(int z = 0;z < 2;z++){
								for(int y = 0;y < 2;y++){// y->z
									int val = (y^cocur) | (z^conex);
									ndp[r^val][z] += dp[r][y];
									if(ndp[r^val][z] >= mod)ndp[r^val][z] -= mod;
								}
							}
						}
						dp = ndp;
					}
					
					pre = cur;
					cur = nex;
				}
				trans[0] += dp[0][first];
				trans[1] += dp[1][first];
			}
			long[] gndp = new long[]{0, 0};
			for(int z = 0;z < 2;z++){
				for(int y = 0;y < 2;y++){
					gndp[y^z] += gdp[y] * trans[z];
					gndp[y^z] %= mod;
				}
			}
			gdp = gndp;
			
			int pre = -1;
			for(int cur = i;;){
				if(ved[cur])break;
				ved[cur] = true;
				int nex = g[cur][0][0];
				if(nex == pre){
					nex = g[cur][1][0];
				}
				
				pre = cur;
				cur = nex;
			}
		}
		out.println(gdp[1]);
	}
	
	long[][] one(int[] row, int[][] xnf, long[][] dp, int mod)
	{
		int[] lto = new int[]{0, 0};
		for(int u : row){
			int[] x = xnf[u];
			for(int z = 0;z < 2;z++){
				int res = 0;
				for(int v = 0;v < x.length;v++){
					if(x[v] > 0){
						res |= z;
					}else{
						res |= z^1;
					}
				}
				lto[z] ^= res;
			}
		}
		{
			long[][] ndp = new long[2][2];
			for(int r = 0;r < 2;r++){
				for(int z = 0;z < 2;z++){
					ndp[r^lto[z]][z] += dp[r][z];
					if(ndp[r^lto[z]][z] >= mod)ndp[r^lto[z]][z] -= mod;
				}
			}
			dp = ndp;
		}
		return dp;
	}
	
	public static int[][] packD(int n, int[] from, int[] to, int sup)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < sup;i++){
			g[from[i]][--p[from[i]]] = to[i];
		}
		return g;
	}
	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w, int sup)
	{
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < sup;i++)p[to[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]][2];
		for(int i = 0;i < sup;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			g[to[i]][p[to[i]]][1] = w[i];
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