//package round475;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	
	int[][][] qb;
	LST lst;
	SuffixAutomatonOfBit sa;
	int[] anss;
	
	void solve()
	{
		char[] s = ns().toCharArray();
		
		sa = SuffixAutomatonOfBit.build(s);
		sa.sortTopologically();
		
		int Q = ni();
		int[][] qs = new int[Q][];
		anss = new int[Q];
		Arrays.fill(anss, -1);
		int p = 0;
		int[] no = sa.enumNumberOfOccurrences();
		for(int z = 0;z < Q;z++){
			int t = ni();
			char[] u = ns().toCharArray();
			SuffixAutomatonOfBit.Node node = sa.track(u);
			if(node == null)continue;
			if(t > no[node.id])continue;
			if(t == 1){
				anss[z] = u.length;
				continue;
			}
			qs[p++] = new int[]{t, node.id, u.length, z};
		}
		
//		tr(sa.toDot(true, true));
//		for(int i = 0;i < sa.gen;i++){
//			tr(i, sa.nodes[i].len);
//		}
		
		qs = Arrays.copyOf(qs, p);
		
		int[] from = new int[sa.gen-1];
		int[] to = new int[sa.gen-1];
		int q = 0;
		for(SuffixAutomatonOfBit.Node u : sa.nodes){
			if(u.link == null)continue;
			from[q] = u.id;
			to[q] = u.link.id;
			q++;
		}
		int[][] g = packU(sa.gen, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		
		int[] des = new int[sa.gen];
		Arrays.fill(des, 1);
		for(int i = sa.gen-1;i >= 1;i--){
			des[par[ord[i]]] += des[ord[i]];
		}
		
		qb = makeBuckets(qs, 1, sa.gen);
		lst = new LST(s.length+1);
		dfs(0, -1, g, false, des);
		
		for(int v : anss){
			out.println(v);
		}
	}
	
	public static int[][][] makeBuckets(int[][] a, int ind, int sup)
	{
		int n = a.length;
		int[][][] bucket = new int[sup+1][][];
		int[] bp = new int[sup+1];
		for(int i = 0;i < n;i++)bp[a[i][ind]]++;
		for(int i = 0;i <= sup;i++)bucket[i] = new int[bp[i]][];
		for(int i = n-1;i >= 0;i--)bucket[a[i][ind]][--bp[a[i][ind]]] = a[i];
		return bucket;
	}
	
	
	private  void answer(int cur)
	{
		for(int[] row : qb[cur]){
			int f = row[0];
			int head = -1;
			for(int i = 0;i < f;i++){
				head = lst.next(head+1);
			}
			int tail = lst.next(0);
			int min = 999999999;
			for(;head != -1;head = lst.next(head+1), tail = lst.next(tail+1)){
				min = Math.min(min, head - tail + row[2]);
			}
			anss[row[3]] = min;
		}
	}
	
	private  void paint(int cur)
	{
		if(sa.nodes[cur].original == null)lst.set(sa.nodes[cur].len);
	}
	
	private  void clear(int cur)
	{
		if(sa.nodes[cur].original == null)lst.unset(sa.nodes[cur].len);
	}
	
	public  void dfs(int cur, int pre, int[][] g, boolean preserve, int[] des)
	{
		int big = -1;
		for(int e : g[cur]){
			if(e == pre)continue;
			if(big == -1 || des[e] > des[big]){
				big = e;
			}
		}
		for(int e : g[cur]){
			if(e != pre && e != big)dfs(e, cur, g, false, des);
		}
		if(big != -1)dfs(big, cur, g, true, des);
		
		// only biggest subtree is painted
		
		// paint subtrees
		// if processing node pairs, put answer(cur);
		paint(cur);
		for(int e : g[cur]){
			if(e != pre && e != big){
				// if processing node pairs, put answerdfs(e, cur, g);
				paintdfs(e, cur, g);
			}
		}
		
		// all node is painted
		answer(cur);
		
		// clear subtrees
		if(!preserve)cleardfs(cur, pre, g);
	}
	
	private  void paintdfs(int cur, int pre, int[][] g)
	{
		paint(cur);
		for(int e : g[cur])if(e != pre)paintdfs(e, cur, g);
	}
	
	private  void cleardfs(int cur, int pre, int[][] g)
	{
		clear(cur);
		for(int e : g[cur])if(e != pre)cleardfs(e, cur, g);
	}
	
	private  void answerdfs(int cur, int pre, int[][] g)
	{
		answer(cur);
		for(int e : g[cur])if(e != pre)answerdfs(e, cur, g);
	}

	
	public static class LST {
		public long[][] set;
		public int n;
//		public int size;
		
		public LST(int n) {
			this.n = n;
			int d = 1;
			for(int m = n;m > 1;m>>>=6, d++);
			
			set = new long[d][];
			for(int i = 0, m = n>>>6;i < d;i++, m>>>=6){
				set[i] = new long[m+1];
			}
//			size = 0;
		}
		
		// [0,r)
		public LST setRange(int r)
		{
			for(int i = 0;i < set.length;i++, r=r+63>>>6){
				for(int j = 0;j < r>>>6;j++){
					set[i][j] = -1L;
				}
				if((r&63) != 0)set[i][r>>>6] |= (1L<<r)-1;
			}
			return this;
		}
		
		// [0,r)
		public LST unsetRange(int r)
		{
			if(r >= 0){
				for(int i = 0;i < set.length;i++, r=r+63>>>6){
					for(int j = 0;j < r+63>>>6;j++){
						set[i][j] = 0;
					}
					if((r&63) != 0)set[i][r>>>6] &= ~((1L<<r)-1);
				}
			}
			return this;
		}
		
		public LST set(int pos)
		{
			if(pos >= 0 && pos < n){
//				if(!get(pos))size++;
				for(int i = 0;i < set.length;i++, pos>>>=6){
					set[i][pos>>>6] |= 1L<<pos;
				}
			}
			return this;
		}
		
		public LST unset(int pos)
		{
			if(pos >= 0 && pos < n){
//				if(get(pos))size--;
				for(int i = 0;i < set.length && (i == 0 || set[i-1][pos] == 0L);i++, pos>>>=6){
					set[i][pos>>>6] &= ~(1L<<pos);
				}
			}
			return this;
		}
		
		public boolean get(int pos)
		{
			return pos >= 0 && pos < n && set[0][pos>>>6]<<~pos<0;
		}
		
		public LST toggle(int pos)
		{
			return get(pos) ? unset(pos) : set(pos);
		}
		
		public int prev(int pos)
		{
			for(int i = 0;i < set.length && pos >= 0;i++, pos>>>=6, pos--){
				int pre = prev(set[i][pos>>>6], pos&63);
				if(pre != -1){
					pos = pos>>>6<<6|pre;
					while(i > 0)pos = pos<<6|63-Long.numberOfLeadingZeros(set[--i][pos]);
					return pos;
				}
			}
			return -1;
		}
		
		public int next(int pos)
		{
			for(int i = 0;i < set.length && pos>>>6 < set[i].length;i++, pos>>>=6, pos++){
				int nex = next(set[i][pos>>>6], pos&63);
				if(nex != -1){
					pos = pos>>>6<<6|nex;
					while(i > 0)pos = pos<<6|Long.numberOfTrailingZeros(set[--i][pos]);
					return pos;
				}
			}
			return -1;
		}
		
		private static int prev(long set, int n)
		{
			long h = set<<~n;
			if(h == 0L)return -1;
			return -Long.numberOfLeadingZeros(h)+n;
		}
		
		private static int next(long set, int n)
		{
			long h = set>>>n;
			if(h == 0L)return -1;
			return Long.numberOfTrailingZeros(h)+n;
		}
		
		@Override
		public String toString()
		{
			List<Integer> list = new ArrayList<Integer>();
			for(int pos = next(0);pos != -1;pos = next(pos+1)){
				list.add(pos);
			}
			return list.toString();
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
	

	
	public static class SuffixAutomatonOfBit {
		
		public Node track(char[] q)
		{
			Node cur = t0;
			for(char c : q){
				cur = cur.getNext(c);
				if(cur == null)return null;
			}
			return cur;
		}
		
		public int[] enumNumberOfOccurrences()
		{
			assert sortedTopologically;
			int n = gen;
			int[] dp = new int[n];
			for(int i = n-1;i >= 1;i--){
				if(nodes[i].original == null)dp[i]++;
				dp[nodes[i].link.id] += dp[i];
			}
			return dp;
		}
		
		public int[] enumFirstOccurrences()
		{
			assert sortedTopologically;
			int[] fo = new int[gen];
			for(int i = gen-1;i >= 0;i--){
				fo[i] = nodes[i].original == null ? nodes[i].len : fo[nodes[i].original.id];
			}
			return fo;
		}
		
		public int[] enumLastOccurrences()
		{
			assert sortedTopologically;
			int[] lo = new int[gen];
			for(int i = gen-1;i >= 0;i--){
				lo[i] = Math.max(lo[i], nodes[i].len);
				if(i > 0)lo[nodes[i].link.id] = Math.max(lo[nodes[i].link.id], lo[i]);
			}
			return lo;
		}

		
		public Node t0;
		public int len;
		public Node[] nodes;
		public int gen;
		private boolean sortedTopologically = false;
		private boolean lexsorted = false;
		
		private SuffixAutomatonOfBit(int n)
		{
			gen = 0;
			nodes = new Node[2*n];
			this.t0 = makeNode(0, null);
		}
		
		private Node makeNode(int len, Node original)
		{
			Node node = new Node();
			node.id = gen;
			node.original = original;
			node.len = len;
			nodes[gen++] = node;
			return node;
		}
		
		public static class Node
		{
			public int id;
			public int len;
			public char key;
			public Node link;
			private Node[] next = new Node[3];
			public Node original;
			public int np = 0;
			public long hit = 0;
			
			public int id(char c)
			{
//				return c >= 'a' ? c-'a' : c-'A'+26;
				return c-'a';
			}
			
			public void putNext(char c, Node to)
			{
				to.key = c;
				if(hit<<~id(c)<0){
					for(int i = 0;i < np;i++){
						if(next[i].key == c){
							next[i] = to;
							return;
						}
					}
				}
				hit |= 1L<<id(c);
				if(np == next.length){
					next = Arrays.copyOf(next, np*2);
				}
				next[np++] = to;
			}
			
			public boolean containsKeyNext(char c)
			{
				return hit<<~id(c)<0;
//				for(int i = 0;i < np;i++){
//					if(next[i].key == c)return true;
//				}
//				return false;
			}
			
			public Node getNext(char c)
			{
				if(hit<<~id(c)<0){
					for(int i = 0;i < np;i++){
						if(next[i].key == c)return next[i];
					}
				}
				return null;
			}
			
			public List<String> suffixes(char[] s)
			{
				List<String> list = new ArrayList<String>();
				if(id == 0)return list;
				int first = original != null ? original.len : len;
				for(int i = link.len + 1;i <= len;i++){
					list.add(new String(s, first - i, i));
				}
				return list;
			}
		}

		public static SuffixAutomatonOfBit build(char[] str)
		{
			int n = str.length;
			SuffixAutomatonOfBit sa = new SuffixAutomatonOfBit(n);
			sa.len = str.length;
			
			Node last = sa.t0;
			for(char c : str){
				last = sa.extend(last, c);
			}
			
			return sa;
		}
		
		public Node extend(Node last, char c)
		{
			Node cur = makeNode(last.len+1, null);
			Node p;
			for(p = last; p != null && !p.containsKeyNext(c);p = p.link){
				p.putNext(c, cur);
			}
			if(p == null){
				cur.link = t0;
			}else{
				Node q = p.getNext(c); // not null
				if(p.len + 1 == q.len){
					cur.link = q;
				}else{
					Node clone = makeNode(p.len+1, q);
					clone.next = Arrays.copyOf(q.next, q.next.length);
					clone.hit = q.hit;
					clone.np = q.np;
					clone.link = q.link;
					for(;p != null && q.equals(p.getNext(c)); p = p.link){
						p.putNext(c, clone);
					}
					q.link = cur.link = clone;
				}
			}
			return cur;
		}
		
		public SuffixAutomatonOfBit lexSort()
		{
			for(int i = 0;i < gen;i++){
				Node node = nodes[i];
				Arrays.sort(node.next, 0, node.np, new Comparator<Node>() {
					public int compare(Node a, Node b) {
						return a.key - b.key;
					}
				});
			}
			lexsorted = true;
			return this;
		}
		
		public SuffixAutomatonOfBit sortTopologically()
		{
			int[] indeg = new int[gen];
			for(int i = 0;i < gen;i++){
				for(int j = 0;j < nodes[i].np;j++){
					indeg[nodes[i].next[j].id]++;
				}
			}
			Node[] sorted = new Node[gen];
			sorted[0] = t0;
			int p = 1;
			for(int i = 0;i < gen;i++){
				Node cur = sorted[i];
				for(int j = 0;j < cur.np;j++){
					if(--indeg[cur.next[j].id] == 0){
						sorted[p++] = cur.next[j];
					}
				}
			}
			
			for(int i = 0;i < gen;i++)sorted[i].id = i;
			nodes = sorted;
			sortedTopologically = true;
			return this;
		}
		
		// visualizer
		
		public String toString()
		{
			StringBuilder sb = new StringBuilder();
			for(Node n : nodes){
				if(n != null){
					sb.append(String.format("{id:%d, len:%d, link:%d, cloned:%b, ",
							n.id,
							n.len,
							n.link != null ? n.link.id : null,
							n.original.id));
					sb.append("next:{");
					for(int i = 0;i < n.np;i++){
						sb.append(n.next[i].key + ":" + n.next[i].id + ",");
					}
					sb.append("}");
					sb.append("}");
					sb.append("\n");
				}
			}
			return sb.toString();
		}
		
		public String toGraphviz(boolean next, boolean suffixLink)
		{
			StringBuilder sb = new StringBuilder("http://chart.apis.google.com/chart?cht=gv:dot&chl=");
			sb.append("digraph{");
			for(Node n : nodes){
				if(n != null){
					if(suffixLink && n.link != null){
						sb.append(n.id)
						.append("->")
						.append(n.link.id)
						.append("[style=dashed],");
					}
					
					if(next && n.next != null){
						for(int i = 0;i < n.np;i++){
							sb.append(n.id)
							.append("->")
							.append(n.next[i].id)
							.append("[label=")
							.append(n.next[i].key)
							.append("],");
						}
					}
				}
			}
			sb.append("}");
			return sb.toString();
		}
		
		public String label(Node n)
		{
			if(n.original != null){
				return n.id + "C";
			}else{
				return n.id + "";
			}
		}
		
		public String toDot(boolean next, boolean suffixLink)
		{
			StringBuilder sb = new StringBuilder("digraph{\n");
			sb.append("graph[rankdir=LR];\n");
			sb.append("node[shape=circle];\n");
			for(Node n : nodes){
				if(n != null){
					if(suffixLink && n.link != null){
						sb.append("\"" + label(n) + "\"")
						.append("->")
						.append("\"" + label(n.link) + "\"")
						.append("[style=dashed];\n");
					}
					
					if(next && n.next != null){
						for(int i = 0;i < n.np;i++){
							sb.append("\"" + label(n) + "\"")
							.append("->")
							.append("\"" + label(n.next[i]) + "\"")
							.append("[label=\"")
							.append(n.next[i].key)
							.append("\"];\n");
						}
					}
				}
			}
			sb.append("}\n");
			return sb.toString();
		}
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