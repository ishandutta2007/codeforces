//package round003;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		int[] b = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
			b[i] = ni();
		}
		
		int[] fo = go(a, b);
		int[] ba = rev(go(b, a));
		int[] ret = fo.length > ba.length ? fo : ba;
		out.println(ret.length);
		for(int v : ret){
			out.print(v+1 + " ");
		}
		out.println();
	}

	public static int[] rev(int[] a)
	{
		int[] b = new int[a.length];
		for(int i = 0;i < a.length;i++)b[a.length-1-i] = a[i];
		return b;
	}
	

	int[] go(int[] a, int[] b)
	{
		int n = a.length;
		int[][] ab = new int[n][];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(a[i] > b[i]){
				ab[p++] = new int[]{a[i], b[i], i};
			}
		}
		ab = Arrays.copyOf(ab, p);
		Arrays.sort(ab, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1] - b[1];
			}
		});
		int[] bs = new int[p];
		for(int i = 0;i < p;i++)bs[i] = ab[i][1];
		SegmentTreeRMQPos st = new SegmentTreeRMQPos(p);
		int[] prev = new int[p];
		Arrays.fill(prev, -1);
		
		int max = 0;
		int argmax = -1;
		for(int i = 0;i < p;i++){
			int ind = Arrays.binarySearch(bs, ab[i][0]);
			if(ind < 0)ind = -ind-2;
			int minval = st.minx(0, ind+1);
			int val = 0;
			if(minval == Integer.MAX_VALUE){
				val = 1;
			}else{
				prev[i] = st.minpos;
				val = -minval + 1;
			}
			st.update(i, -val);
			if(val > max){
				max = val;
				argmax = i;
			}
		}
		int[] route = new int[max];
		for(int cur = argmax, pos = max-1;cur != -1;cur = prev[cur], pos--){
			route[pos] = ab[cur][2];
		}
		return route;
	}
	
	public class SegmentTreeRMQPos {
		public int M, H, N;
		public int[] st;
		public int[] pos;
		
		public SegmentTreeRMQPos(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			pos = new int[M];
			for(int i = 0;i < N;i++)pos[H+i] = i;
			Arrays.fill(st, 0, M, Integer.MAX_VALUE);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		public SegmentTreeRMQPos(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			pos = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
				pos[H+i] = i;
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
			if(st[2*i] <= st[2*i+1]){
				st[i] = st[2*i];
				pos[i] = pos[2*i];
			}else{
				st[i] = st[2*i+1];
				pos[i] = pos[2*i+1];
			}
		}
		
		public int minpos;
		public int minval;
		
		public int minx(int l, int r){
			minval = Integer.MAX_VALUE;
			minpos = -1;
			if(l >= r)return minval;
			while(l != 0){
				int f = l&-l;
				if(l+f > r)break;
				int v = st[(H+l)/f];
				if(v < minval || v == minval && pos[(H+l)/f] < minpos){
					minval = v;
					minpos = pos[(H+l)/f];
				}
				l += f;
			}
			
			while(l < r){
				int f = r&-r;
				int v = st[(H+r)/f-1];
				if(v < minval || v == minval && pos[(H+r)/f-1] < minpos){
					minval = v;
					minpos = pos[(H+r)/f-1];
				}
				r -= f;
			}
			return minval;
		}
		
		public int min(int l, int r){ 
			minpos = -1;
			minval = Integer.MAX_VALUE;
			min(l, r, 0, H, 1);
			return minval;
		}
		
		private void min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				if(st[cur] < minval){
					minval = st[cur];
					minpos = pos[cur];
				}
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid)min(l, r, cl, mid, 2*cur);
				if(mid < r && l < cr)min(l, r, mid, cr, 2*cur+1);
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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