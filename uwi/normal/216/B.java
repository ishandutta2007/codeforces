//package round133;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		boolean[][] g = new boolean[n][n];
		for(int i = 0;i < m;i++){
			int f = ni()-1, t = ni()-1;
			g[f][t] = g[t][f] = true;
		}
		
		boolean[] ved = new boolean[n];
		int oddCycle = 0;
		int oddRope = 0;
		for(int i = 0;i < n;i++){
			if(!ved[i]){
				int dim = 0;
				for(int j = 0;j < n;j++){
					if(g[i][j])dim++;
				}
				if(dim == 1){
					ved[i] = true;
					int cur = i;
					int num = 1;
					inner:
					while(true){
						for(int k = 0;k < n;k++){
							if(g[cur][k]){
								ved[k] = true;
								g[cur][k] = g[k][cur] = false;
								num++;
								cur = k;
								continue inner;
							}
						}
						break;
					}
					if(num % 2 == 1){
						oddRope++;
					}
				}
			}
		}
		
		for(int i = 0;i < n;i++){
			if(!ved[i]){
				int dim = 0;
				for(int j = 0;j < n;j++){
					if(g[i][j])dim++;
				}
				if(dim == 2){
					ved[i] = true;
					int cur = i;
					int num = 1;
					inner:
					while(true){
						for(int k = 0;k < n;k++){
							if(g[cur][k]){
								ved[k] = true;
								g[cur][k] = g[k][cur] = false;
								num++;
								cur = k;
								continue inner;
							}
						}
						break;
					}
					num--;
					if(num % 2 == 1){
						oddCycle++;
					}
				}
			}
		}
		
		int free = 0;
		for(int i = 0;i < n;i++){
			if(!ved[i]){
				free++;
			}
		}
		
		out.println(oddCycle + (free + oddRope) % 2);
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