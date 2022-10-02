//package croc2012.mbtu;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class H {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] s = ns(5001);
		int n = s.length;
		int[] rs = palindrome(s);
		tr(rs);
		
		int[][] ct = new int[n][n];
		for(int i = 0;i < rs.length;i++){
			for(int j = (i&1);j < rs[i];j+=2){
				ct[(i-j)/2][(i+j)/2]++;
			}
		}
		for(int i = n-2;i >= 0;i--){
			for(int j = 1;j < n;j++){
				ct[i][j] += ct[i+1][j] + ct[i][j-1]-ct[i+1][j-1];
			}
		}
		
		int Q = ni();
		for(int i = 0;i < Q;i++){
			int f = ni(), t = ni();
			out.println(ct[f-1][t-1]);
		}
	}
	
	public static int[] palindrome(char[] str)
	{
		int n = str.length;
		int[] r = new int[2*n];
		int k = 0;
		for(int i = 0, j = 0;i < 2*n;i += k, j = Math.max(j-k, 0)){
			// 
			while(i-j >= 0 && i+j+1 < 2*n && str[(i-j)/2] == str[(i+j+1)/2])j++;
			r[i] = j;
			
			// 
			for(k = 1;i-k >= 0 && r[i]-k >= 0 && r[i-k] != r[i]-k;k++){
				r[i+k] = Math.min(r[i-k], r[i]-k);
			}
		}
		return r;
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
		new H().run();
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