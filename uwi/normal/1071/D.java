//package round517;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class D3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int[] lpf = enumLowestPrimeFactors(1000000);
		Map<Long, int[]> map = new HashMap<>();
		long[] hs = new long[1000001];
		for(int i = 1;i <= 1000000;i++){
			int[] lu = factorE(i, lpf);
			Arrays.sort(lu);
			hs[i] = (long)Arrays.hashCode(lu);
			map.put(hs[i], lu);
		}
		
		int K = 8;
		List<List<Set<Long>>> ls = new ArrayList<>();
		List<int[]> vs = new ArrayList<>(map.values());
		int gen = 0;
		Map<Long, Integer> htov = new HashMap<>();
		for(int[] v : vs){
			htov.put((long)Arrays.hashCode(v), gen++);
			cache = new HashSet<>();
			List<Set<Long>> hey = new ArrayList<>();
			for(int t = 0;t <= K;t++)hey.add(new HashSet<>());
			dfs(v, 0, K, hey);
			ls.add(hey);
		}
		
		int[][] cans = new int[ls.size()][ls.size()];
		for(int i = 0;i < ls.size();i++){
			Arrays.fill(cans[i], -1);
		}
		
		outer:
		for(int T = ni();T > 0;T--){
			int a = ni(), b = ni();
			int ia = htov.get(hs[a]);
			int ib = htov.get(hs[b]);
			if(cans[ia][ib] != -1){
				out.println(cans[ia][ib]);
				continue;
			}
			for(int d = 0;d <= 16;d++){
				for(int i = 0;i <= d && i <= 8;i++){
					int j = d-i;
					if(j >= 0 && j <= 8){
						if(!Collections.disjoint(ls.get(ia).get(i), ls.get(ib).get(j))){
							cans[ia][ib] = cans[ib][ia] = d;
							out.println(d);
							continue outer;
						}
					}
				}
			}
			throw new RuntimeException();
		}
	}
	
	Set<Long> cache = new HashSet<>();
	
	void dfs(int[] a, int dep, int lim, List<Set<Long>> set)
	{
		long h = dep + 114514;
		for(int v : a)h = h * 1000000009 + v;
		if(!cache.add(h)){
			return;
		}
		
		long x = 1;
		for(int v : a){
			x = x * (v+1);
		}
		set.get(dep).add(x);
		if(dep == lim)return;
		
		for(int i = 0;i < a.length;i++){
			if(i > 0 && a[i] == a[i-1])continue;
			if(a[i] > 1){
				int[] b = Arrays.copyOf(a, a.length);
				b[i]--;
				Arrays.sort(b);
				dfs(b, dep+1, lim, set);
			}
			{
				int[] b = Arrays.copyOf(a, a.length);
				b[i]++;
				Arrays.sort(b);
				dfs(b, dep+1, lim, set);
			}
			if(a[i] == 1){
				int[] b = Arrays.copyOf(a, a.length-1);
				int p = 0;
				for(int j = 0;j < a.length;j++){
					if(j == i)continue;
					b[p++] = a[j];
				}
				dfs(b, dep+1, lim, set);
			}
		}
		int[] b = Arrays.copyOf(a, a.length+1);
		b[a.length] = 1;
		Arrays.sort(b);
		dfs(b, dep+1, lim, set);
	}
	
	public static int[] factorE(int n, int[] lpf)
	{
		int[] f = new int[9];
		int q = 0;
		int pre = -1;
		while(lpf[n] > 0){
			int p = lpf[n];
			if(p != pre){
				pre = p;
				f[q++] = 1;
			}else{
				f[q-1]++;
			}
			n /= p;
		}
		if(n > 1){
			// big prime
			return new int[]{1};
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
//		int n = 99999, m = 99999;
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(36 + " " + (3*5*7*11<<9) + "\n");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D3().run(); }
	
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