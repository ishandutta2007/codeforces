//package round135;
import java.io.ByteArrayInputStream;
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
		int n = ni();
		int[] from = new int[2*n-2];
		int[] to = new int[2*n-2];
		int[] w = new int[2*n-2];
		for(int i = 0;i < n-1;i++){
			int f = ni()-1;
			int t = ni()-1;
			from[2*i] = f;
			to[2*i] = t;
			w[2*i] = 1;
			from[2*i+1] = t;
			to[2*i+1] = f;
			w[2*i+1] = 0;
		}
		
		int[][][] g = packWD(n, from, to, w);
		dp = 0;
		ep = new int[n];
		lp = new int[n];
		dfs(g, 0, -1);
		
		int min = 99999999;
		for(int i = 0;i < n;i++){
			min = Math.min(min, dp-(lp[i]-ep[i])+ep[i]);
		}
		out.println(min);
		boolean f = true;
		for(int i = 0;i < n;i++){
			if(min == dp-(lp[i]-ep[i])+ep[i]){
				if(!f)out.print(" ");
				f = false;
				out.print(i+1);
			}
		}
		out.println();
	}
	
	void dfs(int[][][] g, int cur, int prev)
	{
		for(int[] e : g[cur]){
			if(e[0] != prev){
				ep[e[0]] = ep[cur] + e[1];
				lp[e[0]] = lp[cur] + 1;
				dfs(g, e[0], cur);
				dp += 1-e[1];
			}
		}
	}
	
	int dp;
	
	int[] ep, lp;
	
	public static int[][][] packWD(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]][2];
		for(int i = 0;i < from.length;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
		}
		return g;
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