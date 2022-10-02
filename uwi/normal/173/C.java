//package croc2012.r1;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] a = new int[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				a[i][j] = ni();
			}
		}
		
		int[][] s = new int[n+1][m+1];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];
			}
		}
		
		int[][][] ss = new int[501][][];
		int max = Integer.MIN_VALUE;
		for(int k = 3;k <= n && k <= m;k += 2){
			ss[k] = new int[n-k+1][m-k+1];
			if(k == 3){
				for(int i = 0;i < n-k+1;i++){
					for(int j = 0;j < m-k+1;j++){
						ss[k][i][j] = s[i+3][j+3]-s[i][j+3]-s[i+3][j]+s[i][j]-a[i+1][j+1]-a[i+1][j];
						max = Math.max(max, ss[k][i][j]);
					}
				}
			}else{
				for(int i = 0;i < n-k+1;i++){
					for(int j = 0;j < m-k+1;j++){
						ss[k][i][j] = s[i+k][j+k]-s[i][j+k]-s[i+k][j]+s[i][j]-ss[k-2][i+1][j+1]-a[i+1][j];
						max = Math.max(max, ss[k][i][j]);
					}
				}
			}
		}
		out.println(max);
	}
	
	void run() throws Exception
	{
//		int n = 500, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " " + n + " ");
//		for(int i = 0;i < n*n;i++){
//			sb.append(gen.nextInt(2000)-1000 + " ");
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
		new C().run();
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