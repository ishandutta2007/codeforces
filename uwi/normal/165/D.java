//package round112;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	static class DJSet { public int[] upper; public DJSet(int n){ upper = new int[n]; Arrays.fill(upper, -1);} public int root(int x){	return upper[x] < 0 ? x : (upper[x] = root(upper[x]));}	public boolean equiv(int x, int y){ return root(x) == root(y);} public void union(int x, int y){ x = root(x);y = root(y);if(x != y) { if(upper[y] < upper[x]) { int d = x; x = y; y = d;	} upper[x] += upper[y]; upper[y] = x;}} public int count(){	int ct = 0;	for(int i = 0;i < upper.length;i++){ if(upper[i] < 0)ct++; } return ct; }}
	
	void solve()
	{
		int n = ni();
		int[] f = new int[n-1];
		int[] t = new int[n-1];
		for(int i = 0;i < n-1;i++){
			f[i] = ni()-1;
			t[i] = ni()-1;
		}
		DJSet ds = new DJSet(n);
		int[][] g = packU(n, f, t);
		int cent = 0;
		for(int i = 0;i < n;i++){
			if(g[i].length >= 3){
				cent = i;
				break;
			}
		}
		
		int[] d = new int[n];
		Arrays.fill(d, -1);
		{
			Queue<Integer> q = new ArrayDeque<Integer>();
			q.add(cent);
			d[cent] = 0;
			while(!q.isEmpty()){
				int cur = q.poll();
				for(int e : g[cur]){
					if(d[e] == -1){
						d[e] = d[cur]+1;
						q.add(e);
						if(d[cur] >= 1){
							ds.union(cur, e);
						}
					}
				}
			}
		}
		
		int[] es = new int[n];
		Arrays.fill(es, -1);
		for(int i = 0;i < n-1;i++){
			if(d[f[i]] < d[t[i]]){
				es[t[i]] = i;
			}else{
				es[f[i]] = i;
			}
		}
		
//		int[] ia = new int[n];
		int[] ie = new int[n];
		for(int i = 0;i < n;i++){
			if(es[i] != -1){
				ie[es[i]] = i;
			}
		}
		
		int[][] ft = new int[n][];
		for(int i = 0;i < n;i++){
			if(ds.upper[i] < 0){
				ft[i] = new int[-ds.upper[i]+1];
			}
		}
		
		int Q = ni();
		for(int q = 0;q < Q;q++){
			int com = ni();
			if(com == 1){
				int u = ni()-1;
				int c = ds.root(ie[u]);
				addFenwick(ft[c], d[ie[u]]-1, -1);
			}else if(com == 2){
				int u = ni()-1;
				int c = ds.root(ie[u]);
				addFenwick(ft[c], d[ie[u]]-1, 1);
			}else if(com == 3){
				int x = ni()-1;
				int y = ni()-1;
				if(x == cent && y == cent){
					out.println(0);
				}else if(x == cent){
					int c = ds.root(y);
					if(sumFenwick(ft[c], d[y]-1) == 0){
						out.println(d[y]);
					}else{
						out.println(-1);
					}
				}else if(y == cent){
					int c = ds.root(x);
					if(sumFenwick(ft[c], d[x]-1) == 0){
						out.println(d[x]);
					}else{
						out.println(-1);
					}
				}else if(ds.equiv(x, y)){
					int c = ds.root(x);
					if(sumFenwick(ft[c], d[x]-1) == sumFenwick(ft[c], d[y]-1)){
						out.println(Math.abs(d[x]-d[y]));
					}else{
						out.println(-1);
					}
				}else{
					int cx = ds.root(x);
					int cy = ds.root(y);
					if(sumFenwick(ft[cx], d[x]-1) == 0 && sumFenwick(ft[cy], d[y]-1) == 0){
						out.println(d[x]+d[y]);
					}else{
						out.println(-1);
					}
				}
			}
		}
	}
	
	public static int[][] packU(int n, int[] from, int[] to)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)p[f]++;
		for(int t : to)p[t]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		if(i < 0)return 0;
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
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