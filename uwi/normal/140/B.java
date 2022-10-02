//package round100;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "4\r\n" + 
			"1 2 3 4\r\n" + 
			"4 1 3 2\r\n" + 
			"4 3 1 2\r\n" + 
			"3 4 2 1\r\n" + 
			"3 1 2 4";
	
	void solve()
	{
		int n = ni();
		int[][] a = new int[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				a[i][j] = ni();
			}
		}
		int[] b = new int[n];
		for(int i = 0;i < n;i++){
			b[i] = ni();
		}
		
		boolean[] alive = new boolean[n];
		int[] best = new int[n];
		int[] bpos = new int[n];
		Arrays.fill(best, n);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(b[j] == i+1){
					alive[j] = true;
					break;
				}
			}
			
			inner:
			for(int j = 0;j < n;j++){ // friend
				for(int k = 0;k < n;k++){ // bind
					if(alive[k] && b[k] != j+1){
						for(int l = 0;l < n;l++){
							if(a[j][l] == b[k]){
								if(l < best[j]){
									best[j] = l;
									bpos[j] = i;
								}
								continue inner;
							}
						}
					}
				}
			}
		}
		
		for(int i = 0;i < n;i++){
			if(i > 0)out.print(" ");
//			out.print(a[i][best[i]]);
			out.print(bpos[i]+1);
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