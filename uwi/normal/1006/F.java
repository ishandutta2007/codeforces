//package round498;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		long K = nl();
		if(!(1 <= n && n <= 20))throw new RuntimeException("n");
		if(!(1 <= m && m <= 20))throw new RuntimeException("m");
		if(!(0 <= K && K <= 1000000000000000000L))throw new RuntimeException("K");
		long[][] a = new long[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				a[i][j] = nl();
				if(!(0 <= a[i][j] && a[i][j] <= 1000000000000000000L))throw new RuntimeException("a");
			}
		}
		
		int h = (n+m-2)/2;
		List<long[]> left = new ArrayList<>();
		dfs(0, 0, h, a, left, 0L);
		
		rot(a);
		
		List<long[]> right = new ArrayList<>();
		dfs(0, 0, n+m-2-h, a, right, 0L);
		
		rot(a);
		
		Map<Long, Map<Long, Integer>> maps = new HashMap<>();
		for(long[] r : right){
			if(!maps.containsKey(r[1])){
				maps.put(r[1], new HashMap<>());
			}
			countup(r[0], maps.get(r[1]));
		}
		
		long ans = 0;
		for(long[] l : left){
			Map<Long, Integer> map = maps.get(n-1-l[1]);
			if(map != null){
				long v = K^l[0]^a[(int)l[1]][(int)(h-l[1])];
				ans += map.getOrDefault(v, 0);
			}
		}
		out.println(ans);
	}
	
	public static <K> void countup(K key, Map<K, Integer> map)
	{
		map.put(key, map.getOrDefault(key, 0) + 1);
	}
	
	void rot(long[][] a)
	{
		int n = a.length, m = a[0].length;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				int k = i*m+j, l = (n-1-i)*m+(m-1-j);
				if(k < l){
					long d = a[i][j]; a[i][j] = a[n-1-i][m-1-j]; a[n-1-i][m-1-j] = d;
				}
			}
		}
	}
	
	void dfs(int r, int c, int h, long[][] a, List<long[]> left, long val)
	{
		int n = a.length, m = a[0].length;
		val ^= a[r][c];
		if(h == 0){
			left.add(new long[]{val, r});
			return;
		}
		if(r+1 < n){
			dfs(r+1, c, h-1, a, left, val);
		}
		if(c+1 < m){
			dfs(r, c+1, h-1, a, left, val);
		}
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