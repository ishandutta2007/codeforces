//package round2;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class B2 {
	IntReader in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = nui();
		int[][] m = new int[n][n];
		boolean zero = false;
		int zi = -1, zj = -1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				m[i][j] = nui();
				if(m[i][j] == 0){
					zero = true;
					zi = i;
					zj = j;
				}
			}
		}
		
		int[] d = {2, 5};
		int[][] dp = new int[n][n];
		int[] z = new int[2];
		StringBuilder[] route = new StringBuilder[2];
		for(int k = 0;k < 2;k++){
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					if(i == 0){
						if(j == 0){
							dp[i][j] = 0;
						}else{
							dp[i][j] = dp[i][j-1];
						}
					}else{
						if(j == 0){
							dp[i][j] = dp[i-1][j];
						}else{
							dp[i][j] = Math.min(dp[i][j-1], dp[i-1][j]);
						}
					}
					int p = 0;
					int o = m[i][j];
					if(o == 0){
						dp[i][j] = 99999999;
					}else{
						while(o%d[k]==0){
							o/=d[k];
							p++;
						}
						dp[i][j] += p;
					}
				}
			}
			z[k] = dp[n-1][n-1];
			int r = n - 1;
			int c = n - 1;
			StringBuilder sb = new StringBuilder();
			while(r != 0 || c != 0){
				if(r == 0){
					sb.append('R');
					c--;
				}else if(c == 0){
					sb.append('D');
					r--;
				}else if(dp[r][c-1] < dp[r-1][c]){
					sb.append('R');
					c--;
				}else{
					sb.append('D');
					r--;
				}
			}
			route[k] = sb;
		}
		int kk = z[0] < z[1] ? 0 : 1;
		if(!zero || z[kk] <= 1){
			out.println(z[kk]);
			out.println(route[kk].reverse());
		}else{
			StringBuilder sb = new StringBuilder();
			for(int i = 0;i < zi;i++){
				sb.append('D');
			}
			for(int i = 0;i < zj;i++){
				sb.append('R');
			}
			for(int i = zi+1;i < n;i++){
				sb.append('D');
			}
			for(int i = zj+1;i < n;i++){
				sb.append('R');
			}
			out.println(1);
			out.println(sb);
		}
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new IntReader(System.in) : new IntReader(new ByteArrayInputStream(INPUT.getBytes()));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new B2().run();
	}
	
	public class IntReader {
		private InputStream is;
		
		public IntReader(InputStream is)
		{
			this.is = is;
		}
		
		public int nui()
		{
			try {
				int num = 0;
				while((num = is.read()) < '0' || num > '9');
				num -= '0';
				
				while(true){
					int b = is.read();
					if(b >= '0' && b <= '9'){
						num = num * 10 + (b - '0');
					}else{
						return num;
					}
				}
			} catch (IOException e) {
			}
			return -1;
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
		
		public String nl()
		{
			try{
				int b = 0;
				StringBuilder sb = new StringBuilder();
				while((b = is.read()) != -1 && (b == '\r' || b == '\n'));
				if(b == -1)return "";
				sb.append((char)b);
				while(true){
					b = is.read();
					if(b == -1)return sb.toString();
					if(b == '\r' || b == '\n')return sb.toString();
					sb.append((char)b);
				}
			} catch (IOException e) {
			}
			return "";
		}
	}
	
	int ni() { return in.ni(); }
	int nui() { return in.nui(); }
	String nl() { return in.nl(); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}