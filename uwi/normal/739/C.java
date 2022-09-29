//package round381;
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
		int n = ni();
		int[] a = na(n);
		long[] b = new long[n-1];
		long[] br = new long[n-1];
		for(int i = 0;i < n-1;i++){
			b[i] = a[i+1] - a[i];
			br[i] = -b[i];
		}
		SegmentTreeRMQL stmin = new SegmentTreeRMQL(b);
		SegmentTreeRMQL stmax = new SegmentTreeRMQL(br);
		MinHeap h = new MinHeap(n);
		
		int[] lefts = new int[n];
		int kar = 0;
		for(int i = 0;i < n-1;i++){
			if(b[i] > 0){
				kar++;
			}else{
				lefts[i] += kar;
				kar = 0;
			}
		}
		lefts[n-1] = kar;
		
		kar = 0;
		int[] rights = new int[n];
		for(int i = n-2;i >= 0;i--){
			if(b[i] < 0){
				kar++;
			}else{
				rights[i+1] += kar;
				kar = 0;
			}
		}
		rights[0] = kar;
		for(int i = 0;i < n;i++){
			h.update(i, -(lefts[i]+rights[i]));
		}
		
		for(int Q = ni();Q > 0;Q--){
			int l = ni()-1, r = ni()-1, p = ni();
			if(l-1 >= 0){
				go(l-1, p, b, br, stmin, stmax, h, lefts, rights);
			}
			if(r < n-1){
				go(r, -p, b, br, stmin, stmax, h, lefts, rights);
			}
			out.println(-h.min()+1);
		}
	}
	
	void go(int x, int p, long[] b, long[] br, SegmentTreeRMQL stmin, SegmentTreeRMQL stmax, MinHeap h, int[] lefts, int[] rights)
	{
		int n = b.length + 1;
		for(int y = x;y <= x+1;y++){
			lefts[y] = 0;
			rights[y] = 0;
			h.update(y, -(lefts[y]+rights[y]));
		}
		if(b[x] >= 0){
			int nex = stmin.firstle(x+1, 0L);
			if(nex == -1)nex = n-1;
			lefts[nex] = 0;
			h.update(nex, -(lefts[nex]+rights[nex]));
		}
		if(b[x] <= 0){
			int pre = stmax.lastle(x-1, 0L);
			pre++;
			rights[pre] = 0;
			h.update(pre, -(lefts[pre]+rights[pre]));
		}
		b[x] += p; br[x] -= p;
		stmin.update(x, b[x]);
		stmax.update(x, br[x]);
		{
			int nex = stmin.firstle(x+1, 0L);
			if(nex == -1)nex = n-1;
			int pre = stmin.lastle(nex-1, 0L);
			lefts[nex] = nex-pre-1;
			h.update(nex, -(lefts[nex]+rights[nex]));
		}
		{
			int pre = stmax.lastle(x-1, 0L);
			int nex = stmax.firstle(pre+1, 0L);
			pre++;
			if(nex == -1)nex = n-1;
			rights[pre] = nex-pre;
			h.update(pre, -(lefts[pre]+rights[pre]));
		}
		for(int y = x;y <= x+1;y++){
			if(y-1 >= 0 && y < n-1 && (
					(b[y-1] > 0 && b[y] > 0) ||
					(b[y-1] < 0 && b[y] < 0)))continue;
			int pre = stmin.lastle(y-1, 0L);
			lefts[y] = y-pre-1;
			int nex = stmax.firstle(y, 0L);
			if(nex == -1)nex = n-1;
			rights[y] = nex-y;
			h.update(y, -(lefts[y]+rights[y]));
		}
	}
	
	public static class MinHeap {
		public int[] a;
		public int[] map;
		public int[] imap;
		public int n;
		public int pos;
		public static int INF = Integer.MAX_VALUE;
		
		public MinHeap(int m)
		{
			n = m+2;
			a = new int[n];
			map = new int[n];
			imap = new int[n];
			Arrays.fill(a, INF);
			Arrays.fill(map, -1);
			Arrays.fill(imap, -1);
			pos = 1;
		}
		
		public int add(int ind, int x)
		{
			int ret = imap[ind];
			if(imap[ind] < 0){
				a[pos] = x; map[pos] = ind; imap[ind] = pos;
				pos++;
				up(pos-1);
			}
			return ret != -1 ? a[ret] : x;
		}
		
		public int update(int ind, int x)
		{
			int ret = imap[ind];
			if(imap[ind] < 0){
				a[pos] = x; map[pos] = ind; imap[ind] = pos;
				pos++;
				up(pos-1);
			}else{
				int o = a[ret];
				a[ret] = x;
				up(ret);
				down(ret);
//				if(a[ret] > o){
//					up(ret);
//				}else{
//					down(ret);
//				}
			}
			return x;
		}
		
		public int remove(int ind)
		{
			if(pos == 1)return INF;
			if(imap[ind] == -1)return INF;
			
			pos--;
			int rem = imap[ind];
			int ret = a[rem];
			map[rem] = map[pos];
			imap[map[pos]] = rem;
			imap[ind] = -1;
			a[rem] = a[pos];
			a[pos] = INF;
			map[pos] = -1;
			
			up(rem);
			down(rem);
			return ret;
		}
		
		public int min() { return a[1]; }
		public int argmin() { return map[1]; }
		public int size() {	return pos-1; }
		
		private void up(int cur)
		{
			for(int c = cur, p = c>>>1;p >= 1 && a[p] > a[c];c>>>=1, p>>>=1){
				int d = a[p]; a[p] = a[c]; a[c] = d;
				int e = imap[map[p]]; imap[map[p]] = imap[map[c]]; imap[map[c]] = e;
				e = map[p]; map[p] = map[c]; map[c] = e;
			}
		}
		
		private void down(int cur)
		{
			for(int c = cur;2*c < pos;){
				int b = a[2*c] < a[2*c+1] ? 2*c : 2*c+1;
				if(a[b] < a[c]){
					int d = a[c]; a[c] = a[b]; a[b] = d;
					int e = imap[map[c]]; imap[map[c]] = imap[map[b]]; imap[map[b]] = e;
					e = map[c]; map[c] = map[b]; map[b] = e;
					c = b;
				}else{
					break;
				}
			}
		}
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
			if(l >= r)return 0L;
			long min = Long.MAX_VALUE;
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
			if(l >= N)return -1;
			if(l < 0)l = 0;
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
			if(l >= N)l = N-1;
			if(l < 0)return -1;
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