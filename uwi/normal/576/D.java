//package round319;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.Random;

public class D6 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] es = new int[m][];
		for(int i = 0;i < m;i++){
			es[i] = new int[]{ni()-1, ni()-1, ni()};
		}
		Arrays.sort(es, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[2] - b[2];
			}
		});
		
		int o = (n>>>6)+1;
		long[][] M = new long[n][o];
		M[n-1][n-1>>>6] |= 1L<<n-1;
		int f = 0;
		long[] v = new long[o];
		v[0] |= 1L<<0;
		
		out:
		for(int i = 0;i < m;i++){
			long[] nv = pow(M, v, es[i][2]-f);
			if(nv[n-1>>>6]<<~(n-1)<0){
				break out;
			}
			v = nv;
			M[es[i][1]][es[i][0]>>>6] |= 1L<<es[i][0];
			f = es[i][2];
		}
		
		long[][][] ms = new long[30][][];
		ms[0] = M;
		for(int i = 1;i <= 29;i++){
			ms[i] = p2(ms[i-1]);
		}
		long ret = f;
		for(int i = 29;i >= 0;i--){
			long[] w = mul(ms[i], v);
			if(w[n-1>>>6]<<~(n-1)<0){
			}else{
				v = w;
				ret += 1L<<i;
			}
		}
		if(ret+1 >= 1L<<30){
			out.println("Impossible");
		}else{
			out.println(ret+1);
		}
	}
	
	public static long[] mul(long[][] A, long[] v)
	{
		int n = A.length;
		int m = v.length;
		long[] w = new long[m];
		for(int i = 0;i < n;i++){
			for(int k = 0;k < m;k++){
				if((A[i][k]&v[k]) != 0){
					w[i>>>6] |= 1L<<i;
					break;
				}
			}
		}
		return w;
	}
	
	public static long[][] p2(long[][] A)
	{
		int n = A.length;
		int m = A[0].length;
		long[][] C = new long[n][m];
		long[] v = new long[m];
		for(int j = 0;j < n;j++){
			Arrays.fill(v, 0L);
			for(int i = 0;i < n;i++){
				v[i>>>6] |= (A[i][j>>>6]>>>j&1)<<i;
			}
			
			for(int i = 0;i < n;i++){
				for(int k = 0;k < m;k++){
					if((A[i][k]&v[k]) != 0){
						C[i][j>>>6] |= 1L<<j;
					}
				}
			}
		}
		return C;
	}
//	
//	public static long[][] p2(long[][] A)
//	{
//		int n = A.length;
//		int m = A[0].length;
//		long[][] C = new long[n][m];
//		long[] v = new long[m];
//		for(int j = 0;j < m;j++){
//			for(int t = 0;t < 64;t++){
//				Arrays.fill(v, 0L);
//				for(int i = 0;i < n;i++){
//					v[i>>>6] |= (A[i][j]>>>t&1)<<i;
//				}
//				
//				for(int i = 0;i < n;i++){
//					for(int k = 0;k < m;k++){
//						if((A[i][k]&v[k]) != 0){
//							C[i][j] |= 1L<<t;
//						}
//					}
//				}
//			}
//		}
//		return C;
//	}
	
	// A^e*v
	public static long[] pow(long[][] A, long[] v, long m)
	{
		long[][] mu = A;
		long[] r = v;
		for(;m > 0;m>>>=1){
			if(m<<63<0)r = mul(mu, r);
			mu = p2(mu);
		}
		return r;
	}
	
	void run() throws Exception
	{
		int n = 150, m = 150;
		Random gen = new Random();
		StringBuilder sb = new StringBuilder();
		sb.append(n + " ");
		sb.append(m + " ");
		for (int i = 0; i < m-1; i++) {
			sb.append((i+1) + " ");
			sb.append(((i+1)%(n-1)+1) + " ");
			sb.append(0 + " ");
		}
		sb.append(1 + " ");
		sb.append(n + " ");
		sb.append(1000000000 + " ");
		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D6().run(); }
	
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