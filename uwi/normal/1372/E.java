//package round655;
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
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] rs = new int[n][];
		
		int[][] left = new int[n][m];
		int[][] right = new int[n][m];
		
		for(int i = 0;i < n;i++){
			int K = ni();
			int[] ls = new int[K];
			for(int j = 0;j < K;j++){
				ls[j] = ni()-1;
				ni();
			}
			rs[i] = ls;
			
			Arrays.fill(left[i], -1);
			for(int j = 0;j < K;j++){
				left[i][ls[j]] = ls[j];
			}
			for(int j = 0;j < m;j++){
				if(left[i][j] < 0){
					left[i][j] = left[i][j-1];
				}
			}
			Arrays.fill(right[i], -1);
			for(int j = 0;j < K-1;j++){
				right[i][ls[j+1]-1] = ls[j+1]-1;
			}
			right[i][m-1] = m-1;
			for(int j = m-1;j >= 0;j--){
				if(right[i][j] < 0){
					right[i][j] = right[i][j+1];
				}
			}
		}
		
		long[][] dp = new long[m][m];
		for(int len = 1;len <= m;len++){
			for(int i = 0;i+len-1 < m;i++){
				int j = i+len-1;
				for(int k = i;k <= j;k++){
					int s = 0;
					for(int l = 0;l < n;l++){
						if(i <= left[l][k] && right[l][k] <= j)s++;
					}
					dp[i][j] = Math.max(dp[i][j], (i <= k-1 ? dp[i][k-1] : 0) + s*s + (k+1 <= j ? dp[k+1][j] : 0));
				}
			}
		}
		out.println(dp[0][m-1]);
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