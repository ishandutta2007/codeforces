//package round171;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		if(n <= 1){
			out.println(1);
			return;
		}
		
		int[][] com = new int[n][];
		for(int i = 0;i < n-1;i++){
			int[] row = new int[n];
			int p = 0;
			for(int j = 0;j <= i;j++){
				for(int k = j;k <= i;k++){
					if(a[j]+a[k] == a[i+1]){
						row[p++] = 1<<j|1<<k;
					}
				}
			}
			com[i] = Arrays.copyOf(row, p);
		}
		
		int[] dp = new int[1<<n-1];
		Arrays.fill(dp, 99999999);
		dp[1] = 1;
		int min = 99999999;
		for(int i = 1;i < 1<<n-1;i++){
			if(dp[i] == 99999999)continue;
			dp[i] = Math.max(dp[i], Integer.bitCount(i));
			int sup = 31-Integer.numberOfLeadingZeros(i);
			boolean ok = false;
			for(int row : com[sup]){
				if((i&row)==row){
					ok = true;
					break;
				}
			}
			if(ok){
				if(sup+1 == n-1){
					min = Math.min(min, dp[i]);
				}else{
					dp[i|1<<sup+1] = Math.min(dp[i|1<<sup+1], dp[i]);
					for(int l = 0;l <= sup;l++){
						if(i<<31-l<0){
							dp[(i|1<<sup+1)^1<<l] = Math.min(dp[(i|1<<sup+1)^1<<l], dp[i]);
						}
					}
				}
			}
//			for(int j = 0;j <= sup;j++){
//				if(i<<31-j<0){
//					for(int k = j;k <= sup;k++){
//						if(i<<31-k<0){
//							if(a[j]+a[k] == a[sup+1]){
////								tr(j,k,sup+1,a[j],a[k],a[sup+1], dp[i], i);
//								if(sup+1 == n-1){
//									min = Math.min(min, dp[i]);
//								}else{
//									dp[i|1<<sup+1] = Math.min(dp[i|1<<sup+1], dp[i]);
//									for(int l = 0;l <= sup;l++){
//										if(i<<31-l<0){
//											dp[(i|1<<sup+1)^1<<l] = Math.min(dp[(i|1<<sup+1)^1<<l], dp[i]);
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
		}
		if(min == 99999999){
			out.println(-1);
		}else{
			out.println(min);
		}
	}
	
	void run() throws Exception
	{
//		int n = 22, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		int[] f = new int[23];
//		f[0] = f[1] = 1;
//		for(int i = 2;i < 23;i++)f[i] = f[i-1] + f[i-2];
//		for(int i = 0;i < n;i++){
//			sb.append(f[i+1] + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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