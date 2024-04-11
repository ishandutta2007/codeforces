//package round83;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class C3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "8 2004 6\r\n" + 
			"7 4\r\n" + 
			"6 4\r\n" + 
			"7 5\r\n" + 
			"5 8\r\n" + 
			"8 4\r\n" + 
			"8 2";
	
	void solve()
	{
		int n = ni();
		long y = nl()-2001;
		int m = ni();
		
		int[][] lt = new int[m][2];
		for(int i = 0;i < m;i++){
			lt[i][0] = ni() - 1;
			lt[i][1] = ni() - 1;
		}
		
		int[] a = new int[n];
		int used = 0;
		outer:
		for(int i = 0;i < n;i++){
			inner:
			for(int j = 0;j < n;j++){
				if(used<<31-j>=0){
					a[i] = j;
					for(int k = 0;k < m;k++){
						if(lt[k][0] <= i && lt[k][1] <= i && a[lt[k][0]] > a[lt[k][1]])continue inner;
					}
					
					int L = n-i-1;
					long[] dp = new long[1<<L]; // position
					dp[0] = 1;
					int[] left = new int[n];
					int lp = 0;
					for(int k = 0;k < n;k++){
						if(used<<31-k>=0 && j != k)left[lp++] = k;
					}
					
					for(int k = 1;k < 1<<L;k++){
						int h = Integer.bitCount(k)-1;
						iinner:
						for(int l = 0;l < L;l++){
							if(k<<31-l<0){
								for(int f = 0;f < m;f++){
									if(lt[f][0] <= i && lt[f][1] == i+1+l && a[lt[f][0]] > left[h])continue iinner;
									if(lt[f][0] == i+l+1 && lt[f][1] <= i && left[h] > a[lt[f][1]])continue iinner;
									if(lt[f][0] == i+l+1 && lt[f][1] > i && k<<31-(lt[f][1]-(i+1))<0)continue iinner;
								}
								dp[k] += dp[k^1<<l];
							}
						}
					}
					
					long v = dp[(1<<L)-1];
					if(y < v){
						used |= 1<<j;
						continue outer;
					}else{
						y -= v;
					}
				}
			}
			out.println("The times have changed");
			return;
		}
		for(int i = 0;i < n;i++){
			if(i > 0)out.print(' ');
			out.print(a[i]+1);
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
		new C3().run();
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