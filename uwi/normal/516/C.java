//package round292;
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
		int n = ni(), Q = ni();
		int[] a = na(n);
		int[] b = na(n);
		long[] ds = new long[2*n+1];
		for(int i = 0;i < 2*n;i++){
			ds[i+1] = ds[i] + a[i%n];
		}
		long[] u = new long[4*n+3];
		for(int i = 0;i < 2*n;i++){
			u[2*i+0] = ds[i] + 2L*b[i%n];
			u[2*i+1] = ds[i] - 2L*b[i%n];
		}

		RMSQ rmsq = RMSQ.preprocess(u);
		for(int i = 0;i < Q;i++){
			int f = ni()-1, t = ni()-1;
			if(f <= t){
				int[] arg = rmsq.srmsq(2*(t+1), 2*(f+n)-1);
				out.println(u[arg[1]] - u[arg[0]]);
			}else{
				int[] arg = rmsq.srmsq(2*(t+1), 2*f-1);
				out.println(u[arg[1]] - u[arg[0]]);
			}
		}
	}
	
	public static class RMSQ {
		// Stock Span Problem
		public static int[] enumPrevWall(long[] a)
		{
			int n = a.length;
			int[] L = new int[n];
			L[0] = -1;
			for(int i = 1;i < n;i++){
				L[i] = i-1;
				while(L[i] > 0 && a[L[i]] < a[i])L[i] = L[L[i]];
			}
			return L;
		}
		
		public static int[] enumPrevWall(int[] a)
		{
			int n = a.length;
			int[] L = new int[n];
			for(int i = 0;i < n;i++){
				L[i] = i-1;
				while(L[i] >= 0 && a[L[i]] < a[i])L[i] = L[L[i]];
			}
			return L;
		}
		
		public static long[] rmq(long[] a, int[] L)
		{
			int n = a.length;
			int[] fs = new int[n];
			for(int i = 1;i < n;i++){
				fs[Math.max(L[i],0)]++;
			}
			int[][] g = new int[n][];
			for(int i = 0;i < n;i++){
				g[i] = new int[fs[i]];
			}
			for(int i = 1;i < n;i++){
				int v = Math.max(L[i], 0);
				g[v][--fs[v]] = i;
			}
			int[] stack = new int[n];
			long[] mins = new long[n];
			Arrays.fill(mins, Long.MAX_VALUE);
			int sp = 0;
			for(int i = 0;i < n-1;i++){
				for(int e : g[i]){
					stack[sp++] = e;
				}
				mins[stack[sp-1]] = Math.min(mins[stack[sp-1]], a[i]);
//				U.tr(Arrays.copyOf(stack, sp));
				if(stack[sp-1] != i+1)throw new RuntimeException();
				sp--;
//				U.tr(sp, i);
				if(sp-1 >= 0){
					mins[stack[sp-1]] = Math.min(mins[stack[sp-1]], mins[stack[sp]]);
				}
			}
			return mins;
		}
		
		// right argmin
		public static int[] argrmq(long[] a, int[] L)
		{
			int n = a.length;
			int[] fs = new int[n];
			for(int i = 1;i < n;i++){
				fs[Math.max(L[i],0)]++;
			}
			int[][] g = new int[n][];
			for(int i = 0;i < n;i++){
				g[i] = new int[fs[i]];
			}
			for(int i = 1;i < n;i++){
				int v = Math.max(L[i], 0);
				g[v][--fs[v]] = i;
			}
			int[] stack = new int[n];
			long[] mins = new long[n];
			int[] minpos = new int[n];
			Arrays.fill(mins, Long.MAX_VALUE);
			Arrays.fill(minpos, -1);
			int sp = 0;
			for(int i = 0;i < n-1;i++){
				for(int e : g[i]){
					stack[sp++] = e;
				}
				if(a[i] <= mins[stack[sp-1]]){
					mins[stack[sp-1]] = a[i];
					minpos[stack[sp-1]] = i;
				}
				if(stack[sp-1] != i+1)throw new RuntimeException();
				sp--;
				if(sp-1 >= 0){
					if(mins[stack[sp]] < mins[stack[sp-1]] || mins[stack[sp]] == mins[stack[sp-1]] && minpos[stack[sp]] > minpos[stack[sp-1]]){
						mins[stack[sp-1]] = mins[stack[sp]];
						minpos[stack[sp-1]] = minpos[stack[sp]];
					}
				}
			}
			return minpos;
		}
		
		public long[] a;
		public long[] cum;
		public int[] L;
		public int[] P;
		public long[] M;
		public SegmentTreeRMQPos MST, CST, ICST;
		
		// [l,r)
		public int[] srmsq(int l, int r)
		{
			l++;
			int m = MST.argmin(l, r+1);
			if(P[m] < l){
				int r1 = CST.argmin(l-1, m-1+1)+1;
				int r2 = MST.argmin(m+1, r+1);
				if(cum[m]-cum[r1-1] < M[r2]){
					return new int[]{P[r2]-1, r2};
				}else{
					return new int[]{r1-1, m};
				}
			}else{
				return new int[]{P[m]-1, m};
			}
		}
		
		public static RMSQ preprocess(long[] cum)
		{
			int n = cum.length-1;
			int[] L = enumPrevWall(cum);
			int[] P = argrmq(cum, L);
			for(int i = 0;i <= n;i++){
				P[i]++;
			}
			long[] M = new long[n+1];
			for(int i = 1;i <= n;i++){
				M[i] = cum[i] - cum[P[i]-1];
			}
			RMSQ ret = new RMSQ();
			ret.cum = cum;
			ret.L = L;
			ret.P = P;
			ret.M = M;
			long[] im = new long[n+1];
			for(int i = 0;i < n+1;i++)im[i] = -M[i];
			ret.MST = new SegmentTreeRMQPos(im);
			ret.CST = new SegmentTreeRMQPos(cum);
			long[] icum = new long[n+1];
			for(int i = 0;i < n+1;i++)icum[i] = -cum[i];
			ret.ICST = new SegmentTreeRMQPos(icum);
			return ret;
		}
		
		public static int[] L(int[] a)
		{
			int n = a.length;
			int[] stack = new int[n];
			int[] ret = new int[n];
			int p = 0;
			for(int i = 0;i < n;i++){
				while(p > 0 && a[stack[p-1]] < a[i])p--;
				ret[i] = p == 0 ? -1 : stack[p-1];
				stack[p++] = i;
			}
			return ret;
		}
		
		public static int[] rmq(int[] a, int[] L)
		{
			int n = a.length;
			int[] fs = new int[n];
			for(int i = 1;i < n;i++){
				fs[Math.max(L[i],0)]++;
			}
			int[][] g = new int[n][];
			for(int i = 0;i < n;i++){
				g[i] = new int[fs[i]];
			}
			for(int i = 1;i < n;i++){
				int v = Math.max(L[i], 0);
				g[v][--fs[v]] = i;
			}
			int[] stack = new int[n];
			int[] mins = new int[n];
			Arrays.fill(mins, Integer.MAX_VALUE);
			int sp = 0;
			for(int i = 0;i < n-1;i++){
				for(int e : g[i]){
					stack[sp++] = e;
				}
				mins[stack[sp-1]] = Math.min(mins[stack[sp-1]], a[i]);
//				U.tr(Arrays.copyOf(stack, sp));
				if(stack[sp-1] != i+1)throw new RuntimeException();
				sp--;
//				U.tr(sp, i);
				if(sp-1 >= 0){
					mins[stack[sp-1]] = Math.min(mins[stack[sp-1]], mins[stack[sp]]);
				}
			}
			return mins;
		}
		
		public static class SegmentTreeRMQPos {
			public int M, H, N;
			public long[] a;
			public int[] pos;
			
			public SegmentTreeRMQPos(int n)
			{
				N = n;
				M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
				H = M>>>1;
				a = new long[H];
				Arrays.fill(a, Long.MAX_VALUE);
				pos = new int[M];
				for(int i = M-1;i >= H;i--)pos[i] = i-H;
				for(int i = H-1;i >= 1;i--)pos[i] = pos[2*i+1];
			}
			
			public SegmentTreeRMQPos(long[] a)
			{
				N = a.length;
				M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
				H = M>>>1;
				this.a = Arrays.copyOf(a, H);
				pos = new int[M];
				for(int i = M-1;i >= H;i--)pos[i] = i-H;
				Arrays.fill(this.a, N, H, Long.MAX_VALUE);
				for(int i = H-1;i >= 1;i--)propagate(i);
			}
			
//			public void update(int pos, int x)
//			{
//				st[H+pos] = x;
//				for(int i = (H+pos)>>>1;i >= 1;i >>>= 1)propagate(i);
//			}
			
			private void propagate(int i)
			{
				if(a[pos[2*i]] >= a[pos[2*i+1]]){
					pos[i] = pos[2*i+1];
				}else{
					pos[i] = pos[2*i];
				}
			}
			
			public int argmin(int l, int r){ return l >= r ? 0 : argmin(l, r, 0, H, 1);}
			
			private int argmin(int l, int r, int cl, int cr, int cur)
			{
				if(l <= cl && cr <= r){
					return pos[cur];
				}else{
					int mid = cl+cr>>>1;
					int can = -1;
					if(cl < r && l < mid){
						int p = argmin(l, r, cl, mid, 2*cur);
						if(can == -1 || a[p] <= a[can])can = p;
					}
					if(mid < r && l < cr){
						int p = argmin(l, r, mid, cr, 2*cur+1);
						if(can == -1 || a[p] <= a[can])can = p;
					}
					return can;
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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