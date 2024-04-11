//package round146;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] from = new int[n];
		int[] to = new int[n];
		for(int i = 0;i < n;i++){
			from[i] = ni();
			to[i] = ni();
		}
		
		int[][] g = packU(n, from, to);
		int[] ring = dfs(g, 0, -1, new int[n], new int[n], 0);
		boolean[] iring = new boolean[n];
		for(int r : ring)iring[r] = true;
		int R = ring.length;
		int I = 9999999;
		
		int[] q = new int[n];
		int[] d = new int[n];
		int[] f = new int[n];
		double ret = 0;
		for(int i = 0;i < n;i++){
			Arrays.fill(d, I);
			
			d[i] = 0;
			f[i] = 0;
			int p = 0;
			q[p++] = i;
			for(int z = 0;z < p;z++){
				int cur = q[z];
				for(int e : g[cur]){
					if(d[e] == I){
						d[e] = d[cur] + 1;
						f[e] = f[cur] + (iring[e] && iring[cur] ? 1 : 0);
						q[p++] = e;
					}
				}
			}
			
			for(int j = 0;j < n;j++){
				if(f[j] != 0){
					ret += 1./(d[j]+1)+1./(d[j]-f[j]+(R-f[j])+1)-1./(d[j]-f[j]+R-1+1);
				}else{
					ret += 1./(d[j]+1);
				}
			}
		}
		out.printf("%.12f\n", ret);
	}
	
	private static int[] dfs(int[][] g, int cur, int pre, int[] flag, int[] hist, int dep)
	{
		flag[cur] = dep+1;
		hist[dep] = cur;
		for(int e : g[cur]){
			if(e != pre && flag[e] != -1){
				if(flag[e] >= 1){
					return Arrays.copyOfRange(hist, flag[e]-1, dep+1);
				}else{
					int[] res = dfs(g, e, cur, flag, hist, dep+1);
					if(res != null)return res;
				}
			}
		}
		flag[cur] = -1;
		return null;
	}
	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
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
		new D3().run();
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