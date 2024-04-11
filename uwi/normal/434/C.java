//package round248;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		int[] L = na(ni());
		int[] R = na(ni());
		TrieNew trie = new TrieNew();
		for(int i = 0;i < n;i++){
			int[] NG = na(ni());
			int val = ni();
			char[] ng = new char[NG.length];
			for(int j = 0;j < NG.length;j++){
				ng[j] = (char)(NG[j]+'a');
			}
			trie.add(ng, val);
		}
		trie.buildFailure();
		if(L.length == 1 && L[0] == 1){
			L = new int[]{0};
		}else{
			for(int i = L.length-1;i >= 0;i--){
				L[i]--;
				if(L[i] < 0){
					L[i] += m;
				}else{
					break;
				}
			}
			for(int i = 0;i < L.length;i++){
				if(L[i] != 0){
					L = Arrays.copyOfRange(L, i, L.length);
					break;
				}
			}
		}
		
		out.println((count(R, trie, K, m) - count(L, trie, K, m) + mod) % mod);
	}
	
	int mod = 1000000007;
	
	long count(int[] r, TrieNew trie, int K, int base)
	{
		if(r.length == 1 && r[0] == 0)return 0L;
		int n = r.length;
		TrieNew.Node[] nodes = trie.toArray();
		int m = nodes.length;
		int[][] pre = new int[m][K+1];
		int[][] cur = new int[m][K+1];
		TrieNew.Node edge = nodes[0];
		int edgeval = 0;
		TrieNew.Node[][] nexts = new TrieNew.Node[m][base];
		for(int i = 0;i < m;i++){
			for(int j = 0;j < base;j++){
				nexts[i][j] = trie.next(nodes[i], (char)(j+'a'));
			}
		}
		
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				Arrays.fill(cur[j], 0);
			}
			for(int j = 0;j < m;j++){
				for(int k = 0;k < base;k++){
					TrieNew.Node next = nexts[j][k];
					int dv = next.hit;
					for(int v = 0;v+dv <= K;v++){
						cur[next.id][v+dv] += pre[j][v];
						if(cur[next.id][v+dv] >= mod)cur[next.id][v+dv] -= mod;
					}
				}
			}
			
			if(i == 0){
				for(int j = 1;j < r[i];j++){
					TrieNew.Node next = nexts[0][j];
					int dv = next.hit;
					if(dv <= K){
						cur[next.id][dv] += 1;
						if(cur[next.id][dv] >= mod)cur[next.id][dv] -= mod;
					}
				}
			}else{
				for(int j = 1;j < base;j++){
					TrieNew.Node next = nexts[0][j];
					int dv = next.hit;
					if(dv <= K){
						cur[next.id][dv] += 1;
						if(cur[next.id][dv] >= mod)cur[next.id][dv] -= mod;
					}
				}
				for(int j = 0;j < r[i];j++){
					TrieNew.Node next = nexts[edge.id][j];
					int dv = edgeval + next.hit;
					if(dv <= K){
						cur[next.id][dv] += 1;
						if(cur[next.id][dv] >= mod)cur[next.id][dv] -= mod;
					}
				}
			}
			
			edge = trie.next(edge, (char)(r[i]+'a'));
			edgeval += edge.hit;
			int[][] dum = pre; pre = cur; cur = dum;
		}
		long allcnt = 0;
		for(int[] row : pre){
			for(int v : row){
				allcnt += v;
			}
		}
//		for(int i = 0;i < m;i++){
//			for(int j = 0;j <= K;j++){
//				if(pre[i][j] > 0){
//					tr(i, j, pre[i][j]);
//				}
//			}
//		}
		if(edgeval <= K)allcnt++;
		return allcnt%mod;
	}
	
	public static class TrieNew {
		public Node root = new Node((char)0, 0);
		public int gen = 1;
		
		public static class Node
		{
			public int id;
			public char c;
			public Node next, firstChild;
			public int hit = 0;
			
			public Node fail;
			
			public Node(char c, int id)
			{
				this.id = id;
				this.c = c;
			}
			
			public String toString(String indent)
			{
				StringBuilder sb = new StringBuilder();
				sb.append(indent + id + ":" + c);
				if(hit != 0)sb.append(" H:" + hit);
				if(fail != null)sb.append(" F:" + fail.id);
				sb.append("\n");
				for(Node c = firstChild;c != null; c = c.next){
					sb.append(c.toString(indent + "  "));
				}
				return sb.toString();
			}
		}
		
		public void add(char[] s, int plus)
		{
			Node cur = root;
			Node pre = null;
			for(char c : s){
				pre = cur; cur = cur.firstChild;
				if(cur == null){
					cur = pre.firstChild = new Node(c, gen++);
				}else{
					for(;cur != null && cur.c != c;pre = cur, cur = cur.next);
					if(cur == null)cur = pre.next = new Node(c, gen++);
				}
			}
			cur.hit += plus;
		}
		
		public void buildFailure()
		{
			root.fail = null;
			Queue<Node> q = new ArrayDeque<Node>();
			q.add(root);
			while(!q.isEmpty()){
				Node cur = q.poll();
				inner:
				for(Node ch = cur.firstChild;ch != null; ch = ch.next){
					q.add(ch);
					for(Node to = cur.fail; to != null; to = to.fail){
						for(Node lch = to.firstChild;lch != null; lch = lch.next){
							if(lch.c == ch.c){
								ch.fail = lch;
								ch.hit += lch.hit;
								continue inner;
							}
						}
					}
					ch.fail = root;
				}
			}
		}
		
		public Node next(Node cur, char c)
		{
			for(;cur != null;cur = cur.fail){
				for(Node ch = cur.firstChild;ch != null; ch = ch.next){
					if(ch.c == c)return ch;
				}
			}
			return root;
		}
		
		public void search(char[] q)
		{
			Node cur = root;
			outer:
			for(char c : q){
				for(;cur != null;cur = cur.fail){
					for(Node ch = cur.firstChild;ch != null; ch = ch.next){
						if(ch.c == c){
							// ch.hit
							cur = ch;
							continue outer;
						}
					}
				}
				cur = root;
			}
		}
		
		public int countHit(char[] q)
		{
			Node cur = root;
			int hit = 0;
			outer:
			for(char c : q){
				for(;cur != null;cur = cur.fail){
					for(Node ch = cur.firstChild;ch != null; ch = ch.next){
						if(ch.c == c){
							hit += ch.hit;
							cur = ch;
							continue outer;
						}
					}
				}
				cur = root;
			}
			return hit;
		}
		
		public Node[] toArray()
		{
			Queue<Node> q = new ArrayDeque<Node>();
			q.add(root);
			Node[] ret = new Node[gen];
			while(!q.isEmpty()){
				Node cur = q.poll();
				ret[cur.id] = cur;
				if(cur.next != null)q.add(cur.next);
				if(cur.firstChild != null)q.add(cur.firstChild);
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
//		int n = 200, m = 20, k = 500;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(10 + " ");
//		sb.append(m + " ");
//		sb.append(k + " ");
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(m) + " ");
//		}
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(m) + " ");
//		}
//		for(int u = 0;u < 10;u++){
//			sb.append(20 + " ");
//			for(int i = 0;i < 20;i++){
//				sb.append(gen.nextInt(m) + " ");
//			}
//			sb.append(gen.nextInt(200)+1 + " ");
//		}
//		INPUT = sb.toString();
		
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