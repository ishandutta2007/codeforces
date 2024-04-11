//package corc2013.r1;
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
		int n = ni(), m = ni();
		int[] a = na(n);
		int[] b = na(n);
		SegmentTreeOverwrite st = new SegmentTreeOverwrite(b);
		for(int i = 0;i < m;i++){
			int t = ni();
			if(t == 1){
				int x = ni()-1, y = ni()-1, K = ni();
				st.update(y, y+K, x);
			}else{
				int x = ni()-1;
				int[] hit = st.attack(x);
				if(hit == null){
					out.println(b[x]);
				}else{
					out.println(a[x+hit[0]-hit[1]]);
				}
			}
		}
	}
	
	public static class SegmentTreeOverwrite {
		public int M, H, N;
		public int[][] cover;
		
		public SegmentTreeOverwrite(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			cover = new int[M][];
		}
		
		public void update(int l, int r, int v){ update(l, r, v, l, 0, H, 1); }
		
		private void update(int l, int r, int v, int begin, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				cover[cur] = new int[]{v, begin};
			}else{
				int mid = cl+cr>>>1;
				if(cover[cur] != null){ // back-propagate
					cover[2*cur] = cover[2*cur+1] = cover[cur];
					cover[cur] = null;
				}
				if(Math.max(l, cl) < Math.min(r, mid)){
					update(l, r, v, begin, cl, mid, 2*cur);
				}
				if(Math.max(l, mid) < Math.min(r, cr)){
					update(l, r, v, begin, mid, cr, 2*cur+1);
				}
			}
		}
		
		public int[] attack(int x){ return attack(x, 0, H, 1); }
		
		private int[] attack(int x, int cl, int cr, int cur)
		{
			if(x == cl && cr-cl == 1){
				return cover[cur];
			}else{
				if(cover[cur] != null){
					return cover[cur];
				}
				int mid = cl+cr>>>1;
				if(cl <= x && x < mid){
					return attack(x, cl, mid, 2*cur);
				}
				if(mid <= x && x < cr){
					return attack(x, mid, cr, 2*cur+1);
				}
				return null;
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