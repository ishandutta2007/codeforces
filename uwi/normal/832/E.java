//package round425;
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
	
	void solve()
	{
		int n = ni();
		int m = ni();
		char[][] ss = nm(n,m);
		int[][] M = new int[m][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				M[j][i] = ss[i][j]-'a';
			}
		}
		Result res = rank(M, 5);
		int[][] o = res.v;
		int rank = res.rank;
		outer:
		for(int Q = ni();Q > 0;Q--){
			char[] ys = ns(m);
			int[] y = new int[m];
			for(int i = 0;i < m;i++)y[i] = ys[i]-'a';
			y = mul(o, y, 5);
			for(int i = rank;i < m;i++){
				if(y[i] != 0){
					out.println(0);
					continue outer;
				}
			}
			out.println(pow(5, n-rank, 1000000007));
		}
	}
	
	public static long pow(long a, long n, long mod) {
		//		a %= mod;
		long ret = 1;
		int x = 63 - Long.numberOfLeadingZeros(n);
		for (; x >= 0; x--) {
			ret = ret * ret % mod;
			if (n << 63 - x < 0)
				ret = ret * a % mod;
		}
		return ret;
	}

	
	public static Result rank(int[][] M, int p)
	{
//		if(M.length == 0)return 0;
		int n = M.length, m = M[0].length;
		int[][] v = new int[n][n];
		for(int i = 0;i < n;i++)v[i][i] = 1;
		
		// Forward Elimination
		for(int i = 0;i < n;i++){
			// select pivot
			boolean pivotFound = false;
			out:
			for(int pi = i;pi < n;pi++){
				for(int pj = i;pj < m;pj++){
					if(M[pi][pj] != 0){
						// pivot found
						if(pj != i){
							// swap columns
							for(int k = 0;k < n;k++){
								int d = M[k][pj]; M[k][pj] = M[k][i]; M[k][i] = d;
							}
						}
						if(pi != i){
							// swap rows
							{int[] d = M[pi]; M[pi] = M[i]; M[i] = d;}
							{int[] d = v[pi]; v[pi] = v[i]; v[i] = d;}
						}
						pivotFound = true;
						break out;
					}
				}
			}
			if(!pivotFound){
				Result res = new Result();
				res.v = v;
				res.rank = i;
				return res;
			}
			
			long ID = invl(M[i][i], p);
			M[i][i] = 1;
			for(int j = i+1;j < m;j++){
				M[i][j] = (int)(M[i][j] * ID % p);
			}
			for(int j = 0;j < n;j++){
				v[i][j] = (int)(v[i][j] * ID % p);
			}
			
			for(int j = i+1;j < n;j++){
				long B = p-M[j][i];
				M[j][i] = 0;
				for(int k = i+1;k < m;k++){
					M[j][k] = (int)((M[j][k] + M[i][k] * B) % p);
				}
				for(int k = 0;k < n;k++){
					v[j][k] = (int)((v[j][k] + v[i][k] * B) % p);
				}
			}
		}
		Result res = new Result();
		res.v = v;
		res.rank = n;
		return res;
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
			}
			sum %= mod;
			w[i] = (int)sum;
		}
		return w;
	}

	
	public static long invl(long a, long mod) {
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
	}

	static class Result
	{
		public int[][] v;
		public int rank;
	};
	
	public static Result operateElementarily(int[][] M, int mod)
	{
		int n = M.length, m = M[0].length;
		int rank = n-1;
		int[][] v = new int[n][n];
		for(int i = 0;i < n;i++)v[i][i] = 1;
				
		// Forward Elimination
		for(int i = 0;i < n;i++){
			// select pivot
			int maxj = -1;
			for(int j = i;j < n;j++){
				if(M[j][i] != 0){
					maxj = j;
					break;
				}
			}
			if(maxj == -1){
				rank = i-1;
				break;
			}
			if(maxj != i){
				int[] dum = M[i]; M[i] = M[maxj]; M[maxj] = dum;
				int[] du = v[i]; v[i] = v[maxj]; v[maxj] = du;
			}
			
			long ID = invl(M[i][i], mod);
			M[i][i] = 1;
			for(int j = i+1;j < m;j++){
				M[i][j] = (int)(M[i][j] * ID % mod);
			}
			for(int j = 0;j < n;j++){
				v[i][j] = (int)(v[i][j] * ID % mod);
			}
			
			for(int j = i+1;j < n;j++){
				long B = mod-M[j][i];
				M[j][i] = 0;
				for(int k = i+1;k < m;k++){
					M[j][k] = (int)((M[j][k] + M[i][k] * B) % mod);
				}
				for(int k = 0;k < n;k++){
					v[j][k] = (int)((v[j][k] + v[i][k] * B) % mod);
				}
			}
		}
		
		// Back Substitution
		for(int i = rank;i >= 0;i--){
			for(int j = rank;j >= i+1;j--){
				long B = mod-M[i][j];
				M[i][j] = 0;
				for(int k = rank+1;k < m;k++){
					M[i][k] = (int)((M[i][k] + M[j][k] * B) % mod);
				}
				for(int k = 0;k < n;k++){
					v[i][k] = (int)((v[i][k] + v[j][k] * B) % mod);
				}
			}
		}
		
		Result ret = new Result();
		ret.v = v;
		ret.rank = rank+1;
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
	
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