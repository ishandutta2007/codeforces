//package round170;
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
		int n = ni(), t = ni();
		int[][] q = new int[n][]; // [ss, sl, ts, tl, suc]
		for(int i = 0;i < n;i++){
			q[i] = new int[]{ni(), ni(), ni(), ni(), 1000000-(int)((nd()+1E-7)*1000000)};
		}
		Arrays.sort(q, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				long ta = a[3], sa = a[4];
				long tb = b[3], sb = b[4];
				return Long.signum((ta*sb-tb*sa)*1000000+sa*sb*(tb-ta));
			}
		});
		
		long[] dp = new long[t+1]; // score
		double[] ep = new double[t+1]; // penalty large
		double[] bp = new double[t+1]; // penalty large
		Arrays.fill(dp, Long.MIN_VALUE + 3);
		dp[0] = 0;
		for(int i = 0;i < n;i++){
			for(int j = t;j >= 0;j--){
				if(dp[j] == -1)continue;
				if(j+q[i][2] <= t){
					// small only
					long ndp = dp[j] + q[i][0]*1000000L;
					double nbp = bp[j] + q[i][2];
					double nep = ep[j] + q[i][2];
					int nind = j+q[i][2];
					if(ndp > dp[nind] || (ndp == dp[nind] && nep < ep[nind])){
						dp[nind] = ndp;
						bp[nind] = nbp;
						ep[nind] = nep;
					}
				}
				if(j+q[i][2]+q[i][3] <= t){
					// small large
					long ndp = dp[j] + q[i][0]*1000000L + q[i][1]*(long)q[i][4];
					double nbp = bp[j] + q[i][2] + q[i][3];
					double nep = (ep[j] + q[i][2]) * (1-(double)q[i][4] / 1000000) + (bp[j] + q[i][2] + q[i][3]) * ((double)q[i][4] / 1000000);
					int nind = j+q[i][2]+q[i][3];
					if(ndp > dp[nind] || (ndp == dp[nind] && nep < ep[nind])){
						dp[nind] = ndp;
						bp[nind] = nbp;
						ep[nind] = nep;
					}
				}
			}
		}
		
		long maxdp = 0L;
		double minep = 0;
		for(int j = t;j >= 0;j--){
			if(dp[j] > maxdp || dp[j] == maxdp && ep[j] < minep){
				maxdp = dp[j];
				minep = ep[j];
			}
		}
		out.printf("%.10f %.10f\n", (double)maxdp / 1000000, minep);
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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