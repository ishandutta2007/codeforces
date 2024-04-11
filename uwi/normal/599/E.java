//package round332;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), q = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		int[] h = new int[n];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1; to[i] = ni()-1;
			h[from[i]] |= 1<<to[i];
			h[to[i]] |= 1<<from[i];
			if(from[i] == to[i]){
				out.println(0);
				return;
			}
		}
		
		int[][] lcas = new int[q][];
		for(int i = 0;i < q;i++){
			lcas[i] = new int[]{ni()-1, ni()-1, ni()-1};
		}
		int[][][] lg = packX(n, lcas, 2);
		
		boolean[][] nglca = new boolean[n][1<<n];
		for(int root = 0;root < n;root++){
			for(int[] lrow : lg[root]){
				if(lrow[0] == lrow[1]){
					if(lrow[0] != lrow[2]){
						out.println(0);
						return;
					}
				}else{
					nglca[root][1<<lrow[0]|1<<lrow[1]] = true;
				}
			}
			for(int i = 0;i < n;i++){
				for(int j = 0;j < 1<<n;j++){
					if(j<<~i>=0){
						nglca[root][j|1<<i] |= nglca[root][j];
					}
				}
			}
		}
		
		long[][] dp = new long[1<<n][n];
		long[][] lpre = new long[1<<n][2];
		long[][] lcur = new long[1<<n][2];
		for(int ptn = 1;ptn < 1<<n;ptn++){
			outer:
			for(int root = 0;root < n;root++){
				if(ptn<<~root<0){
					if(root == 0 && (ptn+1) != 1<<n)continue;
					for(int j = 0;j < n;j++){
						if(ptn<<~j<0 && j != root && (ptn&h[j]) != h[j])continue outer;
					}
					
					int mustcon = ptn&h[root];
					for(int[] lrow : lg[root]){
						if(ptn<<~lrow[0] >= 0)continue outer;
						if(ptn<<~lrow[1] >= 0)continue outer;
					}
					
					int pr = ptn^1<<root;
					for(int i = pr;i >= 0;i--){ i &= pr;
						lpre[i][0] = lpre[i][1] = 0;
					} // include i=0
					
					lpre[0][0] = 1;
					int maycon = pr&~mustcon;
					for(int i = 0;i < n;i++){
						if(mustcon<<~i<0){ // i is in mustcon and subroot
							for(int j = pr;j >= 0;j--){ j &= pr;
								lcur[j][0] = lcur[j][1] = 0;
							} // include j=0
							for(int j = maycon;j >= 0;j--){ j &= maycon;
								if(nglca[root][j|1<<i])continue;
								int al = 1<<root|j;
								if((al&h[i]) != h[i])continue;
								if(dp[j|1<<i][i] == 0)continue;
								int mask = pr&~(j|1<<i);
//								tr("ok", dp[j|1<<i][i], j, i);
								for(int k = mask;k >= 0;k--){ k &= mask;  // j -> j|1<<i|k
									lcur[(j|1<<i)|k][0] += lpre[k][0] * dp[j|1<<i][i];
									lcur[(j|1<<i)|k][1] += lpre[k][1] * dp[j|1<<i][i];
								}
							}
							for(int k = pr;k >= 0;k--){ k &= pr;
								lcur[k][1] += lpre[k][0];
							}
							long[][] dum = lpre; lpre = lcur;lcur = dum;
						}
					}
					
					inner2:
					for(int i = maycon;i >= 1;i--){ i &= maycon;
						if(nglca[root][i])continue;
						long iksum = 0;
						for(int k = 0;k < n;k++){
							if(i<<~k<0){
								iksum += dp[i][k];
								int al = 1<<root|i;
								if((h[k]&al) != h[k])continue inner2;
							}
						}
						// j -> j|i
						for(int j = pr&~i;j >= 0;j--){ j &= pr&~i;
							lpre[j|i][0] += lpre[j][0] * iksum;
							lpre[j|i][1] += lpre[j][1] * iksum;
						} // include i=0
					}
					
					if(root == 0){
						dp[ptn][root] = lpre[pr][0];
					}else{
						dp[ptn][root] = lpre[pr][0] + lpre[pr][1];
					}
//					tr(ptn, root, pr, mustcon, maycon, dp[ptn][root] ,lpre);
				}
			}
		}
		out.println(dp[(1<<n)-1][0]);
	}
	
	static int[][][] packX(int n, int[][] es, int ind) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for (int[] f : es)
			p[f[ind]]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]][];
		for(int i = 0;i < es.length;i++){
			g[es[i][ind]][--p[es[i][ind]]] = es[i];
		}
		return g;
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
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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