//package round297;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	long[] F;
	int[] ps = new int[14];
	long[][] all;
	long ret = 0;
	
	void solve()
	{
		F = new long[19];
		F[0] = 1;
		for(int i = 1;i <= 18;i++)F[i] = F[i-1] * i;
		
		int n = ni(), K = ni();
		long S = nl();
		int[] a = na(n);
		int h = n/2;
		all = new long[14][(int)Math.pow(3, 12)];
		Arrays.fill(ps, 0);
		dfs(0, h, 0, 0L, a);
		for(int i = 0;i < 14;i++){
			Arrays.sort(all[i], 0, ps[i]);
			all[i] = Arrays.copyOf(all[i], ps[i]);
		}
		
		dfs2(h, n, K, S, a);
		out.println(ret);
	}
	
	void dfs(int cur, int to, int use, long s, int[] a)
	{
		if(s > 10000000000000000L)return;
		if(cur == to){
			all[use][ps[use]++] = s;
			return;
		}
		
		dfs(cur+1, to, use, s, a);
		dfs(cur+1, to, use, s+a[cur], a);
		if(a[cur] <= 18)dfs(cur+1, to, use+1, s+F[a[cur]], a);
	}
	
	void dfs2(int cur, int to, int use, long s, int[] a)
	{
		if(s < 0)return;
		if(use < 0)return;
		if(cur == to){
			for(int i = 0;i <= use && i < all.length;i++){
//				tr(all[use], s, upperBound(all[use], s), lowerBound(all[use], s));
				ret += upperBound(all[i], s) - lowerBound(all[i], s) + 1;
			}
			return;
		}
		
		dfs2(cur+1, to, use, s, a);
		dfs2(cur+1, to, use, s-a[cur], a);
		if(a[cur] <= 18)dfs2(cur+1, to, use-1, s-F[a[cur]], a);
	}
	
	public static int lowerBound(long[] a, long v)
	{
		int low = -1, high = a.length;
		while(high-low > 1){
			int h = high+low>>>1;
			if(a[h] >= v){
				high = h;
			}else{
				low = h;
			}
		}
		return high;
	}
	
	public static int upperBound(long[] a, long v)
	{
		int low = -1, high = a.length;
		while(high-low > 1){
			int h = high+low>>>1;
			if(a[h] <= v){
				low = h;
			}else{
				high = h;
			}
		}
		return low;
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