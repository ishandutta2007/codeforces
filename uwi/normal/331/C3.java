//package abbyy3.f;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C5 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	long[][][] dp;
	int[][][] to;
	
	void solve()
	{
		dp = new long[19][10][10]; // [digit][last digit][sumup]
		to = new int[19][10][10];
		for(int i = 0;i <= 9;i++){
			for(int j = 0;j < 10;j++){
				if(j == 0){
					dp[0][i][j] = i == 0 ? 0 : 1;
					to[0][i][j] = -1;
					continue;
				}
				int del = Math.max(j, i);
				if(i-del >= 0){
					dp[0][i][j] = dp[0][i-del][j] + 1;
					to[0][i][j] = to[0][i-del][j];
				}else{
					dp[0][i][j] = 1;
					to[0][i][j] = 10+(i-del);
				}
			}
		}
		for(int d = 1;d <= 18;d++){
			for(int i = 0;i < 10;i++){
				for(int j = 0;j < 10;j++){
					long sum = 0;
					int low = i;
					for(int k = 9;k >= 0;k--){
						sum += dp[d-1][low][Math.max(j, k)];
						low = to[d-1][low][Math.max(j, k)];
					}
					dp[d][i][j] = sum;
					to[d][i][j] = low;
				}
			}
		}
//		for(int i = 0;i < 10;i++){
//			tr(dp[0][i]);
//		}
//		for(int i = 0;i < 10;i++){
//			tr(to[0][i]);
//		}
		long n = nl();
		long ret = 0L;
		int last = (int)(n % 10);
		for(long dd = 10, e = 0;e <= 17;dd *= 10, e++){
			int max = 0;
			for(long u = n/dd/10;u > 0;u /= 10){
				max = Math.max(max, (int)(u % 10));
			}
//			tr(max, last, e, dd);
			for(int k = (int)(n/dd%10);k >= 0;k--){
				ret += dp[(int)e][last][Math.max(max, k)];
//				tr(e, last, Math.max(max, k), ret, k);
				last = to[(int)e][last][Math.max(max, k)];
			}
			if(last == -1){
				n = 0;
				break;
			}
			if(n / (dd*10) * (dd*10) == 0)break;
			n = n / (dd*10) * (dd*10) - 10 + last;
//			tr(n, ret);
		}
//		tr(n);
		out.println(ret);
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
	
	public static void main(String[] args) throws Exception { new C5().run(); }
	
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