//package round99;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int S = 22;
	int H = 10;
	
	void solve()
	{
		// 0,n+m
		// 0+1,n-1+m-1+1
		// -(n-1)+(n-1)+1,m-1+(n-1)+1
		int n = ni(), m = ni();
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++){
			map[i] = ns(m);
		}
		
		char[][] emap = new char[S][S];
		char[][] omap = new char[S][S];
		for(int i = 0;i < S;i++){
			for(int j = 0;j < S;j++){
				emap[i][j] = ' ';
				omap[i][j] = ' ';
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if((i+j)%2 == 0){
					emap[(i+j)/2][H+(-i+j)/2] = map[i][j];
				}else{
					omap[(i+j+1)/2][H+(-i+j+1)/2] = map[i][j];
				}
			}
		}
//		for(int i = 0;i < S;i++){
//			tr(emap[i]);
//		}
//		tr();
//		for(int i = 0;i < S;i++){
//			tr(omap[i]);
//		}
		
		int gr = solve(emap)^solve(omap);
		if(gr == 0){
			out.println("LOSE");
		}else{
			out.println("WIN");
		}
	}
	
	int solve(char[][] map)
	{
		int[][][][] dp = new int[S+2][S+2][S+2][S+2];
		for(int li = 2;li <= S+1;li++){
			for(int rl = 0;rl+li <= S+1;rl++){
				int rr = rl + li;
				for(int lj = 2;lj <= S+1;lj++){
					for(int cl = 0;cl+lj <= S+1;cl++){
						int cr = cl+lj;
						
						BitSet bs = new BitSet();
						for(int i = rl+1;i <= rr-1;i++){
							for(int j = cl+1;j <= cr-1;j++){
								if(map[i-1][j-1] == 'L'){
									bs.set(dp[rl][i][cl][cr]^dp[i][rr][cl][cr]);
								}else if(map[i-1][j-1] == 'R'){
									bs.set(dp[rl][rr][cl][j]^dp[rl][rr][j][cr]);
								}else if(map[i-1][j-1] == 'X'){
									bs.set(dp[rl][i][cl][j]^dp[rl][i][j][cr]^dp[i][rr][cl][j]^dp[i][rr][j][cr]);
								}
							}
						}
						dp[rl][rr][cl][cr] = bs.nextClearBit(0);
					}
				}
			}
		}
//		tr(dp[1][3][20][23]);
//		tr(map[1][20]);
		return dp[0][S+1][0][S+1];
	}
	
	void run() throws Exception
	{
//		int n = 20, m = 20;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < n; i++) {
//			for(int j = 0;j < m;j++){
//				sb.append("X");
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