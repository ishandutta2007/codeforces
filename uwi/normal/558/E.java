//package round312;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		char[] s = ns().toCharArray();
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = s[i] - 'a';
		SegmentTreeOverwrite st = new SegmentTreeOverwrite(a);
		for(int i = 0;i < Q;i++){
			int L = ni()-1, R = ni()-1, dir = ni();
			int[] f = st.sum(L, R+1);
			if(dir == 1){
				for(int j = 0;j < 26;j++){
					if(f[j] > 0){
						st.update(L, L+f[j], j);
						L += f[j];
					}
				}
			}else{
				for(int j = 25;j >= 0;j--){
					if(f[j] > 0){
						st.update(L, L+f[j], j);
						L += f[j];
					}
				}
			}
		}
		st.superfall();
		for(int i = st.H;i < st.H+n;i++){
			out.print((char)('a'+st.cover[i]));
		}
		out.println();
	}

	public static class SegmentTreeOverwrite {
		public int M, H, N;
		public int[][] st;
		public int[] cover;
		public static int K = 26;
		
		public SegmentTreeOverwrite(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M][K];
			cover = new int[M];
			Arrays.fill(cover, -1);
			for(int i = 0;i < N;i++){
				cover[H+i] = a[i];
			}
			for(int i = M-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int i)
		{
			if(cover[i] != -1){
				Arrays.fill(st[i], 0);
				st[i][cover[i]] = H/Integer.highestOneBit(i);
			}else if(i <= H){
				for(int j = 0;j < K;j++)st[i][j] = st[2*i][j] + st[2*i+1][j];
			}
		}
		
		public void superfall()
		{
			for(int cur = 1;cur < H;cur++){
				if(cover[cur] != -1){
					cover[2*cur] = cover[2*cur+1] = cover[cur];
					cover[cur] = -1;
				}
			}
		}
		
		public void update(int l, int r, int v){ update(l, r, v, l, 0, H, 1); }
		
		private void update(int l, int r, int v, int begin, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				cover[cur] = v;
				propagate(cur);
			}else{
				int mid = cl+cr>>>1;
				if(cover[cur] != -1){ // back-propagate
					cover[2*cur] = cover[2*cur+1] = cover[cur];
					cover[cur] = -1;
					propagate(2*cur);
					propagate(2*cur+1);
				}
				if(cl < r && l < mid){
					update(l, r, v, begin, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					update(l, r, v, begin, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		int[] retf;
		
		public int[] sum(int l, int r)
		{
			retf = new int[K];
			sum(l, r, l, 0, H, 1);
			return retf;
		}
		
		private void sum(int l, int r, int begin, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				if(cover[cur] != -1){
					retf[cover[cur]] += cr-cl;
				}else{
					for(int i = 0;i < K;i++)retf[i] += st[cur][i];
				}
			}else{
				int mid = cl+cr>>>1;
				if(cover[cur] != -1){ // back-propagate
					retf[cover[cur]] += Math.min(cr, r) - Math.max(cl, l);
				}else{
					if(cl < r && l < mid){
						sum(l, r, begin, cl, mid, 2*cur);
					}
					if(mid < r && l < cr){
						sum(l, r, begin, mid, cr, 2*cur+1);
					}
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
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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