//package round668;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
//		tr(make(new int[]{-5, 0, 2, 1, 3, 2, 2, 8, 1}));
		int n = ni(), m = ni();
		int[] a = na(n);
		for(int i = 0;i < n;i++){
			a[i] = i+1 - a[i];
		}
		SegmentTreeArray st = new SegmentTreeArray(a);
//		for(int[] row : st.node){
//			tr(row);
//		}

		for(int z = 0;z < m;z++){
			int l = ni(), r = ni();
			out.println(st.apply(l, n-r));
		}
	}

	public static class SegmentTreeArray {
		public int M, H, N;
		public int[][] node;

		public SegmentTreeArray(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;

			node = new int[M][];
			for(int i = 0;i < N;i++){
				node[H+i] = new int[]{0, Integer.MAX_VALUE / 3};
				if(a[i] >= 0) {
					node[H+i][1] = a[i];
				}
			}

			for(int i = H-1;i >= 1;i--){
				propagate(i);
			}
		}

		void propagate(int cur)
		{
			int[] L = node[2*cur], R = node[2*cur+1];
			if(R == null){
				node[cur] = L;
				return;
			}

			int[] C = new int[L.length + R.length-1];
			// L[0], L[1], L[2]
			// R[0], R[1], R[2]

			for(int k = 0;k < C.length;k++){
				int low = -1, high = k+1;
				while(high - low > 1){
					int h = high+low>>1;
					if((k-h >= R.length ? Integer.MAX_VALUE / 2 : R[k-h]-h) < (h >= L.length ? Integer.MAX_VALUE / 2 : L[h])){
						high = h;
					}else{
						low = h;
					}
				}
				C[k] = Math.min(
						(k-low < R.length && low < L.length && low >= 0 ? Math.max(R[k-low]-low, L[low]) : 999999999),
						(k-high < R.length && high < L.length && high <= k ? Math.max(R[k-high]-high, L[high]) : 999999999)
						);
			}
			// 0 0
			// 0 2

			// 0 0 1
			// k = p+q, max(R[k-p]-p, L[p])

			// t >= L[p]
			// t + p >= R[q]
			// t + p + q

//			tr(p, q, C.length, L, R);
//			while(p < L.length && p + q < C.length) {
//				C[p + q] = L[p];
//				p++;
//			}
//			while(q < R.length && p + q < C.length) {
//				C[p + q] = Math.max(R[q] - p, 0);
//				q++;
//			}
//			tr(L, R, C);
			node[cur] = C;
		}

		public int apply(int l, int r) {
//			tr();
			return apply(l, r, 0, 0, H, 1);
		}

		public static int lowerBound(int[] a, int v){ return lowerBound(a, 0, a.length, v); }
		public static int lowerBound(int[] a, int l, int r, int v)
		{
			if(l > r || l < 0 || r > a.length)throw new IllegalArgumentException();
			int low = l-1, high = r;
			while(high-low > 1){
				int h = high+low>>>1;
				if(a[h] >= v){
					high = h;
				}else{
					low = h;
				}
			}
			return high;
		}

		private void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }

		protected int apply(int l, int r, int v, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
//				tr(node[cur], cl, cr, v);
				int to = lowerBound(node[cur], v+1)-1;
				return v + to;
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					v = apply(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					v = apply(l, r, v, mid, cr, 2*cur+1);
				}
				return v;
			}
		}
	}

	static int[] make(int[] a)
	{
		int n = a.length;
		int[] ret = new int[n+1];
		int real = 0;
		for(int i = 0;i < n;i++){
			if(a[i] < 0){
				a[i] += Integer.MAX_VALUE / 3;
			}else{
				real++;
			}
		}
		for(int i = real+1;i <= n;i++){
			ret[i] = Integer.MAX_VALUE / 3;
		}
		StarrySkyTreeL sst = new StarrySkyTreeL(a);
		int f = 0;
//		tr(real, sst.toArray());
		int border = 0;
		while(f < real){
			while(true) {
				int ne = sst.firstle(0, border);
				if (ne == -1) break;
				f++;
				ret[f] = border;

				sst.add(ne, ne + 1, Integer.MAX_VALUE / 3);
				sst.add(ne + 1, n, -1);
			}
			border++;
		}
		return ret;
	}

	public static class StarrySkyTreeL {
		public int M, H, N;
		public long[] st;
		public long[] plus;
		public long I = Long.MAX_VALUE/4; // I+plus<long

		public StarrySkyTreeL(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			plus = new long[H];
		}

		public StarrySkyTreeL(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			plus = new long[H];
			Arrays.fill(st, H+N, M, I);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}

		private void propagate(int i)
		{
			st[i] = Math.min(st[2*i], st[2*i+1]) + plus[i];
		}

		public void add(int l, int r, long v){ if(l < r)add(l, r, v, 0, H, 1); }

		private void add(int l, int r, long v, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				if(cur >= H){
					st[cur] += v;
				}else{
					plus[cur] += v;
					propagate(cur);
				}
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					add(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					add(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}

		public long min(int l, int r){ return l >= r ? I : min(l, r, 0, H, 1);}

		private long min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				int mid = cl+cr>>>1;
				long ret = I;
				if(cl < r && l < mid){
					ret = Math.min(ret, min(l, r, cl, mid, 2*cur));
				}
				if(mid < r && l < cr){
					ret = Math.min(ret, min(l, r, mid, cr, 2*cur+1));
				}
				return ret + plus[cur];
			}
		}

		public void fall(int i)
		{
			if(i < H){
				if(2*i < H){
					plus[2*i] += plus[i];
					plus[2*i+1] += plus[i];
				}
				st[2*i] += plus[i];
				st[2*i+1] += plus[i];
				plus[i] = 0;
			}
		}

		public int firstle(int l, long v) {
			if(l >= H)return -1;
			int cur = H+l;
			for(int i = 1, j = Integer.numberOfTrailingZeros(H)-1;i <= cur;j--){
				fall(i);
				i = i*2|cur>>>j&1;
			}
			while(true){
				fall(cur);
				if(st[cur] <= v){
					if(cur >= H)return cur-H;
					cur = 2*cur;
				}else{
					cur++;
					if((cur&cur-1) == 0)return -1;
					cur = cur>>>Integer.numberOfTrailingZeros(cur);
				}
			}
		}

		public int lastle(int l, long v) {
			if(l < 0)return -1;
			int cur = H+l;
			for(int i = 1, j = Integer.numberOfTrailingZeros(H)-1;i <= cur;j--){
				fall(i);
				i = i*2|cur>>>j&1;
			}
			while(true){
				fall(cur);
				if(st[cur] <= v){
					if(cur >= H)return cur-H;
					cur = 2*cur+1;
				}else{
					if((cur&cur-1) == 0)return -1;
					cur = cur>>>Integer.numberOfTrailingZeros(cur);
					cur--;
				}
			}
		}

		public void addx(int l, int r, long v){
			if(l >= r)return;
			while(l != 0){
				int f = l&-l;
				if(l+f > r)break;
				if(f == 1){
					st[(H+l)/f] += v;
				}else{
					plus[(H+l)/f] += v;
				}
				l += f;
			}

			while(l < r){
				int f = r&-r;
				if(f == 1){
					st[(H+r)/f-1] += v;
				}else{
					plus[(H+r)/f-1] += v;
				}
				r -= f;
			}
		}

		public long minx(int l, int r){
			long lmin = I;
			if(l >= r)return lmin;
			if(l != 0){
				for(int d = 0;H>>>d > 0;d++){
					if(d > 0){
						int id = (H+l-1>>>d);
						lmin += plus[id];
					}
					if(l<<~d<0 && l+(1<<d) <= r){
						long v = st[H+l>>>d];
						if(v < lmin)lmin = v;
						l += 1<<d;
					}
				}
			}
			long rmin = I;
			for(int d = 0;H>>>d > 0;d++){
				if(d > 0 && r < H)rmin += plus[H+r>>>d];
				if(r<<~d<0 && l < r){
					long v = st[(H+r>>>d)-1];
					if(v < rmin)rmin = v;
					r -= 1<<d;
				}
			}
			long min = Math.min(lmin, rmin);
			return min;
		}

		public long[] toArray() { return toArray(1, 0, H, new long[H]); }

		private long[] toArray(int cur, int l, int r, long[] ret)
		{
			if(r-l == 1){
				ret[cur-H] = st[cur];
			}else{
				toArray(2*cur, l, l+r>>>1, ret);
				toArray(2*cur+1, l+r>>>1, r, ret);
				for(int i = l;i < r;i++)ret[i] += plus[cur];
			}
			return ret;
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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