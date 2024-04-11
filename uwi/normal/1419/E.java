//package round671;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--)go();
	}

	int[] primes = sieveEratosthenes(100000);

	void go()
	{
		int n = ni();
		int[][] fs = factor(n, primes);
		List<Integer> check = new ArrayList<>();
		if(fs.length >= 3){
			Set<Integer> done = new HashSet<>();
			for(int i = 0;i < fs.length;i++){
				int[] f = fs[i];
				int q = f[0];
				for(int e = 1;e <= f[1];e++){
					out.print(q + " ");
					done.add(q);
					check.add(q);
					q *= f[0];
				}
				for(int u = fs.length-2;u >= 1;u--){
					int t = fs[(i + u) % fs.length][0] * fs[i][0];
					for (int d = 1; d * d <= n / t; d++) {
						if (n / t % d == 0) {
							if (done.add(t * d)) {
								check.add(t * d);
								out.print(t * d + " ");
							}
							if (done.add(t * (n / t / d))) {
								check.add(t * (n / t / d));
								out.print(t * (n / t / d) + " ");
							}
						}
					}
				}
			}
			out.println();
			out.println(0);
		}else if(fs.length == 2){
			if(fs[0][1] == 1 && fs[1][1] == 1){
				out.println(fs[0][0] + " " + fs[1][0] + " " + n);
				out.println(1);
			}else{
				Set<Integer> done = new HashSet<>();
				for(int i = 0;i < fs.length;i++){
					int[] f = fs[i];
					int q = f[0];
					for(int e = 1;e <= f[1];e++){
						out.print(q + " ");
						check.add(q);
						q *= f[0];
					}
					int t = fs[(i+1) % fs.length][0] * fs[i][0];
					if(i == 0){
						check.add(t);
						out.print(t + " ");
						done.add(t);
					}else {
						for (int d = 1; d * d <= n / t; d++) {
							if (n / t % d == 0) {
								if (done.add(t * d)) {
									check.add(t*d);
									out.print(t * d + " ");
								}
								if (done.add(t * (n / t / d))) {
									check.add(t*(n/t/d));
									out.print(t * (n / t / d) + " ");
								}
							}
						}
					}
				}
				out.println();
				out.println(0);
			}
		}else{
			int[] f = fs[0];
			int q = f[0];
			for(int e = 1;e <= f[1];e++){
				out.print(q + " ");
				check.add(q);
				q *= f[0];
			}
			out.println();
			out.println(0);
		}
//		if(check.size() > 0)ch(check, n);
	}

	void ch(List<Integer> check, int n)
	{
		tr(n);
		int dn = 0;
		for(int d = 2;d <= n;d++){
			if(n % d == 0){
				dn++;
			}
		}
		tr(check.size(), dn);
		assert check.size() == dn;
		for(int i = 0;i < check.size();i++){
			int x = check.get(i);
			int y = check.get((i+1) % check.size());
			assert gcd(x, y) != 1;
		}
	}

	public static int gcd(int a, int b) {
		while (b > 0) {
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
	}


	public static int[][] factor(int n, int[] primes)
	{
		int[][] ret = new int[9][2];
		int rp = 0;
		for(int p : primes){
			if(p * p > n)break;
			int i;
			for(i = 0;n % p == 0;n /= p, i++);
			if(i > 0){
				ret[rp][0] = p;
				ret[rp][1] = i;
				rp++;
			}
		}
		if(n != 1){
			ret[rp][0] = n;
			ret[rp][1] = 1;
			rp++;
		}
		return Arrays.copyOf(ret, rp);
	}

	public static int[] sieveEratosthenes(int n) {
		if (n <= 32) {
			int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
			for (int i = 0; i < primes.length; i++) {
				if (n < primes[i]) {
					return Arrays.copyOf(primes, i);
				}
			}
			return primes;
		}

		int u = n + 32;
		double lu = Math.log(u);
		int[] ret = new int[(int) (u / lu + u / lu / lu * 1.5)];
		ret[0] = 2;
		int pos = 1;

		int[] isnp = new int[(n + 1) / 32 / 2 + 1];
		int sup = (n + 1) / 32 / 2 + 1;

		int[] tprimes = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
		for (int tp : tprimes) {
			ret[pos++] = tp;
			int[] ptn = new int[tp];
			for (int i = (tp - 3) / 2; i < tp << 5; i += tp) ptn[i >> 5] |= 1 << (i & 31);
			for (int j = 0; j < sup; j += tp) {
				for (int i = 0; i < tp && i + j < sup; i++) {
					isnp[j + i] |= ptn[i];
				}
			}
		}

		// 3,5,7
		// 2x+3=n
		int[] magic = {0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14};
		int h = n / 2;
		for (int i = 0; i < sup; i++) {
			for (int j = ~isnp[i]; j != 0; j &= j - 1) {
				int pp = i << 5 | magic[(j & -j) * 0x076be629 >>> 27];
				int p = 2 * pp + 3;
				if (p > n) break;
				ret[pos++] = p;
				if ((long) p * p > n) continue;
				for (int q = (p * p - 3) / 2; q <= h; q += p) isnp[q >> 5] |= 1 << q;
			}
		}

		return Arrays.copyOf(ret, pos);
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