//package round565;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long[] dp = new long[10];
		Arrays.fill(dp, Long.MIN_VALUE /10);
		dp[0] = 0;
		for(int i = 0;i < n;i++){
			int K = ni();
			RankingSimple[] rs = new RankingSimple[4];;
			for(int j = 1;j <= 3;j++){
				rs[j] = new RankingSimple(4-j);
			}
			for(int j = 0;j < K;j++){
				int c = ni();
				int d = ni();
				rs[c].query(-d);
			}
			long[] dmg = new long[4];
			Arrays.fill(dmg, Long.MIN_VALUE / 10);
			dmg[3] = Math.max(dmg[3], -(rs[1].min[0] + rs[1].min[1] + rs[1].min[2]));
			dmg[2] = Math.max(dmg[2], -(rs[1].min[0] + rs[1].min[1]));
			dmg[2] = Math.max(dmg[2], -(rs[1].min[0] + rs[2].min[0]));
			dmg[1] = Math.max(dmg[1], -(rs[1].min[0]));
			dmg[1] = Math.max(dmg[1], -(rs[2].min[0]));
			dmg[1] = Math.max(dmg[1], -(rs[3].min[0]));
			dmg[0] = 0;
			
			long[] xdmg = new long[4];
			Arrays.fill(xdmg, Long.MIN_VALUE / 10);
			xdmg[3] = Math.max(xdmg[3], -(2*rs[1].min[0] + rs[1].min[1] + rs[1].min[2]));
			xdmg[2] = Math.max(xdmg[2], -(2*rs[1].min[0] + rs[1].min[1]));
			xdmg[2] = Math.max(xdmg[2], -(rs[1].min[0] + 2*rs[2].min[0]));
			xdmg[2] = Math.max(xdmg[2], -(2*rs[1].min[0] + rs[2].min[0]));
			xdmg[1] = Math.max(xdmg[1], 2*-(rs[1].min[0]));
			xdmg[1] = Math.max(xdmg[1], 2*-(rs[2].min[0]));
			xdmg[1] = Math.max(xdmg[1], 2*-(rs[3].min[0]));
			
			long[] ndp = new long[10];
			Arrays.fill(ndp, Long.MIN_VALUE /10);
			for(int j = 0;j < 10;j++){
				for(int k = 0;k <= 3;k++){
					if(j+k >= 10){
						ndp[(j+k)%10] = Math.max(ndp[(j+k)%10], dp[j] + xdmg[k]);
					}else{
						ndp[(j+k)%10] = Math.max(ndp[(j+k)%10], dp[j] + dmg[k]);
					}
				}
			}
			dp = ndp;
		}
		long ans = 0;
		for(long v : dp){
			ans = Math.max(ans, v);
		}
		out.println(ans);
	}
	
	public static class RankingSimple {
		public long[] min;
		public int K;
		
		public RankingSimple(int K)
		{
			this.K = K;
			min = new long[K];
			Arrays.fill(min, Long.MAX_VALUE/4);
		}
		
		public void query(long v)
		{
			if(v >= min[K-1])return;
			for(int i = 0;i < K;i++){
				if(v < min[i]){
					for(int j = K-2;j >= i;j--){
						min[j+1] = min[j];
					}
					min[i] = v;
					break;
				}
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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