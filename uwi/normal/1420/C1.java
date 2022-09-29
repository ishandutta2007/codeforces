//package round672;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C1 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--)go();
	}

	void go()
	{
		int n = ni(), Q = ni();
		int[] a = na(n);
		SegmentTreeArray st = new SegmentTreeArray(a);
		out.println(Math.max(st.node[1][0], st.node[1][1]));
		for(int z = 0;z < Q;z++){
			int l = ni()-1, r = ni()-1;
		}
	}

	public static class SegmentTreeArray {
		public int M, H, N;
		public long[][] node;

		public SegmentTreeArray(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;

			node = new long[M][];
			for(int i = 0;i < N;i++){
				// ++ +- -+ --
				node[H+i] = new long[]{0, a[i], -a[i], 0};
			}
			for(int i = H-1;i >= 1;i--)propagate(i);
		}

		private void propagate(int cur)
		{
			node[cur] = prop2(node[2*cur], node[2*cur+1], node[cur]);
		}

		private long[] prop2(long[] L, long[] R, long[] C)
		{
			if(L != null && R != null){
				if(C == null)C = new long[4];
				C[0] = Math.max(L[0] + R[0], L[1] + R[2]);
				C[1] = Math.max(L[0] + R[1], L[1] + R[3]);
				C[2] = Math.max(L[2] + R[0], L[3] + R[2]);
				C[3] = Math.max(L[2] + R[1], L[3] + R[3]);
				return C;
			}else if(L != null){
				return prop1(L, C);
			}else if(R != null){
				return prop1(R, C);
			}else{
				return null;
			}
		}

		private long[] prop1(long[] L, long[] C)
		{
			if(C == null)C = new long[4];
			System.arraycopy(L, 0, C, 0, 4);
			return C;
		}

		public void add(int x, int v) {
			// TODO leaf
			//		node[H+x] = nex;
			for(int i = H+x>>>1;i >= 1;i>>>=1)propagate(i);
		}

		public long sum(int l, int r) {
			long[] N = sum(l, r, 0, H, 1);
			// TODO N
			return N == null ? 0 : Math.max(N[0], N[1]);
		}

		protected long[] sum(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return node[cur];
			}else{
				long[] L = null, R = null;
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					L = sum(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					R = sum(l, r, mid, cr, 2*cur+1);
				}
				return prop2(L, R, null);
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
	
	public static void main(String[] args) throws Exception { new C1().run(); }
	
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