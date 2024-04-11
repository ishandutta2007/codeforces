//package round500;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int q = (n+1)/2+3;
		long[][] dp = new long[3][q]; // 0:none(not candidate), 1:none(candidate), 2:decreased
		long I = (long)1e17;
		Arrays.fill(dp[0], (long)1e17);
		Arrays.fill(dp[1], (long)1e17);
		Arrays.fill(dp[2], (long)1e17);
		dp[1][0] = 0;
		for(int i = 1;i < n;i++){
			long[][] ndp = new long[3][q];
			Arrays.fill(ndp[0], (long)1e17);
			Arrays.fill(ndp[1], (long)1e17);
			Arrays.fill(ndp[2], (long)1e17);
			for(int j = 0;j < q;j++){
				if(dp[0][j] == I && dp[1][j] == I && dp[2][j] == I)continue;
				
				// move a[i]
				if(a[i-1] > a[i]){
					if(j+1 < q)ndp[0][j+1] = Math.min(ndp[0][j+1], dp[1][j]);
					ndp[0][j] = Math.min(ndp[0][j], dp[0][j]);
				}
				if(a[i-1] <= a[i]){
					// down a[i]
					if(j+1 < q)ndp[2][j+1] = Math.min(ndp[2][j+1], dp[1][j] + (a[i]-a[i-1]+1));
					ndp[0][j] = Math.min(ndp[0][j], dp[0][j]);
					ndp[0][j] = Math.min(ndp[0][j], dp[1][j]);
				}
				if(a[i-1] < a[i]){
					ndp[1][j] = Math.min(ndp[1][j], dp[0][j]);
					ndp[1][j] = Math.min(ndp[1][j], dp[1][j]);
				}
				// move a[i-1]
				if(a[i-1] >= a[i]){
					ndp[1][j] = Math.min(ndp[1][j], dp[1][j] + (a[i-1]-a[i]+1));
					ndp[1][j] = Math.min(ndp[1][j], dp[0][j] + (a[i-1]-a[i]+1));
				}
				
				if(i-2 >= 0){
					if(a[i-2]-1 < a[i]){
						ndp[1][j] = Math.min(ndp[1][j], dp[2][j]);
					}
					if(a[i-2]-1 >= a[i]){
						ndp[1][j] = Math.min(ndp[1][j], dp[2][j] + (a[i-2]-1-a[i]+1));
						ndp[0][j] = Math.min(ndp[0][j], dp[2][j]);
					}
				}
			}
			
			dp = ndp;
		}
		long[] anss = new long[(n+1)/2+2];
		Arrays.fill(anss, I);
		for(int i = 0;i <= (n+1)/2;i++){
			anss[i] = Math.min(anss[i], dp[0][i]);
			anss[i+1] = Math.min(anss[i+1], dp[1][i]);
			anss[i] = Math.min(anss[i], dp[2][i]);
		}
		for(int i = (n+1)/2;i >= 1;i--){
			anss[i-1] = Math.min(anss[i], anss[i-1]);
		}
		for(int i = 1;i <= (n+1)/2;i++){
			out.print(anss[i] + " ");
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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