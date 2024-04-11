//package round83;
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
		long n = nl();
		int m = ni();
		int[] alp = new int[m];
		int[] val = new int[m];
		int r = 1;
		for(int i = 0;i < m;i++){
			alp[i] = nc()-'A';
			val[i] = ni();
			r *= val[i];
		}
		int[][] g = packD(26, alp, val);
		int[] mul = new int[26];
		for(int i = 0;i < 26;i++){
			mul[i] = 1;
			for(int j : g[i]){
				mul[i] *= j;
			}
		}
		
		int[][] M = new int[r][r];
		for(int i = 0;i < r;i++){
			int[] a = dec(i, mul);
			for(int j = 0;j < 26;j++){
				if(g[j].length > 0){
					a[j] = (a[j]+1)%mul[j];
					M[enc(a, mul)][i]++;
					a[j] = (a[j]+mul[j]-1)%mul[j];
				}
			}
		}
		
		int[] v = new int[r];
		v[0] = 1;
		int[] rv = pow(M, v, n);
		int ret = 0;
		outer:
		for(int i = 0;i < r;i++){
			int[] a = dec(i, mul);
			for(int j = 0;j < 26;j++){
				if(g[j].length > 0){
					boolean ok = false;
					for(int k : g[j]){
						if(a[j] % k == 0){
							ok = true;
							break;
						}
					}
					if(!ok)continue outer;
				}
			}
			ret += rv[i];
		}
		out.println(ret % MOD);
	}
	
	int[] dec(int a, int[] mul)
	{
		int n = mul.length;
		int[] ret = new int[n];
		for(int i = 0;i < n;i++){
			ret[i] = a % mul[i];
			a /= mul[i];
		}
		return ret;
	}
	
	int enc(int[] a, int[] mul)
	{
		int n = a.length;
		int ret = 0;
		for(int i = n-1;i >= 0;i--){
			ret = ret * mul[i]+a[i];
		}
		return ret;
	}
	
	public static int MOD = 12345;
	
	// int*
	public static int[] mul(int[][] A, int[] v)
	{
		int m = A.length;
		int n = v.length;
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			long sum = 0;
			for(int k = 0;k < n;k++){
				sum += (long)A[i][k] * v[k];
				sum %= MOD;
			}
			w[i] = (int)sum;
		}
		return w;
	}
	
	// int2
	public static int[][] p2(int[][] A)
	{
		int n = A.length;
		int[][] C = new int[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				long sum = 0;
				for(int k = 0;k < n;k++){
					sum += (long)A[i][k] * A[k][j];
					sum %= MOD;
				}
				C[i][j] = (int)sum;
			}
		}
		return C;
	}
	
	// A^e*v
	public static int[] pow(int[][] A, int[] v, long e)
	{
		int[][] MUL = A;
		for(;e > 0;e>>>=1) {
			if((e&1)==1)v = mul(MUL, v);
			MUL = p2(MUL);
		}
		return v;
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
//		long n = 1000000000000000000L;
//		int c = 1000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(c + " ");
//		for (int i = 0; i < c-2; i++) {
//			sb.append((char)(gen.nextInt(26)+'A') + " " + 1 + " ");
//		}
//		sb.append((char)(gen.nextInt(26)+'A') + " " + 3 + " ");
//		sb.append((char)(gen.nextInt(26)+'A') + " " + 41 + " ");
//		INPUT = sb.toString();
		
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
	
	char nc() {
		try {
			int b;
			while ((b = is.read()) != -1
					&& (b == ' ' || b == '\r' || b == '\n'))
				;
			if (b == -1)
				return 0;
			return (char) b;
		} catch (IOException e) {
		}
		return 0;
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