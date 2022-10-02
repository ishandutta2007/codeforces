//package round244;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String s1 = ns(), s2 = ns();
		
		int n = s1.length(), m = s2.length();
		SuffixAutomatonOfBit sa = SuffixAutomatonOfBit.build((s1+'{'+s2).toCharArray());
		sa.sortTopologically();
		
		int z = sa.gen;
		int[] f1 = new int[z];
		int[] f2 = new int[z];
		for(int i = z-1;i >= 1;i--){
			SuffixAutomatonOfBit.Node cur = sa.nodes[i];
			if(cur.original == null){
				if(cur.len >= n+2){
					f2[i]++;
				}else if(cur.len <= n){
					f1[i]++;
				}
			}
			f1[cur.link.id] += f1[i];
			f2[cur.link.id] += f2[i];
		}
		
		int min = 9999999;
		for(int i = 1;i < z;i++){
			if(f1[i] == 1 && f2[i] == 1){
				min = Math.min(sa.nodes[i].link.len + 1, min);
			}
		}
		out.println(min == 9999999 ? -1 : min);
	}
	
	public static class SuffixAutomatonOfBit {
		public Node t0;
		public int len;
		public Node[] nodes;
		public int gen;
		
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
			public int hit = 0;
			
			public void putNext(char c, Node to)
			{
				to.key = c;
				if(hit<<31-(c-'a')<0){
					for(int i = 0;i < np;i++){
						if(next[i].key == c){
							next[i] = to;
							return;
						}
					}
				}
				hit |= 1<<c-'a';
				if(np == next.length){
					next = Arrays.copyOf(next, np*2);
				}
				next[np++] = to;
			}
			
			public boolean containsKeyNext(char c)
			{
				return hit<<31-(c-'a')<0;
//				for(int i = 0;i < np;i++){
//					if(next[i].key == c)return true;
//				}
//				return false;
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

		public static SuffixAutomatonOfBit build(char[] str)
		{
			int n = str.length;
			SuffixAutomatonOfBit sa = new SuffixAutomatonOfBit(n);
			sa.len = str.length;
			
			Node last = sa.t0;
			for(char c : str){
				last = sa.extend(last, c);
//				System.out.println(sa.toDot(true, false));
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
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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