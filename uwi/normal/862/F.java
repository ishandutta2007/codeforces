//package round435;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int Q = ni();
		char[][] ss = new char[n][];
		for(int i = 0;i < n;i++){
			ss[i] = ns().toCharArray();
		}
		int[] lcp = new int[n-1];
		for(int i = 0;i < n-1;i++){
			lcp[i] = lcp(ss[i], ss[i+1]);
		}
		
		SegmentTreeSegPos st = new SegmentTreeSegPos(lcp);
		
		SegmentTreeRMQ lens = new SegmentTreeRMQ(n+1);
		for(int i = 0;i < n;i++)lens.update(i, -ss[i].length);
		
		for(int z = 0;z < Q;z++){
			int t = ni();
			if(t == 1){
				int a = ni()-1, b = ni()-1;
				out.println(Math.max(-lens.minx(a, b+1), st.max(a, b)));
			}else{
				int x = ni()-1;
				char[] y = ns().toCharArray();
				ss[x] = y;
				lens.update(x, -y.length);
				if(x-1 >= 0){
					lcp[x-1] = lcp(ss[x-1], ss[x]);
					st.update(x-1, lcp[x-1]);
				}
				if(x+1 < n){
					lcp[x] = lcp(ss[x], ss[x+1]);
					st.update(x, lcp[x]);
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

	
	public static class SegmentTreeSegPos {
		public int M, H, N;
		public int[][] vasc;
		public int[][] pasc;
		public int[][] vdesc;
		public int[][] pdesc;
		public long[] maxs;
		public int[] lens;
		
		// one word
		public SegmentTreeSegPos(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			vasc = new int[M][];
			pasc = new int[M][];
			vdesc = new int[M][];
			pdesc = new int[M][];
			maxs = new long[M];
			lens = new int[M];
			for(int i = 0;i < N;i++){
				vasc[H+i] = new int[]{a[i]};
				pasc[H+i] = new int[]{0}; // first appeared
				vdesc[H+i] = new int[]{a[i]};
				pdesc[H+i] = new int[]{0}; // last appeared
				maxs[H+i] = a[i]*2;
				lens[H+i] = 1;
			}
			for(int i = N;i < H;i++){
				vasc[H+i] = new int[0];
				pasc[H+i] = new int[0];
				vdesc[H+i] = new int[0];
				pdesc[H+i] = new int[0];
				lens[H+i] = 0;
			}
			for(int i = H-1;i >= 1;i--){
				propagate(i);
			}
		}
		// v:desc
		// p:asc
		
		int[][] merge(int[] v1, int[] p1, int[] v2, int[] p2)
		{
			int[] rv = Arrays.copyOf(v2, v2.length+v1.length);
			int[] rp = Arrays.copyOf(p2, v2.length+v1.length);
			int p = v2.length;
			int last = p > 0 ? p2[p-1] : -1;
			for(int i = 0;i < v1.length;i++){
				if(p > 0 && rv[p-1] <= v1[i]){
					rp[p-1] = p2[p-1] + p1[i] + 1;
				}else if(p == 0 || rv[p-1] > v1[i]){
					rv[p] = v1[i];
					rp[p++] = last + p1[i] + 1;
				}
			}
//			tr(v1, p1, v2, p2, rv, rp);
			return new int[][]{
				Arrays.copyOf(rv, p),
				Arrays.copyOf(rp, p)
			};
		}
		
		private void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
		
		private void propagate(int i)
		{
			int[][] res = merge(vasc[2*i], pasc[2*i], vasc[2*i+1], pasc[2*i+1]);
			vasc[i] = res[0];
			pasc[i] = res[1];
			
			res = merge(vdesc[2*i+1], pdesc[2*i+1], vdesc[2*i], pdesc[2*i]);
			vdesc[i] = res[0];
			pdesc[i] = res[1];
			
			lens[i] = lens[2*i] + lens[2*i+1];
			maxs[i] = Math.max(maxs[2*i], maxs[2*i+1]);
			
			{
				int[] L = vasc[2*i], R = vdesc[2*i+1];
				int[] LP = pasc[2*i], RP = pdesc[2*i+1];
				int k = 0;
				for(int j = 0;j < L.length;j++){
					while(k < R.length && R[k] >= L[j]){
						k++;
					}
					if(k == 0)continue;
					int right = RP[k-1];
					int left = LP[j];
					long val = (long)(left+right+3) * L[j];
//					tr(L, R, LP, RP, left, right, val);
					maxs[i] = Math.max(maxs[i], val);
				}
			}
			{
				int[] R = vasc[2*i], L = vdesc[2*i+1];
				int[] RP = pasc[2*i], LP = pdesc[2*i+1];
				int k = 0;
				for(int j = 0;j < L.length;j++){
					while(k < R.length && R[k] >= L[j]){
						k++;
					}
					if(k == 0)continue;
					int right = RP[k-1];
					int left = LP[j];
					long val = (long)(left+right+3) * L[j];
					maxs[i] = Math.max(maxs[i], val);
				}
			}
		}
		
		public static int[] rev(int[] a)
		{
			int[] b = new int[a.length];
			for(int i = 0;i < a.length;i++)b[a.length-1-i] = a[i];
			return b;
		}

		
		public void update(int pos, int v)
		{
			vasc[H+pos][0] = v;
			vdesc[H+pos][0] = v;
			maxs[H+pos] = vasc[H+pos][0]*2;
			for(int i = H+pos>>>1;i >= 1;i >>>=1){
				propagate(i);
			}
		}
		
		public long max(int l, int r){ 
			gmax = Long.MIN_VALUE;
			
			max(l, r, 0, H, 1);
		return gmax;	
		}
		
		long gmax;
		
		private int[][] max(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				gmax = Math.max(gmax, maxs[cur]);
				return new int[][]{vasc[cur], pasc[cur], vdesc[cur], pdesc[cur]};
			}else{
				int mid = cl+cr>>>1;
				int[][] LX = null, RX = null;
				if(cl < r && l < mid){
					LX = max(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					RX = max(l, r, mid, cr, 2*cur+1);
				}
				
				if(LX == null)return RX;
				if(RX == null)return LX;
				
				int[][] ret = new int[4][];
				int[][] res = merge(LX[0], LX[1], RX[0], RX[1]);
				ret[0] = res[0];
				ret[1] = res[1];
				
				res = merge(RX[2], RX[3], LX[2], LX[3]);
				ret[2] = res[0];
				ret[3] = res[1];
				
				{
					int[] L = LX[0], R = RX[2];
					int[] LP = LX[1], RP = RX[3];
					int k = 0;
					for(int j = 0;j < L.length;j++){
						while(k < R.length && R[k] >= L[j]){
							k++;
						}
						if(k == 0)continue;
						int right = RP[k-1];
						int left = LP[j];
						long val = (long)(left+right+3) * L[j];
//						tr(L, R, LP, RP, left, right, L, val);
						gmax = Math.max(gmax, val);
					}
				}
				{
					int[] R = LX[0], L = RX[2];
					int[] RP = LX[1], LP = RX[3];
					int k = 0;
					for(int j = 0;j < L.length;j++){
						while(k < R.length && R[k] >= L[j]){
							k++;
						}
						if(k == 0)continue;
						int right = RP[k-1];
						int left = LP[j];
						long val = (long)(left+right+3) * L[j];
						gmax = Math.max(gmax, val);
					}
				}
				return ret;
			}
		}
	}

	
	int lcp(char[] a, char[] b)
	{
		for(int i = 0;i < a.length && i < b.length;i++){
			if(a[i] != b[i])return i;
		}
		return Math.min(a.length, b.length);
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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