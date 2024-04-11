//package goodbye2014;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] xs = new int[n];
		int[] hs = new int[n];
		for(int i = 0;i < n;i++){
			xs[i] = ni();
			hs[i] = ni();
		}
		
		SegmentTreeRMQ st = new SegmentTreeRMQ(n);
		int[] reach = new int[n];
		for(int i = n-1;i >= 0;i--){
			int to = xs[i] + hs[i];
			int ind = Arrays.binarySearch(xs, to);
			if(ind < 0)ind = -ind-2;
			// [i,ind]
			int re = -st.min(i, ind+1);
			reach[i] = Math.max(re, to);
			st.update(i, (int)-reach[i]);
		}
		
		int[] par = new int[n];
		long[] cost = new long[n];
		for(int i = n-1;i >= 0;i--){
			int ind = Arrays.binarySearch(xs, (int)reach[i]);
			assert ind < 0;
			ind = -ind-1;
			if(ind >= n){
				par[i] = -1;
				cost[i] = 0;
			}else{
				par[i] = ind;
				cost[i] = xs[ind]-reach[i];
			}
		}
		scost = new long[20][n];
		scost[0] = cost;
		int[][] snext = sparseNext(par);
		
		for(int Q = ni();Q >= 1;Q--){
			int L = ni()-1, R = ni()-1;
			long ret = 0;
			for(int d = 19;d >= 0;d--){
				int nex = snext[d][L];
				if(nex == -1 || nex > R){
				}else{
					ret += scost[d][L];
					L = nex;
				}
			}
			out.println(ret);
		}
	}
	
	long[][] scost;
	
	public int[][] sparseNext(int[] f)
	{
		int n = f.length;
		final int m = 20; // 
		int[][] sf = new int[m][n];
		sf[0] = Arrays.copyOf(f, n);
		for(int i = 1;i < m;i++){
			for(int j = 0;j < n;j++){
				sf[i][j] = sf[i-1][j] == -1 ? -1 : sf[i-1][sf[i-1][j]];
				if(sf[i][j] != -1){
					scost[i][j] = scost[i-1][sf[i-1][j]] + scost[i-1][j];
				}
			}
		}
		return sf;
	}
	
	public class SegmentTreeRMQ {
		public int M, H, N;
		public int[] st;
		
		public SegmentTreeRMQ(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			Arrays.fill(st, 0, M, Integer.MAX_VALUE);
		}
		
		public SegmentTreeRMQ(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			Arrays.fill(st, H+N, M, Integer.MAX_VALUE);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		public void update(int pos, int x)
		{
			st[H+pos] = x;
			for(int i = (H+pos)>>>1;i >= 1;i >>>= 1)propagate(i);
		}
		
		private void propagate(int i)
		{
			st[i] = Math.min(st[2*i], st[2*i+1]);
		}
		
		public int min(int l, int r){ return l >= r ? 0 : min(l, r, 0, H, 1);}
		
		private int min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				int mid = cl+cr>>>1;
				int ret = Integer.MAX_VALUE;
				if(cl < r && l < mid){
					ret = Math.min(ret, min(l, r, cl, mid, 2*cur));
				}
				if(mid < r && l < cr){
					ret = Math.min(ret, min(l, r, mid, cr, 2*cur+1));
				}
				return ret;
			}
		}
		
		public int firstle(int l, int v) {
			int cur = H+l;
			while(true){
				if(st[cur] <= v){
					if(cur < H){
						cur = 2*cur;
					}else{
						return cur-H;
					}
				}else{
					cur++;
					if((cur&cur-1) == 0)return -1;
					if((cur&1)==0)cur>>>=1;
				}
			}
		}
		
		public int lastle(int l, int v) {
			int cur = H+l;
			while(true){
				if(st[cur] <= v){
					if(cur < H){
						cur = 2*cur+1;
					}else{
						return cur-H;
					}
				}else{
					if((cur&cur-1) == 0)return -1;
					cur--;
					if((cur&1)==1)cur>>>=1;
				}
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