//package round659;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
//	[[1, 2, 3, 3, 12, 42, 144, 288]]
	
	void solve()
	{
		char[] s = ns().toCharArray();
		int[][] uc = uniqcount(s);
		int m = uc.length;
		long[] dp = new long[m+1];
		dp[0] = 1;
		int mod = 1000000007;
		int lastz = 0;
		if(uc[m-1][0] == '0'){
			lastz = uc[m-1][1];
		}
		if(m == 1 && lastz > 0){
			out.println(lastz);
			return;
		}
		
		long[] dpft0 = new long[m+3];
		long[] dpft1 = new long[m+3];
		addFenwick(dpft0, 0, 1);
		
		long ans = 0;
		int[] start = new int[m];
		int sp = 0;
		for(int i = 0;i < m;i++){
			// 0
			if(uc[i][0] == '0'){
				{
					int h = Math.min(uc[i][1], lastz);
					ans += (sumFenwick(dpft1, i) - (sp-1 >= 0 ? sumFenwick(dpft1, start[sp-1]) : 0) + mod) * (h);
					ans %= mod;
					for(int k = sp-1;k >= 0;k--){
						int r = start[k];
						if(h - uc[r][1] <= 0)break;
						int l = k == 0 ? 0 : start[k-1];
						ans += (sumFenwick(dpft1, r) - sumFenwick(dpft1, l) + mod) * (h - uc[r][1]);
						ans %= mod;
					}
				}
				long val = 0;
				val += (sumFenwick(dpft1, i) - (sp-1 >= 0 ? sumFenwick(dpft1, start[sp-1]) : 0) + mod) * (uc[i][1]);
				val %= mod;
				for(int k = sp-1;k >= 0;k--){
					int r = start[k];
					if(uc[i][1] - uc[r][1] <= 0)break;
					int l = k == 0 ? 0 : start[k-1];
					val += (sumFenwick(dpft1, r) - sumFenwick(dpft1, l) + mod) * (uc[i][1] - uc[r][1]);
					val %= mod;
				}
				
				if(i == 0){
					val += uc[i][1];
					val %= mod;
				}

				dp[i+1] = val;
				addFenwick(dpft0, i+1, dp[i+1]);
				
				while(sp > 0 && uc[start[sp-1]][1] <= uc[i][1]){
					sp--;
				}
				start[sp++] = i;
			}
			// 1
			if(uc[i][0] == '1'){
				dp[i+1] = sumFenwick(dpft0, i) * uc[i][1] % mod;
				ans += dp[i+1];
				ans %= mod;
				addFenwick(dpft1, i+1, dp[i+1]);
			}
		}
		
		out.println(ans);
	}
	
	public static final int mod = 1000000007;
	
	public static long sumFenwick(long[] ft, int i)
	{
		long sum = 0;
		for(i++;i > 0;i -= i&-i){
			sum += ft[i];
			if(sum >= mod)sum -= mod;
		}
		return sum;
	}
	
	public static void addFenwick(long[] ft, int l, int r, long v)
	{
		addFenwick(ft, l, v);
		addFenwick(ft, r, -v);
	}
	
	public static void addFenwick(long[] ft, int i, long v)
	{
		v %= mod;
		if(v < 0)v += mod;
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i){
			ft[i] += v;
			if(ft[i] >= mod)ft[i] -= mod;
		}
	}
	
	public static long[] restoreFenwick(long[] ft)
	{
		int n = ft.length-1;
		long[] ret = new long[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--){
			ret[i] -= ret[i-1];
			if(ret[i] < 0)ret[i] += mod;
		}
		return ret;
	}

	
	public static int[] enumNextWall(int[] a)
	{
		int n = a.length;
		int[] L = new int[n];
		for(int i = n-1;i >= 0;i--){
			L[i] = i+1;
			while(L[i] < n && a[L[i]] <= a[i])L[i] = L[L[i]];
		}
		return L;
	}

	
	public static int[][] uniqcount(char[] a)
	{
		int n = a.length;
		int p = 0;
		int[][] b = new int[n][];
		for(int i = 0;i < n;i++){
			if(i == 0 || a[i] != a[i-1])b[p++] = new int[]{a[i], 0};
			b[p-1][1]++;
		}
		return Arrays.copyOf(b, p);
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