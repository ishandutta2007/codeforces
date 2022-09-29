//package round497;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int[] lpf = enumLowestPrimeFactors(100005);
		int[] ds = enumNumDivisorsFast(100004, lpf);
		int[][] gcdt = gcdtable(2000);
		int[] set = new int[512];
		for(int T = ni();T > 0;T--){
			int x = ni(), y = ni(), z = ni();
			int[][] nums = new int[3][8];
			int[] t = {x, y, z};
			for(int j = 0;j < 8;j++){
				int g = 0;
				for(int k = 0;k < 3;k++){
					if(j<<~k<0){
						g = (int)gcd3(g, t[k], gcdt);
					}
				}
				for(int k = 0;k < 3;k++){
					int h = (int)gcd3(g, t[k], gcdt);
					nums[k][j] = ds[h];
				}
			}
			for(int i = 0;i < 3;i++){
				for(int k = 0;k < 3;k++){
					for(int j = 0;j < 8;j++){
						if(j<<~k<0){
							nums[i][j^1<<k] -= nums[i][j];
						}
					}
				}
			}
			
			long ans = 0;
			int[] q = new int[3];
			for(int i = 0;i < 8;i++){
				if(nums[0][i] == 0)continue;
				for(int j = 0;j < 8;j++){
					if(nums[1][j] == 0)continue;
					for(int k = 0;k < 8;k++){
						if(nums[2][k] == 0)continue;
						q[0] = i; q[1] = j; q[2] = k;
						Arrays.sort(q);
						int h = q[0]<<6|q[1]<<3|q[2];
						if(set[h] == T)continue;
						set[h] = T;
						if(i == j && j == k){
							long s = nums[0][i];
							long lans = (s*s*s+3*s*s+2*s)/6;
							ans += lans;
						}else if(i == j){
							long s = nums[0][i];
							long r = nums[2][k];
							long lans = (s*s+s)/2*r;
							ans += lans;
						}else if(j == k){
							long s = nums[2][k];
							long r = nums[0][i];
							long lans = (s*s+s)/2*r;
							ans += lans;
						}else if(k == i){
							long s = nums[2][k];
							long r = nums[1][j];
							long lans = (s*s+s)/2*r;
							ans += lans;
						}else{
							long lans = nums[0][i] * nums[1][j] * nums[2][k];
							ans += lans;
						}
//						tr(i, j, k, nums[0][i], nums[1][j], nums[2][k], ans);
					}
				}
			}
			out.println(ans);
		}
	}
	
	public static long gcd3(long a, long b, int[][] gt) {
		if(a == 0)return b;
		if(b == 0)return a;
		
		int ashift = Long.numberOfTrailingZeros(a);
		int bshift = Long.numberOfTrailingZeros(b);
		a >>>= ashift;
		b >>>= bshift;
		while(b != a){
			if(a > b){
				long t = a; a = b; b = t;
			}
			if(b < gt.length)return (long)gt[(int)a][(int)b]<<Math.min(ashift, bshift);
			b -= a;
			b >>>= Long.numberOfTrailingZeros(b);
		}
		
		return a<<Math.min(ashift, bshift);
	}
	
	public static int[][] gcdtable(int n)
	{
		int[][] gcd = new int[n+1][n+1];
		for(int i = 1;i <= n;i++){
			gcd[i][i] = i;
			for(int j = i+1;j <= n;j++){
				gcd[j][i] = gcd[i][j] = gcd[i][j-i];
			}
		}
		return gcd;
	}
	
	public static int gcd(int a, int b) {
		while (b > 0) {
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
	}
	
	
	public static int[] enumNumDivisorsFast(int n, int[] lpf)
	{
		int[] nd = new int[n+1];
		nd[1] = 1;
		for(int i = 2;i <= n;i++){
			int j = i, e = 0;
			while(j % lpf[i] == 0){
				j /= lpf[i];
				e++;
			}
			nd[i] = nd[j] * (e+1);
		}
		return nd;
	}

	
	public static int[] enumLowestPrimeFactors(int n) {
		int tot = 0;
		int[] lpf = new int[n + 1];
		int u = n + 32;
		double lu = Math.log(u);
		int[] primes = new int[(int) (u / lu + u / lu / lu * 1.5)];
		for (int i = 2; i <= n; i++)
			lpf[i] = i;
		for (int p = 2; p <= n; p++) {
			if (lpf[p] == p)
				primes[tot++] = p;
			int tmp;
			for (int i = 0; i < tot && primes[i] <= lpf[p] && (tmp = primes[i] * p) <= n; i++) {
				lpf[tmp] = primes[i];
			}
		}
		return lpf;
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
	
	public static void main(String[] args) throws Exception { new B4().run(); }
	
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