//package ecr88;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Random;

public class F4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++)co[i] = na(5);
		double[] vxs = new double[n];
		double[] vys = new double[n];
		for(int i = 0;i < n;i++){
			vxs[i] = co[i][2]/Math.sqrt(co[i][2]*co[i][2]+co[i][3]*co[i][3]) * co[i][4];
			vys[i] = co[i][3]/Math.sqrt(co[i][2]*co[i][2]+co[i][3]*co[i][3]) * co[i][4];
		}
		
		double low = 0, high = 8e9+7;
		for(int rep = 0;rep < 60;rep++){
			double t = low + (high - low) / 2;
			double[][] ss = new double[n][];
			for(int i = 0;i < n;i++){
				ss[i] = new double[]{
					co[i][0], co[i][1],
					co[i][0]+vxs[i]*t, co[i][1]+vys[i]*t
				};
			}
			if(hasIntersection(ss)){
				high = t;
			}else{
				low = t;
			}
		}
		if(high > 8e9){
			out.println("No show :(");
		}else{
			out.printf("%.14f\n", high);
		}
	}
	
	public static long d2(int[] a, int[] b) { return (long)(b[0]-a[0])*(b[0]-a[0])+(long)(b[1]-a[1])*(b[1]-a[1]); }

	public static Random gen = new Random();
	
	static public class Node
	{
		public double[] s;
		public long priority;
		public Node left, right, parent;
		
		public int count;
		
		public Node(double[] s)
		{
			this.s = s;
			priority = gen.nextLong();
			update(this);
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
	
	public static Node insertb(Node root, Node x, Comparator<Node> comp)
	{
		int ind = lowerBound(root, x, comp);
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
	
	public static int lowerBound(Node a, Node b, Comparator<Node> comp)
	{
		int lcount = 0;
		while(a != null){
			if(comp.compare(a, b) >= 0){
				a = a.left;
			}else{
				lcount += count(a.left) + 1;
				a = a.right;
			}
		}
		return lcount;
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

	static double y(double x, double[] s)
	{
		return (x-s[0])/(s[2]-s[0])*(s[3]-s[1])+s[1];
	}
	
	public static boolean hasIntersection(double[][] ss)
	{
		int n = ss.length;
		List<Event> es = new ArrayList<>();
		for(int i = 0;i < n;i++){
			double[] s = ss[i];
			if(s[0] > s[2]){
				{double x = s[0]; s[0] = s[2]; s[2] = x;}
				{double x = s[1]; s[1] = s[3]; s[3] = x;}
			}
			es.add(new Event(s[0], i, 0));
			es.add(new Event(s[2], i, 1));
		}
		es.sort((a, b) -> {
			if(a.x != b.x)return Double.compare(a.x, b.x);
			return a.type - b.type;
		});
		
		Node[] nodes = new Node[n];
		for(int i = 0;i < n;i++){
			nodes[i] = new Node(ss[i]);
		}
		Node root = null;
		double[] x = {Double.NEGATIVE_INFINITY};
		
		Comparator<Node> comp = (a, b) -> {
			double ay = y(x[0], a.s);
			double by = y(x[0], b.s);
			if(ay != by)return Double.compare(ay, by);
			return 0;
		};

		// (x1,y1)-(x2,y2)
		// (x-x1)/(x2-x1)*(y2-y1)+y1
		
		for(Event e : es){
//			System.err.println(e.id + " " + e.type + " " + e.x);
			if(e.type == 0){
				// insert
				x[0] = e.x;
				root = insertb(root, nodes[e.id], comp);
				
				Node lower = prev(nodes[e.id]);
				if(lower != null && hasCommonPoint(lower.s, nodes[e.id].s)){
					return true;
				}
				
				Node higher = next(nodes[e.id]);
				if(higher != null && hasCommonPoint(higher.s, nodes[e.id].s)){
					return true;
				}
			}else if(e.type == 1){
				// delete
				Node lower = prev(nodes[e.id]);
				Node higher = next(nodes[e.id]);
				root = erase(root, index(nodes[e.id]));
				x[0] = e.x;
				
				if(lower != null && higher != null && hasCommonPoint(lower.s, higher.s)){
					return true;
				}
			}
		}
		
		return false;
	}
	
	static double EPS = 1e-10;
	
	public static int rccw(double ax, double ay, double bx, double by, double tx, double ty){
		double v = (tx-ax)*(by-ay)-(bx-ax)*(ty-ay);
		return Math.abs(v) < EPS ? 0 : (int)Math.signum(v);
	}
	
	public static boolean hasCommonPointIn1D(double ax, double bx, double cx, double dx)
	{
		return Math.min(Math.max(ax, bx), Math.max(cx, dx)) - Math.max(Math.min(ax, bx), Math.min(cx, dx)) >= -EPS;
	}
	
	public static boolean hasCommonPoint(double[] a, double[] b)
	{
		return hasCommonPoint(a[0], a[1], a[2], a[3], b[0], b[1], b[2], b[3]);
	}
	
	public static boolean hasCommonPoint(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy)
	{
		return hasCommonPointIn1D(ax, bx, cx, dx) && hasCommonPointIn1D(ay, by, cy, dy) &&
				rccw(ax, ay, bx, by, cx, cy) * rccw(ax, ay, bx, by, dx, dy) <= 0 &&
				rccw(cx, cy, dx, dy, ax, ay) * rccw(cx, cy, dx, dy, bx, by) <= 0;
	}
	
	public static class Event
	{
		public int type;
		public int id;
		public double x;
		
		public Event(double x, int id, int type)
		{
			this.x = x;
			this.id = id;
			this.type = type;
		}
	}

	
	void run() throws Exception
	{
//		int n = 25000, m = 99999;
//		Random gen = new Random(1);
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(2000)-1000 + " ");
//			sb.append(gen.nextInt(2000)-1000 + " ");
//			sb.append(gen.nextInt(2000)-1000 + " ");
//			sb.append(gen.nextInt(2000)-1000 + " ");
//			sb.append(gen.nextInt(1000)+1 + " ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F4().run(); }
	
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