//package sandbox;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class P19D6 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	static class Query
	{
		char type;
		int x, y;
		int sx;
	}
	
	void solve()
	{
		int Q = ni();
		Query[] qs = new Query[Q];
		int[] xs = new int[Q];
		for(int i = 0;i < Q;i++){
			qs[i] = new Query();
			qs[i].type = ns(7)[0];
			xs[i] = qs[i].x = ni();
			qs[i].y = ni();
		}
		int[] imap = shrinkX(xs);
		for(int i = 0;i < Q;i++){
			qs[i].sx = xs[i];
		}
		
		int n = imap.length;
		int[][] maps = new int[n][];
		// TODO append to library
		int[] dup = new int[n];
		for(int i = 0;i < Q;i++)dup[qs[i].sx]++;
		for(int i = 0;i < n;i++)maps[i] = new int[dup[i]];
		for(int i = 0;i < Q;i++)maps[qs[i].sx][--dup[qs[i].sx]] = qs[i].y;
		for(int i = 0;i < n;i++){
			Arrays.sort(maps[i]);
			int lp = 0;
			for(int j = 0;j < maps[i].length;j++){
				if(j == 0 || maps[i][j] != maps[i][j-1]){
					maps[i][lp++] = maps[i][j];
				}
			}
			maps[i] = Arrays.copyOf(maps[i], lp);
		}
		int[][] fts = new int[n][];
		for(int i = 0;i < n;i++){
			fts[i] = new int[maps[i].length+1];
		}
		
		SegmentTreeRMQPos st = new SegmentTreeRMQPos(n);
		for(Query q : qs){
			if(q.type == 'a'){
				addFenwick(fts[q.sx], Arrays.binarySearch(maps[q.sx], q.y), 1);
				if(q.y > -st.st[st.H+q.sx]){
					st.update(q.sx, -q.y);
				}
			}else if(q.type == 'r'){
				addFenwick(fts[q.sx], Arrays.binarySearch(maps[q.sx], q.y), -1);
				if(q.y == -st.st[st.H+q.sx]){
					int ny = before(fts[q.sx], maps[q.sx].length);
					if(ny == -1){
						st.update(q.sx, Integer.MAX_VALUE);
					}else{
						st.update(q.sx, -ny);
					}
				}
			}else if(q.type == 'f'){
				int left = st.leftpos(q.sx+1, st.H, -(q.y+1));
				if(left == -1){
					out.println(-1);
				}else{
					int ind = Arrays.binarySearch(maps[left], q.y);
					if(ind < 0)ind = -ind-2;
					int af = after(fts[left], ind);
					if(af < 0 || af >= maps[left].length){
						throw new RuntimeException();
					}else{
						out.println(imap[left] + " " + maps[left][af]);
					}
				}
			}
		}
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static int findGFenwick(int[] ft, int v)
	{
		int i = 0;
		int n = ft.length;
		for(int b = Integer.highestOneBit(n);b != 0 && i < n;b >>= 1){
			if(i + b < n){
				int t = i + b;
				if(v >= ft[t]){
					i = t;
					v -= ft[t];
				}
			}
		}
		return v != 0 ? -(i+1) : i-1;
	}
	
	public static int valFenwick(int[] ft, int i)
	{
		return sumFenwick(ft, i) - sumFenwick(ft, i-1);
	}
	
	public static int[] restoreFenwick(int[] ft)
	{
		int n = ft.length-1;
		int[] ret = new int[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
	}
	
	public static int before(int[] ft, int x)
	{
		int u = sumFenwick(ft, x-1);
		if(u == 0)return -1;
		return findGFenwick(ft, u-1)+1;
	}
	
	public static int after(int[] ft, int x)
	{
		int u = sumFenwick(ft, x);
		int f = findGFenwick(ft, u);
		if(f+1 >= ft.length-1)return -1;
		return f+1;
	}
	
	public static class SegmentTreeRMQPos {
		public int M, H, N;
		public int[] st;
		public int[] pos;
		public static int I = Integer.MAX_VALUE;
		
		public SegmentTreeRMQPos(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n, 1))<<2;
			H = M>>>1;
			st = new int[M];
			Arrays.fill(st, I);
			pos = new int[M];
			for(int i = M-1;i >= H;i--)pos[i] = i-H;
			for(int i = H-1;i >= 1;i--){
				pos[i] = pos[2*i];
			}
		}
		
		public SegmentTreeRMQPos(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N, 1))<<2;
			H = M>>>1;
			st = new int[M];
			pos = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
				pos[H+i] = i;
			}
			Arrays.fill(st, H+N, M, I);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		public void update(int p, int x)
		{
			st[H+p] = x;
			for(int i = H+p>>>1;i >= 1;i >>>= 1)propagate(i);
		}
		
		private void propagate(int i)
		{
			if(st[i*2] <= st[i*2+1]){
				st[i] = st[i*2];
				pos[i] = pos[i*2];
			}else{
				st[i] = st[i*2+1];
				pos[i] = pos[i*2+1];
			}
		}
		
		public int leftpos(int l, int r, int v) { return leftpos(l, r, v, 0, H, 1); }
		
		// leftest where <= v
		public int leftpos(int l, int r, int v, int cl, int cr, int cur)
		{
			if(st[cur] > v)return -1;
			if(cur >= H)return pos[cur];
			int mid = cl+cr>>>1;
			if(Math.max(l, cl) < Math.min(r, mid)){
				int L = leftpos(l, r, v, cl, mid, 2*cur);
				if(L != -1)return L;
			}
			if(Math.max(l, mid) < Math.min(r, cr)){
				int R = leftpos(l, r, v, mid, cr, 2*cur+1);
				if(R != -1)return R;
			}
			return -1;
		}
		
		public int[] min(int l, int r) { return min(l, r, 0, H, 1); }
		
		public int[] min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return new int[]{st[cur], pos[cur]};
			}else{
				int mid = cl+cr>>>1;
				int[] L = null, R = null;
				if(Math.max(l, cl) < Math.min(r, mid)){
					L = min(l, r, cl, mid, 2*cur);
				}
				if(Math.max(l, mid) < Math.min(r, cr)){
					R = min(l, r, mid, cr, 2*cur+1);
				}
				if(R == null)return L;
				if(L == null)return R;
				if(L[0] <= R[0])return L;
				return R;
			}
		}
	}
	
	public static int[] shrinkX(int[] a)
	{
		int n = a.length;
		long[] b = new long[n];
		for(int i = 0;i < n;i++)b[i] = (long)a[i]<<32|i;
		Arrays.sort(b);
//		b = radixSort(b);
		int[] ret = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i == 0 || (b[i]^b[i-1])>>32!=0)ret[p++] = (int)(b[i]>>32);
			a[(int)b[i]] = p-1;
		}
		return Arrays.copyOf(ret, p);
	}
	
	void run() throws Exception
	{
//		int n = 200000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
////			int type = 0;
//			int type = gen.nextInt(3);
////			int type = i < n/3 ? 0 : 2;
//			sb.append("arf".charAt(type) + " ");
//			sb.append(gen.nextInt(1000000000) + " ");
//			sb.append(gen.nextInt(1000000000) + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new P19D6().run(); }
	
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}