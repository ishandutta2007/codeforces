//package round154;
import java.io.ByteArrayInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D2 {
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
		
		int[][] act = new int[n+1][m+1];
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				act[i][j] = act[i-1][j] + act[i][j-1] - act[i-1][j-1] + (b[i-1][j-1]=='a' ? 1 : 0);
			}
		}
		
		long ret = 0;
		for(int j = 0;j < m;j++){
			int[] bot = new int[n];
			Arrays.fill(bot, n-1);
			for(int k = j+1;k < m;k++){
				int[] cor = new int[26];
				for(int i = 0;i < n;i++){
					while(bot[i] > i && act[bot[i]+1][k+1]+act[i][j]-act[bot[i]+1][j]-act[i][k+1] > K)bot[i]--;
//					if(bot[j] == i)break;
					// (i,j)-(bot,k)
					for(int u = i==0?0:bot[i-1]+1;u <= bot[i];u++){
						if(b[u][j] == b[u][k])cor[b[u][j]-'a']++;
					}
					if(bot[i] > i && b[i][j] == b[i][k]){
//						tr(cor, i, j, bot[i], k);
						ret += cor[b[i][j]-'a']-1;
					}
					
					if(b[i][j] == b[i][k])cor[b[i][j]-'a']--;
				}
			}
		}
		out.println(ret);
	}
	
	void run() throws Exception
	{
		is = oj ? new FileInputStream("input.txt") : new ByteArrayInputStream(INPUT.getBytes());
		out = oj ?  new PrintWriter("output.txt") : new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new D2().run();
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