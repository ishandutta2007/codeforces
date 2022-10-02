//package adv;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class CF146C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] s = ns().toCharArray();
		SuffixAutomaton sa = SuffixAutomaton.build(s);
		sa.sortTopologically();
		int[] noo = sa.enumNumberOfOccurrences();
//		tr(sa.toDot(true, true));
		int n = ni();
		for(int i = 0;i < n;i++){
			char[] q = ns().toCharArray();
			int m = q.length;
			q = Arrays.copyOf(q, m*2-1);
			for(int j = 0;j < m-1;j++)q[j+m] = q[j];
			
			SuffixAutomaton.Node cur = sa.t0;
			int[] hits = new int[m];
			int p = 0;
			int step = 0;
			for(int j = 0;j < q.length;j++){
				while(cur != sa.t0 && (!cur.containsKeyNext(q[j]) || cur.link != null && cur.link.len+1 >= m)){
					cur = cur.link;
					step = cur.len;
				}
				SuffixAutomaton.Node next = cur.getNext(q[j]);
				step++;
				if(next == null){
					next = sa.t0;
					step = 0;
				}
				if(step >= m){
					hits[p++] = next.id;
				}
				cur = next;
			}
			Arrays.sort(hits, 0, p);

//			tr(Arrays.copyOf(hits, p));
//			tr(noo);
			long ret = 0;
			for(int j = 0;j < p;j++){
				if(j == 0 || hits[j-1] != hits[j]){
					ret += noo[hits[j]];
				}
			}
			out.println(ret);
		}
	}
	
	public static class SuffixAutomaton {
		public Node t0;
		public int len;
		public Node[] nodes;
		public int gen;
		
		private SuffixAutomaton(int n)
		{
			gen = 0;
			nodes = new Node[2*n];
			this.t0 = makeNode(0, false);
		}
		
		private Node makeNode(int len, boolean isCloned)
		{
			Node node = new Node();
			node.id = gen;
			node.isCloned = isCloned;
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
			public boolean isCloned;
			public int np = 0;
			public int hit = 0;
			
			public void putNext(char c, Node to)
			{
				to.key = c;
				hit |= 1<<c-'a';
				for(int i = 0;i < np;i++){
					if(next[i].key == c){
						next[i] = to;
						return;
					}
				}
				if(np == next.length){
					next = Arrays.copyOf(next, np*2);
				}
				next[np++] = to;
			}
			
			public boolean containsKeyNext(char c)
			{
				return hit<<31-(c-'a')<0;
			}
			
			public Node getNext(char c)
			{
				if(hit<<31-(c-'a')<0){
					for(int i = 0;i < np;i++){
						if(next[i].key == c)return next[i];
					}
				}
				return null;
			}
		}

		public static SuffixAutomaton build(char[] str)
		{
			int n = str.length;
			SuffixAutomaton sa = new SuffixAutomaton(n);
			sa.len = str.length;
			
			Node last = sa.t0;
			for(char c : str){
				last = sa.extend(last, c);
			}
			
			return sa;
		}
		
		public Node extend(Node last, char c)
		{
			Node cur = makeNode(last.len+1, false);
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
					Node clone = makeNode(p.len+1, true);
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
		
		public void lexSort()
		{
			for(int i = 0;i < gen;i++){
				Node node = nodes[i];
				Arrays.sort(node.next, 0, node.np, new Comparator<Node>() {
					public int compare(Node a, Node b) {
						return a.key - b.key;
					}
				});
			}
		}
		
		public void sortTopologically()
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
		}
		
		public String toString()
		{
			StringBuilder sb = new StringBuilder();
			for(Node n : nodes){
				if(n != null){
					sb.append(String.format("{id:%d, len:%d, link:%d, cloned:%b, ",
							n.id,
							n.len,
							n.link != null ? n.link.id : null,
							n.isCloned));
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
		
		public String toDot(boolean next, boolean suffixLink)
		{
			StringBuilder sb = new StringBuilder("digraph{\n");
			sb.append("graph[rankdir=LR];\n");
			sb.append("node[shape=circle];\n");
			for(Node n : nodes){
				if(n != null){
					if(suffixLink && n.link != null){
						sb.append(n.id)
						.append("->")
						.append(n.link.id)
						.append("[style=dashed];\n");
					}
					
					if(next && n.next != null){
						for(int i = 0;i < n.np;i++){
							sb.append(n.id)
							.append("->")
							.append(n.next[i].id)
							.append("[label=")
							.append(n.next[i].key)
							.append("];\n");
						}
					}
				}
			}
			sb.append("}\n");
			return sb.toString();
		}
		
		public int lcslen(char[] t)
		{
			if(t.length == 0)return 0;
			Node v = t0;
			int l = 0, best = 0;
			for(int i = 0;i < t.length;i++){
				while(v != t0 && !v.containsKeyNext(t[i])){
					v = v.link;
					l = v.len;
				}
				if(v.containsKeyNext(t[i])){
					v = v.getNext(t[i]);
					l++;
				}
				if(l > best){
					best = l;
				}
			}
			return best;
		}
		
		public String kthDistinctSubstring(long K)
		{
			if(K <= 0)return null;
			int n = gen;
			// preprocess
			long[] dp = new long[n];
			for(int i = n-1;i >= 0;i--){
				dp[i] = 1;
				Node node = nodes[i];
				for(int j = 0;j < node.np;j++){
					int toid = node.next[j].id;
					dp[i] += dp[toid];
				}
			}
//			U.tr(dp);
			if(K >= dp[0])return null;
			
			// greedy
			Node cur = t0;
			StringBuilder sb = new StringBuilder();
			while(K > 0){
				K--;
				for(int j = 0;j < cur.np;j++){
					Node next = cur.next[j];
					int toid = next.id;
					if(K-dp[toid] < 0){
						sb.append(next.key);
						cur = next;
						break;
					}else{
						K -= dp[toid];
					}
				}
			}
			return sb.toString();
		}
		
		public int[] enumNumberOfOccurrences()
		{
			int n = nodes.length;
			int[] dp = new int[n];
			for(int i = n-1;i >= 1;i--){
//				tr(i, nodes[i].id, nodes[i].isCloned, dp[i]);
				if(!nodes[i].isCloned)dp[i]++;
				dp[nodes[i].link.id] += dp[i];
			}
			return dp;
		}
		private void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
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
	
	public static void main(String[] args) throws Exception { new CF146C().run(); }
	
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