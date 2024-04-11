//package round250;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		int[] a = na(n);
		for(int i = 0;i < n;i++){
			a[i] = -a[i];
		}
		SegmentTreeRMQPos st = new SegmentTreeRMQPos(a);
		
		for(int z = 0;z < Q;z++){
			int t = ni();
			if(t == 1){
				int l = ni()-1, r = ni()-1;
				out.println(-st.sum(l, r+1));
			}else if(t == 2){
				int l = ni()-1, r = ni()-1, x = ni();
				st.spread(l, r+1, x);
			}else if(t == 3){
				int pos = ni()-1, x = ni();
				st.update(pos, -x);
			}
		}
	}
	
	public static class SegmentTreeRMQPos {
		public int M, H, N;
		public int[] st;
		public int[] pos;
		public long[] sum;
		
		public SegmentTreeRMQPos(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			pos = new int[M];
			sum = new long[M];
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
			sum = new long[M];
			for(int i = 0;i < N;i++){
				sum[H+i] = st[H+i] = a[i];
				pos[H+i] = i;
			}
			Arrays.fill(st, H+N, M, Integer.MAX_VALUE);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		public void update(int pos, int x)
		{
			sum[H+pos] = st[H+pos] = x;
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
			sum[i] = sum[2*i] + sum[2*i+1];
		}
		
		public void spread(int l, int r, int x)
		{
			spread(l, r, x, 0, H, 1);
		}
		
		private void spread(int l, int r, int x, int cl, int cr, int cur)
		{
			if(st[cur] > -x)return;
			if(cur >= H){
				st[cur] %= x;
				sum[cur] = st[cur];
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid)spread(l, r, x, cl, mid, 2*cur);
				if(mid < r && l < cr)spread(l, r, x, mid, cr, 2*cur+1);
				propagate(cur);
			}
		}
		
		public long sumval = 0;
		
		public long sum(int l, int r){
			sumval = 0L;
			sum(l, r, 0, H, 1);
			return sumval;
		}
		
		private void sum(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				sumval += sum[cur];
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid)sum(l, r, cl, mid, 2*cur);
				if(mid < r && l < cr)sum(l, r, mid, cr, 2*cur+1);
			}
		}
		
		public int[] toArray() { return toArray(1, 0, H, new int[H]); }
		
		private int[] toArray(int cur, int l, int r, int[] ret)
		{
			if(r-l == 1){
				ret[cur-H] = st[cur];
			}else{
				toArray(2*cur, l, l+r>>>1, ret);
				toArray(2*cur+1, l+r>>>1, r, ret);
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
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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