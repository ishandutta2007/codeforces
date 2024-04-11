//package round397;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int Q = ni();
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			qs[i] = new int[]{ni()-1, ni()-1, i};
		}
		
		Arrays.sort(qs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1] - b[1];
			}
		});
		
		DynamicSegmentTreeRMQ stlast = new DynamicSegmentTreeRMQ(n, 30);
		SegmentTreeRMQ st = new SegmentTreeRMQ(n);
		
		int[] anss = new int[Q];
		
		int p = 0;
		for(int i = 0;i < n;i++){
			// x = a[i]
			// find largest j<i where a[j]>=a[i]
			{
				int py = 2000000009;
				while(py > a[i]){
					int j = -stlast.min(a[i], a[i]+(py-a[i]+1)/2);
					if(j < 0)break;
//					tr("U", j, a[i]-a[j]);
					st.updatemin(j, a[j] - a[i]);
					py = a[j];
				}
			}
			{
				int py = -1000000009;
				while(py < a[i]){
					int j = -stlast.min(a[i]-(a[i]-py)/2, a[i]+1);
					if(j < 0)break;
//					tr(j, a[i]-a[j]);
					st.updatemin(j, a[i] - a[j]);
					py = a[j];
				}
			}
			stlast.update(a[i], -i);
			while(p < Q && qs[p][1] <= i){
				anss[qs[p][2]] = st.minx(qs[p][0], i);
				p++;
			}
		}
		for(int v : anss){
			out.println(v);
		}
	}
	
	public static class DynamicSegmentTreeRMQ {
		public int[] vals;
		public int[] ls;
		public int[] rs;
		public int gen;
		public int height;
		public static final int I = Integer.MAX_VALUE;
		public static final int D = I; // default value
		
		public DynamicSegmentTreeRMQ(int Q, int height)
		{
			int bufsize = Q*height + 1;
			this.vals = new int[bufsize];
			this.ls = new int[bufsize];
			this.rs = new int[bufsize];
			Arrays.fill(this.ls, -1);
			Arrays.fill(this.rs, -1);
			this.height = height;
			gen = 0;
			vals[gen++] = D;
		}
		
		public void update(int x, int v)
		{
			updateDfs(0, x, v, height);
		}
		
		private int updateDfs(int id, int x, int v, int d)
		{
			if(id == -1)id = gen++;
			if(d == 0){
				vals[id] = v;
			}else{
				if(x<<~(d-1)<0){
					rs[id] = updateDfs(rs[id], x, v, d-1);
				}else{
					ls[id] = updateDfs(ls[id], x, v, d-1);
				}
				propagate(id);
			}
			return id;
		}
		
		private int val(int id){ return id == -1 ? D : vals[id]; }
		private int L(int id){ return id == -1 ? -1 : ls[id]; }
		private int R(int id){ return id == -1 ? -1 : rs[id]; }
		
		private void propagate(int id)
		{
			if(id == -1)return;
			vals[id] = Math.min(val(ls[id]), val(rs[id]));
		}
		
		public int min(int l, int r)
		{
			minval = I;
			min(l, r, height, 0);
			return minval;
		}
		// [0,1<<h)
		// 
		int minval;
		
		private void min(int l, int r, int d, int id)
		{
			if(l <= 0 && r >= 1<<d){
				minval = Math.min(minval, vals[id]);
			}else{
				// [l,r), [0,1<<d-1)
				if(l < 1<<d-1 && 0 < r && L(id) != -1){
					min(l, r, d-1, L(id));
				}
				if(l < 1<<d && 1<<d-1 < r && R(id) != -1){
					min(l-(1<<d-1), r-(1<<d-1), d-1, R(id));
				}
			}
		}
	}
	
	public static class SegmentTreeRMQ {
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
		
		public void updatemin(int pos, int x)
		{
			st[H+pos] = Math.min(st[H+pos], x);
			for(int i = (H+pos)>>>1;i >= 1;i >>>= 1)propagate(i);
		}
		
		private void propagate(int i)
		{
			st[i] = Math.min(st[2*i], st[2*i+1]);
		}
		
		public int minx(int l, int r){
			int min = Integer.MAX_VALUE;
			if(l >= r)return min;
			while(l != 0){
				int f = l&-l;
				if(l+f > r)break;
				int v = st[(H+l)/f];
				if(v < min)min = v;
				l += f;
			}
			
			while(l < r){
				int f = r&-r;
				int v = st[(H+r)/f-1];
				if(v < min)min = v;
				r -= f;
			}
			return min;
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
//		int n = 100, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(1000000000) + " ");
//		}
//		sb.append(0 + " ");
//		INPUT = sb.toString();

		
		
		
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F2().run(); }
	
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