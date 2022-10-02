//package round163;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] a = na(n);
		SegmentTreeRSQ st = new SegmentTreeRSQ(a); //
		
		for(int q = 0;q < m;q++){
//			tr("phase : " + q);
//			tr(st.st);
//			tr(st.cover);
			char com = nc();
			if(com == '='){
				int l = ni()-1, r = ni()-1, x = ni();
				st.update(l, r+1, x);
			}else if(com == '?'){
				int l = ni()-1, r = ni()-1, K = ni();
				out.println(st.sum(l, r+1, K));
			}
		}
	}
	
	public static class SegmentTreeRSQ {
		public int M, H, N, B;
		public int[][] st; // x*1^0+y*2^0+.., x*1^1+y*2^1+..
		public int[] cover;
		public int mod = 1000000007;
		public int[][] S; // k S[k][i]=\sum_{1<=j<=i} j^k
		public long[][] C;
		
		public SegmentTreeRSQ(int[] a)
		{
			N = a.length;
			H = Integer.highestOneBit(Math.max(N-1,1))<<1;
			M = H<<1;
			B = Integer.numberOfTrailingZeros(H);
			
			S = new int[6][M+1];
			for(int i = 1;i <= M;i++){
				long p = 1;
				for(int k = 0;k <= 5;k++){
					S[k][i] = S[k][i-1] + (int)p;
					if(S[k][i] >= mod){
						S[k][i] -= mod;
					}
					p = p * i % mod;
				}
			}
			
			C = new long[10][10];
			for(int i = 0;i < 10;i++){
				C[i][0] = 1;
				for(int j = 1;j <= i;j++){
					C[i][j] = C[i-1][j] + C[i-1][j-1];
				}
			}
			
			st = new int[M][6];
			cover = new int[M];
			Arrays.fill(cover, -1);
			for(int i = 0;i < N;i++){
				Arrays.fill(st[H+i], a[i]);
			}
			for(int i = H-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		public static long pow(long a, long n, long mod)
		{
			long ret = 1;
			int x = 63-Long.numberOfLeadingZeros(n);
			for(;x >= 0;x--){
				ret = ret * ret % mod;
				if(n<<63-x<0)ret = ret * a % mod;
			}
			return ret;
		}
		
		private void propagate(int i)
		{
			int u = H/Integer.highestOneBit(i);
			if(cover[i] == -1){
				for(int j = 0;j <= 5;j++){
					// sum_i r_i*(R+i)^j - sum_i r_i*i^j
					// = sum_i r_i*sum_e C(j,e)*R^e*i^(j-e)
					// = sum_e C(j,e)*R^e*sum_i r_i*i^(j-e)
					
					// r_1(u/2+1)^j+r_2(u/2+2)^j+...
					// r_1*1^j+r_2*2^j+...
					// C(j,1)S(u/2)^(j-1)+C(j,2)S^2(u/2)^(j-2)+C(j,3)S^3(u/2)^(j-3)
					long v = st[2*i][j];//+st[2*i+1][j];
					for(int e = 0;e <= j;e++){
//						v += C[j][e]*(S[e][u/2]-S[e][u/2-1]+mod)%mod*st[2*i+1][j-e]%mod;
						v += C[j][e]*((long)(S[e][u/2]-S[e][u/2-1]+mod)*st[2*i+1][j-e]%mod);
//						st[i][j] += C[j][e]*pow(u/2, e, mod)%mod*st[2*i+1][j-e]%mod;
					}
					st[i][j] = (int)(v % mod);
				}
			}else{
				for(int j = 0;j <= 5;j++){
					st[i][j] = (int)((long)cover[i]*S[j][u]%mod);
				}
			}
		}
		
		// [l,r), [cl,cr)
		public void update(int l, int r, int v){ update(l, r, v, 0, H, 1); }
		
		protected void update(int l, int r, int v, int cl, int cr, int cur)
		{
			if(cur >= H){
				Arrays.fill(st[cur], v);
			}else if(l <= cl && cr <= r){
				cover[cur] = v;
				propagate(cur);
			}else{
				boolean bp = false;
				if(cover[cur] >= 0){ // back-propagate
					bp = true;
					cover[2*cur] = cover[2*cur+1] = cover[cur];
					cover[cur] = -1;
				}
				int mid = (cl+cr)/2;
				if(Math.max(l, cl) < Math.min(r, mid)){
					update(l, r, v, cl, mid, 2*cur);
				}else if(bp){
					propagate(2*cur);
				}
				if(Math.max(l, mid) < Math.min(r, cr)){
					update(l, r, v, mid, cr, 2*cur+1);
				}else if(bp){
					propagate(2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public int sum(int l, int r, int k) { 
			cache = new HashMap<Long, Integer>();
			return sum(l, r, 0, H, 1, k);
		}
		Map<Long, Integer> cache;
		
		protected int sum(int l, int r, int cl, int cr, int cur, int k)
		{
			if(l <= cl && cr <= r){
				return st[cur][k];
			}else if(cover[cur] >= 0){
				return (int)((long)cover[cur]*S[k][Math.min(r, cr)-Math.max(l, cl)]%mod);
			}else{
				long code = ((cl*31L+cr)*31+cur)*31+k;
				if(cache.containsKey(code)){
					return cache.get(code);
				}
				
				int mid = (cl+cr)/2;
				long ret = 0;
				if(Math.max(l, cl) < Math.min(r, mid)){
					ret += sum(l, r, cl, mid, 2*cur, k);
				}
				if(Math.max(l, mid) < Math.min(r, cr)){
					int num = Math.min(r, mid) - Math.max(l, cl);
					if(num > 0){
						for(int e = 0;e <= k;e++){
							int v = sum(l, r, mid, cr, 2*cur+1, k-e);
							ret += C[k][e]*((long)(S[e][num]-S[e][num-1]+mod)*v%mod);
//							ret += C[k][e]*pow(num, e, mod)%mod*v%mod;
						}
					}else{
						ret += sum(l, r, mid, cr, 2*cur+1, k);
					}
				}
				int reti = (int)(ret%mod);
				cache.put(code, reti);
				return reti;
			}
		}
		
		private void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
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
	
	private char nc() { return (char)skip(); }
	
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}