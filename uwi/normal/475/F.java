//package bayan2014.warmup;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = na(2);
		}
		
		Node rootx = null;
		Node rooty = null;
		for(int i = 0;i < n;i++){
			Node nx = new Node(co[i][0]);
			Node ny = new Node(co[i][1]);
			nx.dual = ny;
			ny.dual = nx;
			rootx = insertb(rootx, nx);
			rooty = insertb(rooty, ny);
			updateGap(nx);
			updateGap(ny);
		}
		
		out.println(dfs(rootx, rooty));
	}
	
	Node temp = null;
	Node troot = null;
	
	int dfs(Node rootx, Node rooty)
	{
		if(rootx == null)return 0;
		if(count(rootx) == 1)return 1;
//		tr(count(rootx));
//		tr(toString(rootx, ""));
//		tr(toString(rooty, ""));
		if(rootx.deshasgap != null){
			int K = index(rootx.deshasgap);
			killGap(rootx.deshasgap);
			Node[] xlr = split(rootx, K);
			if(count(xlr[0]) > count(xlr[1])){
				Node d = xlr[0]; xlr[0] = xlr[1]; xlr[1] = d;
			}
			temp = null;
			troot = rooty;
			dfs2(xlr[0]);
			Node L = temp, R = troot;
			return dfs(xlr[0], L) + dfs(xlr[1], R);
		}else if(rooty.deshasgap != null){
			int K = index(rooty.deshasgap);
			killGap(rooty.deshasgap);
			Node[] ylr = split(rooty, K);
			if(count(ylr[0]) > count(ylr[1])){
				Node d = ylr[0]; ylr[0] = ylr[1]; ylr[1] = d;
			}
			temp = null;
			troot = rootx;
			dfs2(ylr[0]);
			Node L = temp, R = troot;
			return dfs(L, ylr[0]) + dfs(R, ylr[1]);
		}
		return 1;
	}
	
	void dfs2(Node x)
	{
		if(x == null)return;
		int ind = index(x.dual);
		troot = erase(troot, ind);
		updateGap(get(troot, ind));
		temp = insertb(temp, x.dual);
		updateGap(x.dual);
		dfs2(x.left);
		dfs2(x.right);
	}
	
	static void updateGap(Node x)
	{
		if(x == null)return;
//		int ind = index(x);
//		Node r = root(x);
//		Node next = get(r, ind+1);
//		Node prev = get(r, ind-1);
		Node next = next(x);
		Node prev = prev(x);
		boolean pxhg = x.hasgap;
		x.hasgap = prev != null && x.v - prev.v > 1;
		if(x.hasgap != pxhg)propagate(x);
		if(next != null){
			boolean pnhg = next.hasgap;
			next.hasgap = next.v - x.v > 1;
			if(next.hasgap != pnhg)propagate(next);
		}
	}
	
	static Node next(Node x)
	{
		if(x == null)return null;
		if(x.right != null){
			x = x.right;
			while(x.left != null)x = x.left;
			return x;
		}else{
			while(true){
				Node p = x.parent;
				if(p == null)return null;
				if(p.left == x)return p;
				x = p;
			}
		}
	}
	
	static Node prev(Node x)
	{
		if(x == null)return null;
		if(x.left != null){
			x = x.left;
			while(x.right != null)x = x.right;
			return x;
		}else{
			while(true){
				Node p = x.parent;
				if(p == null)return null;
				if(p.right == x)return p;
				x = p;
			}
		}
	}
	
	static void killGap(Node x)
	{
		x.hasgap = false;
		propagate(x);
	}
	
	static void propagate(Node x)
	{
		while(x != null){
			update(x);
			x = x.parent;
		}
	}
	
	static Node root(Node x)
	{
		if(x == null)return null;
		while(x.parent != null)x = x.parent;
		return x;
	}
	
	public static class XorShift extends Random {
		private static final long serialVersionUID = 6806629989739663134L;
		private long x=123456789, y=362436069, z=521288629, w=88675123;
		public XorShift() {super(); x = System.nanoTime();}
		public XorShift(long seed) {super(seed); x = seed;}
		public synchronized void setSeed(long seed) {super.setSeed(seed); x = seed;}
		protected int next(int bits){
			long t=x^x<<11; x=y; y=z; z=w; w=(w^w>>>19^t^t>>>8)&(1L<<32)-1;
			return (int)w>>>32-bits;
		}
	}
		static Random gen = new XorShift();
		
		static public class Node
		{
			public int v; // value
			public long priority;
			public Node left, right, parent;
			public Node dual;
			public boolean hasgap;
			public Node deshasgap;
			
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
				builder.append(", hasgap=");
				builder.append(hasgap);
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
			
			a.deshasgap = a.hasgap ? a : null;
			if(a.left != null && a.left.deshasgap != null)a.deshasgap = a.left.deshasgap;
			if(a.right != null && a.right.deshasgap != null)a.deshasgap = a.right.deshasgap;
			return a;
		}
		
		public static Node disconnect(Node a)
		{
			if(a == null)return null;
			a.left = a.right = a.parent = null;
			return update(a);
		}
		
		public static Node merge(Node a, Node b)
		{
			if(b == null)return a;
			if(a == null)return b;
			if(a.priority > b.priority){
				setParent(a.right, null);
				setParent(b, null);
				a.right = merge(a.right, b);
				setParent(a.right, a);
				return update(a);
			}else{
				setParent(a, null);
				setParent(b.left, null);
				b.left = merge(a, b.left);
				setParent(b.left, b);
				return update(b);
			}
		}
		
		public static int count(Node a)
		{
			return a == null ? 0 : a.count;
		}
		
		public static void setParent(Node a, Node par)
		{
			if(a != null)a.parent = par;
		}
		
		// [0,K),[K,N)
		public static Node[] split(Node a, int K)
		{
			if(a == null)return new Node[]{null, null};
			if(K <= count(a.left)){
				setParent(a.left, null);
				Node[] s = split(a.left, K);
				a.left = s[1];
				setParent(a.left, a);
				s[1] = update(a);
				return s;
			}else{
				setParent(a.right, null);
				Node[] s = split(a.right, K-count(a.left)-1);
				a.right = s[0];
				setParent(a.right, a);
				s[0] = update(a);
				return s;
			}
		}
		
		public static Node insertb(Node root, Node x)
		{
			int ind = search(root, x.v);
			if(ind < 0)ind = -ind-1;
			return insert(root, ind, x);
		}
		
		public static Node insert(Node a, int K, Node b)
		{
			if(a == null)return b;
			if(b.priority < a.priority){
				if(K <= count(a.left)){
					a.left = insert(a.left, K, b);
					setParent(a.left, a);
				}else{
					a.right = insert(a.right, K-count(a.left)-1, b);
					setParent(a.right, a);
				}
				return update(a);
			}else{
				Node[] ch = split(a, K);
				b.left = ch[0]; b.right = ch[1];
				setParent(b.left, b);
				setParent(b.right, b);
				return update(b);
			}
		}
		
		// delete K-th
		public static Node erase(Node a, int K)
		{
			if(a == null)return null;
			if(K < count(a.left)){
				a.left = erase(a.left, K);
				setParent(a.left, a);
				return update(a);
			}else if(K == count(a.left)){
				setParent(a.left, null);
				setParent(a.right, null);
				Node aa = merge(a.left, a.right);
				disconnect(a);
				return aa;
			}else{
				a.right = erase(a.right, K-count(a.left)-1);
				setParent(a.right, a);
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
		
		public static int search(Node a, int q)
		{
			int lcount = 0;
			while(a != null){
				if(a.v == q){
					lcount += count(a.left);
					break;
				}
				if(q < a.v){
					a = a.left;
				}else{
					lcount += count(a.left) + 1;
					a = a.right;
				}
			}
			return a == null ? -(lcount+1) : lcount;
		}
		
		public static Node update(Node a, int K, int v)
		{
			Node f = get(a, K);
			a = erase(a, K);
			f.v = v;
			a = insert(a, K, f);
			return a;
		}
		
		public static int index(Node a)
		{
			if(a == null)return -1;
			int ind = count(a.left);
			while(a != null){
				Node par = a.parent;
				if(par != null && par.right == a){
					ind += count(par.left) + 1;
				}
				a = par;
			}
			return ind;
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
//		int u = 7000;
//		boolean[][] g = new boolean[u][u];
//		int n = 100000;
//		Random gen = new Random(1);
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
////			while(true){
////				int x = gen.nextInt(u);
////				int y = gen.nextInt(u);
////				if(!g[x][y]){
////					g[x][y] = true;
////					sb.append(x + " " + y + " ");
////					break;
////				}
////			}
//			sb.append((i%300*2) + " " + (i/300*2) + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F2().run(); }
	
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