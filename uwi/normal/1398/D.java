//package ecr93;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int R = ni(), G = ni(), B = ni();
		int[] rs = na(R);
		int[] gs = na(G);
		int[] bs = na(B);
		Arrays.sort(rs);
		Arrays.sort(gs);
		Arrays.sort(bs);
		rs = rev_(rs);
		gs = rev_(gs);
		bs = rev_(bs);
		long[][][] dp = new long[R+1][G+1][B+1];
//		for(int i = 0;i <= R;i++){
//			for(int j = 0;j <= G;j++){
//				Arrays.fill(dp[i][j], Long.MIN_VALUE / 3);
//			}
//		}
		long ans = 0;
		for(int i = 0;i <= R;i++){
			for(int j = 0;j <= G;j++){
				for(int k = 0;k <= B;k++){
					long v = 0;
					if(i-1 >= 0 && j-1 >= 0){
						v = Math.max(v, dp[i-1][j-1][k] + rs[i-1] * gs[j-1]);
					}
					if(j-1 >= 0 && k-1 >= 0){
						v = Math.max(v, dp[i][j-1][k-1] + gs[j-1] * bs[k-1]);
					}
					if(k-1 >= 0 && i-1 >= 0){
						v = Math.max(v, dp[i-1][j][k-1] + bs[k-1] * rs[i-1]);
					}
					dp[i][j][k] = v;
					ans = Math.max(ans, v);
				}
			}
		}
		out.println(ans);
	}
	
	public static int[] rev_(int[] a){for(int i = 0, j = a.length-1;i < j;i++,j--){int c = a[i]; a[i] = a[j]; a[j] = c;}return a;}

	
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