//package round185;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), P = ni(); // hill cat feeder
		long[] d = new long[n];
		for(int i = 1;i < n;i++)d[i] = d[i-1] + ni();
		int[][] ht = new int[m][];
		for(int i = 0;i < m;i++){
			ht[i] = na(2);
		}
		long[] cx = new long[m];
		for(int i = 0;i < m;i++){
			cx[i] = ht[i][1] - d[ht[i][0]-1] + d[n-1];
		}
		cx = radixSort(cx);
		
		long[] D = new long[m+1];
		for(int i = 1;i < m+1;i++){
			D[i] = D[i-1] + cx[i-1];
		}
		
		long[] dp = new long[m+1];
		// dp[p][i] = \min(dp[p-1][j]+(d_i-d_{j+1})+(d_i-d_{j+2})+..)
		// d_i
		// dp[p][i] = \min(dp[p-1][j]+(i-j)d_i-D_i+D_j)
		// dp[p][i] = \min(dp[p-1][j]+D_j-j*d_i)-D_i+i*d_i
		// - \ | 
//		tr(cx);
		Arrays.fill(dp, Long.MAX_VALUE/100);
		dp[0] = 0;
		long[][] st = new long[m+1][3];
		for(int i = 1;i <= P;i++){
			int sp = 0;
			int low = 0;
			for(int j = 0;j <= m;j++){
				long pre = dp[j];
				if(j == 0){
					dp[j] = 0;
				}else{
//					tr(j, Arrays.copyOf(st, sp), cx[j-1], low);
					
					long x = cx[j-1];
					while(low+1 < sp && x >= st[low+1][2])low++;
//					tr(st[low][0], x, st[low][1], D[j], j, cx[j-1]);
					dp[j] = st[low][0]*x+st[low][1] - D[j]+j*cx[j-1];
				}
				
				long slope = -j;
				long intercept = pre + D[j];
				// ax+b=cx+d
				// x=-(d-b)/(c-a)
				while(true){
					if(sp == 0){
						st[sp][0] = slope;
						st[sp][1] = intercept;
						st[sp][2] = Long.MIN_VALUE;
						sp++;
						break;
					}
					long[] prv = st[sp-1];
					
//					if(prv[0] == slope){
//						if(prv[0] > slope){
//							sp--;
//							if(low > sp-1)low--;
//						}else{
//							break;
//						}
//					}else 
					if(prv[0] > slope){
//						long x = -(intercept-prv[1]) / (slope-prv[0]);
						long x = divceil(-(intercept-prv[1]), slope-prv[0]);
						if(x <= prv[2]){
							sp--;
//							if(low > sp-1)low--;
						}else{
							st[sp][0] = slope;
							st[sp][1] = intercept;
							st[sp][2] = x;
							sp++;
							break;
						}
					}else{
						throw new AssertionError();
					}
				}
			}
		}
		out.println(dp[m]);
	}
	
	long divceil(long a, long b)
	{
		if(a > 0 ^ b > 0){
			return a/b;
		}else if(b > 0){
			return (a+b-1)/b;
		}else{
			return (-a-b-1)/-b;
		}
//		if(b == 0)throw new AssertionError();
//		long x = a/b;
//		if((a < 0 ^ b > 0) && a%b != 0)x++;
////		if((a < 0 ^ b < 0) && a%b != 0)x--;
//		return x;
	}
	
	public static long[] radixSort(long[] f)
	{
		long[] to = new long[f.length];
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>16&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>16&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>32&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>32&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>48&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>48&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		return f;
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
	
	public static void main(String[] args) throws Exception { new B4().run(); }
	
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