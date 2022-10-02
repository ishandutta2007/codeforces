//package round90re;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		long[][] dd = new long[m][];
		for(int i = 0;i < m;i++){
			dd[i] = new long[]{nl(), nl(), ni(), i+1};
		}
		Arrays.sort(dd, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				return -Long.signum(a[2] - b[2]);
			}
		});
		
		long[] a = new long[m];
		long[] b = new long[m];
		int[] c = new int[m];
		for(int i = 0;i < m;i++){
			a[i] = dd[i][0];
			b[i] = dd[i][1];
			c[i] = (int)dd[i][2];
		}
		
		long[][][] dp = new long[m][n+1][101]; // total [day][subday][range]
		int[][][][] prev = new int[m][n+1][101][];
		long I = Long.MIN_VALUE / 10;
		for(int i = 0;i < m;i++){
			for(int j = 0;j <= n;j++){
				Arrays.fill(dp[i][j], I);
			}
		}
		for(int i = 0;i < m;i++){
			for(int L = 0;L <= b[i]-a[i];L++){
				dp[i][1][L] = a[i]+L;
			}
			for(int j = 2;j <= n;j++){
				for(int L = 0;L <= b[i]-a[i];L++){
					long v = a[i]+L;
					for(int q = 0;q < i;q++){
						if(c[q] > c[i]){
							{
								long pre = (a[i]+L)*K;
								if(a[q] <= pre && pre <= b[q] && dp[q][j-1][(int)(pre-a[q])] >= 0){
									long nex = dp[q][j-1][(int)(pre-a[q])] + v;
									if(nex > dp[i][j][L]){
										dp[i][j][L] = nex;
										prev[i][j][L] = new int[]{q, (int)(pre-a[q])};
									}
								}
							}
							{
								long pre = (a[i]+L)+K;
								if(a[q] <= pre && pre <= b[q] && dp[q][j-1][(int)(pre-a[q])] >= 0){
									long nex = dp[q][j-1][(int)(pre-a[q])] + v;
									if(nex > dp[i][j][L]){
										dp[i][j][L] = nex;
										prev[i][j][L] = new int[]{q, (int)(pre-a[q])};
									}
								}
							}
						}
					}
				}
			}
		}
		
		long max = -1;
		int maxi = -1;
		int maxl = -1;
		for(int i = 0;i < m;i++){
			for(int L = 0;L <= b[i]-a[i];L++){
				if(dp[i][n][L] > max){
					max = dp[i][n][L];
					maxi = i;
					maxl = L;
				}
			}
		}
		if(maxi == -1){
			out.println("NO");
		}else{
			out.println("YES");
			int i = maxi, L = maxl;
			while(true){
				out.println(dd[i][3] + " " + (a[i]+L));
				int[] pr = prev[i][n][L];
				if(pr == null)break;
				i = pr[0]; n--; L = pr[1];
			}
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
	
	public static void main(String[] args) throws Exception { new C2().run(); }
	
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