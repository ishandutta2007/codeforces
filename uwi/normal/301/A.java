//package round182;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class A2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(2*n-1);
		if(n % 2 == 1){
			long sum = 0;
			for(int v : a){
				sum += Math.abs(v);
			}
			out.println(sum);
		}else{
			int[][] dp = new int[2*n][2*n];
			for(int i = 0;i < 2*n;i++){
				Arrays.fill(dp[i], Integer.MIN_VALUE / 100);
			}
			dp[0][0] = 0;
			for(int i = 0;i < 2*n-1;i++){
				for(int j = 0;j <= i;j++){
					dp[i+1][j] = Math.max(dp[i+1][j], dp[i][j] + a[i]);
					dp[i+1][j+1] = Math.max(dp[i+1][j+1], dp[i][j] - a[i]);
				}
			}
			int max = Integer.MIN_VALUE/100;
			for(int j = 0;j <= 2*n-1;j+=2){
				max = Math.max(max, dp[2*n-1][j]);
			}
			out.println(max);
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
	
	public static void main(String[] args) throws Exception { new A2().run(); }
	
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}