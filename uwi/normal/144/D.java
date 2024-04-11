//package round103;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.TreeSet;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), s = ni()-1;
		int[] from = new int[m];
		int[] to = new int[m];
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			w[i] = ni();
		}
		int L = ni();
		
		int[][][] g = packWU(n, from, to, w);
		int[] d = dijk(g, s);
		
		int ct = 0;
		for(int i = 0;i < m;i++){
			int df = d[from[i]];
			int dt = d[to[i]];
			if(w[i] > Math.abs(dt-df)){
				// Math.max(df,dt)+(w[i]-Math.abs(dt-df))/2
				int H = 2*Math.max(df,dt)+(w[i]-Math.abs(dt-df));
				if(H==2*L){
					ct++;
				}else if(H>2*L){
					if(df<L)ct++;
					if(dt<L)ct++;
				}
			}else{
				if(df<L && dt>L)ct++;
				if(dt<L && df>L)ct++;
			}
		}
		for(int i = 0;i < n;i++){
			if(d[i] == L)ct++;
		}
		out.println(ct);
	}
	
	public static int[] dijk(int[][][] g, int from) {
		int n = g.length;
		final int[] td = new int[n];
		Arrays.fill(td, Integer.MAX_VALUE);
		TreeSet<Integer> q = new TreeSet<Integer>(new Comparator<Integer>() {
			public int compare(Integer a, Integer b) {
				if (td[a] - td[b] != 0)
					return td[a] - td[b];
				return a - b;
			}
		});
		q.add(from);
		td[from] = 0;

		while (q.size() > 0) {
			int cur = q.pollFirst();

			for (int i = 0; i < g[cur].length; i++) {
				int next = g[cur][i][0];
				int nd = td[cur] + g[cur][i][1];
				if (nd < td[next]) {
					q.remove(next);
					td[next] = nd;
					q.add(next);
				}
			}
		}

		return td;
	}
	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w)
	{
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int f : from)p[f]++;
		for(int t : to)p[t]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]][2];
		for(int i = 0;i < from.length;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			g[to[i]][p[to[i]]][1] = w[i];
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