//package round668;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--)go();
	}

	void go()
	{
		int n = ni(), a = ni()-1, b = ni()-1, da = ni(), db = ni();
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);

		if(db <= 2 * da) {
			out.println("Alice");
		}else{
			LCAFast2 lf = LCAFast2.build(g, 0);
			if(lf.d(a, b) <= da){
				// one shot
				out.println("Alice");
			}else{
				int[][] pars = parents(g, b);
				int[] dep = pars[2], par = pars[0];
				for(int i = 0;i < n;i++){
					if(dep[i] >= 2*da + 1){
						out.println("Bob");
						return;
					}
				}

				int lim = a;
				for(int k = 0;k < da;k++){
					lim = par[lim];
				}

				int[] ord = pars[1];

				int[] far = enumFarthest(g, par, ord);

				for(int i = 0;i < n;i++){
					if(lf.d(lim, i) > da){
						if(far[i] >= 2*da+1){
							out.println("Bob");
							return;
						}
					}
				}

				out.println("Alice");
			}
		}
	}

	public static int[] enumFarthest(int[][] g, int[] par, int[] ord)
	{
		int n = g.length;
		int[] dp = new int[n];
		int[] dp2 = new int[n];
		Arrays.fill(dp2, -99999999);
		for(int i = n-1;i >= 1;i--){
			int cur = ord[i];
			int v = dp[cur] + 1;
			if(v > dp[par[cur]]){
				dp2[par[cur]] = dp[par[cur]];
				dp[par[cur]] = v;
			}else if(v > dp2[par[cur]]){
				dp2[par[cur]] = v;
			}
		}
		for(int i = 1;i < n;i++){
			int cur = ord[i];
			int v = dp[par[cur]] == dp[cur] + 1 ? dp2[par[cur]] + 1 : dp[par[cur]] + 1;
			if(v > dp[cur]){
				dp2[cur] = dp[cur];
				dp[cur] = v;
			}else if(v > dp2[cur]){
				dp2[cur] = v;
			}
		}
		return dp;
	}

	public static int[][] parents(int[][] g, int root)
	{
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);

		int[] depth = new int[n];
		depth[0] = 0;

		int[] q = new int[n];
		q[0] = root;
		for(int p = 0, r = 1;p < r;p++) {
			int cur = q[p];
			for(int nex : g[cur]){
				if(par[cur] != nex){
					q[r++] = nex;
					par[nex] = cur;
					depth[nex] = depth[cur] + 1;
				}
			}
		}
		return new int[][] {par, q, depth};
	}


	public static int[] diameter(int[][] g)
	{
		int n = g.length;
		int f0 = -1, f1 = -1, d01 = -1;
		int[] q = new int[n];
		boolean[] ved = new boolean[n];
		{
			int qp = 0;
			q[qp++] = 0; ved[0] = true;
			for(int i = 0;i < qp;i++){
				int cur = q[i];
				for(int e : g[cur]){
					if(!ved[e]){
						ved[e] = true;
						q[qp++] = e;
						continue;
					}
				}
			}
			f0 = q[n-1];
		}
		{
			int[] d = new int[n];
			int qp = 0;
			Arrays.fill(ved, false);
			q[qp++] = f0; ved[f0] = true;
			for(int i = 0;i < qp;i++){
				int cur = q[i];
				for(int e : g[cur]){
					if(!ved[e]){
						ved[e] = true;
						q[qp++] = e;
						d[e] = d[cur] + 1;
						continue;
					}
				}
			}
			f1 = q[n-1];
			d01 = d[f1];
		}
		return new int[]{d01, f0, f1};
	}

	public static class LCAFast2 {
		public int n, h;
		public int[][] bigst;
		public int[][] bigind;
		public long[][] smallb;
		public int[] vs, first, deps;

		public int lca(int a, int b)
		{
			return vs[rmqpos(Math.min(first[a], first[b]), Math.max(first[a], first[b]))];
		}

		public int d(int a, int b)
		{
			return dep(a) + dep(b) - 2 * rmqval(Math.min(first[a], first[b]), Math.max(first[a], first[b]));
		}

		public int dep(int x)
		{
			return deps[first[x]];
		}

		public int rmqpos(int l, int r)
		{
			if(l > r)return -1;
			int cl = l>>>6;
			int cr = r>>>6;
			if(cl == cr){
				return argmax(smallb[l&63][cl], r-l+1) + l;
			}else{
				int min = deps[l] - max(smallb[l&63][cl], 63-(l&63)+1);
				int pos = argmax(smallb[l&63][cl], 63-(l&63)+1) + l;

				{
					int can = deps[r>>>6<<6] - max(smallb[0][cr], (r&63)-0+1);
					if(can < min){
						min = can;
						pos = argmax(smallb[0][cr], (r&63)-0+1) + (r>>>6<<6);
					}
				}

				if(cl+1 <= cr-1){
					int len = (cr-1)-(cl+1)+1;
					int h = 31-Integer.numberOfLeadingZeros(len);
					{
						int can = bigst[h][cl+1];
						if(can < min){
							min = can;
							pos = bigind[h][cl+1];
						}
					}
					{
						int can = bigst[h][cr-1-(1<<h)+1];
						if(can < min){
							min = can;
							pos = bigind[h][cr-1-(1<<h)+1];
						}
					}
				}
				return pos;
			}
		}

		public int rmqval(int l, int r)
		{
			if(l > r)return -1;
			int cl = l>>>6;
			int cr = r>>>6;
			if(cl == cr){
				return deps[l] - max(smallb[l&63][cl], r-l+1);
			}else{
				int min = deps[l] - max(smallb[l&63][cl], 63-(l&63)+1);
				min = Math.min(min, deps[r>>>6<<6] - max(smallb[0][cr], (r&63)-0+1));

				if(cl+1 <= cr-1){
					int len = (cr-1)-(cl+1)+1;
					int h = 31-Integer.numberOfLeadingZeros(len);
					min = Math.min(min, bigst[h][cl+1]);
					min = Math.min(min, bigst[h][cr-1-(1<<h)+1]);
				}
				return min;
			}
		}

		public static LCAFast2 build(int[][] g, int root)
		{
			LCAFast2 ret = new LCAFast2();
			int[][] et = eulerTour(g, root);
			int[] vs = et[0], deps = et[1], first = et[2];
			ret.vs = vs;
			ret.first = first;
			ret.deps = deps;

			int n = deps.length;
			int u = n+63>>>6;
			int h = 31-Integer.numberOfLeadingZeros(u) + 1;
			int[][] bigst = new int[h][];
			int[][] bigind = new int[h][];
			int[] cup = new int[u];
			int[] cupind = new int[u];
			Arrays.fill(cup, Integer.MAX_VALUE);
			for(int i = 0;i < n;i++){
				if(deps[i] < cup[i>>>6]){
					cup[i>>>6] = deps[i];
					cupind[i>>>6] = i;
				}
			}
			bigst[0] = cup;
			bigind[0] = cupind;
			for(int i = 1;i < h;i++){
				bigst[i] = new int[u-(1<<i)+1];
				bigind[i] = new int[u-(1<<i)+1];
				for(int j = 0;j + (1<<i) <= u;j++){
					if(bigst[i-1][j] < bigst[i-1][j+(1<<i-1)]){
						bigst[i][j] = bigst[i-1][j];
						bigind[i][j] = bigind[i-1][j];
					}else{
						bigst[i][j] = bigst[i-1][j+(1<<i-1)];
						bigind[i][j] = bigind[i-1][j+(1<<i-1)];
					}
				}
			}

			long[][] smallb = new long[64][u];
			for(int i = 0;i < u;i++){
				long x = 0;
				for(int j = 0;j < 63 && (i<<6|j+1) < n;j++){
					if(deps[i<<6|j] > deps[i<<6|j+1]){
						x |= 1L<<j;
					}
				}
				long val = 0;
				for(int j = 63;j >= 0;j--){
					val <<= 1;
					if(x<<~j<0){
						val |= 1L;
					}else{
						val &= val - 1;
					}
					smallb[j][i] = val;
				}
//
//			for(int j = 0;j < 64;j++){
//				smallb[j][i] = make(x>>>j);
//			}
			}

			ret.n = n; ret.h = h;
			ret.bigst = bigst;
			ret.bigind = bigind;
			ret.smallb = smallb;
			return ret;
		}

		public static int[][] eulerTour(int[][] g, int root)
		{
			int n = g.length;
			int[] vs = new int[2*n-1];
			int[] deps = new int[2*n-1];
			int[] first = new int[n];
			Arrays.fill(first, -1);
			int p = 0;

			int[] stack = new int[n];
			int[] inds = new int[n];
			int sp = 0;
			stack[sp++] = root;
			outer:
			while(sp > 0){
				int cur = stack[sp-1], ind = inds[sp-1];
				vs[p] = cur;
				deps[p] = sp-1;
				if(first[cur] == -1)first[cur] = p;
				p++;
				while(ind < g[cur].length){
					int nex = g[cur][ind++];
					if(first[nex] == -1){
						inds[sp-1] = ind;
						stack[sp] = nex;
						inds[sp] = 0;
						sp++;
						continue outer;
					}
				}
				inds[sp-1] = ind;
				if(ind == g[cur].length)sp--;
			}

			return new int[][]{vs, deps, first};
		}

		// TinyRMQ
		public static long make(long x)
		{
			int h = 0;
			int max = 0;
			long ret = 0;
			for(int i = 0;i < 64;i++){
				if(x<<~i<0){
					h++;
				}else{
					h--;
				}
				if(h > max){
					max = h;
					ret |= 1L<<i;
				}
			}
			return ret;
		}

		public static int max(long x, int r)
		{
			assert r > 0;
			return Long.bitCount(x&(1L<<r-1)-1);
		}

		public static int argmax(long x, int r)
		{
			assert r > 0;
			return 64-Long.numberOfLeadingZeros(x&(1L<<r-1)-1);
		}

	}


	public static int[][] packU(int n, int[] from, int[] to){ return packU(n, from, to, from.length); }
	public static int[][] packU(int n, int[] from, int[] to, int sup)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < sup;i++)p[to[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < sup;i++){
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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