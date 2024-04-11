//package mailru2018.r2;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), s = ni(), m = ni(), K = ni();
		int[] a = na(n);
		int[][] ss = new int[s][];
		for(int i = 0;i < s;i++){
			ss[i] = new int[]{ni()-1, ni()-1};
		}
		int[][] mmls = new int[s][];
		int p = 0;
		outer:
		for(int i = 0;i < s;i++){
			for(int j = 0;j < s;j++){
				if(ss[j][0] == ss[i][0] && ss[i][1] == ss[j][1]){
					if(j < i)continue outer;
				}else if(ss[j][0] <= ss[i][0] && ss[i][1] <= ss[j][1]){
					continue outer;
				}
			}
			mmls[p++] = ss[i];
		}
		mmls = Arrays.copyOf(mmls, p);
		Arrays.sort(mmls, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});

		
		int[] b = Arrays.copyOf(a, n);
		Arrays.sort(b);
		
		int low = -1, high = n;
		while(high - low > 1){
			int h = high+low>>1;
			if(ok(b[h], a, K, m, mmls)){
				high = h;
			}else{
				low = h;
			}
		}
		if(high == n){
			out.println(-1);
		}else{
			out.println(b[high]);
		}
	}
	
	boolean ok(int v, int[] a, int K, int M, int[][] ms)
	{
		int n = a.length;
//		tr(v, a, K, M, ms);
		int[] cum = new int[n+1];
		for(int i = 0;i < n;i++){
			cum[i+1] = cum[i] + (a[i] <= v ? 1 : 0);
		}
		int[][] dp = new int[M+1][n+1];
		for(int i = 0;i <= M;i++){
			Arrays.fill(dp[i], Integer.MIN_VALUE / 2);
		}
		dp[0][0] = 0;
		int[] dpmaxs = new int[M+1];
		Arrays.fill(dpmaxs, Integer.MIN_VALUE / 2);
		SegmentTreeRMQ[] dpp = new SegmentTreeRMQ[M+1];
		for(int i = 0;i < M+1;i++){
			dpp[i] = new SegmentTreeRMQ(n+1);
		}
		dpp[0].update(0, 0);
		int p = 0;
		int pr = 0;
		for(int i = 0;i < n;i++){
			if(p < ms.length && ms[p][1] == i){
				for(int j = 0;j < M;j++){
					for(int k = pr;k <= ms[p][0];k++){
						dpmaxs[j] = Math.max(dpmaxs[j], dp[j][k]);
					}
					
					int val = dpmaxs[j] + cum[i+1] - cum[ms[p][0]];
					val = Math.max(val, -dpp[j].minx(ms[p][0]+1, i+1)+cum[i+1]);
					dp[j+1][i+1] = val;
					if(val >= K){
						return true;
					}
					dpp[j+1].update(i+1, -val+cum[i+1]);
				}
				pr = ms[p][0] + 1;
				p++;
			}else{
			}
		}
		return false;
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

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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