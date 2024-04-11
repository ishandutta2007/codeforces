//package round115;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int[][] t = new int[2][5];
		for(int i = 0;i < 2;i++){
			for(int j = 0;j < 5;j++){
				t[i][j] = ni();
			}
		}
		if(t[0][4] == 100){
			out.printf("%.8f\n", 0.);
			return;
		}
		if(t[1][4] == 100){
			out.printf("%.8f\n", 1.);
			return;
		}
		int[] ord = new int[100];
		int p = 0;
		for(int i = 0;i < t[0][1]*t[1][1];i++){
			if(i % t[0][1] == 0)ord[p++] = 0;
			if(i % t[1][1] == 0)ord[p++] = 1;
		}
		ord = Arrays.copyOf(ord, p);
		
		double[][] dp = new double[2][201];
		dp[0][t[0][0]] = 1;
		dp[1][t[1][0]] = 1;
		int q = 0;
		double[] win = new double[2];
		double[] rest = {1., 1.};
		for(;1.0-win[0]-win[1] >= 1E-5;q=(q+1)%p){
			int u = ord[q];
			double[] ndp = new double[201];
			double w = (1-(double)t[u][4]/100)/(t[u][3]-t[u][2]+1);
			for(int i = 1;i <= 200;i++){
				ndp[i] += dp[u^1][i] * t[u][4] / 100;
				for(int j = t[u][2];j <= t[u][3];j++){
					ndp[Math.max(i-j,0)] += dp[u^1][i] * w;
				}
			}
			dp[u^1] = ndp;
			win[u] += ndp[0]/rest[u]*(1.0-win[0]-win[1]);
			rest[u] -= ndp[0];
		}
		out.printf("%.8f\n", win[0]);
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
		new D4().run();
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