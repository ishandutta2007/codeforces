//package manthan2017;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	long[][][] hdps = new long[11][61][];
	long[][][] dps = new long[11][61][];
	
	void solve()
	{
		for(int b = 2;b <= 10;b++){
			long[] dp = new long[1<<b];
			dp[0] = 1;
			dps[b][0] = dp;
			for(int i = 1;i <= 60;i++){
				long[] pdp = new long[1<<b];
				for(int j = 0;j < 1<<b;j++){
					for(int k = 1;k < b;k++){
						pdp[j^1<<k] += dp[j];
					}
				}
				hdps[b][i] = pdp;
				
				long[] ndp = new long[1<<b];
				for(int j = 0;j < 1<<b;j++){
					for(int k = 0;k < b;k++){
						ndp[j^1<<k] += dp[j];
					}
				}
				dps[b][i] = ndp;
				dp = ndp;
			}
		}
		
		for(int Q = ni();Q > 0;Q--){
			int b = ni();
			long L = nl(), R = nl();
			out.println(count(R, b) - count(L-1, b));
		}
	}
	
	long count(long n, int b)
	{
		char[] s = Long.toString(n, b).toCharArray();
		long ans = 0;
		int ptn = 0;
		for(int i = 0;i < s.length;i++){
			int v = s[i]-'0';
			for(int j = i == 0 ? 1 : 0;j < v;j++){
				ans += dps[b][s.length-1-i][ptn^1<<j];
			}
			ptn ^= 1<<v;
		}
		if(ptn == 0)ans++;
		for(int i = 1;i < s.length;i++){
			ans += hdps[b][i][0];
		}
		return ans;
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