//package round95;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		char[][] b = new char[n][];
		for(int i = 0;i < n;i++){
			b[i] = ns(m);
		}
		
		boolean[][] star = new boolean[n][m];
		for(int i = 1;i < n-1;i++){
			for(int j = 1;j < m-1;j++){
				if(b[i][j] == '1' && b[i-1][j] == '1' && b[i+1][j] == '1' &&
						b[i][j-1] == '1' && b[i][j+1] == '1'){
					star[i][j] = true;
				}
			}
		}
		int[][] rowsum = new int[n][m+1];
		for(int i = 0;i < n;i++){
			for(int j = 1;j <= m;j++){
				rowsum[i][j] = rowsum[i][j-1] + (star[i][j-1] ? 1 : 0);
			}
		}
		
		int[][] rectsum = new int[n+1][m+1];
		for(int j = 0;j <= m;j++){
			for(int i = 1;i <= n;i++){
				rectsum[i][j] = rectsum[i-1][j] + rowsum[i-1][j];
			}
		}
		
		long ret = 0;
		for(int i = 1;i < n-1;i++){
			for(int j = 1;j < m-1;j++){
				int c = m-2;
				for(int r = i;r < n-1;r++){
					while(c >= j && rectsum[r+1][c+1]-rectsum[r+1][j]-rectsum[i][c+1]+rectsum[i][j] >= K){
						c--;
					}
//					tr(i, j, r, c, m-1-c);
					ret += m-2-c;
				}
			}
		}
		out.println(ret);
	}
	
	void run() throws Exception
	{
//		int n = 500, m = 500;
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " " + m + " " + 999 + " ");
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < m;j++){
//				sb.append(1);
//			}
//			sb.append('\n');
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
		new F().run();
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