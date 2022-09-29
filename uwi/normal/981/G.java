//package avito2018;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.Random;

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			int t = ni();
			if(t == 1){
				qs[i] = new int[]{1, ni()-1, ni()-1, ni()};
			}else{
				qs[i] = new int[]{2, ni()-1, ni()-1};
			}
		}
		
		int[] cts = new int[n+1];
		for(int[] q : qs){
			if(q[0] == 1)cts[q[3]]++;
		}
		int[][] g = new int[n+1][];
		for(int i = 0;i <= n;i++){
			g[i] = new int[cts[i]];
		}
		Arrays.fill(cts, 0);
		for(int i = 0;i < Q;i++){
			int[] q = qs[i];
			if(q[0] == 1)g[q[3]][cts[q[3]]++] = i;
		}
		
		int[][] xqs = new int[3*Q][];
		int p = 0;
		for(int i = 1;i <= n;i++){
			int[] row = g[i];
			
			Node root = null;
			for(int id : row){
				int l = qs[id][1], r = qs[id][2]+1;
				int pre = l;
				int lb = lowerBound(root, l);
				if(lb-1 >= 0){
					Node prev = get(root, lb-1);
					if(l < prev.w){
						xqs[p++] = new int[]{l, Math.min(r, prev.w), id, 1}; // x2
						l = prev.v;
						r = Math.max(prev.w, r);
						pre = prev.w;
						root = erase(root, lb-1);
					}
				}
				
				while(true){
					lb = lowerBound(root, l);
					if(lb < count(root) && get(root, lb).v < r){
						Node x = get(root, lb);
						if(pre < x.v)xqs[p++] = new int[]{pre, x.v, id, 0}; // +1
						if(x.v < Math.min(x.w, r))xqs[p++] = new int[]{x.v, Math.min(x.w, r), id, 1}; // x2
						r = Math.max(r, x.w);
						pre = x.w;
						root = erase(root, lb);
					}else{
						break;
					}
				}
				
				if(pre < r){
					xqs[p++] = new int[]{pre, r, id, 0}; // +1
				}
				lb = lowerBound(root, l);
				root = insert(root, lb, new Node(l, r));
			}
		}
		Arrays.sort(xqs, 0, p, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[2] - b[2];
			}
		});

		
		int o = 0;
		SegmentTreeRSQ st = new SegmentTreeRSQ(n+1);
		for(int i = 0;i < Q;i++){
			while(o < p && xqs[o][2] == i){
				if(xqs[o][3] == 0){
					st.add(xqs[o][0], xqs[o][1], 1);
				}else{
					st.mul(xqs[o][0], xqs[o][1], 2);
				}
				o++;
//				tr(st.st);
//				tr(st.plus);
//				tr(st.muls);
			}
			if(qs[i][0] == 2){
//				tr("A2", qs[i]);
				out.println(st.sum(qs[i][1], qs[i][2]+1));
			}
		}
	}
	
	public static Random gen = new Random();
	
	static public class Node
	{
		public int v; // value
		public int w;
		public long priority;
		public Node left, right, parent;
		
		public int count;
		
		public Node(int v, int w)
		{
			this.v = v;
			this.w = w;
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
	
	public static Node mergeTechnically(Node x, Node y)
	{
		if(count(x) > count(y)){
			Node d = x; x = y; y = d;
		}
		// |x|<=|y|
		for(Node cur : nodesdfs(x))y = insertb(y, disconnect(cur));
		return y;
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

	
	static int mod = 998244353;
	
	public static class SegmentTreeRSQ {
		public int M, H, N;
		public long[] st;
		public long[] plus;
		public long[] muls;
		
		public SegmentTreeRSQ(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			plus = new long[H];
			muls = new long[H];
			Arrays.fill(muls, 1);
		}
		
		public SegmentTreeRSQ(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			plus = new long[H];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			for(int i = (M>>1)-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		private void propagate(int i)
		{
			int count = H/Integer.highestOneBit(i);
			st[i] = ((st[2*i]+st[2*i+1])*muls[i]+plus[i]*count) % mod;
		}
		
		void fall(int cur)
		{
			if(2*cur >= H){
				st[2*cur] = (st[2*cur] * muls[cur] + plus[cur]) % mod;
				st[2*cur+1] = (st[2*cur+1] * muls[cur] + plus[cur]) % mod;
			}else{
				for(int d = 0;d < 2;d++){
					muls[2*cur+d] = muls[2*cur+d] * muls[cur] % mod;
					plus[2*cur+d] = (plus[2*cur+d] * muls[cur] + plus[cur]) % mod;
					propagate(2*cur+d);
				}
			}
			muls[cur] = 1;
			plus[cur] = 0;
		}
		
		public void add(int l, int r, int v) { if(l < r)add(l, r, v, 0, H, 1); }
		
		private void add(int l, int r, int v, int cl, int cr, int cur)
		{
			if(cur >= H){
				st[cur] += v;
				if(st[cur] >= mod)st[cur] -= mod;
			}else if(l <= cl && cr <= r){
				plus[cur] += v;
				if(plus[cur] >= mod)plus[cur] -= mod;
				propagate(cur);
			}else{
				int mid = cl+cr>>>1;
				
				fall(cur);
				if(cl < r && l < mid){
					add(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					add(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public void mul(int l, int r, int v) { if(l < r)mul(l, r, v, 0, H, 1); }
		
		private void mul(int l, int r, int v, int cl, int cr, int cur)
		{
			if(cur >= H){
				st[cur] = st[cur] * v % mod;
			}else if(l <= cl && cr <= r){
				fall(cur);
				muls[cur] = muls[cur] * v % mod;
				propagate(cur);
			}else{
				int mid = cl+cr>>>1;
				
				fall(cur);
				if(cl < r && l < mid){
					mul(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					mul(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public long sum(int l, int r) { 
			return sum(l, r, 0, H, 1);
		}
		
		private long sum(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				int mid = cl+cr>>>1;
				long ret = 0;
				if(cl < r && l < mid){
					ret += sum(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					ret += sum(l, r, mid, cr, 2*cur+1);
				}
//				System.err.println(cur + " " + muls[cur] + " " + plus[cur]);
				ret = ret * muls[cur] + plus[cur]*(Math.min(r,cr)-Math.max(l,cl));
				return ret % mod;
			}
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
	
	public static void main(String[] args) throws Exception { new G().run(); }
	
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