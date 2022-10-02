//package round259;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] s = new int[n];
		int[] m = new int[n];
		int[] r = new int[n];
		for(int i = 0;i < n;i++){
			s[i] = ni();
			m[i] = ni();
			r[i] = ni();
		}
		
		SegmentTreeOverwrite st = new SegmentTreeOverwrite(s, m, r);
		int Q = ni();
		for(int z = 0;z < Q;z++){
			int t = ni();
			int L = ni()-1, R = ni()-1;
			out.println(st.sum(L, R+1, t));
			st.update(L, R+1, t);
		}
	}
	
	public static class SegmentTreeOverwrite {
		public int M, H, N;
		public int[][] tomaxs;
		public int[][][] alls;
		public long[][] cums;
		public long[][] coos;
		public int[][] times; // liter time left
		public int[] s, m, r;
		
		public SegmentTreeOverwrite(int[] s, int[] m, int[] r)
		{
			this.s = s;
			this.m = m;
			this.r = r;
			N = s.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			alls = new int[M][][];
			for(int i = 0;i < H;i++){
				if(i < N){
					alls[H+i] = new int[][]{{m[i], r[i], r[i] == 0 ? 1000000003 : (m[i]+r[i]-1)/r[i]}};
				}else{
					alls[H+i] = new int[0][];
				}
			}
			for(int i = H-1;i >= 1;i--){
				alls[i] = new int[alls[2*i].length+alls[2*i+1].length][];
				int p = 0;
				for(int[] seq : alls[2*i])alls[i][p++] = seq;
				for(int[] seq : alls[2*i+1])alls[i][p++] = seq;
				Arrays.sort(alls[i], new Comparator<int[]>() {
					public int compare(int[] a, int[] b) {
						return a[2] - b[2];
					}
				});
			}
			tomaxs = new int[M][];
			times = new int[M][];
			cums = new long[M][];
			coos = new long[M][];
			for(int i = 0;i < H;i++){
				if(i < N){
					times[H+i] = new int[]{s[i], 0};
				}else{
					times[H+i] = new int[]{0, 0};
				}
			}
			for(int i = 1;i < M;i++){
				tomaxs[i] = new int[alls[i].length];
				cums[i] = new long[alls[i].length+1];
				coos[i] = new long[alls[i].length+1];
				for(int j = 0;j < alls[i].length;j++){
					tomaxs[i][j] = alls[i][j][2]*2;
					cums[i][j+1] = cums[i][j] + alls[i][j][0];
					coos[i][j+1] = coos[i][j] + alls[i][j][1];
				}
			}
		}
		
		public long sum(int i, int t)
		{
			if(times[i] == null)throw new RuntimeException();
			long past = t-times[i][1];
			if(times[i][0] != 0){
				// leaf
				return Math.min(times[i][0]+past*r[i-H], m[i-H]);
			}else{
				int ind = Arrays.binarySearch(tomaxs[i], 2*(int)past+1);
				ind = -ind-1;
				return cums[i][ind] + (coos[i][coos[i].length-1]-coos[i][ind])*past;
			}
		}
		
		public void update(int l, int r, int t){ update(l, r, t, l, 0, H, 1); }
		
		private void update(int l, int r, int t, int begin, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				times[cur] = new int[]{0, t};
			}else{
				int mid = cl+cr>>>1;
				if(times[cur] != null){ // back-propagate
					times[2*cur] = times[2*cur+1] = times[cur];
					times[cur] = null;
				}
				if(cl < r && l < mid){
					update(l, r, t, begin, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					update(l, r, t, begin, mid, cr, 2*cur+1);
				}
			}
		}
		
		public long sum(int l, int r, int t){ return sum(l, r, t, l, 0, H, 1); }
		
		private long sum(int l, int r, int t, int begin, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r && times[cur] != null){
				return sum(cur, t);
			}else{
				int mid = cl+cr>>>1;
				if(times[cur] != null){ // back-propagate
					times[2*cur] = times[2*cur+1] = times[cur];
					times[cur] = null;
				}
				long ret = 0L;
				if(cl < r && l < mid){
					ret += sum(l, r, t, begin, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					ret += sum(l, r, t, begin, mid, cr, 2*cur+1);
				}
				return ret;
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