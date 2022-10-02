//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class R87D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), a = ni()-1, b = ni()-1;
		boolean[][] g = new boolean[n][n];
		int[] dim = new int[n];
		for(int i = 0;i < m;i++){
			int f = ni()-1, t = ni()-1;
			g[f][t] = g[t][f] = true;
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(g[i][j])dim[i]++;
			}
			g[i][i] = true;
		}
		double[] st = new double[n];
		for(int i = 0;i < n;i++)st[i] = nd();
		
		double[][] M = new double[n*n][n*n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(i == j)continue;
				for(int k = 0;k < n;k++){
					for(int l = 0;l < n;l++){
						if(g[i][k] && g[j][l]){
							M[k*n+l][i*n+j] =
									(i==k ? st[i] : (1-st[i])/dim[i]) *
									(j==l ? st[j] : (1-st[j])/dim[j]);
						}
					}
				}
			}
		}
		
		double[] v = new double[n*n];
		v[a*n+b] = 1;
		double[] e = S(M, v);
		for(int i = 0;i < n;i++){
			if(i > 0)out.print(" ");
			out.printf("%.10f", e[i*n+i]);
		}
		out.println();
	}
	
	public double[] S(double[][] T, double[] v)
	{
		int n = T.length;
		double[][] U = new double[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				U[i][j] = (i == j ? 1 : 0) - T[i][j];
			}
		}
		return solve(U, v);
	}
	
	public double[] solve(double[][] a, double[] c)
	{
		int n = a.length;
		int[] ps = new int[n];
		for(int i = 0;i < n;i++)ps[i] = i;
		
		// 
		for(int i = 0;i < n;i++){
			int pivot = -1;
			int from = -1;
			double amax = 0;
			for(int j = i;j < n;j++){
				if(Math.abs(a[ps[j]][i]) > amax){
					amax = Math.abs(a[ps[j]][i]);
					pivot = ps[j];
					from = j;
				}
			}
			if(pivot == -1)return null;
			int d = ps[i]; ps[i] = ps[from]; ps[from] = d;
			
			for(int j = i+1;j < n;j++){
				a[ps[i]][j] /= a[ps[i]][i];
			}
			c[ps[i]] /= a[ps[i]][i];
			a[ps[i]][i] = 1.0;
			for(int j = i+1;j < n;j++){
				for(int k = i+1;k < n;k++){
					a[ps[j]][k] -= a[ps[j]][i] * a[ps[i]][k];
				}
				c[ps[j]] -= a[ps[j]][i] * c[ps[i]];
				a[ps[j]][i] = 0.0;
			}
			
		}
		
		// 
		for(int i = n-1;i >= 0;i--){
			for(int j = i-1;j >= 0;j--){
				c[ps[j]] -= a[ps[j]][i] * c[ps[i]];
			}
		}
		
		double[] ret = new double[n];
		for(int i = 0;i < n;i++){
			ret[i] = c[ps[i]];
		}
		
		return ret;
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
	
	public static void main(String[] args) throws Exception { new R87D().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}