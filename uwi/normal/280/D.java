//package round172;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

// 1613
public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		SegmentTreeNode st = new SegmentTreeNode(a);
		int Q = ni();
		for(int z = 0;z < Q;z++){
			int t = ni();
			if(t == 0){
				int x = ni()-1;
				int val = ni();
				st.update(x, val);
			}else{
				int l = ni()-1;
				int r = ni()-1;
				int K = ni();
				long ans = 0;
				SegmentTreeNode.Node[] hist = new SegmentTreeNode.Node[K];
				int p = 0;
				
				for(int i = 0;i < K;i++){
					SegmentTreeNode.Node max = st.max(l, r+1);
//					tr(i);
//					tr("M", max);
//					if(i == 1){
//						for(SegmentTreeNode.Node node : st.node){
//							tr(node);
//						}
//					}
					if(max.max <= 0)break;
					ans += max.max;
					hist[p++] = max;
					st.flip(l+max.argmaxl, l+max.argmaxr);
				}
				out.println(ans);
				while(p > 0){
					SegmentTreeNode.Node max = hist[p-1];
					st.flip(l+max.argmaxl, l+max.argmaxr);
					p--;
				}
			}
		}
	}
	
	// [l,r)
	public static class SegmentTreeNode {
		public int M, H, N;
		public Node[] node;
		
		private static class Node
		{
			long sum;
			int len;
			long max, min;
			int argmaxl, argmaxr;
			int argminl, argminr;
			long suffixMax, suffixMin;
			int suffixArgmax, suffixArgmin;
			long prefixMax, prefixMin;
			int prefixArgmax, prefixArgmin;
			int flip;
			
			public Node() {
			}
			
			public void flip()
			{
				long d;
				int e;
				sum = -sum;
				d = -max; max = -min; min = d;
				e = argmaxl; argmaxl = argminl; argminl = e;
				e = argmaxr; argmaxr = argminr; argminr = e;
				d = -prefixMax; prefixMax = -prefixMin; prefixMin = d;
				d = -suffixMax; suffixMax = -suffixMin; suffixMin = d;
				e = prefixArgmax; prefixArgmax = prefixArgmin; prefixArgmin = e;
				e = suffixArgmax; suffixArgmax = suffixArgmin; suffixArgmin = e;
			}
			
			public void init(int v)
			{
				max = v;
				min = v;
				argmaxl = 0;
				argmaxr = 1;
				argminl = 0;
				argminr = 1;
				suffixMax = suffixMin = v;
				suffixArgmax = suffixArgmin = 0;
				prefixMax = prefixMin = v;
				prefixArgmax = prefixArgmin = 1;
				sum = v;
				len = 1;
				flip = 1;
			}

			@Override
			public String toString() {
				return "Node [sum=" + sum + ", len=" + len + ", max=" + max + ", min=" + min + ", argmaxl=" + argmaxl
						+ ", argmaxr=" + argmaxr + ", argminl=" + argminl + ", argminr=" + argminr + ", suffixMax="
						+ suffixMax + ", suffixMin=" + suffixMin + ", suffixArgmax=" + suffixArgmax + ", suffixArgmin="
						+ suffixArgmin + ", prefixMax=" + prefixMax + ", prefixMin=" + prefixMin + ", prefixArgmax="
						+ prefixArgmax + ", prefixArgmin=" + prefixArgmin + ", flip=" + flip + "]";
			}
		}
		
		public SegmentTreeNode(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
			node = new Node[M];
			for(int i = 0;i < N;i++){
				node[H+i] = new Node();
				node[H+i].init(a[i]);
			}
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int cur)
		{
			node[cur] = prop2(node[2*cur], node[2*cur+1], node[cur]);
		}
		
		private Node prop2(Node L, Node R, Node C)
		{
			if(L != null && R != null){
				if(C == null)C = new Node();
				C.sum = L.sum + R.sum;
				C.len = L.len + R.len;
				
				{
					long lv = L.prefixMax;
					long rv = L.sum + R.prefixMax;
					if(lv > rv){
						C.prefixMax = lv; C.prefixArgmax = L.prefixArgmax;
					}else{
						C.prefixMax = rv; C.prefixArgmax = L.len + R.prefixArgmax;
					}
				}
				{
					long lv = L.prefixMin;
					long rv = L.sum + R.prefixMin;
					if(lv < rv){
						C.prefixMin = lv; C.prefixArgmin = L.prefixArgmin;
					}else{
						C.prefixMin = rv; C.prefixArgmin = L.len + R.prefixArgmin;
					}
				}
				{
					long lv = L.suffixMax + R.sum;
					long rv = R.suffixMax;
					if(lv > rv){
						C.suffixMax = lv; C.suffixArgmax = L.suffixArgmax;
					}else{
						C.suffixMax = rv; C.suffixArgmax = L.len + R.suffixArgmax;
					}
				}
				{
					long lv = L.suffixMin + R.sum;
					long rv = R.suffixMin;
					if(lv < rv){
						C.suffixMin = lv; C.suffixArgmin = L.suffixArgmin;
					}else{
						C.suffixMin = rv; C.suffixArgmin = L.len + R.suffixArgmin;
					}
				}
				
				C.min = Long.MAX_VALUE;
				C.argminl = C.argminr = -1;
				if(L.min < C.min){
					C.min = L.min;
					C.argminl = L.argminl;
					C.argminr = L.argminr;
				}
				if(R.min < C.min){
					C.min = R.min;
					C.argminl = L.len + R.argminl;
					C.argminr = L.len + R.argminr;
				}
				if(L.suffixMin + R.prefixMin < C.min){
					C.min = L.suffixMin + R.prefixMin;
					C.argminl = L.suffixArgmin;
					C.argminr = L.len + R.prefixArgmin;
				}
				
				C.max = Long.MIN_VALUE;
				C.argmaxl = C.argmaxr = -1;
				if(L.max > C.max){
					C.max = L.max;
					C.argmaxl = L.argmaxl;
					C.argmaxr = L.argmaxr;
				}
				if(R.max > C.max){
					C.max = R.max;
					C.argmaxl = L.len + R.argmaxl;
					C.argmaxr = L.len + R.argmaxr;
				}
				if(L.suffixMax + R.prefixMax > C.max){
					C.max = L.suffixMax + R.prefixMax;
					C.argmaxl = L.suffixArgmax;
					C.argmaxr = L.len + R.prefixArgmax;
				}
				
				if(C.flip == 0)C.flip = 1;
				if(C.flip == -1)C.flip();
				
				return C;
			}else if(L != null){
				return prop1(L, C);
			}else if(R != null){
				return prop1(R, C);
			}else{
				return null;
			}
		}
		
		private void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
		
		private Node prop1(Node L, Node C)
		{
			if(C == null)C = new Node();
			C.argmaxl = L.argmaxl;
			C.argmaxr = L.argmaxr;
			C.argminl = L.argminl;
			C.argminr = L.argminr;
			C.sum = L.sum;
			C.len = L.len;
			C.max = L.max;
			C.min = L.min;
			C.suffixArgmax = L.suffixArgmax;
			C.suffixArgmin = L.suffixArgmin;
			C.prefixArgmax = L.prefixArgmax;
			C.prefixArgmin = L.prefixArgmin;
			C.flip = 1;
			C.suffixMax = L.suffixMax;
			C.suffixMin = L.suffixMin;
			C.prefixMax = L.prefixMax;
			C.prefixMin = L.prefixMin;
//			try {
//				for(Field f : L.getClass().getDeclaredFields()){
//					f.set(C, f.get(L));
//				}
//				C.flip = 1;
//			} catch (SecurityException | IllegalArgumentException | IllegalAccessException e) {
//				e.printStackTrace();
//			}
			return C;
		}
		
		public void update(int pos, int v) {
			node[H+pos].init(v);
			for(int i = H+pos>>>1;i >= 1;i>>>=1)propagate(i);
		}
		
		public void flip(int l, int r) {
			flip(l, r, 0, H, 1);
		}
		
		protected void flip(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				node[cur].flip = -node[cur].flip;
				node[cur].flip();
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					flip(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					flip(l, r, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public Node max(int l, int r) {
			Node N = max(l, r, 0, H, 1);
			return N;
		}
		
		protected Node max(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return prop1(node[cur], null);
			}else{
				Node L = null, R = null;
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					L = max(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					R = max(l, r, mid, cr, 2*cur+1);
				}
				Node C = prop2(L, R, null);
//				tr("L", L);
//				tr("R", R);
//				tr("C", C, node[cur].flip);
				if(node[cur].flip == -1)C.flip();
				return C;
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