//package educational.round17;
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
		int m = ni();
		long[][] a = new long[3][m];
		for(int i= 0;i < 3;i++){
			for(int j = 0;j < m;j++)a[i][j] = nl();
		}
		// 012
		// ABB BBA A.. ..A .A.
		long[][] dp = new long[m][5];
		dp[0][0] = a[0][0]+a[1][0]+a[2][0];
		dp[0][2] = a[0][0];
		dp[0][3] = a[0][0]+a[1][0]+a[2][0];
		dp[0][4] = a[0][0]+a[1][0];
		dp[0][1] = Long.MIN_VALUE / 10;
		for(int i = 1;i < m;i++){
			Arrays.fill(dp[i], Long.MIN_VALUE / 10);
			long[] pre = dp[i-1], cur = dp[i];
			long[] col = {a[0][i], a[1][i], a[2][i]};
			cur[0] = Math.max(cur[0], pre[0]+col[0]+col[1]+col[2]);
			cur[1] = Math.max(cur[1], pre[1]+col[0]+col[1]+col[2]);
			cur[2] = Math.max(cur[2], pre[2]+col[0]);
			cur[3] = Math.max(cur[3], pre[3]+col[2]);
			cur[4] = Math.max(cur[4], pre[4]+col[1]);
			
			cur[3] = Math.max(cur[3], pre[0]+col[0]+col[1]+col[2]);
			cur[2] = Math.max(cur[2], pre[1]+col[0]+col[1]+col[2]);
			
			cur[4] = Math.max(cur[4], pre[2]+col[0]+col[1]);
			cur[3] = Math.max(cur[3], pre[2]+col[0]+col[1]+col[2]);
			cur[4] = Math.max(cur[4], pre[3]+col[2]+col[1]);
			cur[2] = Math.max(cur[2], pre[3]+col[2]+col[1]+col[0]);
			cur[0] = Math.max(cur[0], pre[2]+col[2]+col[1]+col[0]);
			cur[1] = Math.max(cur[1], pre[3]+col[2]+col[1]+col[0]);
			cur[2] = Math.max(cur[2], pre[4]+col[1]+col[0]);
			cur[3] = Math.max(cur[3], pre[4]+col[1]+col[2]);
		}
		out.println(dp[m-1][3]);
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