//package educational.round21;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "5 8\r\n" + 
			"5 5 1\r\n" + 
			"1 5 4\r\n" + 
			"4 6 3\r\n" + 
			"1 12 4\r\n" + 
			"3 12 1";
	
	void solve()
	{
		int n = ni(), K = ni();
		int[][] ds = new int[n][];
		for(int i = 0;i < n;i++){
			ds[i] = new int[]{ni(), ni(), ni()};
		}
		Arrays.sort(ds, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[2] - b[2];
			}
		});
		long[] isp = isp(200005);
		
		List<Edge> es = new ArrayList<>();
		int src = n, sink = n+1;
		for(int i = 0;i < n;i++){
			if(ds[i][1] % 2 == 0){
				es.add(new Edge(src, i, 0));
			}else{
				es.add(new Edge(i, sink, 0));
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(ds[i][1] % 2 == 0 && ds[j][1] % 2 == 1){
					int v = ds[i][1] + ds[j][1];
					if(isp[v>>>6]<<~v<0){
						es.add(new Edge(i, j, 99999999));
					}
				}
			}
		}
		
		Edge[][] g = compileWD(sink+1, es);
		int one = -1;
		long all = 0;
		for(int i = 0;i < n;i++){
			all += ds[i][0];
			for(Edge e : g[src]){
				if(e.to == i){
					e.capacity = ds[i][0];
					e.complement.capacity = ds[i][0];
				}
			}
			for(Edge e : g[sink]){
				if(e.to == i){
					e.capacity = ds[i][0];
					e.complement.capacity = ds[i][0];
				}
			}
			if(ds[i][1] == 1){
				if(one != -1){
					for(Edge e : g[sink]){
						if(e.to == one){
							e.capacity = 0;
							e.complement.capacity = 0;
						}
					}
					all -= ds[one][0];
				}
				one = i;
			}
			reset(g);
			long F = maximumFlowDinicNoRec(g, src, sink);
			if(all - F >= K){
				out.println(ds[i][2]);
				return;
			}
		}
		out.println(-1);
	}
	
	public static class Edge
	{
		public int from, to;
		public int capacity;
		public int flow;
		public Edge complement;
		public boolean cloned;
		
		public Edge(int from, int to, int capacity) {
			this.from = from;
			this.to = to;
			this.capacity = capacity;
		}
	}
	
	public static void reset(Edge[][] g)
	{
		for(Edge[] row : g){
			for(Edge e : row){
				e.flow = e.cloned ? e.capacity : 0;
			}
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
			clone.cloned = true;
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
			clone.cloned = true;
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
	
	public static long maximumFlowDinic(Edge[][] g, int source, int sink)
	{
		int n = g.length;
		int[] d = new int[n];
		int[] q = new int[n];
		long ret = 0;
		while(true){
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
			int[] sp = new int[n];
			for(int i = 0;i < n;i++)sp[i] = g[i].length - 1;
			ret += dfsDinic(d, g, sp, source, sink, Long.MAX_VALUE);
		}
		
		return ret;
	}
	
	private static long dfsDinic(int[] d, Edge[][] g, int[] sp, int cur, int sink, long min)
	{
		if(cur == sink)return min;
		long left = min;
		for(int i = sp[cur];i >= 0;i--){
			Edge ne = g[cur][i];
			if(d[ne.to] == d[cur]+1 && ne.capacity - ne.flow > 0){
				long fl = dfsDinic(d, g, sp, ne.to, sink, Math.min(left, ne.capacity - ne.flow));
				if(fl > 0){
					left -= fl;
					ne.flow += fl;
					ne.complement.flow -= fl;
					if(left == 0){
						sp[cur] = i;
						return min;
					}
				}
			}
		}
		sp[cur] = -1;
		return min-left;
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
			for(int i = 0;i < n;i++)probe[i] = g[i].length-1;
			int sp = 0;
			stack[sp] = source;
			lefts[sp] = Long.MAX_VALUE / 10;
			parflow[sp] = 0;
			sp++;
			long delta = 0;
			boolean down = true;
			while(sp > 0){
				int cur = stack[sp-1];
				long left = lefts[sp-1];
				if(cur == sink){
					delta += left;
					parflow[sp-1] = left;
					sp--;
					down = false;
					continue;
				}
				if(!down){
					if(parflow[sp] > 0){
						lefts[sp-1] -= parflow[sp];
						left = lefts[sp-1];
						Edge ne = g[cur][probe[cur]];
						ne.flow += parflow[sp];
						ne.complement.flow -= parflow[sp];
						parflow[sp-1] += parflow[sp];
					}
					if(left > 0)probe[cur]--;
				}
				if(left > 0 && probe[cur] >= 0){
					down = true;
					Edge ne = g[cur][probe[cur]];
					if(d[ne.to] == d[cur]+1 && ne.capacity - ne.flow > 0){
						lefts[sp] = Math.min(left, ne.capacity - ne.flow);
						stack[sp] = ne.to;
						parflow[sp] = 0;
						sp++;
					}else{
						probe[cur]--;
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
	
	/**
	 * source
	 * sourcetrue, sinkfalse
	 * 
	 * @param g
	 * @param source
	 * @param sink
	 * @return
	 */
	public static boolean[] restoreCutPessimistically(Edge[][] g, int src)
	{
		int n = g.length;
		boolean[] ved = new boolean[n];
		ved[src] = true;
		int[] q = new int[n];
		int p = 0;
		q[p++] = src;
		for(int r = 0;r < p;r++){
			int cur = q[r];
			for(Edge e : g[cur]){
				assert e.from == cur;
				if(e.flow < e.capacity && !ved[e.to]){
					ved[e.to] = true;
					q[p++] = e.to;
				}
			}
		}
		return ved;
	}
	
	/**
	 * sink
	 * sourcetrue, sinkfalse
	 * @param g
	 * @param sink
	 * @return
	 */
	public static boolean[] restoreCutOptimisitically(Edge[][] g, int sink)
	{
		int n = g.length;
		boolean[] ved = new boolean[n];
		Arrays.fill(ved, true);
		ved[sink] = false;
		int[] q = new int[n];
		int p = 0;
		q[p++] = sink;
		for(int r = 0;r < p;r++){
			int cur = q[r];
			for(Edge e : g[cur]){
				assert e.from == cur;
				if(e.flow > 0 && ved[e.to]){
					ved[e.to] = false;
					q[p++] = e.to;
				}
			}
		}
		return ved;
	}

	
	public static long[] isp(int n)
	{
		int[] tprimes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
		if(n <= 64){
			long ptn = 0;
			for(int p : tprimes)if(p <= n)ptn |= 1L<<p;
			return new long[]{ptn};
		}
		
		long[] isnp = new long[(n+1)/64+1];
		int sup = (n+1)/64+1;
		
		isnp[0] |= 1<<1;
		for(int tp : tprimes){
			long[] ptn = new long[tp];
			for(int i = 0;i < tp<<6;i+=tp)ptn[i>>>6] |= 1L<<i;
			for(int j = 0;j < sup;j += tp){
				for(int i = 0;i < tp && i+j < sup;i++){
					isnp[j+i] |= ptn[i];
				}
			}
		}
		
		final int[] magic = {0, 1, 2, 53, 3, 7, 54, 27, 4, 38, 41, 8, 34, 55, 48, 28, 62, 5, 39, 46, 44, 42, 22, 9, 24, 35, 59, 56, 49, 18, 29, 11, 63, 52, 6, 26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10, 51, 25, 36, 32,
	              60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12};
		out:
		for(int i = 0;i < sup;i++){
			for(long j = ~isnp[i];j != 0;j &= j-1){
				int p = i<<6|magic[(int)((j&-j)*0x022fdd63cc95386dL>>>58)];
				if((long)p*p > n)break out;
				for(int q = p*p;q <= n;q += p)isnp[q>>6] |= 1L<<q;
			}
		}
		
		for(int i = 0;i < isnp.length;i++)isnp[i] = ~isnp[i];
		for(int tp : tprimes)isnp[0] |= 1L<<tp;
		isnp[isnp.length-1] &= (1L<<n+1)-1;
		
		return isnp;
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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