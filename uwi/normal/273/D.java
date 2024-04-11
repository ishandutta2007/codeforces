//package round167;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int mod = 1000000007;
		int n = ni(), m = ni();
		int[][][][] dp = new int[n][n][2][2];
		long ret = 0;
		for(int i = 0;i < m;i++){
			long[][][][] imos = new long[n+1][n+1][2][2];
			if(i > 0){
				for(int j = 0;j < n;j++){
					for(int k = j;k < n;k++){
						imos[j][j][0][0] += dp[j][k][0][0];
						imos[j][k+1][0][0] -= dp[j][k][0][0];
						imos[k+1][j][0][0] -= dp[j][k][0][0];
						imos[k+1][k+1][0][0] += dp[j][k][0][0];
						
						imos[j][j][0][0] += dp[j][k][0][1];
						imos[j][k][0][0] -= dp[j][k][0][1];
						imos[k+1][j][0][0] -= dp[j][k][0][1];
						imos[k+1][k][0][0] += dp[j][k][0][1];
						imos[j][k][0][1] += dp[j][k][0][1];
//						imos[j][n][0][1] -= dp[j][k][0][1];
						imos[k+1][k][0][1] -= dp[j][k][0][1];
//						imos[k+1][n][0][1] += dp[j][k][0][1];
						
						imos[j+1][j][0][0] += dp[j][k][1][0];
						imos[j+1][k+1][0][0] -= dp[j][k][1][0];
						imos[k+1][j][0][0] -= dp[j][k][1][0];
						imos[k+1][k+1][0][0] += dp[j][k][1][0];
						imos[0][j][1][0] += dp[j][k][1][0];
						imos[0][k+1][1][0] -= dp[j][k][1][0];
						imos[j+1][j][1][0] -= dp[j][k][1][0];
						imos[j+1][k+1][1][0] += dp[j][k][1][0];
						
						imos[j+1][j][0][0] += dp[j][k][1][1];
						imos[j+1][k][0][0] -= dp[j][k][1][1];
						imos[k+1][j][0][0] -= dp[j][k][1][1];
						imos[k+1][k][0][0] += dp[j][k][1][1];
						imos[j+1][k][0][1] += dp[j][k][1][1];
//						imos[j+1][n][0][1] -= dp[j][k][1][1];
						imos[k+1][k][0][1] -= dp[j][k][1][1];
//						imos[k+1][n][0][1] += dp[j][k][1][1];
						imos[0][j][1][0] += dp[j][k][1][1];
						imos[0][k][1][0] -= dp[j][k][1][1];
						imos[j+1][j][1][0] -= dp[j][k][1][1];
						imos[j+1][k][1][0] += dp[j][k][1][1];
						imos[0][k][1][1] += dp[j][k][1][1];
//						imos[0][n][1][1] -= dp[j][k][1][1];
						imos[j+1][k][1][1] -= dp[j][k][1][1];
//						imos[j+1][n][1][1] += dp[j][k][1][1];
					}
				}
			}
			
			imos[0][0][1][1]++;
			
			for(int j = 0;j < n;j++){
				for(int k = 0;k < n;k++){
					for(int u = 0;u < 2;u++){
						for(int v = 0;v < 2;v++){
							if(k-1 >= 0)imos[j][k][u][v] += imos[j][k-1][u][v];
							if(j-1 >= 0)imos[j][k][u][v] += imos[j-1][k][u][v];
							if(j-1 >= 0 && k-1 >= 0)imos[j][k][u][v] -= imos[j-1][k-1][u][v];
							if(j <= k){
								dp[j][k][u][v] = (int)(imos[j][k][u][v] % mod);
								ret += dp[j][k][u][v];
							}
						}
					}
				}
			}
		}
		
		out.println(ret%mod);
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
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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