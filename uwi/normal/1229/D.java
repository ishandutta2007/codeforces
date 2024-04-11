//package round588;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.Queue;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	int[][] to;
	int K, F;
	int[][] tos;
	int[][] toss;
	int[] btc;
	
	long h(boolean[] ved)
	{
		long h = 0;
		for(int i = 0;i < F;i++){
			h = h * 1000000009 + (ved[i] ? 1 : 0);
		}
		return h;
	}
	
	void solve()
	{
		int n = ni();
		K = ni();
		F = 1; for(int i = 1;i <= K;i++)F *= i;
		
		to = new int[F][F];
		for(int i = 0;i < F;i++){
			for(int j = 0;j < F;j++){
				int[] na = apply(decPerm(i, K), decPerm(j, K));
				int nac = encPerm(na);	
				to[i][j] = nac;
			}
		}
		
		Map<Long, Integer> set = new HashMap<>();
		boolean[][] spans = new boolean[156][];
		int sp = 0;
		for(int u = 0;u < F;u++){
			for(int v = u;v < F;v++){
				int[] es = {u, v};
				boolean[] ved = new boolean[F];
				ved[0] = true;
				Queue<Integer> q = new ArrayDeque<>();
				q.add(0);
				while(!q.isEmpty()){
					int cur = q.poll();
					for(int e : es){
						int nac = to[cur][e];
						if(!ved[nac]){
							ved[nac] = true;
							q.add(nac);
						}
					}
				}
				
				long h = h(ved);
				if(!set.containsKey(h)){
					set.put(h, sp);
					spans[sp++] = ved;
				}
			}
		}
		
		tos = new int[sp][F];
		for(int i = 0;i < sp;i++){
			for(int j = 0;j < F;j++){
				if(spans[i][j]){
					tos[i][j] = i;
					continue;
				}
				
				boolean[] my = Arrays.copyOf(spans[i], F);
				Queue<Integer> q = new ArrayDeque<>();
				q.add(j);
				my[j] = true;
				while(!q.isEmpty()){
					int cur = q.poll();
					for(int k = 0;k < F;k++){
						if(my[k]){
							if(!my[to[k][cur]]){
								my[to[k][cur]] = true;
								q.add(to[k][cur]);
							}
							if(!my[to[cur][k]]){
								my[to[cur][k]] = true;
								q.add(to[cur][k]);
							}
						}
					}
				}
				long h = h(my);
				tos[i][j] = set.get(h);
			}
		}
		
		toss = new int[sp][sp];
		for(int i = 0;i < sp;i++){
			for(int j = 0;j < sp;j++){
				int cur = i;
				boolean[] v = spans[j];
				for(int k = 0;k < F;k++){
					if(v[k]){
						cur = tos[cur][k];
					}
				}
				toss[i][j] = cur;
			}
		}
		
		btc = new int[sp];
		for(int i = 0;i < sp;i++){
			for(int j = 0;j < F;j++){
				if(spans[i][j])btc[i]++;
			}
		}
		
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			int[] b = na(K);
			for(int j = 0;j < K;j++)b[j]--;
			a[i] = encPerm(b);
		}
		
		ans = 0;
		
		// 
		dfs(0, n, a);
		
		out.println(ans);
	}
	
	long ans = 0;
	
	void dfs(int l, int r, int[] a)
	{
		if(r-l == 1){
			ans += btc[tos[0][a[l]]];
			return;
		}
		
		int h = l+r>>1;
		int[][] L = go(h-1, l-1, -1, a);
		int[][] R = go(h, r, 1, a);
		for(int[] el : L){
			for(int[] er : R){
				ans += (long)btc[toss[el[0]][er[0]]] * el[1] * er[1];
			}
		}
		
		dfs(l, h, a);
		dfs(h, r, a);
	}
	
	int[][] go(int s, int t, int step, int[] a)
	{
		int sid = 0;
		int[][] uc = new int[Math.min(Math.abs(s-t), 160)][];
		int p = 0;
		for(int i = s;i != t;i += step){
			int nsid = tos[sid][a[i]];
			if(p > 0 && nsid == sid){
				uc[p-1][1]++;
			}else{
				uc[p++] = new int[]{nsid, 1};
			}
			sid = nsid;
		}
		return Arrays.copyOf(uc, p);
	}
	
	
	
	public static void tf(boolean... r)
	{
		for(boolean x : r)System.out.print(x?'#':'.');
		System.out.println();
	}
	
	public static int[] apply(int[] a, int[] b)
	{
		int n = a.length;
		int[] c = new int[n];
		for(int i = 0;i < n;i++){
			c[i] = b[a[i]];
		}
		return c;
	}
	
	public static int encPerm(int[] a)
	{
		int n = a.length;
		int used = 0;
		int ret = 0;
		for(int i = 0;i < n;i++){
			ret = ret * (n - i) + a[i] - Integer.bitCount(used & ((1<<a[i]) - 1));
			used |= 1<<a[i];
		}
		return ret;
	}
	
	public static int[] decPerm(int c, int n) {
		int[] a = new int[n];
		for (int i = n - 1; i >= 0; c /= n - i, i--) {
			a[i] = c % (n - i);
		}
		int rem = (1 << n) - 1;
		for(int i = 0;i < n;i++){
			int x = rem;
			for(int j = 0;j < a[i];j++, x &= x-1);
			
			a[i] = Integer.numberOfTrailingZeros(x);
			rem ^= x&-x;
		}
		return a;
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