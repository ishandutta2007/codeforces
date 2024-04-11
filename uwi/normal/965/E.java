//package round476;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		TrieByList trie = new TrieByList();
		for(int i = 0;i < n;i++){
			trie.add(ns().toCharArray());
		}
		TrieByList.Node[] nodes = trie.toArray();
		
		int m = nodes.length;
		int[][] ch = new int[m][];
		int[] nl = new int[m];
		for(int i = 0;i < m;i++){
			ch[i] = new int[nodes[i].p];
			nl[i] = nodes[i].hit;
			for(int j = 0;j < ch[i].length;j++){
				ch[i][j] = nodes[i].child[j].id;
			}
		}
		
		long ans = 0;
		for(int e : ch[0]){
			Node res = dfs(e, ch, nl, 1);
			ans -= sum(res);
		}
		out.println(ans);
	}
	
	long sum(Node a)
	{
		if(a == null)return 0;
		return a.key + sum(a.left) + sum(a.right);
	}
	
	Node dfs(int cur, int[][] ch, int[] nl, int dep)
	{
		Node my = nl[cur] == 1 ? new Node(-dep) : null;
		for(int e : ch[cur]){
			Node res = dfs(e, ch, nl, dep+1);
			my = merge(my, res);
		}
		
		if(nl[cur] == 0){
			Node nmy = deleteRoot(my);
			my.key = -dep;
			my = merge(my, nmy);
		}
		return my;
	}
	
	public static class Node
	{
		public int key;
		public Node left, right;
		public int dist;
		
		public Node(int x)
		{
			key = x;
			left = right = null;
			dist = 0;
		}
		
		public Node(Node n)
		{
			key = n.key;
			left = n.left;
			right = n.right;
			dist = n.dist;
		}
		
		public void disconnect()
		{
			left = right = null;
			dist = 0;
		}
		
		public String toString(String indent)
		{
			StringBuilder sb = new StringBuilder();
			if(left != null)sb.append(left.toString(indent + "  "));
			sb.append(indent).append(key).append('\n');
			if(right != null)sb.append(right.toString(indent + "  "));
			return sb.toString();
		}
	}
	
	public static Node merge(Node m, Node n)
	{
		if(m == null)return n;
		if(n == null)return m;
		if(m.key > n.key){ // compare
			Node d = m; m = n; n = d;
		}
		// m = new Node(m); // if uncommented, heap becomes persistent.
		m.right = merge(m.right, n);
		if(m.left == null || m.right.dist > m.left.dist){
			Node d = m.left; m.left = m.right; m.right = d;
		}
		m.dist = m.right == null ? 0 : m.right.dist + 1;
		return m;
	}
	
	public static Node insert(int x, Node n)
	{
		return merge(n, new Node(x));
	}
	
	public static int min(Node n)
	{
		return n != null ? n.key : Integer.MAX_VALUE;
	}
	
	public static int min2(Node n)
	{
		if(n == null)return Integer.MAX_VALUE;
		return Math.min(min(n.left), min(n.right));
	}
	
	public static Node deleteRoot(Node n){
		if(n == null)return null;
		Node ret = merge(n.left, n.right);
		n.disconnect();
		return ret;
	}
	
	public static Node build(int[] a)
	{
		if(a.length == 0)return null;
		Queue<Node> q = new ArrayDeque<Node>();
		for(int x : a)q.add(new Node(x));
		while(q.size() > 1){
			q.add(merge(q.poll(), q.poll()));
		}
		return q.poll();
	}
	
	public static class TrieByList {
		public Node root = new Node((char)0, 0);
		public int gen = 1;
		
		public static class Node
		{
			public int id;
			public char c;
			
			public long ptn = 0;
			public int p = 0;
			public Node[] child = null;
			public int hit = 0;
			
			public Node fail;
			
			public Node(char c, int id)
			{
				this.id = id;
				this.c = c;
			}
			
			public int enc(char c)
			{
//				return c <= 'Z' ? c-'A' : c-'a'+32;
				return c-'a';
			}
			
			public void appendChild(Node n)
			{
				if(p == 0){
					child = new Node[1];
				}else if(p+1 >= child.length){
					child = Arrays.copyOf(child, child.length*2);
				}
				int z = enc(n.c);
				int nind = Long.bitCount(ptn<<~z);
				ptn |= 1L<<z;
				System.arraycopy(child, nind, child, nind+1, p-nind);
				child[nind] = n;
				p++;
			}
			
			public Node search(char c)
			{
				if(ptn<<~enc(c)<0){
					return child[Long.bitCount(ptn<<~enc(c))-1];
				}else{
					return null;
				}
			}
			
			public String toString(String indent)
			{
				StringBuilder sb = new StringBuilder();
				sb.append(indent + id + ":" + c);
				if(hit != 0)sb.append(" H:" + hit);
				if(fail != null)sb.append(" F:" + fail.id);
				sb.append("\n");
				for(int i = 0;i < p;i++){
					sb.append(child[i].toString(indent + "  "));
				}
				return sb.toString();
			}
		}
		
		public void add(char[] s)
		{
			Node cur = root;
			Node pre = null;
			for(char c : s){
				pre = cur;
				cur = pre.search(c);
				if(cur == null){
					cur = new Node(c, gen++);
					pre.appendChild(cur);
				}
			}
			cur.hit++;
		}
		
		public void buildFailure()
		{
			root.fail = null;
			Queue<Node> q = new ArrayDeque<Node>();
			q.add(root);
			while(!q.isEmpty()){
				Node cur = q.poll();
				inner:
				for(int i = 0;i < cur.p;i++){
					Node ch = cur.child[i];
					q.add(ch);
					for(Node to = cur.fail; to != null; to = to.fail){
						Node lch = to.search(ch.c);
						if(lch != null){
							ch.fail = lch;
							ch.hit += lch.hit; // propagation of hit
							continue inner;
						}
					}
					ch.fail = root;
				}
			}
		}
		
		public Node next(Node cur, char c)
		{
			for(;cur != null;cur = cur.fail){
				Node next = cur.search(c);
				if(next != null){
					return next;
				}
				// dead
			}
			return root;
		}
		
		public int countHit(char[] q)
		{
			Node cur = root;
			int hit = 0;
			outer:
			for(char c : q){
				for(;cur != null;cur = cur.fail){
					Node next = cur.search(c);
					if(next != null){
						hit += next.hit;
						cur = next;
						continue outer;
					}
				}
				cur = root;
			}
			return hit;
		}
		
		public Node[] toArray()
		{
			Node[] ret = new Node[gen];
			ret[0] = root;
			for(int i = 0;i < gen;i++){
				Node cur = ret[i];
				for(int j = 0;j < cur.p;j++){
					ret[cur.child[j].id] = cur.child[j];
				}
			}
			return ret;
		}
		
		public String toString()
		{
			return root.toString("");
		}
	}

	
	void run() throws Exception
	{
//		int n = 1000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			for(int j = 0;j < m/n;j++){
//				sb.append((char)('a'+gen.nextInt(26)));
//			}
//			sb.append("\n");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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