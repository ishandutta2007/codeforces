//package round284;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		
		SegmentTreeArray st = new SegmentTreeArray(a);
		for(int Q = ni();Q >= 1;Q--){
			char com = nc();
			if(com == 'C'){
				int id = ni()-1, v = ni();
				st.update(id, v);
			}else if(com == 'A'){
				int l = ni()-1, r = ni()-1;
				out.println(st.apply(l, r));
			}
		}
	}
	
	public static class SegmentTreeArray {
		public int M, H, N;
		public int[][] node;
		public int K = 60;
		
		public int[][] preset = new int[7][];
		
		public SegmentTreeArray(int[] a)
		{
			for(int i = 2;i <= 6;i++){
				preset[i] = new int[60];
				Arrays.fill(preset[i], 1);
				for(int j = 0;j < 60;j+=i){
					preset[i][j] = 2;
				}
			}
			
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
			node = new int[M][];
			for(int i = 0;i < N;i++){
				node[H+i] = preset[a[i]];
			}
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int cur)
		{
			node[cur] = prop2(node[2*cur], node[2*cur+1], node[cur]);
		}
		
		private int[] prop2(int[] L, int[] R, int[] C)
		{
			if(L != null && R != null){
				if(C == null)C = new int[K];
				for(int i = 0;i < K;i++){
					int j = i + L[i];
					if(j >= K)j %= K;
					C[i] = R[j] + L[i];
				}
				return C;
			}else if(L != null){
				return prop1(L, C);
			}else if(R != null){
				return prop1(R, C);
			}else{
				return null;
			}
		}
		
		private int[] prop1(int[] L, int[] C)
		{
			if(C == null)C = new int[K];
			for(int i = 0;i < K;i++){
				C[i] = L[i];
			}
			return C;
		}
		
		public void update(int x, int v) {
			node[H+x] = preset[v];
			for(int i = H+x>>>1;i >= 1;i>>>=1)propagate(i);
		}
		
		int time = 0;
		
		public int apply(int l, int r) {
			time = 0;
			apply(l, r, 0, H, 1);
			return time;
		}
		
		protected void apply(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				time += node[cur][time%K];
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					apply(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					apply(l, r, mid, cr, 2*cur+1);
				}
			}
		}
//		private void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
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