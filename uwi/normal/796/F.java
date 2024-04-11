//package round408x;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class F3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	// a
	// a
	// 11
	// S
	// 
	// S
	// 
	
	int LIM = 1000000000;
//	int LIM = 20;
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] qs = new int[m][];
		for(int i = 0;i < m;i++){
			int t = ni();
			if(t == 1){
				qs[i] = new int[]{1, ni()-1, ni()-1, ni()};
			}else{
				qs[i] = new int[]{2, ni()-1, ni()};
			}
		}
		
		long[] a = new long[n];
		Arrays.fill(a, Long.MAX_VALUE);
		SegmentTreeWeakOverwriteRAddRMQL st = new SegmentTreeWeakOverwriteRAddRMQL(a);
		
		for(int[] q : qs){
			if(q[0] == 1){
				st.weakupdate(q[1], q[2]+1, q[3]);
			}else{
				if(a[q[1]] == Long.MAX_VALUE){
					a[q[1]] = st.min(q[1], q[1]+1);
				}
			}
		}
		for(int i = 0;i < n;i++){
			if(a[i] == Long.MAX_VALUE){
				a[i] = st.min(i, i+1);
			}
		}
//		tr(a);
		
		// a is maximum 
		
		// simulate
		long[] b = Arrays.stream(a).map(x -> -x).toArray();
		SegmentTreeRMQL st2 = new SegmentTreeRMQL(b);
		for(int[] q : qs){
			if(q[0] == 1){
//				tr(q, st2.min(q[1], q[2]+1) ,q[3]);
				if(-st2.min(q[1], q[2]+1) != q[3]){
					out.println("NO");
					return;
				}
			}else{
				st2.update(q[1], -q[2]);
			}
		}
		
		int[][] ys = new int[m][];
		int yp = 0;
		for(int i = 0;i < m;i++){
			if(qs[i][0] == 1){
				ys[yp++] = new int[]{qs[i][3], i};
			}
		}
		Arrays.sort(ys, 0, yp, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		int[] yv = new int[yp];
		for(int i = 0;i < yp;i++)yv[i] = ys[i][0];
		
		int[][] qqs = new int[m][];
		int qp = 0;
		int[] z = new int[n];
		Arrays.fill(z, -1);
		int[] times = new int[n]; // [value, duration the value is alive]
		
		int[][] mqs = new int[m][];
		int mp = 0;
		for(int i = 0;i < m;i++){
			int[] q = qs[i];
			if(q[0] == 1){
				mqs[mp++] = new int[]{q[3], i}; // [value, when]
			}else{
				if(z[q[1]] != -1){
					qqs[qp++] = new int[]{z[q[1]], times[q[1]], i, q[1]}; // [value, fromwhen, towhen, which]
				}
				z[q[1]] = q[2];
				times[q[1]] = i;
			}
		}
		for(int i = 0;i < n;i++){
			if(z[i] != -1){
				qqs[qp++] = new int[]{z[i], times[i], m, i};
			}
		}
		
		Arrays.sort(qqs, 0, qp, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		Arrays.sort(mqs, 0, mp, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		
		boolean[] fmax = new boolean[yp];
		int j = 0;
		for(int i = 0;i < mp;i++){
			int val = mqs[i][0];
			while(j < qp && qqs[j][0] < val)j++;
			int k = j;
			while(k < qp && qqs[k][0] <= val)k++;
			
			// [j,k)
			for(int l = j;l < k;l++){
				if(qqs[l][1] <= mqs[i][1] && mqs[i][1] < qqs[l][2] && qs[mqs[i][1]][1] <= qqs[l][3] && qqs[l][3] <= qs[mqs[i][1]][2]){
					fmax[Arrays.binarySearch(yv, mqs[i][0])] = true;
				}
			}
			
			k = j;
		}
		
		int[][] lims = new int[n][];
		for(int i = 0;i < n;i++){
			lims[i] = new int[]{(int)Math.min(a[i], LIM), i};
		}
		Arrays.sort(lims, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
//		
//		tr(yv);
//		tr(fmax);
//		tr(lims);
		
//		tr(yv);
//		tr(fmax);
		long[] ret = new long[n];
		long V = 0;
		for(int i = n-1;i >= 0;i--){
			long lim = lims[i][0];
			int w = Arrays.binarySearch(yv, (int)lim);
			if(w >= 0 && !fmax[w]){
				V |= lim;
			}
		}
		for(int i = n-1;i >= 0;i--){
			long lim = lims[i][0];
			int w = Arrays.binarySearch(yv, (int)lim);
			if(w >= 0 && !fmax[w]){
				fmax[w] = true;
				V |= lim;
				ret[lims[i][1]] = lim;
				continue;
			}
			long nval = 0;
			for(int d = 29;d >= 0;d--){
				if(lim >= 1L<<d && V<<~d>=0){
					V |= 1L<<d;
					nval += 1L<<d;
					lim -= 1L<<d;
				}
			}
			ret[lims[i][1]] = nval;
		}
		
//		tr(ret);
		out.println("YES");
		long O = 0;
		for(int i = 0;i < n;i++){
//			O |= ret[i];
			out.print(ret[i] + " ");
		}
//		out.println(O);
		out.println();
	}
	
	public static class SegmentTreeRMQL {
		public int M, H, N;
		public long[] st;
		
		public SegmentTreeRMQL(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			Arrays.fill(st, 0, M, Long.MAX_VALUE);
		}
		
		public SegmentTreeRMQL(long[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			Arrays.fill(st, H+N, M, Long.MAX_VALUE);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		public void update(int pos, long x)
		{
			st[H+pos] = x;
			for(int i = (H+pos)>>>1;i >= 1;i >>>= 1)propagate(i);
		}
		
		private void propagate(int i)
		{
			st[i] = Math.min(st[2*i], st[2*i+1]);
		}
		
		public long minx(int l, int r){
			long min = Long.MAX_VALUE;
			if(l >= r)return min;
			while(l != 0){
				int f = l&-l;
				if(l+f > r)break;
				long v = st[(H+l)/f];
				if(v < min)min = v;
				l += f;
			}
			
			while(l < r){
				int f = r&-r;
				long v = st[(H+r)/f-1];
				if(v < min)min = v;
				r -= f;
			}
			return min;
		}
		
		public long min(int l, int r){ return l >= r ? 0 : min(l, r, 0, H, 1);}
		
		private long min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				int mid = cl+cr>>>1;
				long ret = Long.MAX_VALUE;
				if(cl < r && l < mid){
					ret = Math.min(ret, min(l, r, cl, mid, 2*cur));
				}
				if(mid < r && l < cr){
					ret = Math.min(ret, min(l, r, mid, cr, 2*cur+1));
				}
				return ret;
			}
		}
		
		public int firstle(int l, long v) {
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
		
		public int lastle(int l, long v) {
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


	
	public static class SegmentTreeWeakOverwriteRAddRMQL {
		public int M, H, N;
		public long[] st;
		public long[] plus;
		public long[] cover;
		private long I = Integer.MAX_VALUE;
		
		public SegmentTreeWeakOverwriteRAddRMQL(long[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			cover = new long[H];
			Arrays.fill(cover, I);
			plus = new long[H];
			st = new long[M];
			Arrays.fill(st, I);
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			for(int i = H-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		private void propagate(int i)
		{
			st[i] = Math.min(st[2*i], st[2*i+1]) + plus[i];
			if(cover[i] != I){
				st[i] = Math.min(st[i], cover[i]);
			}
		}
		
		private void fall(int cur)
		{
			if(2*cur >= H){
				st[2*cur] += plus[cur];
				st[2*cur+1] += plus[cur];
			}else{
				for(int i = 2*cur;i < 2*cur+2;i++){
					if(cover[i] != I){
						cover[i] += plus[cur];
					}
					plus[i] += plus[cur];
					propagate(i);
				}
			}
			if(cover[cur] != I){
				if(2*cur >= H){
					if(cover[cur] < st[2*cur])st[2*cur] = cover[cur];
					if(cover[cur] < st[2*cur+1])st[2*cur+1] = cover[cur];
				}else{
					if(cover[2*cur] == I || cover[cur] < cover[2*cur])cover[2*cur] = cover[cur];
					if(cover[2*cur+1] == I || cover[cur] < cover[2*cur+1])cover[2*cur+1] = cover[cur];
					propagate(2*cur);
					propagate(2*cur+1);
				}
			}
			
			plus[cur] = 0;
			cover[cur] = I;
		}
		
		
		
		public void add(int l, int r, long v){ add(l, r, v, 0, H, 1); }
		
		private void add(int l, int r, long v, int cl, int cr, int cur)
		{
			// a1 c1
			// a2 c2
			// max(c2+a1,c1)
			// a1+a2 
			
			if(l <= cl && cr <= r){
				if(cr == cl+1){
					st[cur] += v;
				}else{
					plus[cur] += v;
					if(cover[cur] != I){
						cover[cur] += v;
					}
					propagate(cur);
				}
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
		
		public void weakupdate(int l, int r, long v){ weakupdate(l, r, v, 0, H, 1); }
		
		private void weakupdate(int l, int r, long v, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				if(cr == cl+1){
					st[cur] = Math.min(st[cur], v);
				}else{
					if(cover[cur] == I || v < cover[cur]){
						cover[cur] = v;
						propagate(cur);
					}
				}
			}else{
				int mid = cl+cr>>>1;
				fall(cur);
				if(cl < r && l < mid){
					weakupdate(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					weakupdate(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public long min(int l, int r){ return min(l, r, 0, H, 1); }
		
		private long min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				int mid = cl+cr>>>1;
				long L = I, R = I;
				if(cl < r && l < mid){
					L = min(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					R = min(l, r, mid, cr, 2*cur+1);
				}
				long ret = Math.min(L, R) + plus[cur];
				if(cover[cur] != I)ret = Math.min(ret, cover[cur]);
				return ret;
			}
		}
		
		public long[] toArray() { return toArray(1, 0, H, new long[H]); }
		
		private long[] toArray(int cur, int l, int r, long[] ret)
		{
			if(r-l == 1){
				ret[cur-H] = st[cur];
			}else{
				toArray(2*cur, l, l+r>>>1, ret);
				toArray(2*cur+1, l+r>>>1, r, ret);
				for(int i = l;i < r;i++){
					ret[i] += plus[cur];
					if(cover[cur] != I)ret[i] = Math.min(ret[i], cover[cur]);
				}
			}
			return ret;
		}
		
		public void trtree()
		{
			for(int d = 1;d < H;d*=2){
				for(int i = 0;i < d;i++){
					if(cover[d+i] != I){
						System.out.printf("[%d|%d(%d)] ", st[d+i], plus[d+i], cover[d+i]);
					}else{
						System.out.printf("[%d|%d] ", st[d+i], plus[d+i]);
					}
				}
				System.out.println();
			}
			for(int i = 0;i < H;i++){
				System.out.printf("[%d] ", st[H+i]);
			}
			System.out.println();
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
	
	public static void main(String[] args) throws Exception { new F3().run(); }
	
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