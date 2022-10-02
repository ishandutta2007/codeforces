//package round75;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class C {
	int MOD = 1000000009;
	IntReader in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		DisjointSet ds = new DisjointSet(n);
		int p = 1;
		for(int i = 0;i < m;i++){
			int a = ni() - 1;
			int b = ni() - 1;
			if(ds.equiv(a, b)){
				p = p*2%MOD;
			}
			ds.union(a,b);
			out.println((p+MOD-1)%MOD);
		}
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
		new C().run();
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