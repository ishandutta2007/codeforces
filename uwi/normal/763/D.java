//package round395;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.Random;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	int[] mods = new int[2];
	int[] muls = new int[2];
	long[] anss;
	long[][] pows = new long[2][];
	
	void solve()
	{
		int n = ni();
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		
		Random gen = new Random();
		for(int i = 0;i < 2;i++){
			mods[i] = BigInteger.probablePrime(30, gen).intValue();
			muls[i] = BigInteger.probablePrime(29, gen).intValue();
			pows[i] = enumPows(muls[i], 105000, mods[i]);
		}
		
		long[][] hs = new long[2][n];
		for(int z = 0;z < 2;z++){
			long[] temp = new long[n];
			for(int i = n-1;i >= 0;i--){
				int cur = ord[i];
				long h = 114514;
				int p = 0;
				for(int e : g[cur]){
					if(e == par[cur])continue;
					temp[p++] = hs[z][e];
				}
				Arrays.sort(temp, 0, p);
				for(int j = 0;j < p;j++){
					h = (h * muls[z] + temp[j] * temp[j]) % mods[z];
				}
				hs[z][cur] = h;
			}
		}
		Map<Long, Integer> lhc = new HashMap<>();
		for(int i = 0;i < n;i++){
			inc(lhc, hs[0][i]<<32|hs[1][i], 1);
//			tr(hs[0][i]<<32|hs[1][i], 1);
		}
		
		max = -1;
		argmax = -1;
		
//		anss = new long[n];
		dfs(0, -1, new long[]{hs[0][0], hs[1][0]}, par, g, hs, lhc);
		out.println(argmax+1);
//		for(int i = 0;i <n;i++){
//			out.println(anss[i]);
//		}
	}
	
	void inc(Map<Long, Integer> map, long k, int v)
	{
		if(map.containsKey(k)){
			if(map.get(k) + v == 0){
				map.remove(k);
			}else{
				map.put(k, map.get(k) + v);
			}
		}else{
			map.put(k, v);
		}
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

	
	public static long[] enumPows(int a, int n, int mod)
	{
		a %= mod;
		long[] pows = new long[n+1];
		pows[0] = 1;
		for(int i = 1;i <= n;i++)pows[i] = pows[i-1] * a % mod;
		return pows;
	}
	
	int max = -1;
	int argmax = -1;
	
	void dfs(int cur, int pre, long[] downh, int[] par, int[][] g, long[][] hs, Map<Long, Integer> lhc)
	{
		inc(lhc, hs[0][cur]<<32|hs[1][cur], -1);
//		tr(hs[0][cur]<<32|hs[1][cur], -1);
//		tr(lhc.size);
		
		long[][] temp = new long[2][g[cur].length];
		
		long[][] ph = new long[2][g[cur].length+1];
		for(int z = 0;z < 2;z++){
			int p = 0;
			for(int e : g[cur]){
				if(e == par[cur]){
					temp[z][p++] = downh[z];
				}else{
					temp[z][p++] = hs[z][e];
				}
			}
			Arrays.sort(temp[z]);
			
			ph[z][0] = 114514;
			for(int j = 0;j < p;j++){
				ph[z][j+1] = (ph[z][j] * muls[z] + temp[z][j] * temp[z][j]) % mods[z];
			}
		}
//		tr(cur);
//		anss[cur] = lhc.size() + 1;
		if(lhc.size() > max){
			max = lhc.size();
			argmax = cur;
		}
		
		long[] lhs = new long[2];
		for(int e : g[cur]){
			if(e == pre)continue;
			for(int z = 0;z < 2;z++){
				int ind = Arrays.binarySearch(temp[z], hs[z][e]);
				assert ind >= 0;
				long lower = (ph[z][ph[0].length-1] - ph[z][ind+1] * pows[z][ph[0].length-1-(ind+1)]);
				long higher = ph[z][ind] * pows[z][ph[0].length-2-ind];
				long lh = (higher+lower) % mods[z];
				if(lh < 0)lh += mods[z];
				lhs[z] = lh;
			}
			inc(lhc, lhs[0]<<32|lhs[1], 1);
//			tr(lhs[0]<<32|lhs[1], 1);
			dfs(e, cur, lhs, par, g, hs, lhc);
			inc(lhc, lhs[0]<<32|lhs[1], -1);
//			tr(lhs[0]<<32|lhs[1], -1);
		}
		inc(lhc, hs[0][cur]<<32|hs[1][cur], 1);
//		tr(hs[0][cur]<<32|hs[1][cur], 1);
	}

	public static int[][] parents3(int[][] g, int root) {
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);

		int[] depth = new int[n];
		depth[0] = 0;

		int[] q = new int[n];
		q[0] = root;
		for (int p = 0, r = 1; p < r; p++) {
			int cur = q[p];
			for (int nex : g[cur]) {
				if (par[cur] != nex) {
					q[r++] = nex;
					par[nex] = cur;
					depth[nex] = depth[cur] + 1;
				}
			}
		}
		return new int[][] { par, q, depth };
	}

	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
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
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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