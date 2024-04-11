//package round656;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Set;

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--)go();
	}
	
	void go()
	{
		int n = ni();
		int[] a = na(n);
		int[] b = na(n);
		for(int i = 0;i < n;i++)a[i]--;
		for(int i = 0;i < n;i++)b[i]--;
		int[] f = new int[n];
		for(int i = 0;i < n;i++)f[a[i]]++;
		for(int i = 0;i < n;i++)f[b[i]]++;
		for(int i = 0;i < n;i++){
			if(f[i] != 2){
				out.println(-1);
				return;
			}
		}
		int[] c = concat(a, b);
		int[][] buc = makeBuckets(c, n-1);
		int[] from = new int[2*n];
		int[] to = new int[2*n];
		int[] ws = new int[2*n];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(buc[i][1] < n){
				// source
				for(int j = 0;j < 2;j++){
					int step = 1;
					for(int cur = buc[i][j];;){
						int l = c[cur+n];
						if(buc[l][0] >= n){
							// sink
							from[p] = i;
							to[p] = l;
							ws[p] = step<<1|j;
							p++;
							break;
						}
						cur = buc[l][0];
						step++;
					}
				}
			}
		}
//		tr(Arrays.copyOf(from, p));
//		tr(Arrays.copyOf(to, p));
//		tr(Arrays.copyOf(ws, p));
		int[][][] g = packWD(n, from, to, ws, p);
		int[][][] ig = packWD(n, to, from, ws, p);
		int[] dirs = minWeightMatching(g, ig);
		out.println(ret);
		
		List<Integer> hand = new ArrayList<>();
		for(int i = 0;i < n;i++){
			if(buc[i][1] < n){
				// source
				int j = dirs[i];
				for(int cur = buc[i][j];;){
					int l = c[cur+n];
					out.print(cur+1 + " ");
					hand.add(cur);
					if(buc[l][0] >= n){
						// sink
						break;
					}
					cur = buc[l][0];
				}
			}
		}
		out.println();
		
		assert hand.size() == ret;
		Set<Integer> set = new HashSet<>(hand);
		assert set.size() == hand.size();
		for(int u : hand){
			assert 0 <= u && u < n;
		}
		for(int u : hand){
			int d = c[u]; c[u] = c[u+n]; c[u+n] = d;
		}
		{
			Set<Integer> perm = new HashSet<>();
			for(int i = 0;i < n;i++){
				assert perm.add(c[i]);
			}
		}
		{
			Set<Integer> perm = new HashSet<>();
			for(int i = 0;i < n;i++){
				assert perm.add(c[i+n]);
			}
		}
	}
	
	long ret;
	
	int[] minWeightMatching(int[][][] g, int[][][] ig)
	{
		int n = g.length;
		int[] dirs = new int[n];
		ret = 0;
		Arrays.fill(dirs, -1);
		for(int i = 0;i < n;i++){
			if(g[i].length == 2 && dirs[i] == -1){
				int[] cost = new int[2];
				cost[0] = g[i][0][1]/2;
				for(int j = g[i][0][0], p = i;;){
					cost[1] += (ig[j][0][0] == p ? ig[j][1][1] : ig[j][0][1])/2;
					int nj = ig[j][0][0] ^ ig[j][1][0] ^ p;
					if(nj == i)break;
					p = j; j = nj;
					cost[0] += (g[j][0][0] == p ? g[j][1][1] : g[j][0][1])/2;
					nj = g[j][0][0] ^ g[j][1][0] ^ p;
					p = j; j = nj;
				}
				int par = cost[0] <= cost[1] ? 0 : 1;
				dirs[i] = g[i][0][1]&1^par;
				for(int j = g[i][0][0], p = i;;){
					int nj = ig[j][0][0] ^ ig[j][1][0] ^ p;
					if(nj == i)break;
					p = j; j = nj;
					dirs[j] = (g[j][0][0] == p ? g[j][1][1] : g[j][0][1])&1^par;
					nj = g[j][0][0] ^ g[j][1][0] ^ p;
					p = j; j = nj;
				}
				ret += Math.min(cost[0], cost[1]);
			}
		}
		
		return dirs;
	}
	
	public static int[][][] packWD(int n, int[] from, int[] to, int[] w){ return packWD(n, from, to, w, from.length); }
	public static int[][][] packWD(int n, int[] from, int[] to, int[] w, int sup)
	{
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]][2];
		for(int i = 0;i < sup;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
		}
		return g;
	}

	
	public static int[][] makeBuckets(int[] a, int sup)
	{
		int n = a.length;
		int[][] bucket = new int[sup+1][];
		int[] bp = new int[sup+1];
		for(int i = 0;i < n;i++)bp[a[i]]++;
		for(int i = 0;i <= sup;i++)bucket[i] = new int[bp[i]];
		for(int i = n-1;i >= 0;i--)bucket[a[i]][--bp[a[i]]] = i;
		return bucket;
	}

	
	public static int[] concat(int[]... s)
	{
		int n = 0; // if making first element 0, n = 1.
		for(int[] u : s)n += u.length;
		int[] ret = new int[n];
		n = 0; // if making first element 0, n = 1.
		for(int[] u : s){
			System.arraycopy(u, 0, ret, n, u.length);
			n += u.length;
		}
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
	
	public static void main(String[] args) throws Exception { new G().run(); }
	
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