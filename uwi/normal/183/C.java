//package croc.Final;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "3 3 1 2 3 1 1 2";
//	String INPUT = "4 4\r\n" + 
//			"1 2\r\n" + 
//			"2 1\r\n" + 
//			"3 4\r\n" + 
//			"4 3";
//	String INPUT = "5 2\r\n" + 
//			"1 4\r\n" + 
//			"2 5";
//	String INPUT = "4 5\r\n" + 
//			"1 2\r\n" + 
//			"2 3\r\n" + 
//			"3 1\r\n" + 
//			"2 4\r\n" + 
//			"4 1";
//	String INPUT = "4 4\r\n" + 
//			"1 1\r\n" + 
//			"1 2\r\n" + 
//			"2 1\r\n" + 
//			"1 2";
	boolean[] ved;
	int[][] g;
	int[][] ig;
	int[] col;
	int N = 999999;
	int G = -1;
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		g = packD(n, from, to);
		ig = invGraph(g);
		
		ved = new boolean[n];
		col = new int[n];
		Arrays.fill(col, N);
		for(int i = 0;i < n;i++){
			if(!ved[i]){
				col[i] = 0;
				rec(i);
			}
		}
		if(G == -1){
			out.println(n);
		}else{
			out.println(G);
		}
	}
	
	void rec(int c)
	{
		ved[c] = true;
		for(int e : g[c]){
			if(col[e] == N){
				col[e] = col[c]+1;
			}else{
				int d = Math.abs((col[c]+1) - col[e]);
				if(d > 0){
					if(G == -1){
						G = d;
					}else{
						G = gcd(G, d);
					}
				}
			}
			if(!ved[e]){
				rec(e);
			}
		}
		for(int e : ig[c]){
			if(col[e] == N){
				col[e] = col[c]-1;
			}else{
				int d = Math.abs((col[c]-1) - col[e]);
				if(d > 0){
					if(G == -1){
						G = d;
					}else{
						G = gcd(G, d);
					}
				}
			}
			if(!ved[e]){
				rec(e);
			}
		}
	}
	
	public static int gcd(int a, int b) {
		while (b > 0){
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
	}
	
	public static int[][] invGraph(int[][] g)
	{
		int n = g.length;
		int[] p = new int[n];
		for(int f = 0;f < n;f++){
			for(int t : g[f])p[t]++;
		}
		int[][] r = new int[n][];
		for(int i = 0;i < n;i++)r[i] = new int[p[i]];
		for(int f = n-1;f >= 0;f--){
			for(int t : g[f])r[t][--p[t]] = f;
		}
		return r;
	}
	
	public static int[][] packD(int n, int[] from, int[] to)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)p[f]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
			g[from[i]][--p[from[i]]] = to[i];
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