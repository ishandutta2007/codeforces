//package round98;
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
		char[] line = ns(500);
		int n = line.length;
		for(int p = 0, q = n-1;p < q;p++,q--){
			char d = line[p]; line[p] = line[q]; line[q] = d;
		}
		int k = ni();
		
		int[][] dp = new int[n+1][k+1];
		int[][] prev = new int[n+1][k+1];
		for(int[] row : dp){
			Arrays.fill(row, 9999999);
		}
		dp[0][0] = 0;
		for(int i = 1;i <= n;i++){
			int[] cost = new int[n];
			for(int f = 0;f < i;f++){
				// [f,i)
				int diff = 0;
				for(int p = f, q = i-1;p < q;p++,q--){
					if(line[p] != line[q])diff++;
				}
				cost[f] = diff;
			}
			
			for(int j = 1;j <= k;j++){
				for(int f = 0;f < i;f++){
					int v = dp[f][j-1] + cost[f];
					if(v < dp[i][j]){
						dp[i][j] = v;
						prev[i][j] = f;
					}
				}
			}
		}
		
		int min = Integer.MAX_VALUE;
		int minj = -1;
		for(int j = 1;j <= k;j++){
			if(dp[n][j] < min){
				min = dp[n][j];
				minj = j;
			}
		}
		out.println(min);
		for(int u = minj, v = n;u >= 1;u--){
			if(u < minj)out.print("+");
			int nv = prev[v][u];
			for(int x = nv, y = v-1;x < y;x++,y--){
				line[y] = line[x];
			}
			out.print(new String(line, nv, v-nv));
			v = nv;
		}
		out.println();
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