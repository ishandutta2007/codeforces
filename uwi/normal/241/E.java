//package bayan2012;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	static int[][] packD(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
			g[from[i]][--p[from[i]]] = to[i];
		}
		return g;
	}
	
	void dfs(int[][] g, int cur, BitSet bs)
	{
		bs.set(cur);
		for(int e : g[cur]){
			if(!bs.get(e)){
				dfs(g, e, bs);
			}
		}
	}
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packD(n, from, to);
		BitSet cango = new BitSet();
		dfs(g, 0, cango);
		int[][] ig = packD(n, to, from);
		BitSet cande = new BitSet();
		dfs(ig, n-1, cande);
		cango.and(cande);
		
		int[] fs = new int[2*m];
		int[] ts = new int[2*m];
		int[] w  = new int[2*m];
		int p = 0;
		for(int i = 0;i < m;i++){
			if(cango.get(from[i]) && cango.get(to[i])){
				fs[p] = from[i]; ts[p] = to[i]; w[p] = 2;
				fs[p+1] = to[i]; ts[p+1] = from[i]; w[p+1] = -1;
				p += 2;
			}
		}
		fs = Arrays.copyOf(fs, p);
		ts = Arrays.copyOf(ts, p);
		w = Arrays.copyOf(w, p);
		int[] d = bf(fs, ts, w, n, 0);
		if(d == null){
			out.println("No");
		}else{
			out.println("Yes");
			for(int i = 0;i < m;i++){
				if(cango.get(from[i]) && cango.get(to[i])){
					out.println(d[to[i]] - d[from[i]]);
				}else{
					out.println(1);
				}
			}
		}
	}
	
	public static int[] bf(int[] from, int[] to, int[] w, int n, int start)
	{
		int[] d = new int[n];
		Arrays.fill(d, Integer.MAX_VALUE / 2);
		d[start] = 0;
		int m = from.length;
		
		for(int r = 0;r < n-1;r++){
			boolean updated = false;
			for(int j = 0;j < m;j++){
				if(d[from[j]] + w[j] < d[to[j]]){
					d[to[j]] = d[from[j]] + w[j];
					updated = true;
				}
			}
			if(!updated)break;
		}
		for(int i = 0;i < m;i++){
			if(d[from[i]] + w[i] < d[to[i]]){
				return null;
			}
		}
		
		return d;
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
		new E().run();
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