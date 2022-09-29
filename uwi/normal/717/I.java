//package bubblecup9f;
import java.awt.geom.Line2D;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.Random;

public class I {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		double[][] ca = new double[n][];
		for(int i = 0;i < n;i++){
			ca[i] = new double[]{ni(), ni(), ni()};
		}
		int m = ni();
		double[][] cb = new double[m][];
		for(int i = 0;i < m;i++){
			cb[i] = new double[]{ni(), ni(), ni()};
		}
		double[] a1 = new double[]{ca[1][0]-ca[0][0], ca[1][1]-ca[0][1], ca[1][2]-ca[0][2]};
		double[] a2 = new double[]{ca[2][0]-ca[0][0], ca[2][1]-ca[0][1], ca[2][2]-ca[0][2]};
		double[] na = normalize(cross(a1, a2));
		
		double[][] vs = new double[n+m][];
		for(int i = 0;i < n;i++){
			vs[i] = ca[i];
		}
		for(int i = 0;i < m;i++){
			vs[i+n] = cb[i];
		}
		double[][] vvs = rot(na, new double[]{0, 0, 1}, vs);
		double Z = 0;
		for(int i = 0;i < n;i++){
			Z += vvs[i][2];
		}
		Z /= n;
		Z += 1e-9;
		
		double[][] es = new double[m+2*n][];
		int p = 0;
		for(int i = 0, j = 1;i < m;i++,j++){
			if(j == m)j = 0;
			if(vvs[i+n][2] < Z && vvs[j+n][2] > Z){
				if(vvs[j+n][2] != vvs[i+n][2]){
					double k = (Z-vvs[i+n][2])/(vvs[j+n][2]-vvs[i+n][2]);
					es[p++] = new double[]{
							vvs[i+n][0]+k*(vvs[j+n][0]-vvs[i+n][0]),
							vvs[i+n][1]+k*(vvs[j+n][1]-vvs[i+n][1]),
							1
					};
				}
			}else if(vvs[i+n][2] > Z && vvs[j+n][2] < Z){
				if(vvs[j+n][2] != vvs[i+n][2]){
					double k = (Z-vvs[i+n][2])/(vvs[j+n][2]-vvs[i+n][2]);
					es[p++] = new double[]{
							vvs[i+n][0]+k*(vvs[j+n][0]-vvs[i+n][0]),
							vvs[i+n][1]+k*(vvs[j+n][1]-vvs[i+n][1]),
							-1
					};
				}
			}
		}
//		tr(es);
		for(int i = 0, j = 1;i < n;i++,j++){
			if(j == n)j = 0;
			double x0 = vvs[i][0], y0 = vvs[i][1];
			double x1 = vvs[j][0], y1 = vvs[j][1];
			if(Math.abs(x0-x1) < 1e-9)continue;
			es[p++] = new double[]{Math.min(x0, x1), i, 1, j};
			es[p++] = new double[]{Math.max(x0, x1), i, -1, j};
		}
		Arrays.sort(es, 0, p, new Comparator<double[]>() {
			public int compare(double[] a, double[] b) {
				if(a[0] != b[0])return Double.compare(a[0], b[0]);
				return -Double.compare(a[2], b[2]);
			}
		});
		
		Node[] nodes = new Node[n];
		Node root = null;
		int bal = 0;
		for(int i = 0;i < p;i++){
			double[] e = es[i];
			if(e.length == 4){
				if(e[2] == 1){
					nodes[(int)e[1]] = new Node(vvs[(int)e[1]], vvs[(int)e[3]]);
					root = insertb(root, nodes[(int)e[1]], i+1 < p ? (e[0]+es[i+1][0])/2 : 1e13);
				}else{
					root = erase(root, index(nodes[(int)e[1]]));
				}
			}else{
//				tr(lowerBound(root, e, e, e[0]));
				if((lowerBound(root, e, e, e[0])&1) == 1){
					bal += (int)e[2];
				}
			}
//			tr(toString(root, ""));
		}
		if(bal != 0){
			out.println("YES");
		}else{
			out.println("NO");
		}
	}
	
	public static Random gen = new Random(1145);
	
	static public class Node
	{
		public int v; // value
		public long priority;
		public Node left, right, parent;
		public double[] a, b;
		
		public int count;
		
		public Node(double[] a, double[] b)
		{
			if(a[0] > b[0]){
				double[] d = a; a = b; b = d;
			}
			this.a = a;
			this.b = b;
			priority = gen.nextLong();
			update(this);
		}

		@Override
		public String toString() {
			StringBuilder builder = new StringBuilder();
			builder.append("Node [v=");
			builder.append(Arrays.toString(a));
			builder.append(Arrays.toString(b));
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
	
	public static String toString(Node a, String indent)
	{
		if(a == null)return "";
		StringBuilder sb = new StringBuilder();
		sb.append(toString(a.left, indent + "  "));
		sb.append(indent).append(a).append("\n");
		sb.append(toString(a.right, indent + "  "));
		return sb.toString();
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
	
	public static Node insertb(Node root, Node x, double midx)
	{
		int ind = lowerBound(root, x.a, x.b, midx);
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
	
//	public static Node mergeTechnically(Node x, Node y)
//	{
//		if(count(x) > count(y)){
//			Node d = x; x = y; y = d;
//		}
//		// |x|<=|y|
//		for(Node cur : nodesdfs(x))y = insertb(y, disconnect(cur));
//		return y;
//	}
	
	static int robccw(double ux, double uy, double vx, double vy, double px, double py)
	{
		double eps = 1e-8;
		if(Line2D.ptSegDist(ux, uy, vx, vy, px, py) > eps){
			return Line2D.relativeCCW(ux, uy, vx, vy, px, py);
		}
		return 0;
	}
	
	static double y(double x, double[] a, double[] b)
	{
		if(a == b)return a[1];
		if(b[0]-a[0] == 0)return 1e13;
		return a[1] + (x-a[0])/(b[0]-a[0])*(b[1]-a[1]);
	}
	private static void trz(Object... o) { System.out.println(Arrays.deepToString(o)); }
	
	public static int lowerBound(Node a, double[] u, double[] v, double x)
	{
		if(u[0] > v[0]){
			double[] d = u; u = v; v = d;
		}
//		trz("LB", u, v, x);
		int lcount = 0;
		while(a != null){
			int comp = 0;
			// --->
			//  * = 1
			
			// u-v, a.a-a.b
			if(comp == 0 && u != v){
				comp = robccw(u[0], u[1], v[0], v[1], x, y(x, a.a, a.b));
//				trz("rob", u[0], u[1], v[0], v[1], x, y(x, a.a, a.b), comp);
			}
			if(comp == 0){
//				trz("HI", a.a[0], a.a[1], a.b[0], a.b[1], x, y(x, u, v));
				comp = -robccw(a.a[0], a.a[1], a.b[0], a.b[1], x, y(x, u, v));
			}
			
			if(comp <= 0){
				a = a.left;
			}else{
				lcount += count(a.left) + 1;
				a = a.right;
			}
		}
//		trz(lcount);
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
	
	public static Node[] nodes(Node a) { return nodes(a, new Node[a.count], 0, a.count); }
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
	
	public static double[][] rot(double[] from, double[] to, double[][] xs)
	{
		double nfrom = Math.sqrt(from[0]*from[0]+from[1]*from[1]+from[2]*from[2]);
		for(int i = 0;i < 3;i++)from[i] /= nfrom;
		double nto = Math.sqrt(to[0]*to[0]+to[1]*to[1]+to[2]*to[2]);
		for(int i = 0;i < 3;i++)to[i] /= nto;
		double dot = from[0]*to[0]+from[1]*to[1]+from[2]*to[2];
		if(dot >= 1)dot = 1;
		if(dot <= -1)dot = -1;
		double angle = Math.acos(dot);
		if(Math.abs(angle) < 1E-8)return xs;
		if(Math.abs(Math.PI-angle) < 1E-8){
			double[][] ret = new double[xs.length][3];
			for(int i = 0;i < xs.length;i++){
				ret[i][0] = -xs[i][0];
				ret[i][1] = -xs[i][1];
				ret[i][2] = -xs[i][2];
			}
			return ret;
		}
		
		double[] axis = new double[]{
				from[1]*to[2]-from[2]*to[1],
				from[2]*to[0]-from[0]*to[2],
				from[0]*to[1]-from[1]*to[0]
		};
		double nax = Math.sqrt(axis[0]*axis[0]+axis[1]*axis[1]+axis[2]*axis[2]);
		for(int i = 0;i < 3;i++)axis[i] /= nax;
		
		double[][] ret = new double[xs.length][3];
		
		double ncos = Math.cos(angle);
		double nsin = Math.sin(angle);
		double scos = 1.0 - ncos;
		
		double sxy = axis[0] * axis[1] * scos;
		double syz = axis[1] * axis[2] * scos;
		double sxz = axis[0] * axis[2] * scos;
		double sz = nsin * axis[2];
		double sy = nsin * axis[1];
		double sx = nsin * axis[0];
		
		int p = 0;
		for(double[] x : xs){
			ret[p][0] = (ncos+axis[0]*axis[0]*scos)*x[0] + (-sz+sxy)*x[1]+(sy+sxz)*x[2];
			ret[p][1] = (sz+sxy)*x[0]+(ncos+axis[1]*axis[1]*scos)*x[1]+(-sx+syz)*x[2];
			ret[p][2] = (-sy+sxz)*x[0]+(sx+syz)*x[1]+(ncos+axis[2]*axis[2]*scos)*x[2];
			p++;
		}
		return ret;
	}
	
	public static double[] normalize(double[] v)
	{
		double norm = Math.sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
		v[0] /= norm;
		v[1] /= norm;
		v[2] /= norm;
		return v;
	}
	
	public static double[] cross(double[] a, double[] b)
	{
		return new double[]{
				a[1]*b[2]-a[2]*b[1],
				a[2]*b[0]-a[0]*b[2],
				a[0]*b[1]-a[1]*b[0]
		};
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
	
	public static void main(String[] args) throws Exception { new I().run(); }
	
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