//package round321;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni() + ni();
		char[] s = ns().toCharArray();
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			qs[i] = na(4);
		}
		
		Random gen = new Random(0);
		int mod = -1, H = -1;
		int[] rets = new int[Q];
		for(int rep = 0;rep < 2;rep++){
			while(true){
				mod = BigInteger.probablePrime(30, gen).intValue();
				H = BigInteger.probablePrime(29, gen).intValue();
				if(mod > H)break;
			}
			SegmentTreeRSQHash st = new SegmentTreeRSQHash(s, H, mod);
			int u = 0;
			for(int[] q : qs){
				if(q[0] == 1){
					st.update(q[1]-1, q[2], (char)(q[3]+'0'));
				}else{
					if(q[2]-q[1]+1 == q[3]){
//						out.println("YES");
					}else{
						long lh = st.sum(q[1]-1, q[2]-q[3]);
						long rh = st.sum(q[1]-1+q[3], q[2]);
						if(lh != rh)rets[u] = -1;
//						out.println(lh == rh ? "YES" : "NO");
					}
				}
				u++;
			}
		}
		for(int i = 0;i < Q;i++){
			if(qs[i][0] == 2){
				out.println(rets[i] == 0 ? "YES" : "NO");
			}
		}
	}
	
	public static class SegmentTreeRSQHash {
		public int M, H, N;
		public long[] st;
		public long[] cover;
		public long HASH, MOD;
		
		public long[] pows;
		public long[] gas;
		
		public SegmentTreeRSQHash(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
		}
		
		public SegmentTreeRSQHash(char[] a, long HASH, long MOD)
		{
			this.HASH = HASH;
			this.MOD = MOD;
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			cover = new long[H];
			pows = new long[H+1];
			pows[0] = 1;
			for(int i = 1;i <= H;i++)pows[i] = pows[i-1] * HASH % MOD;
			gas = new long[H+1];
			gas[0] = 1;
			for(int i = 1;i <= H;i++){
				gas[i] = gas[i-1] + pows[i];
				if(gas[i] >= MOD)gas[i] -= MOD;
			}
			
			for(int i = (M>>1)-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		private void propagate(int i)
		{
			if(cover[i] == 0){
				st[i] = (st[2*i]*pows[H/Integer.highestOneBit(i)/2]+st[2*i+1])%MOD;
			}else{
				st[i] = cover[i]*gas[H/Integer.highestOneBit(i)-1]%MOD;
			}
		}
		
		public void update(int x, long v)
		{
			st[H+x] = v;
			for(int cur = H+x>>>1;cur >= 1;cur>>>=1)propagate(cur);
		}
		
		public void update(int l, int r, char v) { 
			update(l, r, v, 0, H, 1);
		}
		
		protected void update(int l, int r, char v, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				if(cur >= H){
					st[cur] = v;
				}else{
					cover[cur] = v;
					propagate(cur);
				}
			}else{
				if(cover[cur] != 0){
					if(2*cur < H){
						cover[2*cur] = cover[2*cur+1] = cover[cur];
						cover[cur] = 0;
						propagate(2*cur);
						propagate(2*cur+1);
					}else{
						st[2*cur] = st[2*cur+1] = cover[cur];
						cover[cur] = 0;
					}
				}
				
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					update(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					update(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public long sum(int l, int r) { 
			return sum(l, r, 0, H, 1);
		}
		
		protected long sum(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				if(cover[cur] != 0){
					int len = Math.min(r, cr) - Math.max(l, cl);
					return gas[len-1] * cover[cur] % MOD;
				}
				
				long L = Long.MIN_VALUE, R = Long.MIN_VALUE;
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					L = sum(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					R = sum(l, r, mid, cr, 2*cur+1);
				}
				if(L != Long.MIN_VALUE && R != Long.MIN_VALUE){
					int rlen = Math.min(r, cr) - Math.max(l, mid);
					return (pows[rlen] * L + R) % MOD;
				}else if(L != Long.MIN_VALUE){
					return L;
				}else if(R != Long.MIN_VALUE){
					return R;
				}else{
					throw new RuntimeException();
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