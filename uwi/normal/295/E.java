//package round179;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		Node root = new Node(Integer.MAX_VALUE);
		root.priority = Long.MAX_VALUE;
		
		int n = ni();
		int[] x = na(n);
		Node[] nl = new Node[n];
		for(int i = 0;i < n;i++){
			nl[i] = new Node(x[i]);
			insert(root, nl[i]);
		}
		int m = ni();
		for(int q = 0;q < m;q++){
			int t = ni();
			if(t == 1){
				int p = ni()-1, d = ni();
				x[p] += d;
				remove(nl[p]);
				nl[p].v += d;
				insert(root, nl[p]);
			}else{
				
				int l = ni(), r = ni();
				long[] res = go(root, l, r);
				if(res == null){
					out.println(0L);
				}else{
					out.println(res[0] - (res[2]-1)*res[1]);
				}
//				tr("x", x); // -60 -48 28 50
//				tr(l, r, root.toString(""));
			}
		}
	}
	
	static public class Node
	{
		public int v; // value
		public int dup; // multiplicity
		public long p2; // 0*a+2*b+4*c+6*d
		public long sum; // a+b+c+d
		public long priority;
		public Node left, right, parent;
		public int gl, gr;
		
		public int count;
		
		public Node(int v)
		{
			this.v = v;
			this.dup = 1;
			this.parent = null;
			priority = gen.nextLong();
			count = 1;
			p2 = 0; sum = v;
			gl = gr = v;
		}
		
		public void update()
		{
			sum = 0;
			count = 0;
			p2 = 0;
			gl = gr = v;
			if(left != null){
				sum += left.sum;
				p2 += left.p2;
				count += left.count;
				gl = left.gl;
			}
			
			sum += v;
			p2 += (long)v*count*2L;
			count += dup;
			
			if(right != null){
				gr = right.gr;
				sum += right.sum;
				p2 += right.p2+2L*count*right.sum;
				count += right.count;
			}
		}
		
		public String toString()
		{
			StringBuilder sb = new StringBuilder();
//			if(dup > 1)throw new AssertionError();
			sb.append(String.format("v:%d, p2:%d, sum:%d, count:%d, [%d,%d], par:%s", v, p2, sum, count, gl, gr, parent == null ? "null" : parent.v));
			return sb.toString();
		}
		
		public String toString(String indent)
		{
			StringBuilder sb = new StringBuilder();
			if(left != null)sb.append(left.toString(indent + "  "));
			sb.append(indent).append(this).append("\n");
			if(right != null)sb.append(right.toString(indent + "  "));
			return sb.toString();
		}
	}
	
	protected static Random gen = new Random(1);
	
	public static int countLE(Node n, int x)
	{
		if(n == null)return 0;
		if(n.parent != null && n.parent.left == n && n.parent.v <= x){
			return n.count;
		}else{
			int ret = countLE(n.left, x);
			if(n.v <= x)ret += n.dup;
			if(n.v < x)ret += countLE(n.right, x);
			return ret;
		}
	}
	
	public static long[] go(Node n, int l, int r)
	{
		if(n == null)return null;
		if(l <= n.gl && n.gr <= r){
			return new long[]{n.p2, n.sum, n.count};
		}
		if(r < n.v){
			return go(n.left, l, r);
		}
		if(n.v < l){
			return go(n.right, l, r);
		}
		
		long[] L = null, R = null;
		if(l < n.v){
			L = go(n.left, l, n.v);
		}
		if(n.v < r){
			R = go(n.right, n.v, r);
		}
		
		long sum = 0, count = 0, p2 = 0;
		if(L != null){
			p2 += L[0];
			sum += L[1];
			count += L[2];
		}
		sum += n.v;
		p2 += 2L*n.v*count;
		count += n.dup;
		
		if(R != null){
			p2 += R[0] + 2L*count*R[1];
			sum += R[1];
			count += R[2];
		}
		return new long[]{p2, sum, count};
	}
	
	
	
//	public static Node first(Node n, int len)
//	{
//		if(n == null)return null;
//		Node res = first(n.left, len);
//		if(res != null)return res;
//		if(n.r-n.l >= len)return n;
//		return first(n.right, len);
//	}
//
//	public static Node ceil(Node n, int x)
//	{
//		if(n == null)return null;
//		if(n.l <= x && x < n.r)return n;
//		if(x < n.l){
//			Node res = ceil(n.left, x);
//			if(res == null)res = n;
//			return res;
//		}
//		return ceil(n.right, x);
//	}
	
	public static Node insert(Node n, int v)
	{
		if(n == null)return new Node(v);
		if(v == n.v){
			// already inserted
			n.dup++;
		}else if(v < n.v){
			n.left = insert(n.left, v);
			n.left.parent = n;
			if(n.priority < n.left.priority){
				n = rotateRight(n);
				if(n.right != null)n.right.update();
			}
		}else{
			n.right = insert(n.right, v);
			n.right.parent = n;
			if(n.priority < n.right.priority){
				n = rotateLeft(n);
				if(n.left != null)n.left.update();
			}
		}
		n.update();
		return n;
	}
	
	public static Node insert(Node n, Node x)
	{
		if(n == null){
			return x;
		}
		if(x.v == n.v){
			// already inserted
			n.dup++;
		}else if(x.v < n.v){
			n.left = insert(n.left, x);
			n.left.parent = n;
			if(n.priority < n.left.priority){
				n = rotateRight(n);
				if(n.right != null)n.right.update();
			}
		}else{
			n.right = insert(n.right, x);
			n.right.parent = n;
			if(n.priority < n.right.priority){
				n = rotateLeft(n);
				if(n.left != null)n.left.update();
			}
		}
		if(n.left == x || n.right == x)x.update();
		n.update();
		return n;
	}
	
	public static void disconnect(Node n)
	{
		if(n == null)return;
		n.left = n.right = n.parent = null;
		n.update();
	}
	
	public static void propagate(Node n)
	{
		for(;n != null;n = n.parent)n.update();
	}
	
	public static Node find(Node n, int x)
	{
		if(n == null)return null;
		if(x == n.v)return n;
		if(x < n.v)return find(n.left, x);
		return find(n.right, x);
	}
	
	public static Node remove(Node t)
	{
		while(true){
			if(t == null)return null;
			if(t.left == null && t.right == null){
				// leaf
				if(t.parent != null){
					if(t.equals(t.parent.left))t.parent.left = null;
					if(t.equals(t.parent.right))t.parent.right = null;
					propagate(t.parent);
				}
				disconnect(t);
				break;
			}else if(t.left != null && t.right != null){
				if(t.left.priority < t.right.priority){
					rotateRight(t);
				}else{
					rotateLeft(t);
				}
				continue;
			}else if(t.left != null){
				Node p = t.parent;
				Node c = t.left;
				if(p != null){
					if(t.equals(p.left))p.left = c;
					if(t.equals(p.right))p.right = c;
				}
				c.parent = p;
				disconnect(t);
				if(p != null)propagate(p);
				break;
			}else if(t.right != null){
				Node p = t.parent;
				Node c = t.right;
				if(p != null){
					if(t.equals(p.left))p.left = c;
					if(t.equals(p.right))p.right = c;
				}
				c.parent = p;
				disconnect(t);
				propagate(p);
				break;
			}
		}
		return t;
	}
	
	private static Node rotateRight(Node n)
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
	
	private static Node rotateLeft(Node n)
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
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}