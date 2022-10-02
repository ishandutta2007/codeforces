//package round122;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int M2 = 1<<13;
		int M5 = 5*5*5*5*5*5*5*5*5*5*5*5*5;
		
		long f = nl();
		int x2 = (int)(f % M2);
		int[] fa2 = new int[M2];
		int[] a2 = new int[1<<14];
		a2[0] = 0;
		a2[1] = 1;
		Arrays.fill(fa2, -1);
		fa2[0] = 0;
		fa2[1] = 1;
		for(int i = 2;i < 13000;i++){
			a2[i] = (a2[i-1] + a2[i-2]) % M2;
			if(fa2[a2[i]] == -1)fa2[a2[i]] = i;
		}
		if(fa2[x2] == -1){
			out.println(-1);
			return;
		}
		
		int f5 = (int)(f%5);
		List<Long> l = new ArrayList<Long>();
		{
			int[] a = new int[20];
			a[0] = 0;
			a[1] = 1;
			for(int i = 2;i < 4*5;i++){
				a[i] = (a[i-1] + a[i-2]) % 5;
			}
			for(int i = 0;i < 4*5;i++){
				if(a[i] == f5){
					l.add((long)i);
				}
			}
		}
		
		int[][] F = {
				{1, 1}, {1, 0}
		};
		for(long m = 25;m <= M5;m*=5){
			int fm = (int)(f % m);
			List<Long> nl = new ArrayList<Long>();
			for(long ll : l){
				for(int k = 0;k < 5;k++){
					long ne = ll+k*4*(m/5);
					long nf = 0;
					if(ne == 0){
						nf = 0;
					}else{
						nf = pow(F, new int[]{1, 0}, ne-1, (int)m)[0];
					}
					if(nf == fm){
						nl.add(ne);
					}
				}
			}
			l = nl;
		}
		
		long min = Long.MAX_VALUE;
		for(long ll : l){
			for(int i = 0;i < a2.length;i++){
				if(a2[i] == f % M2){
					long num = crtx(new long[]{M2*3/2, 4L*M5}, new long[]{i, ll}).longValue();
					if(num >= 0){
						min = Math.min(min, num);
					}
				}
			}
//			long num = crt(M2*3/2, fa2[x2], 4L*M5, ll);
		}
		if(min == Long.MAX_VALUE){
			out.println(-1);
		}else{
			out.println(min);
		}
	}
	
	public static long crt(long p, long m, long q, long n)
	{
		long[] apr = exGCD(p, q);
		if((n - m) % apr[0] != 0)return -1;
		long mod = p * q / apr[0];
		long a = (apr[1] * (n - m) / apr[0] * p + m) % mod;
		if(a < 0)a += mod;
		return a;
	}
	
	// int*
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
	
	// int2
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
	
	public static BigInteger[] exGCD(BigInteger a, BigInteger b)
	{
		BigInteger p = BigInteger.ONE, q = BigInteger.ZERO, r = BigInteger.ZERO, s = BigInteger.ONE;
		while(b.signum() > 0){
			BigInteger c = a.divide(b);
			BigInteger d;
			d = a; a = b; b = d.mod(b);
			d = p; p = q; q = d.subtract(c.multiply(q));
			d = r; r = s; s = d.subtract(c.multiply(s));
		}
		return new BigInteger[]{a, p, r};
	}
	
	public static BigInteger bi(long x){ return BigInteger.valueOf(x); }
	
	public static BigInteger crtx(long[] divs, long[] mods)
	{
		BigInteger div = bi(divs[0]), mod = bi(mods[0]);
		for(int i = 1;i < divs.length;i++){
			BigInteger[] apr = exGCD(div, bi(divs[i]));
			BigInteger mm = bi(mods[i]).subtract(mod);
			if(mm.mod(apr[0]).signum() != 0)return bi(-1);
			BigInteger da = div.divide(apr[0]);
			BigInteger ndiv = bi(divs[i]).multiply(da);
			BigInteger nmod = apr[1].multiply(mm).multiply(da).add(mod).mod(ndiv);
			if(nmod.signum() < 0)nmod = nmod.add(ndiv);
			div = ndiv;
			mod = nmod;
		}
		return mod;
	}
	
	// A^e*v
	public static int[] pow(int[][] A, int[] v, long e, int mod)
	{
		int[][] MUL = A;
		for(;e > 0;e>>>=1) {
			if((e&1)==1)v = mul(MUL, v, mod);
			MUL = p2(MUL, mod);
		}
		return v;
	}
	
	public static long[] exGCD(long a, long b)
	{
		long p = 1, q = 0, r = 0, s = 1;
		while(b > 0){
			long c = a / b;
			long d;
			d = a; a = b; b = d % b;
			d = p; p = q; q = d - c * q;
			d = r; r = s; s = d - c * s;
		}
		return new long[]{a, p, r};
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
		new E2().run();
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