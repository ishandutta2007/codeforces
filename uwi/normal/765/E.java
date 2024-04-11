//package round397;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		
		int[] dp = new int[n];
		int[] deadtype = new int[n];
		// -1 : perfect death (kind >= 3 or #-1 >= 2)
		// 1 : disappeared
		// 2 : NG*1 + 1 color**
		// 3 : 2 colors.
		// 4 : 3 colors.
		int[][][] deadarg = new int[n][][];
		int[][] colors = new int[n][];
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			int ldeath = 0;
			int[][] lens = new int[g[cur].length][];
			int lastld = -1;
			int p = 0;
			int nc = 0;
			for(int e : g[cur]){
				if(e == par[cur])continue;
				nc++;
				if(dp[e] == -1){
					lastld = e;
					ldeath++;
				}else{
					lens[p++] = new int[]{dp[e] + 1, e};
				}
			}
			
			if(nc == 0){
				dp[cur] = 0;
				continue;
			}
			
			Arrays.sort(lens, 0, p, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[0] - b[0];
				}
			});
			if(ldeath == 0 && lens[0][0] == lens[p-1][0]){
				dp[cur] = lens[0][0];
			}else if(nc == 1){
				dp[cur] = -1;
				deadtype[cur] = 1;
			}else{
				dp[cur] = -1;
				int nt = 1;
				for(int j = 0;j < p-1;j++){
					if(lens[j][0] < lens[j+1][0])nt++;
				}
				if(ldeath >= 2 || nt >= 3 || ldeath >= 1 && nt >= 2){
					deadtype[cur] = -1;
				}else if(ldeath == 1){
					assert nt == 1;
					deadtype[cur] = 2;
					deadarg[cur] = new int[][]{
						{lastld, lens[0][0]}
					};
				}else{
					assert nt == 2;
					int one = 0;
					for(int j = 0;j < p;j++){
						if(lens[0][0] == lens[j][0]){
							one++;
						}
					}
					colors[cur] = new int[]{lens[0][0], lens[p-1][0]};
					int[][] temp = new int[2][];
					int lcp = 0;
					if(one == 1){
						temp[lcp++] = new int[]{lens[0][1], lens[p-1][0], lens[0][0]};
					}
					if(p-one == 1){
						temp[lcp++] = new int[]{lens[p-1][1], lens[0][0], lens[p-1][0]};
					}
					deadtype[cur] = 3;
					deadarg[cur] = Arrays.copyOf(temp, lcp);
				}
			}
		}
//		tr(dp);
//		tr(deadtype);
//		tr(deadarg);
//		tr(colors);
		
		int ret = Integer.MAX_VALUE;
		
		{
			if(dp[0] >= 0){
				int glen = dp[0];
				while(glen % 2 == 0)glen /= 2;
				ret = Math.min(ret, glen);
			}else if(deadtype[0] == 3){
				int glen = colors[0][0]+colors[0][1];
				while(glen % 2 == 0)glen /= 2;
				ret = Math.min(ret, glen);
			}
		}
		
		for(int i = 1;i < n;i++){
			int cur = ord[i];
			int pa = par[cur];
			int vpa = -1;
			if(dp[pa] != -1){
				vpa = dp[pa] + 1;
			}else if(deadtype[pa] == -1){
			}else if(deadtype[pa] == 1){
				if(pa == 0)vpa = 1;
				assert dp[cur] == -1;
			}else if(deadtype[pa] == 2){
				if(deadarg[pa][0][0] == cur){
					vpa = deadarg[pa][0][1] + 1;
				}
			}else if(deadtype[pa] == 3){
				for(int j = 0;j < deadarg[pa].length;j++){
					if(deadarg[pa][j][0] == cur){
						vpa = deadarg[pa][j][1] + 1;
					}
				}
			}
//			tr(cur, vpa);
			
			if(dp[cur] != -1 && vpa != -1){
				int can = vpa;
				int glen = dp[cur] + can;
				while(glen % 2 == 0)glen /= 2;
				ret = Math.min(ret, glen);
			}
			if(dp[cur] == -1 && deadtype[cur] == 3){
				for(int j = 0;j < colors[cur].length;j++){
					if(colors[cur][j] == vpa){
						int glen = colors[cur][0] + colors[cur][1];
						while(glen % 2 == 0)glen /= 2;
						ret = Math.min(ret, glen);
					}
				}
			}
			
			if(vpa >= 0){
				if(g[cur].length == 2){
					dp[cur] = vpa;
				}else if(dp[cur] != -1){
					if(dp[cur] == vpa){
					}else{
						dp[cur] = -1;
						deadtype[cur] = 0;
					}
				}else if(deadtype[cur] == 2){
					if(deadarg[cur][0][1] == vpa){
					}else{
						dp[cur] = -1;
						deadtype[cur] = 0;
					}
				}else if(deadtype[cur] == 3){
					int[][] nd = new int[1][];
					int np = 0;
					for(int j = 0;j < deadarg[cur].length;j++){
						if(deadarg[cur][j][1] == vpa){
							nd[np++] = deadarg[cur][j];
						}
					}
					if(np == 0){
						dp[cur] = -1;
						deadtype[cur] = 0;
					}else{
						deadarg[cur] = nd;
					}
				}
			}else{
				dp[cur] = -1;
				deadtype[cur] = 0;
			}
		}
		out.println(ret == Integer.MAX_VALUE ? -1 : ret);
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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