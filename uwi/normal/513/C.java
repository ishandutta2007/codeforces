//package rocket2015;
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
		int[][] as = new int[n][];
		for(int i = 0;i < n;i++){
			int[] g = na(2);
			as[i] = new int[]{10001-g[1], 10001-g[0]};
		}
		
		double E = 0;
		for(int i = 0;i < n;i++){
			double[] es = new double[10002];
			for(int j = 1;j <= 10001;j++){
				double P = 1;
				for(int k = 0;k < n;k++){
					if(k != i){
						if(as[k][1] < j){
							P = 0; break;
						}
						int len = as[k][1] - Math.max(as[k][0], j) + 1;
						P *= (double)len / (as[k][1]-as[k][0]+1);
					}
				}
				es[j] = P;
			}
			for(int j = 1;j <= 10000;j++){
				es[j] -= es[j+1];
			}
			for(int j = 10000;j >= 1;j--){
				es[j] *= j;
			}
			for(int j = 10000;j >= 1;j--){
				es[j] += es[j+1];
			}
			for(int j = as[i][0];j <= as[i][1];j++){
				E += es[j+1]/(as[i][1]-as[i][0]+1);
			}
		}
		
		for(int v = 1;v <= 10000;v++){
			double[] dp = new double[n+1];
			dp[0] = 1;
			for(int i = 0;i < n;i++){
				double peq = 0, pup = 0;
				if(as[i][0] <= v && v <= as[i][1]){
					peq = 1./(as[i][1]-as[i][0]+1);
				}
				if(v+1 <= as[i][1]){
					int len = as[i][1] - Math.max(as[i][0], v+1) + 1;
					pup = (double)len / (as[i][1]-as[i][0]+1);
				}
				for(int j = n-1;j >= 0;j--){
					dp[j+1] += dp[j] * peq;
					dp[j] = dp[j] * pup;
				}
			}
			for(int i = 2;i <= n;i++){
				E += v * dp[i];
			}
		}
		out.printf("%.12f\n", 10001-E);
		
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