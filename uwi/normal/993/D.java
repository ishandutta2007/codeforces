//package round488;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[] b = na(n);
		int[][] ts = new int[n][];
		for(int i = 0;i < n;i++){
			ts[i] = new int[]{a[i], b[i]};
		}
		Arrays.sort(ts, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return -(a[0] - b[0]);
				return -(a[1] - b[1]);
			}
		});
		// first is crazy
		
		int W = 100*n+1;
		long[][] dp = new long[W][n/2+1]; // sum b, space
		long I = Long.MAX_VALUE / 1000;
		for(int i = 0;i < W;i++){
			Arrays.fill(dp[i], I);
		}
		dp[0][0] = 0;
		for(int i = 0;i < n;){
			int j = i;
			while(j < n && ts[i][0] == ts[j][0])j++;
			
			long[][] ndp = new long[W][n/2+1]; // sum b, space
			for(int k = 0;k < W;k++){
				Arrays.fill(ndp[k], I);
			}
			for(int k = 0;k < W;k++){
				for(int l = 0;l <= n/2;l++){ // space
					if(dp[k][l] == I)continue;
					long asum = 0;
					int bsum = 0;
					for(int m = 0;m <= j-i;m++){ // m=show, hide
						if(l-(j-i-m) >= 0){
							int nl = Math.min(l-(j-i-m)+m, n/2);
							ndp[k+bsum][nl] = 
									Math.min(
											ndp[k+bsum][nl], 
											dp[k][l] + asum
											);
						}
						if(m < j-i){
							bsum += ts[i+m][1];
							asum += ts[i+m][0];
						}
					}
				}
			}
			dp = ndp;
			
			i = j;
		}
		
		long ans = Long.MAX_VALUE;
		for(int i = 1;i < W;i++){
			long min = I;
			for(int j = 0;j <= n/2;j++){
				min = Math.min(min, dp[i][j]);
			}
			if(min == I)continue;
			// min/i*1000
			ans = Math.min(ans, (min*1000+i-1)/i);
		}
		out.println(ans);
	}
	
	void run() throws Exception
	{
//		int n = 50, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(100000000)+1 + " ");
//		}
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(100)+1 + " ");
//		}
//		INPUT = sb.toString();

		
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