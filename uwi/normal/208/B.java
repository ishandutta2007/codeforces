//package round130;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		char[][] c = new char[n][];
		for(int i = 0;i < n;i++){
			c[i] = ns(2);
		}
		if(n >= 3){
			boolean[][][][] dp = new boolean[2][n][n][n];
			dp[0][n-3][n-2][n-1] = true;
			int cur = 1, prev = 0;
			for(int x = n-1;x >= 3;x--, cur^=1, prev^=1){
				for(int i = 0;i < n;i++){
					for(int j = 0;j < n;j++){
						Arrays.fill(dp[cur][i][j], false);
					}
				}
				for(int i = 0;i < n;i++){
					for(int j = 0;j < n;j++){
						for(int k = 0;k < n;k++){
							if(dp[prev][i][j][k]){
								dp[cur][x-3][i][k] |= c[j][0]==c[k][0] || c[j][1]==c[k][1];
								dp[cur][k][i][j] |= c[x-3][0]==c[k][0] || c[x-3][1]==c[k][1];
							}
						}
					}
				}
			}
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					for(int k = 0;k < n;k++){
						if(dp[prev][i][j][k]){
							if(c[j][0]==c[k][0]||c[j][1]==c[k][1]){
								if(c[i][0]==c[k][0]||c[i][1]==c[k][1]){
									out.println("YES");
									return;
								}
							}
						}
					}
				}
			}
			out.println("NO");
		}else if(n == 1){
			out.println("YES");
		}else{
			if(c[0][0]==c[1][0]||c[0][1]==c[1][1]){
				out.println("YES");
			}else{
				out.println("NO");
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
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
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
	
	public long nl()
	{
		try {
			long num = 0;
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
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}