//package round157;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int m = ni();
		int[] ct = count(m);
//		out.println(Arrays.toString(ct));
//		if(true)return;
		int mod = 1000000007;
		for(int i = 0;i < ct.length;i++){
			ct[i] %= mod;
		}
		long ret = 0;
		for(int u = 1;u <= 9;u++){
			for(int a = 0;a < u;a++){
				for(int b = 0;a+b < u;b++){
					for(int c = 0;a+b+c < u;c++){
						for(int d = 0;a+b+c+d < u;d++){
							for(int e = 0;a+b+c+d+e < u;e++){
								for(int f = 0;a+b+c+d+e+f < u;f++){
									int[] pl = new int[10];
									pl[a]++;
									pl[b]++;
									pl[c]++;
									pl[d]++;
									pl[e]++;
									pl[f]++;
									
									long lret = ct[u];
									for(int i = 0;i <= 9;i++){
										for(int j = 0;j < pl[i];j++){
											lret = lret * (ct[i]-j) % mod;
										}
									}
									ret += lret;
								}
							}
						}
					}
				}
			}
		}
		out.println(ret%mod);
	}
	
	
	
	int[] count(long m)
	{
		int[][] dp = new int[11][11];
		dp[0][0] = 1;
		
		int e = 0;
		long d = 1;
		for(;d <= m;d *= 10,e++){
			for(int i = 10;i >= 0;i--){
				dp[e+1][i] = dp[e][i]*8+(i-1 >= 0 ? dp[e][i-1]*2 : 0);
			}
		}
		
		int[] ret = new int[11];
		int edge = 0;
		for(;e >= 0;d /= 10,e--){
			int q = (int)(m/d%10);
			for(int i = 0;i < q;i++){
				if(i == 4 || i == 7){
					for(int k = 0;k <= 10 && edge+1+k <= 10;k++){
						ret[edge+1+k] += dp[e][k];
					}
				}else{
					for(int k = 0;k <= 10 && edge+k <= 10;k++){
						ret[edge+k] += dp[e][k];
					}
				}
			}
			if(q == 4 || q == 7)edge++;
		}
		ret[edge]++;
		ret[0]--;
		
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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