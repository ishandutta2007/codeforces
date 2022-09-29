//package rohspc2018;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Queue;
import java.util.Set;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for (int i = 0; i < m; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		
		for(int i = 0;i < n;i++){
			if(g[i].length != n-1){
				Arrays.sort(g[i]);
				int ng = -1;
				for(int j = 0;j < n;j++){
					if(j == i)continue;
					if(Arrays.binarySearch(g[i], j) < 0){
						ng = j;
						break;
					}
				}
				assert ng != -1;
				
				Queue<Integer> q = new ArrayDeque<>();
				int[] d = new int[n];
				Arrays.fill(d, 99999999);
				d[i] = 0;
				d[ng] = 0;
				q.add(i);
				q.add(ng);
				while(!q.isEmpty()){
					int cur = q.poll();
					for(int e : g[cur]){
						if(d[e] > d[cur] + 1){
							d[e] = d[cur] + 1;
							q.add(e);
						}
					}
				}
				
				int[] nfrom = new int[m];
				int[] nto = new int[m];
				int p = 0;
				for(int j = 0;j < m;j++){
					if(d[from[j]] < d[to[j]] || d[from[j]] == d[to[j]] && from[j] < to[j]){
						nfrom[p] = from[j]; nto[p] = to[j];
					}else{
						nfrom[p] = to[j]; nto[p] = from[j];
					}
					p++;
				}
				
				int[][] lg = packD(n, nfrom, nto, p);
				int[] ord = sortTopologically(lg);
				out.println("YES");
				int[] iord = new int[n];
				for(int j = 0;j < n;j++){
					iord[ord[j]] = j + 1;
				}
				for(int j = 0;j < n;j++){
					out.print(iord[j] + " ");
				}
				out.println();
				int[] first = Arrays.copyOf(iord, n);
				iord[ng] = 1;
				for(int j = 0;j < n;j++){
					out.print(iord[j] + " ");
				}
				out.println();
				int[] second = Arrays.copyOf(iord, n);
//				check(first, second, g);
				return;
			}
		}
		out.println("NO");
	}
	
	void check(int[] a, int[] b, int[][] g)
	{
		tr(a);
		tr(b);
		int n = a.length;
		Set<Integer> set = new HashSet<>();
		for(int i = 0;i < n;i++){
			assert 1 <= a[i];
			assert a[i] <= n;
			set.add(a[i]);
		}
		assert set.size() == n;
		set.clear();
		for(int i = 0;i < n;i++){
			assert 1 <= b[i];
			assert b[i] <= n;
			set.add(b[i]);
		}
		assert set.size() < n;
		for(int i = 0;i < n;i++){
			for(int e : g[i]){
				assert Integer.signum(a[i]-a[e]) == Integer.signum(b[i]-b[e]);
			}
		}
	}
	
	public static int[] sortTopologically(int[][] g)
	{
		int n = g.length;
		int[] ec = new int[n];
		for(int i = 0;i < n;i++){
			for(int to : g[i])ec[to]++;
		}
		int[] ret = new int[n];
		int q = 0;
		
		// sources
		for(int i = 0;i < n;i++){
			if(ec[i] == 0)ret[q++] = i;
		}
		
		for(int p = 0;p < q;p++){
			for(int to : g[ret[p]]){
				if(--ec[to] == 0)ret[q++] = to;
			}
		}
		// loop
		for(int i = 0;i < n;i++){
			if(ec[i] > 0)return null;
		}
		return ret;
	}

	
	public static int[][] packD(int n, int[] from, int[] to){ return packD(n, from, to, from.length);}
	public static int[][] packD(int n, int[] from, int[] to, int sup)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < sup;i++){
			g[from[i]][--p[from[i]]] = to[i];
		}
		return g;
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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