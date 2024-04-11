//package round38;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class G3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		RBST st = new RBST();
		for(int i = 0;i < n;i++){
			int a = ni(), c = ni();
			int low = Math.max(st.size()-c, 0)-1, high = st.size();
			while(high - low > 1){
				int x = (high + low) / 2;
				if(a > -st.min(x, st.size()-1)){
					high = x;
				}else{
					low = x;
				}
			}
			st.insert(high, new RBST.Node(-a, null, i+1));
		}
		int[] l = st.toArray();
		for(int i = 0;i < l.length;i++){
			if(i > 0)out.print(" ");
			out.print(l[i]);
		}
		out.println();
	}
	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(100000)+1 + " ");
//			sb.append(gen.nextInt(100000)+1 + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static class RBST {
		static public class Node
		{
			public int data;
			public int label;
			public long priority;
			public Node left, right, parent;
			public int count;
			
			public int min;
			
			public Node(int data, Node parent)
			{
				this.data = data;
				this.parent = parent;
				priority = gen.nextLong();
				update();
			}
			
			public Node(int data, Node parent, int label)
			{
				this.data = data;
				this.parent = parent;
				this.label = label;
				priority = gen.nextLong();
				update();
			}
			
			public void update()
			{
				count = 1;
				if(left != null)count += left.count;
				if(right != null)count += right.count;
				
				min = data;
				if(left != null)min = Math.min(min, left.min);
				if(right != null)min = Math.min(min, right.min);
			}
			
			public void propagate()
			{
				update();
				if(parent != null)parent.propagate();
			}
			
			public int min(int a, int b)
			{
				if(a == 0 && b == count-1)return min;
				int nl = left != null ? left.count : 0;
				int ret = Integer.MAX_VALUE;
				if(a < nl)ret = Math.min(ret, left.min(a, Math.min(b, nl-1)));
				if(a <= nl && nl <= b)ret = Math.min(ret, data);
				if(right != null && b > nl)ret = Math.min(ret, right.min(Math.max(a-(nl+1), 0), b-(nl+1)));
				return ret;
			}
			
			public void disconnect()
			{
				left = null; right = null; parent = null;
				update();
			}
			
			public String toString()
			{
				return "data:" + data
						+ ", count:" + count
						+ ", left:" + (left != null ? left.data : null)
						+ ", right:" + (right != null ? right.data : null)
						+ ", parent:" + (parent != null ? parent.data : null)
						;
			}
			
			public List<Integer> toList()
			{
				List<Integer> ret = new ArrayList<Integer>();
				if(left != null)ret.addAll(left.toList());
				ret.add(label);
				if(right != null)ret.addAll(right.toList());
				return ret;
			}
			
			public int toArray(int[] a, int p)
			{
				if(left != null)p = left.toArray(a, p);
				a[p++] = label;
				if(right != null)p = right.toArray(a, p);
				return p;
			}
		}
		
		protected static Random gen = new Random();
		public Node root = null;
		
		public Node insert(int ind, int x)
		{
			if(!inrange(ind, true))return null;
			Node n = new Node(x, null);
			root = insert(root, ind, n);
			return n;
		}
		
		public Node insert(int ind, Node n)
		{
			if(!inrange(ind, true))return null;
			root = insert(root, ind, n);
			return n;
		}
		
		public Node remove(int ind)
		{
			if(!inrange(ind, false))return null;
			return remove(get(root, ind));
		}
		
		public Node get(int ind)
		{
			if(!inrange(ind, false))return null;
			return get(root, ind);
		}
		
		public int update(int ind, int x)
		{
			if(!inrange(ind, false))return Integer.MIN_VALUE;
			Node n = get(root, ind);
			int old = n.data;
			n.data = x;
			n.propagate();
			return old;
		}
		
		public int min(int a, int b)
		{
			if(!inrange(a, false) || !inrange(b, false) || a > b)return Integer.MIN_VALUE+2;
			return root.min(a, b);
		}
		
		public String toString() { return toString(root, ""); }
		
		public String toString(Node n, String indent)
		{
			if(n != null) {
				StringBuilder sb = new StringBuilder();
				sb.append(toString(n.left, indent + "  "));
				sb.append(indent);
				sb.append(n.toString());
				sb.append('\n');
				sb.append(toString(n.right, indent + "  "));
				return sb.toString();
			}else {
				return "";
			}
		}
		
		public List<Integer> toList() {	return root == null ? new ArrayList<Integer>() : root.toList(); }
		public int size() { return root == null ? 0 : root.count; }
		
		public int[] toArray()
		{
			int[] ret = new int[size()];
			if(root != null)root.toArray(ret, 0);
			return ret;
		}
		
		// NOT VERIFIED
		public static RBST build(int[] a)
		{
			RBST st = new RBST();
			int n = a.length;
			long[] pr = new long[n];
			for(int i = 0;i < n;i++)pr[i] = gen.nextLong();
			
			Arrays.sort(pr);
			Node[] ns = new Node[n];
			for(int i = 0;i < n;i++){
				ns[i] = new Node(a[i], i == 0 ? null : ns[(i+1)/2-1]);
				ns[i].priority = pr[i];
			}
			for(int i = n-1;i >= 0;i--){
				ns[i].update();
			}
			
			st.root = ns[0];
			return st;
		}
		
		// ---------------------------------------------
		
		private boolean inrange(int ind, boolean plus)
		{
			if(root == null){
				if(ind != 0)return false;
			}else{
				if(plus){
					if(ind < 0 || ind > root.count)return false;
				}else{
					if(ind < 0 || ind >= root.count)return false;
				}
			}
			return true;
		}
		
		private Node insert(Node n, int ind, Node x)
		{
			if(n == null)return x;
			int nl = n.left != null ? n.left.count : 0;
			if(ind <= nl){
				n.left = insert(n.left, ind, x);
				n.left.parent = n;
				if(n.priority > n.left.priority){
					n = rotateRight(n);
					n.right.update();
				}
			}else{
				ind -= nl+1;
				n.right = insert(n.right, ind, x);
				n.right.parent = n;
				if(n.priority > n.right.priority){
					n = rotateLeft(n);
					n.left.update();
				}
			}
			n.update();
			return n;
		}
		
		private Node remove(Node t)
		{
			if(t == null)return null;
			if(t.left == null && t.right == null){
				// leaf
				if(t.parent != null){
					if(t.equals(t.parent.left))t.parent.left = null;
					if(t.equals(t.parent.right))t.parent.right = null;
					t.parent.propagate();
				}
				t.disconnect();
				if(root.equals(t))root = null;
			}else if(t.left != null && t.right != null){
				if(t.left.priority < t.right.priority){
					rotateRight(t);
				}else{
					rotateLeft(t);
				}
				if(root.equals(t))root = t.parent;
				remove(t);
			}else if(t.left != null){
				Node p = t.parent;
				Node c = t.left;
				if(p != null){
					if(t.equals(p.left))p.left = c;
					if(t.equals(p.right))p.right = c;
				}
				c.parent = p;
				t.disconnect();
				if(root.equals(t))root = c;
				if(p != null)p.propagate();
			}else if(t.right != null){
				Node p = t.parent;
				Node c = t.right;
				if(p != null){
					if(t.equals(p.left))p.left = c;
					if(t.equals(p.right))p.right = c;
				}
				c.parent = p;
				t.disconnect();
				if(root.equals(t))root = c;
				if(p != null)p.propagate();
			}
			return t;
		}
		
		private Node get(Node n, int ind)
		{
			if(n == null)return null;
			int nl = n.left != null ? n.left.count : 0;
			if(ind < nl){
				return get(n.left, ind);
			}
			ind -= nl;
			if(ind == 0){
				return n;
			}
			ind--;
			return get(n.right, ind);
		}
		
		/**
		 *    H
		 *    A
		 *  B   C
		 * D E F G
		 *
		 *    H
		 *    B
		 *  D   A
		 *     E C
		 *     
		 * @param n
		 * @return
		 */
		private Node rotateRight(Node n)
		{
			Node A = n;
			Node B = n.left;
			Node E = B != null ? B.right : null;
			Node H = A.parent;
			if(H != null){
				if(A.equals(H.right)){
					H.right = B;
				}else{
					H.left = B;
				}
			}
			if(B != null)B.parent = H;
			if(B != null)B.right = A;
			A.parent = B;
			A.left = E;
			if(E != null)E.parent = A;
			return B;
		}
		
		/**
		 *    H
		 *    A
		 *  B   C
		 * D E F G
		 *
		 *    H
		 *    C
		 *  A   G
		 * B F
		 * 
		 * @param n
		 * @return
		 */
		private Node rotateLeft(Node n)
		{
			Node A = n;
			Node C = n.right;
			Node F = C != null ? C.left : null;
			Node H = A.parent;
			if(H != null){
				if(A.equals(H.right)){
					H.right = C;
				}else{
					H.left = C;
				}
			}
			if(C != null)C.parent = H;
			if(C != null)C.left = A;
			A.parent = C;
			A.right = F;
			if(F != null)F.parent = A;
			return C;
		}
	}
	
	public static void main(String[] args) throws Exception
	{
		new G3().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}