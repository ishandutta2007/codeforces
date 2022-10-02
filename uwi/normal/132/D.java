//package round96;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] line = ns(1000000);
		int n = line.length;
		int[][] dp = new int[n+1][2];
		int[][] prev = new int[n+1][2];
		int last = -1;
		for(last = n-1;last >= 0 && line[last] == '0';last--);
		dp[0][1] = 9999999;
		for(int i = 0;i < last;i++){
			if(line[i] == '1'){
				dp[i+1][0] = dp[i][0] + 1;
				prev[i+1][0] = 0;
				if(dp[i][0] + 1 < dp[i][1]){
					dp[i+1][1] = dp[i][0] + 1;
					prev[i+1][1] = 0;
				}else{
					dp[i+1][1] = dp[i][1];
					prev[i+1][1] = 1;
				}
			}else{
				if(dp[i][1] + 1 < dp[i][0]){
					dp[i+1][0] = dp[i][1]+1;
					prev[i+1][0] = 1;
				}else{
					dp[i+1][0] = dp[i][0];
					prev[i+1][0] = 0;
				}
				dp[i+1][1] = dp[i][1] + 1;
				prev[i+1][1] = 1;
			}
		}
		if(line[last] == '1'){
			dp[last+1][0] = dp[last][0] + 1;
			dp[last+1][1] = dp[last][1] + 1;
		}else{
			dp[last+1][0] = dp[last][0];
			dp[last+1][1] = dp[last][1];
		}
		prev[last+1][0] = 0;
		prev[last+1][1] = 1;
		
		out.println(Math.min(dp[last+1][0], dp[last+1][1]));
		int x = dp[last+1][0] < dp[last+1][1] ? 0 : 1;
		boolean sign = true;
		for(int i = last+1;i >= 1;i--){
			if(dp[i-1][prev[i][x]] < dp[i][x]){
				if(prev[i][x] != x){
					sign = !sign;
				}
			}
			x = prev[i][x];
		}
		x = dp[last+1][0] < dp[last+1][1] ? 0 : 1;
		for(int i = last+1;i >= 1;i--){
			if(dp[i-1][prev[i][x]] < dp[i][x]){
				if(prev[i][x] != x){
					sign = !sign;
					out.print(sign?'+':'-');
					out.print("2^");
					out.println(n-i+1);
//					out.printf("%c2^%d\n", sign?'+':'-', n-i+1);
				}else{
					out.print(sign?'+':'-');
					out.print("2^");
					out.println(n-i);
//					out.printf("%c2^%d\n", sign?'+':'-', n-i);
				}
			}
			x = prev[i][x];
		}
	}
	
	void run() throws Exception
	{
//		StringBuilder sb = new StringBuilder();
//		for(int o = 1;o <= 999999;o++) {
//			sb.append(Math.random() < 0.5 ? 1 : 0);
//		}
//		INPUT = "1" + sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
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