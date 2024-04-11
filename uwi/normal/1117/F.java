//package educational.round60;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), P = ni();
		char[] s = ns(n);
		int[][] a = new int[P][];
		for(int i = 0;i < P;i++){
			a[i] = na(P);
		}
		// pos of 1, ptn of *, lower
		int[] imos = new int[1<<P];
		boolean[] ngs = new boolean[1<<P];
		
		int H = P/2;
		int[] lasts = new int[P];
		Arrays.fill(lasts, -1);
		for(int i = 0;i < n;i++){
			long[] as = new long[P];
			for(int j = 0;j < P;j++)as[j] = (long)lasts[j]+1<<32|j;
			Arrays.sort(as);
			int zero = 0;
			for(int j = P-1;j >= 0;j--){
				if(as[j]>>>32 == 0)break;
				int tar = (int)as[j];
				int hit = 1<<tar|1<<s[i]-'a';
				if(a[s[i]-'a'][tar] == 0){
					assert (hit&zero) == 0;
					if(j <= H){
						int mask = (1<<P)-1^zero^hit;
						for(int k = mask;k >= 0;k--){ k &= mask;
							ngs[k|hit] = true;
						} // include k=0
					}else{
						for(int k = zero;k >= 0;k--){
							k &= zero;
							imos[hit|k] += (Integer.bitCount(k)&1) == 1 ? -1 : 1;
						} // include k=0
					}
				}
				if(s[i]-'a' == tar)break;
				zero |= 1<<tar;
			}
			
			lasts[s[i]-'a'] = i;
		}
		
		for(int i = 0;i < P;i++){
			for(int j = 0;j < 1<<P;j++){
				if(j<<~i>=0){
					imos[j|1<<i] += imos[j];
				}
			}
		}
		for(int i =0;i < 1<<P;i++){
			if(imos[i] > 0){
				ngs[i] = true;
			}
		}
		
		int[] f = new int[P];
		for(char c : s)f[c-'a']++;
		
		boolean[] dp = new boolean[1<<P];
		dp[(1<<P)-1] = true;
		int ans = Integer.MAX_VALUE;
		for(int i = (1<<P)-1;i >= 0;i--){
			if(dp[i]){
				for(int j = 0;j < P;j++){
					if(i<<~j<0 && !ngs[i^1<<j]){
						dp[i^1<<j] = true;
					}
				}
				int len = 0;
				for(int j = 0;j < P;j++){
					if(i<<~j<0){
						len += f[j];
					}
				}
				ans = Math.min(ans, len);
			}
		}
		out.println(ans);
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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