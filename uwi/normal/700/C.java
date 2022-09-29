//package round364;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Queue;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int s = ni()-1, t = ni()-1;
		int[] from = new int[m];
		int[] to = new int[m];
		int[] w = new int[m];
		DJSet ds = new DJSet(n);
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			w[i] = ni();
			ds.union(from[i], to[i]);
		}
		if(!ds.equiv(s, t)){
			out.println(0);
			out.println(0);
			return;
		}
		
		int[][][] wg = packWU(n, from, to, w);
		int[][] g = packU(n, from, to);
		int[] clus = decomposeToBECC(g);
		int[][][] cg = condense(wg, clus);
		int u = cg.length;
		int cs = clus[s], ct = clus[t];
		int[] h = new int[u];
		int[][] which = new int[u][];
		Arrays.fill(h, Integer.MAX_VALUE);
		Queue<Integer> q = new ArrayDeque<>();
		q.add(cs);
		while(!q.isEmpty()){
			int cur = q.poll();
			for(int[] e : cg[cur]){
				if(e[0] != cs && h[e[0]] == Integer.MAX_VALUE){
					if(e[1] < h[cur]){
						which[e[0]] = new int[]{cur, e[0]};
					}else{
						which[e[0]] = which[cur];
					}
					h[e[0]] = Math.min(e[1], h[cur]);
					q.add(e[0]);
				}
			}
		}
		long ONE = h[ct];
		
		List<Edge> xes = new ArrayList<>();
		for(int i = 0;i < m;i++){
			if(clus[from[i]] != clus[to[i]]){
				xes.add(new Edge(from[i], to[i], w[i]+10000000000L));
			}else{
				xes.add(new Edge(from[i], to[i], w[i]+3000000000L));
			}
		}
		Edge[][] xg = compileWU(n, xes);
		long XF = maximumFlowDinicNoRec(xg, s, t);
		long TWO = Long.MAX_VALUE;
		if(XF <= (3000000000L+1000000000L)*2){
			TWO = XF-3000000000L*2;
		}
		
		if(ONE >= Integer.MAX_VALUE && TWO == Long.MAX_VALUE){
			out.println(-1);
			return;
		}
		if(ONE < TWO){
			assert which[ct] != null;
			out.println(ONE);
			out.println(1);
			for(int i = 0;i < m;i++){
				if(clus[from[i]] == which[ct][0] && clus[to[i]] == which[ct][1]){
					out.println(i+1);
					break;
				}
				if(clus[to[i]] == which[ct][0] && clus[from[i]] == which[ct][1]){
					out.println(i+1);
					break;
				}
			}
		}else{
			Queue<Integer> xq = new ArrayDeque<>();
			xq.add(s);
			boolean[] ved = new boolean[n];
			ved[s] = true;
			while(!xq.isEmpty()){
				int cur = xq.poll();
				for(Edge e : xg[cur]){
					if(e.flow < e.capacity && !ved[e.to]){
						ved[e.to] = true;
						xq.add(e.to);
					}
				}
			}
			out.println(XF-3000000000L*2);
			out.println(2);
			int lct = 0;
			for(int i = 0;i < m;i++){
				if(ved[from[i]] != ved[to[i]]){
					lct++;
					out.print(i+1 + " ");
				}
			}
			assert lct == 2;
		}
	}
	
	public static class DJSet {
		public int[] upper;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean union(int x, int y) {
			x = root(x);
			y = root(y);
			if (x != y) {
				if (upper[y] < upper[x]) {
					int d = x;
					x = y;
					y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for (int u : upper)
				if (u < 0)
					ct++;
			return ct;
		}
	}

	
	public static int[][][] condense(int[][][] g, int[] clus)
	{
		int n = g.length;
		int m = 0;
		for(int i = 0;i < n;i++)m = Math.max(m, clus[i]);
		m++;
		
		int[] cp = new int[m];
		for(int i = 0;i < n;i++){
			cp[clus[i]] += g[i].length;
		}
		int[][][] c = new int[m][][];
		for(int i = 0;i < m;i++){
			c[i] = new int[cp[i]][];
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < g[i].length;j++){
				c[clus[i]][--cp[clus[i]]] = new int[]{clus[g[i][j][0]], g[i][j][1]};
			}
		}
		
		for(int i = 0;i < m;i++){
			Arrays.sort(c[i], new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					if(a[0] != b[0])return a[0] - b[0];
					return a[1] - b[1];
				}
			});
			int jp = 0;
			for(int j = 0;j < c[i].length;j++){
				if((j == 0 || c[i][j][0] != c[i][j-1][0]) && c[i][j][0] != i){
					c[i][jp++] = c[i][j];
				}
			}
			c[i] = Arrays.copyOf(c[i], jp);
		}
		return c;
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
	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]][2];
		for (int i = 0; i < from.length; i++) {
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			g[to[i]][p[to[i]]][1] = w[i];
		}
		return g;
	}

	
	public static int[] decomposeToBECC(int[][] g)
	{
		int n = g.length;
		boolean[] visited = new boolean[n];
		int[] ord = new int[n];
		int[] low = new int[n];
		
		int[] ids = new int[n];
		int[] inds = new int[n];
		int[] parct = new int[n];
		int pos = 0;
		for(int i = 0;i < n;i++){
			if(!visited[i]){
				ids[0] = i;
				inds[0] = 0;
				int sp = 1;
				while(sp > 0){
					int cur = ids[sp-1];
					if(inds[sp-1] == 0){
						visited[cur] = true;
						ord[cur] = low[cur] = pos++;
						parct[sp-1] = 0;
					}
					if(inds[sp-1] == g[cur].length){
						if(sp-2 >= 0)low[ids[sp-2]] = Math.min(low[ids[sp-2]], low[cur]);
						sp--;
						continue;
					}
					int next = g[cur][inds[sp-1]];
					if(!visited[next]){
						ids[sp] = next;
						inds[sp] = 0;
						inds[sp-1]++;
						sp++;
						continue;
					}else if(sp-2 >= 0 && (next != ids[sp-2] || ++parct[sp-1] >= 2)){
						low[cur] = Math.min(low[cur], ord[next]);
					}
					inds[sp-1]++;
				}
			}
		}
		
		int[] clus = new int[n];
		Arrays.fill(clus, -1);
		int[] q = new int[n];
		int cnum = 0;
		for(int i = 0;i < n;i++){
			if(clus[i] == -1){
				int p = 0;
				q[p++] = i;
				clus[i] = cnum++;
				for(int r = 0;r < p;r++){
					int cur = q[r];
					for(int next : g[cur]){
						if(clus[next] == -1){
							clus[next] = ord[cur] < low[next] ? cnum++ : clus[cur];
							q[p++] = next;
						}
					}
				}
			}
		}
		return clus;
	}

	
	public static class Edge
	{
		public int from, to;
		public long capacity;
		public long flow;
		public Edge complement;
		// public int iniflow;
		
		public Edge(int from, int to, long capacity) {
			this.from = from;
			this.to = to;
			this.capacity = capacity;
		}
	}
	
	public static Edge[][] compileWD(int n, List<Edge> edges)
	{
		Edge[][] g = new Edge[n][];
		// cloning
		for(int i = edges.size()-1;i >= 0;i--){
			Edge origin = edges.get(i);
			Edge clone = new Edge(origin.to, origin.from, origin.capacity);
			clone.flow = origin.capacity;
			clone.complement = origin;
			origin.complement = clone;
			edges.add(clone);
		}
		
		int[] p = new int[n];
		for(Edge e : edges)p[e.from]++;
		for(int i = 0;i < n;i++)g[i] = new Edge[p[i]];
		for(Edge e : edges)g[e.from][--p[e.from]] = e;
		return g;
	}
	
	public static Edge[][] compileWU(int n, List<Edge> edges)
	{
		Edge[][] g = new Edge[n][];
		// cloning
		for(int i = edges.size()-1;i >= 0;i--){
			Edge origin = edges.get(i);
			Edge clone = new Edge(origin.to, origin.from, origin.capacity*2);
			origin.flow = origin.capacity;
			clone.flow = origin.capacity;
			clone.complement = origin;
			origin.complement = clone;
			origin.capacity *= 2;
			edges.add(clone);
		}
		
		int[] p = new int[n];
		for(Edge e : edges)p[e.from]++;
		for(int i = 0;i < n;i++)g[i] = new Edge[p[i]];
		for(Edge e : edges)g[e.from][--p[e.from]] = e;
		return g;
	}	
	
	public static long maximumFlowDinicNoRec(Edge[][] g, int source, int sink)
	{
		int n = g.length;
		int[] d = new int[n]; // distance
		int[] q = new int[n]; // queue for BFS
		long ret = 0;
		int[] stack = new int[n];
		long[] lefts = new long[n]; // left to flow
		long[] parflow = new long[n];
		int[] probe = new int[n]; // search pointer
		while(true){
			// BFS
			Arrays.fill(d, -1);
			q[0] = source;
			int r = 1;
			d[source] = 0;
			for(int v = 0;v < r;v++){
				int cur = q[v];
				for(Edge ne : g[cur]){
					if(d[ne.to] == -1 && ne.capacity - ne.flow > 0) {
						q[r++] = ne.to;
						d[ne.to] = d[cur] + 1;
					}
				}
			}
			if(d[sink] == -1)break;
			
			// DFS
			for(int i = 0;i < n;i++)probe[i] = g[i].length;
			int sp = 0;
			stack[sp] = source;
			lefts[sp] = Long.MAX_VALUE;
			parflow[sp] = 0;
			sp++;
			long delta = 0;
			boolean down = true;
			while(sp > 0){
				int cur = stack[sp-1];
				long fl = lefts[sp-1];
				if(cur == sink){
					delta += fl;
					parflow[sp-1] = fl;
					sp--;
					down = false;
					continue;
				}
				if(!down && parflow[sp] > 0){
					lefts[sp-1] -= parflow[sp];
					fl = lefts[sp-1];
					Edge ne = g[cur][probe[cur]];
					ne.flow += parflow[sp];
					ne.complement.flow -= parflow[sp];
					parflow[sp-1] += parflow[sp];
				}
				if(fl > 0 && probe[cur] > 0){
					down = true;
					Edge ne = g[cur][--probe[cur]];
					if(d[ne.to] == d[cur]+1 && ne.capacity - ne.flow > 0){
						lefts[sp] = Math.min(lefts[sp-1], ne.capacity - ne.flow);
						stack[sp] = ne.to;
						parflow[sp] = 0;
						sp++;
					}
				}else{
					down = false;
					sp--;
				}
			}
			ret += delta;
		}
		return ret;
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