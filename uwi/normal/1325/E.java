//package round628;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Set;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[] lpf = enumLowestPrimeFactors(1000000);
		int[] from = new int[n];
		int[] to = new int[n];
		Set<Integer> sol = new HashSet<>();
		Set<Long> cors = new HashSet<>();
		int ep = 0;
		boolean two = false;
		for(int v : a){
			int[][] f = factorFast(v, lpf);
			assert f.length <= 2;
			int dis = 0;
			int whi = 0;
			for(int[] u : f){
				u[1] &= 1;
				if(u[1] == 1){
					dis++;
					whi = u[0];
				}
			}
			if(dis == 0){
				out.println(1);
				return;
			}
			if(dis == 1){
				if(!sol.add(whi)){
					two = true;
				}
			}else{
				long code = (long)f[0][0]<<32|f[1][0];
				if(!cors.add(code)){
					two = true;
				}
				from[ep] = f[0][0];
				to[ep] = f[1][0];
				ep++;
			}
		}
		if(two){
			out.println(2);
			return;
		}
		
		// o - - o
		// cycle
		
		// simple
		int[][] g = packU(1000001, from, to, ep);
		int ans = Integer.MAX_VALUE;
		
		{
			int I = 999999999;
			int[] qs = new int[n+5];
			int[] ds = new int[1000005];
			Arrays.fill(ds, I);
			for(int s : sol){
				int qp = 0;
				qs[qp++] = s;
				ds[s] = 0;
				inner:
				for(int y = 0;y < qp;y++){
					int cur = qs[y];
					if(ds[cur] + 2 >= ans)break;
					for(int e : g[cur]){
						if(ds[e] > ds[cur] + 1){
							ds[e] = ds[cur] + 1;
							if(sol.contains(e)){
								ans = Math.min(ans, ds[e] + 2);
								break inner;
							}
							qs[qp++] = e;
						}
					}
				}
				for(int y = 0;y < qp;y++){
					ds[qs[y]] = I;
				}
			}
		}
		
		int[] primes = sieveEratosthenes(1000);
		int m = primes.length;
		
		int[] lds = new int[1000001];
		Arrays.fill(lds, 9999999);
		
		int[] qs = new int[n+5];
		int[] pre = new int[1000005];
		Arrays.fill(pre, -1);
		for(int i = 0;i < m;i++){
			int qp = 0;
			qs[qp++] = primes[i];
			lds[primes[i]] = 0;
			pre[primes[i]] = -1;
			for(int y = 0;y < qp;y++){
				int cur = qs[y];
				for(int e : g[cur]){
					if(lds[e] > lds[cur] + 1){
						lds[e] = lds[cur] + 1;
						pre[e] = cur;
						qs[qp++] = e;
					}else if(e != pre[cur]){
						ans = Math.min(ans, lds[e] + lds[cur] + 1);
					}
				}
			}
			for(int y = 0;y < qp;y++){
				lds[qs[y]] = 9999999;
				pre[qs[y]] = -1;
			}
		}
		
		if(ans >= 999999){
			out.println(-1);
		}else{
			out.println(ans);
		}
	}
	
	public static int[] sieveEratosthenes(int n) {
		if (n <= 32) {
			int[] primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
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

		int[] tprimes = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
		for (int tp : tprimes) {
			ret[pos++] = tp;
			int[] ptn = new int[tp];
			for (int i = (tp - 3) / 2; i < tp << 5; i += tp)
				ptn[i >> 5] |= 1 << (i & 31);
			for (int j = 0; j < sup; j += tp) {
				for (int i = 0; i < tp && i + j < sup; i++) {
					isnp[j + i] |= ptn[i];
				}
			}
		}

		// 3,5,7
		// 2x+3=n
		int[] magic = { 0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17,
				9, 6, 16, 5, 15, 14 };
		int h = n / 2;
		for (int i = 0; i < sup; i++) {
			for (int j = ~isnp[i]; j != 0; j &= j - 1) {
				int pp = i << 5 | magic[(j & -j) * 0x076be629 >>> 27];
				int p = 2 * pp + 3;
				if (p > n)
					break;
				ret[pos++] = p;
				if ((long) p * p > n)
					continue;
				for (int q = (p * p - 3) / 2; q <= h; q += p)
					isnp[q >> 5] |= 1 << q;
			}
		}

		return Arrays.copyOf(ret, pos);
	}

	
	public static int[][] packU(int n, int[] from, int[] to){ return packU(n, from, to, from.length); }
	public static int[][] packU(int n, int[] from, int[] to, int sup)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < sup;i++)p[to[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < sup;i++){
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
	}

	
	public static int[][] factorFast(int n, int[] lpf)
	{
		int[][] f = new int[9][];
		int q = 0;
		while(lpf[n] > 0){
			int p = lpf[n];
			if(q == 0 || p != f[q-1][0]){
				f[q++] = new int[]{p, 1};
			}else{
				f[q-1][1]++;
			}
			n /= p;
		}
		if(n > 1){
			// big prime
			return new int[][]{{n, 1}};
		}
		return Arrays.copyOf(f, q);
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
//		int n = 100000, m = 99999;
//		int[] primes = sieveEratosthenes(500000);
//		
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		Set<Integer> hey = new HashSet<>();
//		for(int rep = 0;rep < n;rep++){
//			tr(rep);
//			inner:
//			while(true){
//				int x = gen.nextInt(primes.length);
//				int y = gen.nextInt(primes.length);
//				if(x != y && (long)primes[x] * primes[y] <= 500000){
//					if(hey.add(primes[x] * primes[y])){
//						sb.append(primes[x] * primes[y] + " ");
//						break inner;
//					}
//				}
//			}
//		}
//		
//		int num = 0;
//		for(int i = 0;i < primes.length;i++){
//			for(int j = i+1;j < primes.length && num <= n;j++){
//				if((long)primes[i] * primes[j] <= 1000000){
//					sb.append(primes[i] * primes[j] + " ");
//					num++;
//				}
//			}
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