//package round155;
import java.io.ByteArrayInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), v = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		int m = ni();
		int[][] fr = new int[m][];
		for(int i = 0;i < m;i++){
			fr[i] = new int[]{ni()-1, ni()-1, ni(), i+1}; // from to food ind
		}
		
		Arrays.sort(fr, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[2] - b[2];
			}
		});
		
		int[][] ev = new int[2*m][];
		for(int i = 0;i < m;i++){
			ev[2*i] = new int[]{i, fr[i][0]};
			ev[2*i+1] = new int[]{i, fr[i][1]+1};
		}
		Arrays.sort(ev, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1] - b[1];
			}
		});
		
		int[][] dp = new int[n+1][401];
		for(int i = 0;i <= n;i++){
			Arrays.fill(dp[i], -999999);
		}
		
		int[][][] prev = new int[n+1][401][];
		boolean[] alive = new boolean[m];
		dp[0][0] = 0;
		int p = 0;
		for(int i = 0;i < n;i++){ // day i
			while(p < 2*m && ev[p][1] <= i){
				alive[ev[p][0]] ^= true;
				p++;
			}
			for(int j = 0;j <= 400;j++){ // left 
				int have = j+a[i]-v;
				int nex = Math.min(have, a[i]);
				if(nex >= 0 && nex <= 400){
					if(dp[i][j] > dp[i+1][nex]){
						dp[i+1][nex] = dp[i][j];
						prev[i+1][nex] = new int[]{j, -1};
					}
				}
				int rate = 0;
				for(int k = 0;k < m;k++){
					if(alive[k]){
						have -= fr[k][2];
						if(have < 0)break;
						nex = Math.min(have, a[i]);
						rate++;
						if(dp[i][j]+rate > dp[i+1][nex]){
							dp[i+1][nex] = dp[i][j]+rate;
							prev[i+1][nex] = new int[]{j, k};
						}
					}
				}
			}
		}
		
		int max = -9999999;
		int maxj = -1;
		for(int j = 0;j <= 400;j++){
			if(max < dp[n][j]){
				max = dp[n][j];
				maxj = j;
			}
		}
		out.println(max);
		
		int[] lims = new int[n];
		for(int i = n;i >= 1;i--){
			lims[i-1] = prev[i][maxj][1];
			maxj = prev[i][maxj][0];
		}
		
		Arrays.fill(alive, false);
		p = 0;
		for(int i = 0;i < n;i++){ // day i
			while(p < 2*m && ev[p][1] <= i){
				alive[ev[p][0]] ^= true;
				p++;
			}
			StringBuilder row = new StringBuilder();
			int valid = 0;
			for(int k = 0;k <= lims[i];k++){
				if(alive[k]){
					row.append(" ").append(fr[k][3]);
					valid++;
				}
			}
			out.print(valid);
			out.println(row);
		}
	}
	
	void run() throws Exception
	{
//		int n = 400, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(1 + " ");
//		for(int i = 0;i < n;i++){
//			sb.append((gen.nextInt(400)+1) + " ");
//		}
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(1 + " ");
//			sb.append(400 + " ");
//			sb.append((gen.nextInt(3)+1) + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? new FileInputStream("input.txt") : new ByteArrayInputStream(INPUT.getBytes());
		out = oj ? new PrintWriter("output.txt") : new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new E2().run();
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