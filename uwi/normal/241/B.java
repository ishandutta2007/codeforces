//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class BayanB2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int D = 30;
		int n = ni(), m = ni();
		int[] a = na(n);
		Arrays.sort(a);
		
		for(int i = 0;i < n;i++){
			a[i] *= 2;
		}
		int mod = 1000000007;
		
		int[][] window = new int[n][];
		for(int i = 0;i < n;i++){
			window[i] = new int[]{i+1, n, -1};
		}
		
		int[][] one = new int[n+1][D+1];
		for(int d = D;d >= 1;d--){
			for(int i = 0;i < n;i++){
				one[i+1][d] = one[i][d] + (a[i]>>>d&1);
			}
		}
		
		int base = 0;
		long sum = 0;
		for(int d = D;d >= 1;d--){
			int count = 0;
			for(int i = 0;i < n;i++){
				int ind = -Arrays.binarySearch(a, window[i][0], window[i][1], (base^(a[i]>>>d+1<<d+1))|(1<<d)-1)-1;
				window[i][2] = ind;
				// a[i]d1
				if(a[i]<<31-d>=0){
					count += window[i][1]-ind;
				}else{
					count += ind-window[i][0];
				}
//				tr(window[i]);
			}
//			tr("count", d, base, count, m, sum);
			if(count > m){
				// 1 (1)
				for(int i = 0;i < n;i++){
					if(a[i]<<31-d>=0){
						window[i][0] = window[i][2];
					}else{
						window[i][1] = window[i][2];
					}
				}
				base |= 1<<d;
			}else{
				// 0 (1)
				m -= count;
				
				// 1
				for(int i = 0;i < n;i++){
					if(a[i]<<31-d>=0){
						for(int j = D;j >= 1;j--){
							if(a[i]<<31-j>=0){
								sum += ((long)one[window[i][1]][j]-one[window[i][2]][j]<<j-1)%mod;
							}else{
								sum += ((long)window[i][1]-window[i][2]-one[window[i][1]][j]+one[window[i][2]][j]<<j-1)%mod;
							}
						}
					}else{
						for(int j = D;j >= 1;j--){
							if(a[i]<<31-j>=0){
								sum += ((long)one[window[i][2]][j]-one[window[i][0]][j]<<j-1)%mod;
							}else{
								sum += ((long)window[i][2]-window[i][0]-one[window[i][2]][j]+one[window[i][0]][j]<<j-1)%mod;
							}
						}
					}
				}
				
				for(int i = 0;i < n;i++){
					if(a[i]<<31-d>=0){
						window[i][1] = window[i][2];
					}else{
						window[i][0] = window[i][2];
					}
				}
			}
		}
		sum += m * (base / 2) % mod;
		out.println(sum % mod);
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
	
	public static void main(String[] args) throws Exception { new BayanB2().run(); }
	
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