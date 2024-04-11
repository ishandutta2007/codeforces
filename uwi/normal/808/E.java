//package educational.round21;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] ws = new int[4][n];
		int[] wp = new int[4];
		Random gen = new Random();
		for(int i = 0;i < n;i++){
			int w = ni();
			int c = ni();
			ws[w][wp[w]++] = c;
		}
		
		long[][] cum = new long[4][];
		for(int i = 1;i <= 3;i++){
			ws[i] = Arrays.copyOf(ws[i], wp[i]);
			ws[i] = shuffle(ws[i], gen);
			Arrays.sort(ws[i]);
			for(int j = 0, k = ws[i].length-1;j < k;j++,k--){
				int d = ws[i][j]; ws[i][j] = ws[i][k]; ws[i][k] = d;
			}
			cum[i] = new long[ws[i].length+1];
			for(int j = 0;j < cum[i].length-1;j++){
				cum[i][j+1] = cum[i][j] + ws[i][j];
			}
		}
		
		long[] dp = new long[m+1];
		Arrays.fill(dp, Long.MIN_VALUE / 3);
		dp[0] = 0;
		for(int i = 1;i <= 3;i++){
			long[] ndp = new long[m+1];
			Arrays.fill(ndp, Long.MIN_VALUE / 3);
			gcum = cum[i];
			for(int u = 0;u < i;u++){
				long[] odp = new long[(m-u)/i+1];
				for(int j = u, k = 0;j <= m;j+=i,k++){
					odp[k] = -dp[j];
				}
				long[] nldp = new long[odp.length];
				divideAndConquer(0, odp.length, 0, odp.length, odp, nldp);
				for(int j = u, k = 0;j <= m;j+=i,k++){
					ndp[j] = -nldp[k];
				}
			}
			dp = ndp;
		}
		out.println(Arrays.stream(dp).max().getAsLong());
	}
	
	long[] gcum;
	
	public void divideAndConquer(int l, int r, int argl, int argr, long[] pre, long[] cur)
	{
		if(l >= r)return;
		int h = l+r>>1;
		long min = Long.MAX_VALUE / 3;
		int argmin = -1;
		for(int i = Math.max(argl, 0);i < argr && i <= h;i++){
			long val = pre[i] + f(i, h); // [i,h)
			if(val < min){
				min = val;
				argmin = i;
			}
		}
		cur[h] = min;
		
		if(r-l > 1){
			divideAndConquer(l, h, argl, argmin+1, pre, cur);
			divideAndConquer(h+1, r, argmin, argr, pre, cur);
		}else{
			cur[l] = Math.min(cur[l], pre[l]);
		}
	}
	
	private long f(int l, int r){
		if(r-l < gcum.length){
			return -gcum[r-l];
		}else{
			return Long.MAX_VALUE / 3;
		}
	}
	
	public static int[] shuffle(int[] a, Random gen){ for(int i = 0, n = a.length;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }

	
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