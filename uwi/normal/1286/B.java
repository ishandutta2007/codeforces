//package round612;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] par = new int[n];
		int[] c = new int[n];
		for(int i = 0;i < n;i++) {
			par[i] = ni()-1;
			c[i] = ni();
		}
		int root = 0;
		for(int i = 0;i < n;i++) {
			if(par[i] == -1)root = i;
		}
		
		int[][] g = parentToG(par);
		int[][] pars = parents3(g, root);
		int[] ord = pars[1], dep = pars[2];
		
		int[] des = new int[n];
		Arrays.fill(des, 1);
		for(int i = n-1;i >= 1;i--) {
			int cur = ord[i];
			des[par[cur]] += des[cur];
		}
		
		for(int i = 0;i < n;i++) {
			if(c[i] > des[i]-1) {
				out.println("NO");
				return;
			}
		}
		out.println("YES");
		
		Node[] nodes = new Node[n];
		for(int i =0;i < n;i++)nodes[i] = new Node(i);
		for(int i = n-1;i >= 0;i--) {
			int cur = ord[i];
			Node roo = null;
			for(int e : g[cur]) {
				if(par[cur] == e)continue;
				roo = merge(roo, nodes[e]);
			}
			nodes[cur] = insert(roo, c[cur], nodes[cur]);
		}
		
		Node[] ns = nodes(nodes[root]);
		int[] ans = new int[n];
		for(int i = 0;i < n;i++) {
			ans[ns[i].v] = i+1;
		}
		for(int v : ans) {
			out.print(v + " ");
		}
		out.println();
	}
	
	public static Random gen = new Random();
						
	static public class Node
	{
		public int v; // value
		public long priority;
		public Node left, right, parent;
		
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
			builder.append(", parent=");
			builder.append(parent != null ? parent.v : "null");
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
		
		// TODO
		return a;
	}
	
	public static void propagate(Node x)
	{
		for(;x != null;x = x.parent)update(x);
	}
	
	public static Node disconnect(Node a)
	{
		if(a == null)return null;
		a.left = a.right = a.parent = null;
		return update(a);
	}
	
	public static Node root(Node x)
	{
		if(x == null)return null;
		while(x.parent != null)x = x.parent;
		return x;
	}
	
	public static int count(Node a)
	{
		return a == null ? 0 : a.count;
	}
	
	public static void setParent(Node a, Node par)
	{
		if(a != null)a.parent = par;
	}
	
	public static Node merge(Node a, Node b, Node... c)
	{
		Node x = merge(a, b);
		for(Node n : c)x = merge(x, n);
		return x;
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
	
	public static Node[] split(Node x)
	{
		if(x == null)return new Node[]{null, null};
		if(x.left != null)x.left.parent = null;
		Node[] sp = new Node[]{x.left, x};
		x.left = null;
		update(x);
		while(x.parent != null){
			Node p = x.parent;
			x.parent = null;
			if(x == p.left){
				p.left = sp[1];
				if(sp[1] != null)sp[1].parent = p;
				sp[1] = p;
			}else{
				p.right = sp[0];
				if(sp[0] != null)sp[0].parent = p;
				sp[0] = p;
			}
			update(p);
			x = p;
		}
		return sp;
	}
	
	public static Node[] split(Node a, int... ks)
	{
		int n = ks.length;
		if(n == 0)return new Node[]{a};
		for(int i = 0;i < n-1;i++){
			if(ks[i] > ks[i+1])throw new IllegalArgumentException(Arrays.toString(ks));
		}
		
		Node[] ns = new Node[n+1];
		Node cur = a;
		for(int i = n-1;i >= 0;i--){
			Node[] sp = split(cur, ks[i]);
			cur = sp[0];
			ns[i] = sp[0];
			ns[i+1] = sp[1];
		}
		return ns;
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
		int ind = lowerBound(root, x.v);
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
	
	public static int lowerBound(Node a, int q)
	{
		int lcount = 0;
		while(a != null){
			if(a.v >= q){
				a = a.left;
			}else{
				lcount += count(a.left) + 1;
				a = a.right;
			}
		}
		return lcount;
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
	
	public static Node next(Node x)
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
	
	public static Node prev(Node x)
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
	
	public static Node build(int[] a, int l, int r)
	{
		if(l >= r)return null;
		
		int h = l+r>>1;
		Node root = new Node(a[h]);
		
		Node L = build(a, l, h);
		root.left = L;
		if(L != null)L.parent = root;
		
		Node R = build(a, h+1, r);
		root.right = R;
		if(R != null)R.parent = root;
		
		return update(root);
	}
	
	
	public static Node[] nodes(Node a) { return nodes(a, new Node[count(a)], 0, count(a)); }
	public static Node[] nodes(Node a, Node[] ns, int L, int R)
	{
		if(a == null)return ns;
		nodes(a.left, ns, L, L+count(a.left));
		ns[L+count(a.left)] = a;
		nodes(a.right, ns, R-count(a.right), R);
		return ns;
	}
	
	// faster than nodes but inconsistent
	public static Node[] nodesdfs(Node a) { return nodesdfs(a, new Node[a.count], new int[]{0}); }
	public static Node[] nodesdfs(Node a, Node[] ns, int[] pos)
	{
		if(a == null)return ns;
		ns[pos[0]++] = a;
		nodesdfs(a.left, ns, pos);
		nodesdfs(a.right, ns, pos);
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

	
	public static int[][] parentToG(int[] par)
	{
		int n = par.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				ct[i]++;
				ct[par[i]]++;
			}
		}
		int[][] g = new int[n][];
		for(int i = 0;i < n;i++){
			g[i] = new int[ct[i]];
		}
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				g[par[i]][--ct[par[i]]] = i;
				g[i][--ct[i]] = par[i];
			}
		}
		return g;
	}

	
	void run() throws Exception
	{
//		int n = 2000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(i + " " + gen.nextInt(n-i) + "\n");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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