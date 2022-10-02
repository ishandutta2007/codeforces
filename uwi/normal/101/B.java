//package round79;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class B2 {
	IntReader in;
	PrintWriter out;
//	String INPUT = "5 4 0 3 0 3 3 5 3 5";
	String INPUT = "5 5 0 5 0 3 0 1 0 4 0 2";
//	String INPUT = "1 0";
	
	int mod = 1000000007;
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int[][] r = new int[m][2];
		for(int i = 0;i < m;i++){
			r[i][0] = ni();
			r[i][1] = ni();
		}
		Arrays.sort(r, new Comparator<int[]>(){
			public int compare(int[] a, int[] b)
			{
				if(a[1] - b[1] != 0)return a[1] - b[1];
				return a[0] - b[0];
			}
		});
		
		int[] c = new int[2*m];
		for(int i = 0;i < m;i++){
			c[2*i] = r[i][0];
			c[2*i+1] = r[i][1];
		}
		
		int[] sh = shrink(c);
		
		int[] dp = new int[m];
		long last = 0;
		long[] cum = new long[2*m+1];
		for(int i = 0;i < m;i++){
			long v = 0;
			if(r[i][0] == 0)v++;
			
			v += cum[sh[2*i+1]] - cum[sh[2*i]];
			v = (v + mod) % mod;
			dp[i] = (int)v;
			cum[sh[2*i+1]+1] += dp[i];
			if(i < m-1){
				for(int j = sh[2*i+1]+1;j < sh[2*(i+1)+1]+1;j++){
					cum[j+1] = cum[j];
				}
			}
			if(r[i][1] == n){
				last += dp[i];
			}
		}
		out.println(last % mod);
	}
	
	public static int[] shrink(int[] a)
	{
		int n = a.length;
		long[] b = new long[n];
		for(int i = 0;i < n;i++)b[i] = (long)a[i]<<32|i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i>0 && (b[i]^b[i-1])>>32!=0)p++;
			ret[(int)b[i]] = p;
		}
		return ret;
	}
	
	void run() throws Exception
	{
//		int n = 100000;
//		StringBuilder sb = new StringBuilder(1000000000 + " " + 100000 + " ");
//		Random r = new Random();
//		for(int i = 0;i < n-2;i++){
//			int a = r.nextInt(500000000);
//			int b = r.nextInt(500000000)+500000000;
//			sb.append(a + " " + b + " ");
//		}
//		sb.append(0 + " " + 500000000 + " ");
//		sb.append(500000001 + " " + 1000000000 + " ");
//		INPUT = sb.toString();
		in = oj ? new IntReader(System.in) : new IntReader(new ByteArrayInputStream(INPUT.getBytes()));
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new B2().run();
	}
	
	public class IntReader {
		private InputStream is;
		
		public IntReader(InputStream is)
		{
			this.is = is;
		}
		
		public int ni()
		{
			try {
				int num = 0;
				boolean minus = false;
				while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
				if(num == '-'){
					num = 0;
					minus = true;
				}else{
					num -= '0';
				}
				
				while(true){
					int b = is.read();
					if(b >= '0' && b <= '9'){
						num = num * 10 + (b - '0');
					}else{
						return minus ? -num : num;
					}
				}
			} catch (IOException e) {
			}
			return -1;
		}
		
		public long nl()
		{
			try {
				long num = 0;
				boolean minus = false;
				while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
				if(num == '-'){
					num = 0;
					minus = true;
				}else{
					num -= '0';
				}
				
				while(true){
					int b = is.read();
					if(b >= '0' && b <= '9'){
						num = num * 10 + (b - '0');
					}else{
						return minus ? -num : num;
					}
				}
			} catch (IOException e) {
			}
			return -1;
		}
		
		public String nline()
		{
			try{
				int b = 0;
				StringBuilder sb = new StringBuilder();
				while((b = is.read()) != -1 && (b == '\r' || b == '\n'));
				if(b == -1)return "";
				sb.append((char)b);
				while(true){
					b = is.read();
					if(b == -1)return sb.toString();
					if(b == '\r' || b == '\n')return sb.toString();
					sb.append((char)b);
				}
			} catch (IOException e) {
			}
			return "";
		}
		
		public String ns()
		{
			try{
				int b = 0;
				StringBuilder sb = new StringBuilder();
				while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
				if(b == -1)return "";
				sb.append((char)b);
				while(true){
					b = is.read();
					if(b == -1)return sb.toString();
					if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
					sb.append((char)b);
				}
			} catch (IOException e) {
			}
			return "";
		}
	}
	
	int ni() { return in.ni(); }
	long nl() { return in.nl(); }
	String nline() { return in.nline(); }
	String ns() { return in.ns(); }
	double nd() { return Double.parseDouble(in.ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}