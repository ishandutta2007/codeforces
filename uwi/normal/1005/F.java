//package round496;
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

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n= ni(), m = ni(), K = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		Map<Long, Integer> map = new HashMap<>();
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			map.put((long)from[i]<<32|to[i], i);
			map.put((long)to[i]<<32|from[i], i);
		}
		int[][] g = packU(n, from ,to);
		Queue<Integer> q = new ArrayDeque<Integer>();
		int[] d = new int[n];
		Arrays.fill(d, 99999999);
		q.add(0);
		d[0] = 0;
		while(!q.isEmpty()){
			int cur = q.poll();
			for(int e : g[cur]){
				if(d[e] > d[cur] + 1){
					d[e] = d[cur] + 1;
					q.add(e);
				}
			}
		}
		
		int[][] options = new int[n][];
		int[] temp = new int[n];
		for(int i = 0;i < n;i++){
			int p = 0;
			for(int e : g[i]){
				if(d[e] == d[i] - 1){
					temp[p++] = map.get((long)i<<32|e);
				}
			}
			options[i] = Arrays.copyOf(temp, p);
		}
		
		long num = 1;
		for(int[] row : options){
			if(row.length == 0)continue;
			num *= row.length;
			if(num > 1e9){
				num = (long)1e9;
			}
		}
		
		out.println(Math.min(num, K));
		
		char[] hey = new char[m];
		Arrays.fill(hey, '0');
		this.K = K;
		dfs(1, options, hey);
	}
	
	int K;
	
	void dfs(int cur, int[][] options, char[] hey)
	{
		if(K == 0)return;
		if(cur == options.length){
			out.println(new String(hey));
			K--;
			return;
		}
		for(int e : options[cur]){
			hey[e] = '1';
			dfs(cur+1, options, hey);
			if(K == 0)return;
			hey[e] = '0';
		}
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