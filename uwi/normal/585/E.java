//package round325;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int z = 10000000;
		int[] lpf = enumLowestPrimeFactors(z+1);
		mobs = enumMobiusByLPF(z+1, lpf);
		
		f = new int[z+1];
		for(int i = 0;i < n;i++){
			dfsDivisors0(a[i], lpf, 1);
		}
		
		p2 = new int[n+1];
		mod = 1000000007;
		p2[0] = 1;
		for(int i = 1;i <= n;i++){
			p2[i] = p2[i-1] * 2;
			if(p2[i] >= mod)p2[i] -= mod;
		}
		
		long pf1 = 0;
		for(int i = 1;i <= z;i++){
			pf1 += mobs[i] * (p2[f[i]]-1);
		}
		pf1 %= mod;
		if(pf1 < 0)pf1 += mod;

		ret = 0;
		for(int i = 0;i < n;i++){
			long before = pf1;
			after = before;
			dfsDivisors(a[i], lpf, 1);
			ret += before-after - after;
		}
		ret %= mod;
		if(ret < 0)ret += mod;
		out.println(ret);
	}
	
	int mod;
	long ret = 0;
	int[] f;
	int[] mobs;
	int[] p2;
	long after;
	
	public static int[] enumMobiusByLPF(int n, int[] lpf)
	{
		int[] mob = new int[n+1];
		mob[1] = 1;
		for(int i = 2;i <= n;i++){
			int j = i/lpf[i];
			if(lpf[j] == lpf[i]){
//				mob[i] = 0;
			}else{
				mob[i] = -mob[j];
			}
		}
		return mob;
	}
	
	public void dfsDivisors(int n, int[] lpf, int cur)
	{
		if(n == 1){
			int d = cur;
			after -= mobs[d] * (p2[f[d]-1]-1);
			return;
		}
		
		int p = lpf[n];
		int e = 0;
		for(;p == lpf[n];e++, n /= p);
		for(int i = 0;i <= e && i <= 1;i++){
			dfsDivisors(n, lpf, cur);
			cur *= p;
		}
	}
	
	public void dfsDivisors0(int n, int[] lpf, int cur)
	{
		if(n == 1){
			f[cur]++;
			return;
		}
		
		int p = lpf[n];
		int e = 0;
		for(;p == lpf[n];e++, n /= p);
		for(int i = 0;i <= e && i <= 1;i++){
			dfsDivisors0(n, lpf, cur);
			cur *= p;
		}
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
			for (int i = 0; i < tot && primes[i] <= lpf[p]
					&& (tmp = primes[i] * p) <= n; i++) {
				lpf[tmp] = primes[i];
			}
		}
		return lpf;
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
	
	void run() throws Exception
	{
//		int n = 500000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(8648640 + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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