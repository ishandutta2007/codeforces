//package round8;
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
		int x = ni(), y = ni();
		int n = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = new int[]{ni()-x, ni()-y};
		}
		
		int[] c1 = new int[n];
		int[][] c2 = new int[n][n];
		for(int i = 0;i < n;i++){
			c1[i] = (co[i][0]*co[i][0]+co[i][1]*co[i][1])*2;
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				c2[i][j] = c2[j][i] = (co[i][0]*co[i][0]+co[i][1]*co[i][1])+(co[j][0]*co[j][0]+co[j][1]*co[j][1])+(co[j][0]-co[i][0])*(co[j][0]-co[i][0])+(co[j][1]-co[i][1])*(co[j][1]-co[i][1]);
			}
		}
		
		int[] dp = new int[1<<n];
		int[] prev = new int[1<<n];
		prev[0] = -1;
		for(int i = 1;i < 1<<n;i++){
			int a = Integer.numberOfTrailingZeros(i);
			dp[i] = c1[a] + dp[i^1<<a];
			prev[i] = 1<<a;
			for(int j = a+1;j < n;j++){
				if(i<<31-j<0){
					int v = dp[i^1<<a^1<<j] + c2[a][j];
					if(v < dp[i]){
						dp[i] = v;
						prev[i] = 1<<a^1<<j;
					}
				}
			}
		}
		out.println(dp[(1<<n)-1]);
		int cur = (1<<n)-1;
		out.print("0");
		while(true){
			int targ;
			if(prev[cur] == -1){
				targ = cur;
			}else{
				targ = prev[cur];
				cur ^= prev[cur];
			}
			int a = Integer.numberOfTrailingZeros(targ);
			int b = Integer.numberOfTrailingZeros(targ&targ-1);
			if(targ == 1<<a){
				out.print(" " + (a+1));
			}else{
				out.print(" " + (a+1));
				out.print(" " + (b+1));
			}
			out.print(" 0");
			if(cur == 0)break;
		}
		out.println();
	}
	
	void run() throws Exception
	{
//		int n = 24, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(0 + " " + 0  + " " + n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(100) + " ");
//			sb.append(gen.nextInt(100) + " ");
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