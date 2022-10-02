//package saratov11;
import java.io.ByteArrayInputStream;
import java.io.FileInputStream;
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
		int n = ni(), m = ni();
		int[][] a = new int[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				a[i][j] = ni();
			}
		}
		int[] son = new int[3];
		for(int i = 0;i < 3;i++)son[i] = ni();
		
		int[] row = new int[n];
		int[] rs = new int[n+1];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				row[i] += a[i][j];
			}
		}
		for(int i = 0;i < n;i++){
			rs[i+1] = rs[i] + row[i];
		}
		int[] col = new int[m];
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				col[i] += a[j][i];
			}
		}
		int[] cs = new int[m+1];
		for(int i = 0;i < m;i++){
			cs[i+1] = cs[i] + col[i];
		}
		
		Arrays.sort(son);
		
		int ct = 0;
		for(int i = 1;i < n;i++){
			for(int j = i+1;j < n;j++){
				int[] u = new int[]{rs[i], rs[j] - rs[i], rs[n]-rs[j]};
				Arrays.sort(u);
				if(son[0] == u[0] && son[1] == u[1] && son[2] == u[2]){
					ct++;
				}
			}
		}
		for(int i = 1;i < m;i++){
			for(int j = i+1;j < m;j++){
				int[] u = new int[]{cs[i], cs[j] - cs[i], cs[m]-cs[j]};
				Arrays.sort(u);
				if(son[0] == u[0] && son[1] == u[1] && son[2] == u[2]){
					ct++;
				}
			}
		}
		out.println(ct);
	}
	
	void run() throws Exception
	{
		is = oj ? new FileInputStream("input.txt") : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter("output.txt");
		
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