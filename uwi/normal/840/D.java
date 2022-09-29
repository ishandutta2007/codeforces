//package round429;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

// 214900
public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		int[] a = na(n);
		Node[] es = makeEntries(a);
		for(int z = 0;z < Q;z++){
			int l = ni()-1, r = ni()-1;
			int K = ni();
			out.println(go(es[l], es[r+1], (r-l+1)/K+1));
		}
	}
	
	public static int go(Node X, Node Y, int B)
	{
		Node XL = X.left, YL = Y.left;
		if(XL != null && B <= YL.des - XL.des){
			int res = go(XL, YL, B);
			if(res != -1)return res;
		}
		if(B <= Y.count - X.count){
			return X.num;
		}
		
		Node XR = X.right, YR = Y.right;
		if(XR != null && B <= YR.des - XR.des){
			int res = go(XR, YR, B);
			if(res != -1)return res;
		}
		return -1;
	}
	
	public static class Node
	{
		public int num;
		public int count;
		public int des;
		public Node left, right;
		
		public Node(int num, int count) {
			this.num = num;
			this.count = count;
			des = count;
		}
		
		public Node clone()
		{
			Node ret = new Node(num, count);
			ret.left = this.left;
			ret.right = this.right;
			return ret;
		}
		
		public void update()
		{
			des = count;
			if(left != null)des += left.des;
			if(right != null)des += right.des;
		}
		
		public Node insert(int x)
		{
			if(x < num){
				left = left.clone();
				left.insert(x);
			}else if(x > num){
				right = right.clone();
				right.insert(x);
			}else{
				count++; // e is always cloned.
			}
			update();
			return this;
		}
		
		public Node erase(int x)
		{
			if(x < num){
				left = left.clone();
				left.erase(x);
			}else if(x > num){
				right = right.clone();
				right.erase(x);
			}else{
				count--; // e is always cloned.
			}
			update();
			return this;
		}
		
		public String toString(String indent) {
			StringBuilder builder = new StringBuilder();
			if(left != null){
				builder.append(left.toString(indent + "  "));
			}
			builder.append("[num=");
			builder.append(num);
			builder.append(", count=");
			builder.append(count);
			builder.append(", des=");
			builder.append(des);
			builder.append("]\n");
			if(right != null){
				builder.append(right.toString(indent + "  "));
			}
			return builder.toString();
		}
	}
	
	// TODO CHECK
	public static int kth(Node X, Node Y, int K)
	{
		while(K > 0){
			Node XL = X.left, YL = Y.left;
			if(XL != null && K < YL.des - XL.des){
				X = XL; Y = YL;
			}else{
				if(XL != null){
					K -= YL.des - XL.des;
				}
				if(K < Y.count - X.count){
					return Y.num;
				}else{
					K -= Y.count - X.count;
					X = X.right; Y = Y.right;
				}
			}
		}
		return Integer.MIN_VALUE;
	}
	
	public static Node[] makeEntries(int[] a)
	{
		int n = a.length;
		Node[] entry = new Node[n+1];
		entry[0] = buildPBST(a);
		for(int i = 0;i < n;i++){
			entry[i+1] = entry[i].clone().insert(a[i]);
		}
		return entry;
	}
	
	public static Node buildPBST(int[] oa){
		int n = oa.length;
		int[] a = Arrays.copyOf(oa, n);
		Arrays.sort(a);
		int[] b = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(i == 0 || a[i] != a[i-1]){
				b[p++] = a[i];
			}
		}
		b = Arrays.copyOf(b, p);
		return dfs(0, p, b);
	}
	
	private static Node dfs(int l, int r, int[] b)
	{
		if(l == r)return null;
		int m = l+r>>>1;
		Node ret = new Node(b[m], 0);
		ret.left = dfs(l, m, b);
		ret.right = dfs(m+1, r, b);
		return ret;
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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