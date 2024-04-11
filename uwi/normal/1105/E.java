//package round533;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		Map<String, Integer> n2id = new HashMap<>();
		int gen = 0;
		long[] ptns = new long[n+1];
		int p = -1;
		for(int i = 0;i < n;i++){
			int t = ni();
			if(t == 1){
				if(p < 0 || ptns[p] != 0){
					p++;
				}
			}else{
				String name = ns();
				if(!n2id.containsKey(name)){
					n2id.put(name, gen++);
				}
				int v = n2id.get(name);
				ptns[p] |= 1L<<v;
			}
		}
		ptns = Arrays.copyOf(ptns, p+1);
		long[] g = new long[m];
		for(int j = 0;j < ptns.length;j++){
			for(int i = 0;i < m;i++){
				if(ptns[j]<<~i<0){
					g[i] |= ptns[j];
				}
			}
		}
		for(int i = 0;i < m;i++){
			g[i] &= ~(1L<<i);
			g[i] = ~g[i]&(1L<<m)-1;
		}
		out.println(solveMaximumClique(g));
	}
	
	public static int solveMaximumClique(long[] g)
	{
		int n = g.length;
		int h = n/2;
		int[] dp = new int[1<<n-h];
		for(int i = 0;i < 1<<h;i++){
			long cover = (1L<<n)-1;
			for(int j = 0;j < h;j++){
				if(i<<~j<0)cover &= g[j];
			}
			if((cover&i) == i){
				dp[(int)(cover>>>h)] = Math.max(dp[(int)(cover>>>h)], Integer.bitCount(i));
			}
		}
		for(int i = 0;i < n-h;i++){
			for(int j = 0;j < 1<<n-h;j++){
				if(j<<~i>=0){
					dp[j] = Math.max(dp[j], dp[j|1<<i]);
				}
			}
		}
		
		int ret = 0;
		for(int i = 0;i < 1<<n-h;i++){
			long cover = (1L<<n)-1;
			for(int j = 0;j < n-h;j++){
				if(i<<~j<0)cover &= g[j+h];
			}
			if((cover&(long)i<<h) == (long)i<<h){
				ret = Math.max(ret, Integer.bitCount(i) + dp[i]);
			}
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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