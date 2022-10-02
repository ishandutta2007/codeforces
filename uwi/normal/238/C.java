//package round148;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] from = new int[2*(n-1)];
		int[] to = new int[2*(n-1)];
		int[] dir = new int[2*(n-1)];
		for(int i = 0;i < n-1;i++){
			from[i*2] = ni()-1;
			to[i*2] = ni()-1;
			dir[i*2] = 1;
			from[i*2+1] = to[i*2];
			to[i*2+1] = from[i*2];
			dir[i*2+1] = -1;
		}
		
		int[][][] g = packWD(n, from, to, dir);
		int min = Integer.MAX_VALUE;
		for(int i = 0;i < n;i++){
			int down = dfs(g, i, -1);
			int ret = dfs2(g, i, -1, 0);
//			tr(i, down , ret);
			min = Math.min(min, down + ret);
		}
		out.println(min);
	}
	
	int dfs(int[][][] g, int cur, int pre)
	{
		int ret = 0;
		for(int[] e : g[cur]){
			if(e[0] != pre){
				ret += dfs(g, e[0], cur) + (e[1] == -1 ? 1 : 0);
			}
		}
		return ret;
	}
	
	int dfs2(int[][][] g, int cur, int pre, int ep)
	{
		int ret = ep;
		for(int[] e : g[cur]){
			if(e[0] != pre){
				int nep = Math.min(0, ep + (e[1] == -1 ? -1 : 1));
				ret = Math.min(ret, dfs2(g, e[0], cur, nep));
			}
		}
		return ret;
	}
	
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
		new C2().run();
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