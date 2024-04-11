//package educational.round30;
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
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		char[] s = ns(n);
		char[] fb = ns(n);
		
		SuffixAutomatonOfBit sa = SuffixAutomatonOfBit.build(s);
		sa.sortTopologically();
		long[] dp = new long[sa.gen];
		for(int i = sa.gen-1;i >= 1;i--){
			if(sa.nodes[i].original == null && fb[sa.nodes[i].len-1] == '0')dp[i]++;
			dp[sa.nodes[i].link.id] += dp[i];
		}
		long ans = 0;
		for(int i = 1;i < sa.gen;i++){
			ans = Math.max(ans, (long)dp[i] * (sa.nodes[i].len));
		}
		out.println(ans);
	}
	
	public static class SuffixAutomatonOfBit {
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
		
	}

	
	public static char[] rev(char[] a)
	{
		char[] b = new char[a.length];
		for(int i = 0;i < a.length;i++)b[a.length-1-i] = a[i];
		return b;
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