//package round167;
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
	
	int[][] BURIED = {
			{0, 2},
			{1, 1},
			{2, 1},
			{1, 2},
			{2, 2},
			{0, 4},
			{1, 2},
			{2, 4},
			{0, 8},
			{1, 12},
			{2, 1},
			{0, 17},
			{2, 1},
			{1, 23},
			{2, 4},
			{0, 35},
			{2, 1},
			{1, 53},
			{2, 5},
			{0, 76},
			{2, 5},
			{1, 103},
			{2, 19},
			{0, 155},
			{2, 7},
			{1, 236},
			{2, 25},
			{0, 341},
			{2, 23},
			{1, 463},
			{2, 86},
			{0, 697},
			{2, 32},
			{1, 1060},
			{2, 115},
			{0, 1532},
			{2, 106},
			{1, 2081},
			{2, 389},
			{0, 3136},
			{2, 145},
			{1, 4769},
			{2, 518},
			{0, 6892},
			{2, 479},
			{1, 9364},
			{2, 1751},
			{0, 14110},
			{2, 655},
			{1, 21458},
			{2, 2333},
			{0, 31012},
			{2, 2158},
			{1, 42137},
			{2, 7880},
			{0, 63493},
			{2, 2950},
			{1, 96560},
			{2, 10499},
			{0, 139552},
			{2, 9713},
			{1, 189616},
			{2, 35461},
			{0, 285716},
			{2, 13277},
			{1, 434518},
			{2, 47248},
			{0, 627983},
			{2, 43709},
			{1, 853270},
			{2, 159577},
			{0, 1285721},
			{2, 59747},
			{1, 1955329},
			{2, 212618},
			{0, 2825923},
			{2, 196691},
			{1, 3839713},
			{2, 718099},
			{0, 5785742},
			{2, 268864},
			{1, 8798978},
			{2, 956783},
			{0, 12716653},
			{2, 885110},
			{1, 17278708},
			{2, 3231446},
			{0, 26035837},
			{2, 1209890},
			{1, 39595399},
			{2, 4305526},
			{0, 57224936},
			{2, 3982997},
			{1, 77754184},
			{2, 14541509},
			{0, 117161266},
			{2, 5444506},
			{1, 178179293},
			{2, 19374869},
			{0, 257512210},
			{2, 17923489},
			{1, 115568306}
	};
	
	void solve()
	{
		int n = ni();
		long p = ni();
		int mod = 1000000007;
		long[] ct = new long[3];
		long pp = p;
		for(int[] b : BURIED){
			ct[b[0]] += pp*(pp-1)/2;
			pp -= b[1];
			if(pp <= 0)break;
			ct[b[0]] -= pp*(pp-1)/2;
		}
		for(int i = 0;i < 3;i++){
			ct[i] %= mod;
		}
		
		long[][] dp = new long[n+1][4];
		dp[0][0] = 1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < 4;j++){
				for(int k = 0;k < 3;k++){
					dp[i+1][j^k] += dp[i][j]*ct[k]%mod;
				}
			}
			for(int j = 0;j < 4;j++){
				dp[i+1][j] %= mod;
			}
		}
		out.println((dp[n][1]+dp[n][2]+dp[n][3])%mod);
	}
	
	public static long invl(long a, long mod)
	{
		long b = mod;
		long p = 1, q = 0;
		while(b > 0){
			long c = a / b;
			long d;
			d = a; a = b; b = d % b;
			d = p; p = q; q = d - c * q;
		}
		return p < 0 ? p + mod : p;
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}