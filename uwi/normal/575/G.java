//package bubble8;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.InputMismatchException;
import java.util.Queue;

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		int[] w = new int[m];
		for (int i = 0; i < m; i++) {
			from[i] = ni();
			to[i] = ni();
			w[i] = ni();
		}
		int[][][] g = packWU(n, from, to, w);
		int[] ds = distmap(g, 0);
		int[] dg2 = distmap2(g, n-1);
		
		int[] come = new int[n];
		Arrays.fill(come, 10);
		Queue<Integer> q = new ArrayDeque<>();
		
		int N = n+3;
		for(int i = 0;i < n;i++){
			if(dg2[i] == 0){
				N = Math.min(N, ds[i]);
			}
		}
		
		char[] ret = new char[N];
		for(int i = 0;i < n;i++){
			if(dg2[i] == 0 && ds[i] == N){
				q.add(i);
				come[i] = -1;
			}
		}
		
		int pos = 0;
		while(!q.isEmpty()){
			if(ds[q.peek()] == 0)break;
			Queue<Integer> nq = new ArrayDeque<>();
			int lmin = 10;
			while(!q.isEmpty()){
				int cur = q.poll();
				for(int[] e : g[cur]){
					if(ds[e[0]] < ds[cur]){
						if(come[e[0]] == 10){
							nq.add(e[0]);
						}
						if(e[1] < come[e[0]]){
							come[e[0]] = e[1];
						}
						lmin = Math.min(lmin, e[1]);
					}
				}
			}
			ret[pos++] = (char)('0'+lmin);
			while(!nq.isEmpty()){
				int cur = nq.poll();
				if(come[cur] == lmin){
					q.add(cur);
				}
			}
		}
		boolean vis = false;
		for(int i = 0;i < N;i++){
			if(ret[i] != '0')vis = true;
			if(vis)out.print(ret[i]);
		}
		if(!vis)out.print(0);
		out.println();
		
//		if(dg2[i] == 0 && ds[i] == N){
		q = new ArrayDeque<>();
		q.add(0);
		
		int[] prev = new int[n];
		Arrays.fill(prev, -1);
		int[] dsx = new int[n];
		Arrays.fill(dsx, 99999999);
		dsx[0] = 0;
		while(!q.isEmpty()){
			int cur = q.poll();
			for(int[] e : g[cur]){
				if(dsx[e[0]] > dsx[cur] + 1){
					if(N-1-ds[cur] >= 0){
						if(ret[N-1-ds[cur]] != '0' + e[1])continue;
					}else{
						if(e[1] != 0)continue;
					}
					dsx[e[0]] = dsx[cur] + 1;
					q.add(e[0]);
					prev[e[0]] = cur;
				}
			}
		}
		
		out.println(dsx[n-1]+1);
		int[] route = new int[dsx[n-1]+1];
		int p = dsx[n-1];
		for(int i = n-1;i != -1;i = prev[i]){
			route[p--] = i;
		}
		
		for(int v : route){
			out.print(v + " ");
		}
		out.println();
	}
	
	int[] distmap(int[][][] g, int s)
	{
		int n = g.length;
		int[] d = new int[n];
		Arrays.fill(d, 999999999);
		d[s] = 0;
		Queue<Integer> q = new ArrayDeque<>();
		q.add(s);
		while(!q.isEmpty()){
			int cur = q.poll();
			for(int[] e : g[cur]){
				if(d[e[0]] > d[cur] + 1){
					d[e[0]] = d[cur] + 1;
					q.add(e[0]);
				}
			}
		}
		return d;
	}
	
	int[] distmap2(int[][][] g, int s)
	{
		int n = g.length;
		int[] d = new int[n];
		Arrays.fill(d, 999999999);
		d[s] = 0;
		Deque<Integer> q = new ArrayDeque<>();
		q.add(s);
		while(!q.isEmpty()){
			int cur = q.pollFirst();
			for(int[] e : g[cur]){
				if(e[1] > 0){
					if(d[e[0]] > d[cur] + 1){
						d[e[0]] = d[cur] + 1;
						q.addLast(e[0]);
					}
				}else{
					if(d[e[0]] > d[cur]){
						d[e[0]] = d[cur];
						q.addFirst(e[0]);
					}
				}
			}
		}
		return d;
	}
	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]][2];
		for (int i = 0; i < from.length; i++) {
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			g[to[i]][p[to[i]]][1] = w[i];
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
	
	public static void main(String[] args) throws Exception { new G().run(); }
	
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