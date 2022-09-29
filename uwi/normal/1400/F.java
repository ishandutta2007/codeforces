//package ecr94;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] s = ns().toCharArray();
		int X = ni();
		
		char[] a = new char[X+1];
		trie = new TrieByList();
		dfs(X, 0, a, X);
		
		int n = s.length;
		int[] dp = new int[trie.gen];
		Arrays.fill(dp, -99999999);
		dp[0] = 0;
		trie.buildFailure();
		TrieByList.Node[] nodes = trie.toArray();
		for(char c : s){
			int[] ndp = Arrays.copyOf(dp, trie.gen);
			for(int i = 0;i < trie.gen;i++){
				TrieByList.Node node = trie.next(nodes[i], c);
				if(node.hit == 0)ndp[node.id] = Math.max(ndp[node.id], dp[i] + 1);
			}
			dp = ndp;
		}
		
		int ans = n;
		for(int v : dp){
			ans = Math.min(ans, n-v);
		}
		out.println(ans);
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
				return c-'0';
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

	TrieByList trie;
	
	void dfs(int n, int pos, char[] a, int X)
	{
		if(n == 0){
			for(int i = 0;i < pos;i++){
				int t = 0;
				for(int j = i;j < pos;j++){
					t += a[j]-'0';
					if(t != X && X % t == 0)return;
				}
			}
			
//			tr(Arrays.copyOf(a, pos));
//			all.add(Arrays.copyOf(a, pos));
			trie.add(Arrays.copyOf(a, pos));
			return;
		}
		
		for(int i = 1;i <= 9 && i <= n;i++){
			a[pos] = (char)('0'+i);
			dfs(n-i, pos+1, a, X);
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