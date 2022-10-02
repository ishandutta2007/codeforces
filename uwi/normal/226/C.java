//package round140;
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
		int m = ni();
		long l = nl(), r = nl();
		long k = nl();
		long oks = -1;
		for(long s = 2000000;s >= 1;s--){
			if(r/s-(l-1)/s >= k){
				oks = s;
				break;
			}
		}
		// s<=(l-1)/a, s>(l-1)/(a+1), s<=r/(k+a)
		// a<=(l-1)/s<a+1
		// [r/s]>=k+a
		// k+a<=r/s
		{
			long sup = r/k;
			long inf = (l-1)+1;
			if(inf <= sup){
				oks = Math.max(oks, sup);
			}
		}
		for(long a = 1;a <= 2000000;a++){
			long sup = Math.min((l-1)/a, r/(k+a));
			long inf = (l-1+a+1)/(a+1);
			if(inf <= sup){
//				tr(a, (l-1+a+1)/(a+1), (l-1)/a, r/(k+a));
				oks = Math.max(oks, sup);
			}
		}
		
		int[][] A = {
				{1, 1},
				{1, 0}
		};
		int[] v = new int[]{1, 0};
		out.println(pow(A, v, oks, m)[1]);
	}
	
	public static int[] mul(int[][] A, int[] v, int mod)
	{
		int m = A.length;
		int n = v.length;
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			long sum = 0;
			for(int k = 0;k < n;k++){
				sum += (long)A[i][k] * v[k];
				sum %= mod;
			}
			w[i] = (int)sum;
		}
		return w;
	}
	
	// int2()
	public static int[][] p2(int[][] A, int mod)
	{
		int n = A.length;
		int[][] C = new int[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				long sum = 0;
				for(int k = 0;k < n;k++){
					sum += (long)A[i][k] * A[k][j];
					sum %= mod;
				}
				C[i][j] = (int)sum;
			}
		}
		return C;
	}
	
	// A^e*v
	public static int[] pow(int[][] A, int[] v, long e, int mod)
	{
		int[][] MUL = A;
		for(int i = 0;i < v.length;i++)v[i] %= mod;
		for(;e > 0;e>>>=1) {
			if((e&1)==1)v = mul(MUL, v, mod);
			MUL = p2(MUL, mod);
		}
		return v;
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