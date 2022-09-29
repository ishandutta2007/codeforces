//package round558;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.PriorityQueue;
import java.util.Queue;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), Q = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		int[] ws = new int[m];
		int[] inds = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			ws[i] = ni();
			inds[i] = i;
		}
		int[][][] g = packWU(n, from, to, ws, inds);
		Datum pre = dijkl(g, 0);
		Datum suf = dijkl(g, n-1);
		
		int[] reachpre = new int[n];
		Arrays.fill(reachpre, -1);
		
		int[][] ptree = parentToG(pre.par);
		int[][] pars = parents3(ptree, 0);
		int[] par = pars[0], dep = pars[2];
		
		boolean[] onpath = new boolean[n];
		boolean[] inpath = new boolean[m];
		for(int i = n-1;i != -1;i = pre.par[i]){
			onpath[i] = true;
			if(i > 0)inpath[pre.pare[i]] = true;
		}
		
		int[] dws = new int[n+1];
		for(int i = 0;i < n;i++){
			if(onpath[i]){
				for(int[] e : g[i]){
					if(par[i] == e[0] && inpath[e[2]]){
						dws[dep[i]] = e[1];
					}
				}
				
				Queue<Integer> q = new ArrayDeque<>();
				q.add(i);
				reachpre[i] = dep[i];
				while(!q.isEmpty()){
					int cur = q.poll();
					for(int[] e : g[cur]){
						if(!onpath[e[0]] && reachpre[e[0]] == -1 && par[e[0]] == cur){
							reachpre[e[0]] = dep[i];
							q.add(e[0]);
						}
					}
				}
			}
		}
		
		long[] anss = new long[Q];
		
		int[][] qs = new int[Q][];
		int p = 0;
		
		for(int i = 0;i < Q;i++){
			int x = ni()-1, v = ni();
			int f = from[x], t = to[x];
			if(inpath[x]){
				if(v <= ws[x]){
					anss[i] = pre.d[n-1] + v - ws[x];
				}else{
					qs[p++] = new int[]{Math.max(dep[f], dep[t]), i, v};
				}
			}else{
				long la = pre.d[n-1];
				la = Math.min(la, pre.d[f] + suf.d[t] + v);
				la = Math.min(la, pre.d[t] + suf.d[f] + v);
				anss[i] = la;
			}
		}
		qs = Arrays.copyOf(qs, p);
		Arrays.sort(qs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		
		PriorityQueue<long[]> pq = new PriorityQueue<>(
				(x, y) -> Long.compare(x[1], y[1])
//				Long.compare(
//						Math.min(pre.d[from[x]] + suf.d[to[x]] + ws[x], pre.d[to[x]] + suf.d[from[x]] + ws[x]),
//						Math.min(pre.d[from[y]] + suf.d[to[y]] + ws[y], pre.d[to[y]] + suf.d[from[y]] + ws[y])
//						)
				);
		int[][] tos = new int[m][];
		int pp = 0;
		for(int i = 0;i < m;i++){
			if(!inpath[i]){
				tos[pp++] = new int[]{i, Math.min(reachpre[from[i]], reachpre[to[i]])};
			}
		}
		tos = Arrays.copyOf(tos, pp);
		Arrays.sort(tos, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1] - b[1];
			}
		});
		
		int qq = 0;
		int lq = 0;
		for(int i = 0;i <= n;i++){
			while(qq < pp && tos[qq][1] < i){
				int x = tos[qq][0];
				pq.add(new long[]{
						x, 
						Math.min(pre.d[from[x]] + suf.d[to[x]] + ws[x], pre.d[to[x]] + suf.d[from[x]] + ws[x]),
				});
				qq++;
			}
			while(!pq.isEmpty()){
				long[] cu = pq.poll();
				int cur = (int)cu[0];
				if(Math.max(reachpre[from[cur]], reachpre[to[cur]]) >= i){
					pq.add(cu);
					break;
				}
			}
			// dep, ind, v
			while(lq < p && qs[lq][0] <= i){
				if(!pq.isEmpty()){
					int top = (int)(pq.peek()[0]);
					long ans = pre.d[n-1] + qs[lq][2] - dws[qs[lq][0]];
					ans = Math.min(ans, 
							Math.min(pre.d[from[top]] + suf.d[to[top]] + ws[top], pre.d[to[top]] + suf.d[from[top]] + ws[top])
							);
					anss[qs[lq][1]] = ans;
				}else{
					anss[qs[lq][1]] = pre.d[n-1] + qs[lq][2] - dws[qs[lq][0]];
				}
				lq++;
			}
		}
		for(long v : anss){
			out.println(v);
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

	
	public static int[][] parentToG(int[] par)
	{
		int n = par.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				ct[i]++;
				ct[par[i]]++;
			}
		}
		int[][] g = new int[n][];
		for(int i = 0;i < n;i++){
			g[i] = new int[ct[i]];
		}
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				g[par[i]][--ct[par[i]]] = i;
				g[i][--ct[i]] = par[i];
			}
		}
		return g;
	}

	
	public static class Datum
	{
		long[] d;
		int[] par;
		int[] pare;
		public Datum(long[] d, int[] par, int[] pare) {
			this.d = d;
			this.par = par;
			this.pare = pare;
		}
	}
	
	public static Datum dijkl(int[][][] g, int from)
	{
		int n = g.length;
		long[] td = new long[n];
		int[] par = new int[n];
		Arrays.fill(par, -1);
		int[] pare = new int[n];
		Arrays.fill(pare, -1);
		
		Arrays.fill(td, Long.MAX_VALUE / 3);
		MinHeapL q = new MinHeapL(n);
		q.add(from, 0);
		td[from] = 0;
		
		while(q.size() > 0){
			int cur = q.argmin();
			q.remove(cur);
			
			for(int[] e : g[cur]){
				int next = e[0];
				long nd = td[cur] + e[1];
				if(nd < td[next]){
					td[next] = nd;
					par[next] = cur;
					pare[next] = e[2];
					q.update(next, nd);
				}
			}
		}
		
		return new Datum(td, par, pare);
	}
	
	public static class MinHeapL {
		public long[] a;
		public int[] map;
		public int[] imap;
		public int n;
		public int pos;
		public static long INF = Long.MAX_VALUE;
		
		public MinHeapL(int m)
		{
			n = Integer.highestOneBit((m+1)<<1);
			a = new long[n];
			map = new int[n];
			imap = new int[n];
			Arrays.fill(a, INF);
			Arrays.fill(map, -1);
			Arrays.fill(imap, -1);
			pos = 1;
		}
		
		public long add(int ind, long x)
		{
			int ret = imap[ind];
			if(imap[ind] < 0){
				a[pos] = x; map[pos] = ind; imap[ind] = pos;
				pos++;
				up(pos-1);
			}
			return ret != -1 ? a[ret] : x;
		}
		
		public long update(int ind, long x)
		{
			int ret = imap[ind];
			if(imap[ind] < 0){
				a[pos] = x; map[pos] = ind; imap[ind] = pos;
				pos++;
				up(pos-1);
			}else{
				a[ret] = x;
				up(ret);
				down(ret);
			}
			return x;
		}
		
		public long remove(int ind)
		{
			if(pos == 1)return INF;
			if(imap[ind] == -1)return INF;
			
			pos--;
			int rem = imap[ind];
			long ret = a[rem];
			map[rem] = map[pos];
			imap[map[pos]] = rem;
			imap[ind] = -1;
			a[rem] = a[pos];
			a[pos] = INF;
			map[pos] = -1;
			
			up(rem);
			down(rem);
			return ret;
		}
		
		public long min() { return a[1]; }
		public int argmin() { return map[1]; }
		public int size() {	return pos-1; }
		
		private void up(int cur)
		{
			for(int c = cur, p = c>>>1;p >= 1 && a[p] > a[c];c>>>=1, p>>>=1){
				long d = a[p]; a[p] = a[c]; a[c] = d;
				int e = imap[map[p]]; imap[map[p]] = imap[map[c]]; imap[map[c]] = e;
				e = map[p]; map[p] = map[c]; map[c] = e;
			}
		}
		
		private void down(int cur)
		{
			for(int c = cur;2*c < pos;){
				int b = a[2*c] < a[2*c+1] ? 2*c : 2*c+1;
				if(a[b] < a[c]){
					long d = a[c]; a[c] = a[b]; a[b] = d;
					int e = imap[map[c]]; imap[map[c]] = imap[map[b]]; imap[map[b]] = e;
					e = map[c]; map[c] = map[b]; map[b] = e;
					c = b;
				}else{
					break;
				}
			}
		}
	}

	
	public static int[][][] packWU(int n, int[] from, int[] to, int[]... ws){ return packWU(n, from, to, from.length, ws); }
	public static int[][][] packWU(int n, int[] from, int[] to, int sup, int[]... ws)
	{
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < sup;i++)p[to[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]][ws.length+1];
		for(int i = 0;i < sup;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			for(int j = 0;j < ws.length;j++)g[from[i]][p[from[i]]][j+1] = ws[j][i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			for(int j = 0;j < ws.length;j++)g[to[i]][p[to[i]]][j+1] = ws[j][i];
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