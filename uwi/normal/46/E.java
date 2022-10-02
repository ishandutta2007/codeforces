//package round43;


import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E {
	private static IntReader in;
	private static PrintWriter out;
	private static String INPUT = "";
	
	public static void solve()
	{
		int n = in.ni();
		int m = in.ni();
		int[][] a = new int[n][m];
		for(int i = 0;i < n;i++){
			int sum = 0;
			for(int j = 0;j < m;j++){
				sum += in.ni();
				a[i][j] = sum;
			}
		}
		
		long[][] dp = new long[n][m];
		for(int j = 0;j < m;j++){
			dp[0][j] = a[0][j];
		}
		for(int i = 1;i < n;i++){
			if(i % 2 == 0){
				dp[i][0] = Long.MIN_VALUE / 9999;
			}else{
				dp[i][m - 1] = Long.MIN_VALUE / 9999;
			}
			for(int j = 1;j < m;j++){
				if(i % 2 == 0){
					dp[i][j] = Math.max(dp[i][j-1], dp[i-1][j-1]);
				}else{
					dp[i][m - 1 - j] = Math.max(dp[i][m - 1 - j + 1], dp[i-1][m - 1 - j + 1]);
				}
			}
			
			for(int j = 0;j < m;j++){
				dp[i][j] += a[i][j];
			}
		}
		long max = Long.MIN_VALUE;
		for(int i = 0;i < m;i++){
			max = Math.max(max, dp[n-1][i]);
		}
		out.println(max);
	}
	
	public static void main(String[] args) throws Exception
	{
		in = INPUT.isEmpty() ? new IntReader(System.in) : new IntReader(new ByteArrayInputStream(INPUT.getBytes()));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	public static class IntReader {
		private InputStream is;
		
		public IntReader(InputStream is)
		{
			this.is = is;
		}
		
		public int ni()
		{
			try {
				int num = 0;
				boolean minus = false;
				while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
				if(num == '-'){
					num = 0;
					minus = true;
				}else{
					num -= '0';
				}
				
				while(true){
					int b = is.read();
					if(b == -1)return minus ? -num : num;
					if(b >= '0' && b <= '9'){
						num = num * 10 + (b - '0');
					}else{
						return minus ? -num : num;
					}
				}
			} catch (IOException e) {
			}
			return -1;
		}
	}
	
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}