//package round10;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D_re {
	InputStream is;
	PrintWriter out;
	String INPUT = "3 1 2 3 3 1 3 2";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[n-1-i] = ni();
		int m = ni();
		int[] b = new int[m];
		for(int i = 0;i < m;i++)b[m-1-i] = ni();
		
		int[][] dp = new int[n][m];
		int[][] rowmax = new int[n][m+1];
		int[][] rowmaxp = new int[n][m+1];
		int[][][] prev = new int[n][m][2];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(a[i] == b[j]){
					int max = 0;
					int maxk = -1;
					int maxl = -1;
					for(int k = 0;k < i;k++){
						if(max < rowmax[k][j] && a[k] > a[i]){
							max = rowmax[k][j];
							maxk = k;
							maxl = rowmaxp[k][j];
						}
					}
					dp[i][j] = max + 1;
					prev[i][j][0] = maxk;
					prev[i][j][1] = maxl;
				}else{
					prev[i][j][0] = -1;
					prev[i][j][1] = -1;
				}
				if(rowmax[i][j] < dp[i][j]){
					rowmax[i][j+1] = dp[i][j];
					rowmaxp[i][j+1] = j;
				}else{
					rowmax[i][j+1] = rowmax[i][j];
					rowmaxp[i][j+1] = rowmaxp[i][j];
				}
			}
		}
		
		int ml = 0;
		int mli = -1, mlj = -1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(dp[i][j] > ml){
					ml = dp[i][j];
					mli = i; mlj = j;
				}
			}
		}
		
		out.println(ml);
		if(ml > 0){
			for(int r = mli, c = mlj;!(r == -1 && c == -1);){
				if(r != mli)out.print(" ");
				out.print(a[r]);
				
				int nr = prev[r][c][0];
				int nc = prev[r][c][1];
				r = nr; c = nc;
			}
			out.println();
		}
	}
	
	void run() throws Exception
	{
//		StringBuilder sb = new StringBuilder();
//		int n = 500;
//		Random gen = new Random(999);
//		for(int q = 0;q < 2;q++){
//			sb.append(n + " ");
//			for(int i = 0;i < n;i++){
////				sb.append(gen.nextInt(1000000001) + " ");
//				sb.append(gen.nextInt(1) + " ");
//			}
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new D_re().run();
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