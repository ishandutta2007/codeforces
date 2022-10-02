//package round283;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	// 012 120 201
	// 1 1 2 4 6 10 23 33 56
	void solve()
	{
		long n = nl();
		int K = ni();
		
		if(n <= K){
			int u = 1;
			for(int i = 0;i < n;i++){
				u = u * 2 % mod;
			}
			out.println(u);
			return;
		}
		
		int t = (int)(Math.log(10)*18/Math.log(K) + 1);
		int[][][] B = new int[2*K][2*K][2*K];
		
		int mod = 1000000007;
		for(int i = 0;i < 2*K;i++){
			for(int j = 1;j < 2*K;j++){
				B[i][j][j-1] = 1;
			}
			B[i][0][0] = 2;
			B[i][0][i] += mod-1;
		}
		int[][][] C = new int[K][][];
		for(int i = 0;i < K;i++){
			if(i == 0){
				C[i] = pow(B[K-i], K-i);
			}else{
				C[i] = mul(pow(B[2*K-i], i), pow(B[K-i], K-i));
			}
		}
		
		int[][][] M = new int[t+1][][];
		int[][][] MK = new int[t+1][][];
		int[][][] MKT = new int[t+1][][];
		M[1] = C[1];
		MK[1] = pow(C[1], K-1);
		MKT[1] = MK[1];
		for(int z = 2;z < t;z++){
			M[z] = mul(MKT[z-1], C[z%K]);
//			M[z] = C[z%K];
//			for(int y = 1;y < z;y++){
//				M[z] = mul(MK[y], M[z]);
//			}
			MK[z] = pow(M[z], K-1);
			MKT[z] = mul(MK[z], MKT[z-1]);
		}
		int[][][] rem = new int[t+1][][];
		rem[1] = MK[1];
		for(int z = 2;z < t;z++){
			rem[z] = mul(MK[z], rem[z-1]);
		}
		
		long[] d = new long[64];
		int p = 0;
		while(n > 0){
			d[p++] = n % K;
			n /= K;
		}
		
		int[] v = new int[2*K];
		v[K] = 1;
		for(int i = K-1;i >= 0;i--){
			v[i] = v[i+1] * 2 % mod;
		}
		
		int prev = -1;
		for(int u = p-1;u >= 2;u--){
			long e = d[u];
			for(int i = 0;i < e;i++){
				if(prev != -1)v = mul(C[prev], v);
				v = mul(rem[u-1], v);
				prev = u%K;
			}
		}
		{
			int u = 1;
			long e = d[u];
			if(e > 0){
				if(prev != -1)v = mul(C[prev], v);
				for(int i = 1;i < e;i++){
					v = mul(C[1], v);
					prev = u%K;
				}
				prev = 1;
			}
		}
		if(prev == -1)prev = 1;
		for(int j = 0;j < K-prev && d[0] > 0;j++, d[0]--){
			v = mul(B[K-prev], v);
		}
		for(int j = 0;j < prev && d[0] > 0;j++, d[0]--){
			v = mul(B[2*K-prev], v);
		}
		out.println(v[0]);
	}
	
	public static int[][] mul(int[][] A, int[][] B)
	{
		int m = A.length;
		int n = A[0].length;
		int o = B[0].length;
		int[][] C = new int[m][o];
		for(int i = 0;i < m;i++){
			long[] sum = new long[n];
			for(int k = 0;k < n;k++){
				for(int j = 0;j < n;j++){
					sum[j] += (long)A[i][k] * B[k][j];
					if(sum[j] >= BIG)sum[j] -= BIG;
				}
			}
			for(int j = 0;j < n;j++){
				C[i][j] = (int)(sum[j] % mod);
			}
		}
		return C;
	}
	
	///////// begin
	public static final int mod = 1000000007;
	public static final long m2 = (long)mod*mod;
	public static final long BIG = 8L*m2;
	
	// A^e*v
	public static int[] pow(int[][] A, int[] v, long e)
	{
		for(int i = 0;i < v.length;i++){
			if(v[i] >= mod)v[i] %= mod;
		}
		int[][] MUL = A;
		for(;e > 0;e>>>=1) {
			if((e&1)==1)v = mul(MUL, v);
			MUL = p2(MUL);
		}
		return v;
	}
	
	// int matrix*int vector
	public static int[] mul(int[][] A, int[] v)
	{
		int m = A.length;
		int n = v.length;
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			long sum = 0;
			for(int k = 0;k < n;k++){
				sum += (long)A[i][k] * v[k];
				if(sum >= BIG)sum -= BIG;
			}
			w[i] = (int)(sum % mod);
		}
		return w;
	}
	
	// int matrix^2 (be careful about minus value)
	public static int[][] p2(int[][] A)
	{
		int n = A.length;
		int[][] C = new int[n][n];
		for(int i = 0;i < n;i++){
			long[] sum = new long[n];
			for(int k = 0;k < n;k++){
				for(int j = 0;j < n;j++){
					sum[j] += (long)A[i][k] * A[k][j];
					if(sum[j] >= BIG)sum[j] -= BIG;
				}
			}
			for(int j = 0;j < n;j++){
				C[i][j] = (int)(sum[j] % mod);
			}
		}
		return C;
	}
	
	//////////// end

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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
	
	public static int[][] pow(int[][] A, long e)
	{
		int[][] MUL = A;
		int n = A.length;
		int[][] C = new int[n][n];
		for(int i = 0;i < n;i++)C[i][i] = 1;
		for(;e > 0;e>>>=1) {
			if((e&1)==1)C = mul(C, MUL);
			MUL = p2(MUL);
		}
		return C;
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