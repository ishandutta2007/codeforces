//package codestrike2014.finals;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		Node root = null;
		int n = ni(), m = ni();
		for(int i = 0;i < n;i++){
			root = insert(root, i, new Node(-1));
		}
		
		int[][] ops = new int[m][];
		for(int i = 0;i < m;i++){
			ops[i] = new int[]{ni()-1, ni()-1};
		}
		
		boolean[] marked = new boolean[n];
		for(int i = m-1;i >= 0;i--){
			Node top = get(root, 0);
			root = erase(root, 0);
			if(top.v == -1){
				if(marked[ops[i][0]]){
					out.println(-1);
					return;
				}
			}else{
				if(ops[i][0] != top.v){
					out.println(-1);
					return;
				}
			}
			top.v = ops[i][0];
			marked[top.v] = true;
			root = insert(root, ops[i][1], top);
		}
		
		Node[] nodes = nodes(root);
		int p = 0;
		for(int i = 0;i < n;i++){
			if(nodes[i].v != -1){
				out.print(nodes[i].v+1);
				out.print(" ");
			}else{
				while(p < n && marked[p])p++;
				out.print(p+1);
				out.print(" ");
				p++;
			}
		}
		out.println();
	}
	
	static Random gen = new Random();
	
	static public class Node
	{
		public int v; // value
		public long priority;
		public Node left, right;
		
		public int count;
		
		public Node(int v)
		{
			this.v = v;
			priority = gen.nextLong();
			update(this);
		}

		@Override
		public String toString() {
			StringBuilder builder = new StringBuilder();
			builder.append("Node [v=");
			builder.append(v);
			builder.append(", count=");
			builder.append(count);
			builder.append("]");
			return builder.toString();
		}
	}

	public static Node update(Node a)
	{
		if(a == null)return null;
		a.count = 1;
		if(a.left != null)a.count += a.left.count;
		if(a.right != null)a.count += a.right.count;
		
		return a;
	}
	
	public static Node disconnect(Node a)
	{
		if(a == null)return null;
		a.left = a.right = null;
		return update(a);
	}
	
	public static Node merge(Node a, Node b)
	{
		if(b == null)return a;
		if(a == null)return b;
		if(a.priority > b.priority){
			a.right = merge(a.right, b);
			return update(a);
		}else{
			b.left = merge(a, b.left);
			return update(b);
		}
	}
	
	public static int count(Node a)
	{
		return a == null ? 0 : a.count;
	}
	
	// [0,K),[K,N)
	public static Node[] split(Node a, int K)
	{
		if(a == null)return new Node[]{null, null};
		if(K <= count(a.left)){
			Node[] s = split(a.left, K);
			a.left = s[1];
			s[1] = update(a);
			return s;
		}else{
			Node[] s = split(a.right, K-count(a.left)-1);
			a.right = s[0];
			s[0] = update(a);
			return s;
		}
	}
	
	public static Node insert(Node a, int K, Node b)
	{
		if(a == null)return b;
		if(b.priority < a.priority){
			if(K <= count(a.left)){
				a.left = insert(a.left, K, b);
			}else{
				a.right = insert(a.right, K-count(a.left)-1, b);
			}
			return update(a);
		}else{
			Node[] ch = split(a, K);
			b.left = ch[0]; b.right = ch[1];
			return update(b);
		}
	}
	
	// delete K-th
	public static Node erase(Node a, int K)
	{
		if(a == null)return null;
		if(K < count(a.left)){
			a.left = erase(a.left, K);
			return update(a);
		}else if(K == count(a.left)){
			Node aa = merge(a.left, a.right);
			disconnect(a);
			return aa;
		}else{
			a.right = erase(a.right, K-count(a.left)-1);
			return update(a);
		}
	}
	
	public static Node get(Node a, int K)
	{
		while(a != null){
			if(K < count(a.left)){
				a = a.left;
			}else if(K == count(a.left)){
				break;
			}else{
				K = K - count(a.left)-1;
				a = a.right;
			}
		}
		return a;
	}
	
	public static Node update(Node a, int K, int v)
	{
		Node f = get(a, K);
		a = erase(a, K);
		f.v = v;
		a = insert(a, K, f);
		return a;
	}
	
	public static Node[] nodes(Node a) { return nodes(a, new Node[a.count], 0, a.count); }
	public static Node[] nodes(Node a, Node[] ns, int L, int R)
	{
		if(a == null)return ns;
		nodes(a.left, ns, L, L+count(a.left));
		ns[L+count(a.left)] = a;
		nodes(a.right, ns, R-count(a.right), R);
		return ns;
	}
	
	public static String toString(Node a, String indent)
	{
		if(a == null)return "";
		StringBuilder sb = new StringBuilder();
		sb.append(toString(a.left, indent + "  "));
		sb.append(indent).append(a).append("\n");
		sb.append(toString(a.right, indent + "  "));
		return sb.toString();
	}
	
	void run() throws Exception
	{
//		int n = 1000000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(1 + " ");
//			sb.append(1 + " ");
////			sb.append(gen.nextInt(1000000)+1 + " ");
////			sb.append(gen.nextInt(1000000)+1 + " ");
//		}
//		INPUT = sb.toString();
		
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