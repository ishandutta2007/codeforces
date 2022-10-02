//package round77;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class EX {
	IntReader in;
	PrintWriter out;
	String INPUT = "10 1 1 10";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		DisjointSet ds = new DisjointSet(n);
		for(int i = 0;i < m;i++) {
			int u = ni() - 1;
			int v = ni() - 1;
			ds.union(u, v);
		}
		
		int[] ctb = new int[n+1];
		for(int i = 0;i < n;i++) {
			if(ds.upper[i] < 0) {
				ctb[-ds.upper[i]]++;
			}
		}
		
		int[] dp = new int[n+1];
		Arrays.fill(dp, 9999999);
		dp[0] = 0;
		for(int i = 1;i <= n;i++) {
			if(ctb[i] > 0) {
				for(int j = ctb[i], c = 1;j > 0;c<<=1) {
					int z = Math.min(j, c);
					j -= c;
					for(int k = n;k >= z*i;k--) {
						dp[k] = Math.min(dp[k], dp[k-z*i]+z);
					}
				}
			}
		}
		
		int[] ln = new int[80];
		ln[0] = 0;
		int lp = 1;
		int pv = 0;
		for(int d = 1;d <= 6;d++) {
			int pp = pv;
			pv = lp;
			for(int i = lp-1;i >= pp;i--) {
				for(int j = 4;j <= 7;j+=3) {
					int v = ln[i] * 10 + j;
					if(v <= n) {
						ln[lp++] = v;
					}
				}
			}
		}
		
		int gm = 9999999;
		for(int i = 1;i < lp;i++) {
			gm = Math.min(gm, dp[ln[i]]);
		}
		out.println(gm > 9000000 ? -1 : gm-1);
	}
	
	void run() throws Exception
	{
		in = oj ? new IntReader(System.in) : new IntReader(new ByteArrayInputStream(INPUT.getBytes()));
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new EX().run();
	}
	
	public class DisjointSet {
		public int[] upper; // minus:num_element(root) plus:root(normal)
		
		public DisjointSet(int n)
		{
			upper = new int[n];
			Arrays.fill(upper, -1);
		}
		
		public int root(int x)
		{
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}
		
		public boolean equiv(int x, int y)
		{
			return root(x) == root(y);
		}
		
		public void union(int x, int y)
		{
			x = root(x);
			y = root(y);
			if(x != y) {
				if(upper[y] < upper[x]) {
					int d = x; x = y; y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
		}
		
		public int count()
		{
			int ct = 0;
			for(int i = 0;i < upper.length;i++){
				if(upper[i] < 0)ct++;
			}
			return ct;
		}
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