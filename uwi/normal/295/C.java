//package round179;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int mod = 1000000007;
		int n = ni(), K = ni();
		int w1 = 0, w2 = 0;
		for(int i = 0;i < n;i++){
			if(ni() == 50){
				w1++;
			}else{
				w2++;
			}
		}
		
		long[][] C = new long[101][101];
		for(int i = 0;i <= 100;i++){
			C[i][0] = 1;
			for(int j = 1;j <= i;j++){
				C[i][j] = C[i-1][j] + C[i-1][j-1];
				if(C[i][j] >= mod)C[i][j] -= mod;
			}
		}
		
		int I = 99999999;
		int[][][] d = new int[w1+1][w2+1][2]; // [this50][this100][0:this,1:that]
		for(int i = 0;i <= w1;i++){
			for(int j = 0;j <= w2;j++){
				d[i][j][0] = d[i][j][1] = I;
			}
		}
		long[][][] dp = new long[w1+1][w2+1][2];
		dp[w1][w2][0] = 1L;
		d[w1][w2][0] = 0;
		Queue<int[]> q = new ArrayDeque<int[]>();
		q.add(new int[]{w1, w2, 0});
		while(!q.isEmpty()){
			int[] cur = q.poll();
			if(cur[2] == 0){
				int s1 = cur[0], s2 = cur[1];
				for(int j = 0;j <= s1;j++){
					for(int k = 0;k <= s2;k++){
						if(j+k == 0)continue;
						if(50*j+100*k>K)break;
						int ns1 = s1-j, ns2 = s2-k;
						if(d[ns1][ns2][1] == I){
							d[ns1][ns2][1] = d[s1][s2][0] + 1;
							dp[ns1][ns2][1] = dp[s1][s2][0] * C[s1][j] % mod * C[s2][k] % mod;
							q.add(new int[]{ns1, ns2, 1});
						}else if(d[ns1][ns2][1] == d[s1][s2][0] + 1){
							dp[ns1][ns2][1] = (dp[ns1][ns2][1] + dp[s1][s2][0]*C[s1][j]%mod*C[s2][k])%mod;
						}
					}
				}
			}else{
				int s1 = cur[0], s2 = cur[1];
				for(int j = 0;j <= w1-s1;j++){
					for(int k = 0;k <= w2-s2;k++){
						if(j+k == 0)continue;
						if(50*j+100*k>K)break;
						int ns1 = s1+j, ns2 = s2+k;
						if(d[ns1][ns2][0] == I){
							d[ns1][ns2][0] = d[s1][s2][1] + 1;
							dp[ns1][ns2][0] = dp[s1][s2][1] * C[w1-s1][j] % mod * C[w2-s2][k] % mod;
							q.add(new int[]{ns1, ns2, 0});
						}else if(d[ns1][ns2][0] == d[s1][s2][1] + 1){
							dp[ns1][ns2][0] = (dp[ns1][ns2][0] + dp[s1][s2][1]*C[w1-s1][j]%mod*C[w2-s2][k])%mod;
						}
					}
				}
			}
		}
		if(d[0][0][1] == I){
			out.println(-1);
			out.println(0);
		}else{
			out.println(d[0][0][1]);
			out.println(dp[0][0][1]);
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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