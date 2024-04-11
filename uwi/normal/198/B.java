//package round125;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		char[][] b = new char[2][];
		for(int i = 0;i < 2;i++){
			b[i] = ns(n);
		}
		int[][] d = new int[2][n];
		int I = Integer.MAX_VALUE / 10;
		for(int i = 0;i < 2;i++){
			Arrays.fill(d[i], I);
		}
		d[0][0] = 0;
		Queue<int[]> q = new ArrayDeque<int[]>();
		q.add(new int[]{0, 0});
		while(!q.isEmpty()){
			int[] cur = q.poll();
			int r = cur[0], c = cur[1];
			if(c+K >= n){
				out.println("YES");
				return;
			}
			if(c+1 < n && b[r][c+1] == '-' && d[r][c+1] > d[r][c] + 1 && c+1 >= d[r][c]+1){
				d[r][c+1] = d[r][c]+1;
				q.add(new int[]{r, c+1});
			}
			if(c-1 >= 0 && b[r][c-1] == '-' && d[r][c-1] > d[r][c] + 1 && c-1 >= d[r][c]+1){
				d[r][c-1] = d[r][c]+1;
				q.add(new int[]{r, c-1});
			}
			if(c+K < n && b[r^1][c+K] == '-' && d[r^1][c+K] > d[r][c] + 1 && c+K >= d[r][c]+1){
				d[r^1][c+K] = d[r][c]+1;
				q.add(new int[]{r^1, c+K});
			}
		}
		out.println("NO");
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