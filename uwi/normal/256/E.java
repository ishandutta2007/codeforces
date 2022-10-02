//package round156;
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
	int mod = 777777777;
	
	void solve()
	{
		int n = ni(), m = ni();
		
		int[][] w = new int[3][3];
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < 3;j++){
				w[i][j] = ni();
			}
		}
		
		SegmentTreeRMQ st = new SegmentTreeRMQ(n, w);
		
		for(int i = 0;i < m;i++){
			int v = ni()-1, t = ni();
			st.update(v, t);
			out.println(st.result());
		}
	}
	
	public class SegmentTreeRMQ {
		public int M, H, N, B;
		public int[] a;
		public int[][][] seq;
		public int[][] w;
		int mod = 777777777;
		
		public SegmentTreeRMQ(int n, int[][] w)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n-1, 1))<<2;
			H = M>>>1;
			B = Integer.numberOfTrailingZeros(H);
			a = new int[n];
			seq = new int[M][][];
			this.w = w;
			for(int i = 0;i < n;i++){
				seq[H+i] = make(i, i, a, w);
			}
			for(int i = H-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		public void update(int pos, int x)
		{
			a[pos] = x;
			seq[H+pos] = make(pos, pos, a, w);
			for(int i = (H+pos)>>>1;i >= 1;i >>>= 1)propagate(i);
		}
		
		private int[][] copy(int[][] s)
		{
			int[][] ret = new int[s.length][];
			for(int i = 0;i < s.length;i++){
				if(s[i] != null)ret[i] = Arrays.copyOf(s[i], s[i].length);
			}
			return ret;
		}
		
		private void propagate(int i)
		{
			if(seq[2*i] == null){
				seq[i] = null;
			}else if(seq[2*i+1] == null){
				seq[i] = copy(seq[2*i]);
			}else{
				if(seq[2*i][0] != null){
					int[] ini = seq[2*i][0];
					seq[i] = new int[4][];
					seq[i][0] = new int[3];
					// 0 j j k
					for(int j = 1;j <= 3;j++){
						for(int k = 1;k <= 3;k++){
							seq[i][0][k-1] = (int)((seq[i][0][k-1] + (long)seq[2*i+1][j][k-1] * ini[j-1]) % mod);
						}
					}
				}else{
					seq[i] = new int[4][];
					seq[i][1] = new int[3];
					seq[i][2] = new int[3];
					seq[i][3] = new int[3];
					// j k l
					for(int j = 1;j <= 3;j++){
						for(int k = 1;k <= 3;k++){
							for(int l = 1;l <= 3;l++){
								seq[i][j][l-1] = (int)((seq[i][j][l-1] + (long)seq[2*i+1][k][l-1] * seq[2*i][j][k-1]) % mod);
							}
						}
					}
				}
			}
		}
		
		public long result()
		{
			return ((long)seq[1][0][0]+seq[1][0][1]+seq[1][0][2]) % mod;
		}
		
		int[][] make(int l, int r, int[] a, int[][] w)
		{
			int[][] ret = new int[4][];
			int[][] dp = new int[2][3];
			int[] cur = dp[1], pre = dp[0];
			
			if(l > 0){
				for(int s = 1;s <= 3;s++){
					Arrays.fill(pre, 0);
					pre[s-1] = 1;
					for(int j = l;j <= r;j++){
						Arrays.fill(cur, 0);
						if(a[j] > 0){
							for(int k = 0;k < 3;k++){
								if(w[k][a[j]-1] == 1){
									cur[a[j]-1] += pre[k];
									if(cur[a[j]-1] >= mod)cur[a[j]-1] -= mod;
								}
							}
						}else{
							for(int u = 0;u < 3;u++){
								for(int k = 0;k < 3;k++){
									if(w[k][u] == 1){
										cur[u] += pre[k];
										if(cur[u] >= mod)cur[u] -= mod;
									}
								}
							}
						}
						int[] dum = pre; pre = cur; cur = dum;
					}
					ret[s] = Arrays.copyOf(pre, 3);
				}
			}else{
				Arrays.fill(pre, 0);
				if(a[l] > 0){
					pre[a[l]-1] = 1;
				}else{
					pre[0] = 1;
					pre[1] = 1;
					pre[2] = 1;
				}
				for(int j = l+1;j <= r;j++){
					Arrays.fill(cur, 0);
					if(a[j] > 0){
						for(int k = 0;k < 3;k++){
							if(w[k][a[j]-1] == 1){
								cur[a[j]-1] += pre[k];
								if(cur[a[j]-1] >= mod)cur[a[j]-1] -= mod;
							}
						}
					}else{
						for(int u = 0;u < 3;u++){
							for(int k = 0;k < 3;k++){
								if(w[k][u] == 1){
									cur[u] += pre[k];
									if(cur[u] >= mod)cur[u] -= mod;
								}
							}
						}
					}
					int[] dum = pre; pre = cur; cur = dum;
				}
				ret[0] = Arrays.copyOf(pre, 3);
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