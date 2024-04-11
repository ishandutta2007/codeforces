//package tech2016.elim1;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int[] a = na(6);
		String[] SZ = {
				"S","M", "L", "XL", "XXL", "XXXL"
		};
		int n = ni();
		int[] ts = new int[n];
		Arrays.fill(ts, -1);
		int[] type = new int[n];
		for(int i = 0;i < n;i++){
			String x = ns();
			if(x.indexOf(",") >= 0){
				type[i] = 1;
				x = x.substring(0, x.indexOf(","));
			}
			for(int j = 0;j < SZ.length;j++){
				if(SZ[j].equals(x)){
					ts[i] = j;
					break;
				}
			}
		}
		int[] b = Arrays.copyOf(a, 6);
		for(int i = 0;i < n;i++){
			if(type[i] == 0){
				b[ts[i]]--;
			}
		}
		if(Arrays.stream(b).anyMatch(x -> x < 0)){
			out.println("NO");
			return;
		}
		List<Edge> es = new ArrayList<>();
		int[] fs = new int[5];
		for(int i = 0;i < n;i++){
			if(type[i] == 1){
				fs[ts[i]]++;
			}
		}
		int all = Arrays.stream(fs).sum();
		for(int i = 0;i < 5;i++){
			es.add(new Edge(11, i, fs[i]));
			es.add(new Edge(i, 5+i, fs[i]));
			es.add(new Edge(i, 6+i, fs[i]));
		}
		for(int i = 0;i < 6;i++){
			es.add(new Edge(5+i, 12, b[i]));
		}
		long F = maximumFlowDinicNoRec(compileWD(13, es), 11, 12);
		if(F != all){
			out.println("NO");
			return;
		}
		out.println("YES");
		for(int i = 0;i < n;i++){
			if(type[i] == 0){
				out.println(SZ[ts[i]]);
			}else{
				for(Edge e : es){
					if(e.from == ts[i] && e.to == 5+ts[i] && e.flow > 0){
						e.flow--;
						out.println(SZ[ts[i]]);
						break;
					}
					if(e.from == ts[i] && e.to == 6+ts[i] && e.flow > 0){
						e.flow--;
						out.println(SZ[ts[i]+1]);
						break;
					}
				}
			}
		}
	}
	
	public static class Edge
	{
		public int from, to;
		public int capacity;
		public int flow;
		public Edge complement;
		// public int iniflow;
		
		public Edge(int from, int to, int capacity) {
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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