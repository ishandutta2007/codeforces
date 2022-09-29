//package round575;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.PriorityQueue;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		int[] ws = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			ws[i] = ni();
		}
		int[][][] g = packWU(n, from, to, ws);
		for(int[][] row : g){
			Arrays.sort(row, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[1] - b[1];
				}
			});

		}
		
		PriorityQueue<long[]> pq = new PriorityQueue<>((x, y) -> Long.compare(x[2], y[2]));
		Map<Long, Long> map = new HashMap<>();
		for(int i = 0;i < m;i++){
			map.put((long)Math.min(from[i], to[i])<<20|Math.max(from[i], to[i]), (long)ws[i]);
			pq.add(new long[]{Math.min(from[i], to[i]), Math.max(from[i], to[i]), ws[i]});
		}
		for(int i = 0;i < K;i++){
			long[] cur = null;
			while(true){
				cur = pq.poll();
				long code = (long)cur[0]<<20|cur[1];
				if(map.get(code) == cur[2])break;
			}
			if(i == K-1){
				out.println(cur[2]);
				return;
			}
			int f = (int)cur[0];
			int t = (int)cur[1];
			int ct = 0;
			for(int[] e : g[f]){
				if(e[0] == t)continue;
				if(++ct > K)break;
				long code = (long)Math.min(e[0], t)<<20|Math.max(e[0], t);
				if(!map.containsKey(code) || map.get(code) > e[1] + cur[2]){
					map.put(code, e[1]+cur[2]);
					pq.add(new long[]{Math.min(e[0], t), Math.max(e[0], t), e[1] + cur[2]});
				}
			}
			ct = 0;
			for(int[] e : g[t]){
				if(e[0] == f)continue;
				if(++ct > K)break;
				long code = (long)Math.min(e[0], f)<<20|Math.max(e[0], f);
				if(!map.containsKey(code) || map.get(code) > e[1] + cur[2]){
					map.put(code, e[1]+cur[2]);
					pq.add(new long[]{Math.min(e[0], f), Math.max(e[0], f), e[1] + cur[2]});
				}
			}
		}
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
//		int n = 200000, m = 99999;
//		Random gen = new Random(114514);
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n-1 + " ");
//		sb.append(400 + " ");
//		for (int i = 0; i < n-1; i++) {
//			sb.append(1 + " " + (i+2) + " " + gen.nextInt(1000000000) +"\n");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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