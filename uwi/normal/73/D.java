//package round66;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D2 {
	IntReader in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int k = ni();
		DisjointSet ds = new DisjointSet(n);
		for(int i = 0;i < m;i++){
			ds.union(ni()-1, ni()-1);
		}
		int[] count = new int[n];
		for(int i = 0;i < n;i++){
			count[ds.root(i)]++;
		}
		int con = 0;
		int cap = 2;
		for(int i = 0;i < n;i++){
			if(count[i] > 0){
				cap += Math.min(count[i], k)-2;
				con++;
			}
		}
		int r;
		if(k >= 2){
			r = cap < 0 ? (-cap+1)/2 : 0;
		}else if(k == 1){
			r = Math.max(con - 2, 0);
		}else{
			r = con - 1;
		}
		out.println(r);
//		out.println(Math.max(ds.count()-k-1,0));
	}
	
	public class DisjointSet {
		public int[] rank, upper;
		
		public DisjointSet(int n)
		{
			rank = new int[n];
			upper = new int[n];
			for(int i = 0;i < n;i++){
				upper[i] = i;
			}
		}
		
		int root(int x)
		{
			if(upper[x] != x)upper[x] = root(upper[x]);
			return upper[x];
		}
		
		boolean areInSameSet(int x, int y)
		{
			return root(x) == root(y);
		}
		
		public void union(int x, int y)
		{
			x = root(x);
			y = root(y);
			if(rank[x] > rank[y]){
				upper[y] = x;
			}else if(rank[x] < rank[y]){
				upper[x] = y;
			}else if(x != y){
				upper[y] = x;
				rank[x]++;
			}
		}
		
		public int count()
		{
			int ct = 0;
			for(int i = 0;i < upper.length;i++){
				if(root(i) == i)ct++;
			}
			return ct;
		}
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new IntReader(System.in) : new IntReader(new ByteArrayInputStream(INPUT.getBytes()));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D2().run();
	}
	
	public class IntReader {
		private InputStream is;
		
		public IntReader(InputStream is)
		{
			this.is = is;
		}
		
		public int nui()
		{
			try {
				int num = 0;
				while((num = is.read()) != -1 && (num < '0' || num > '9'));
				num -= '0';
				
				while(true){
					int b = is.read();
					if(b == -1)return num;
					if(b >= '0' && b <= '9'){
						num = num * 10 + (b - '0');
					}else{
						return num;
					}
				}
			} catch (IOException e) {
			}
			return -1;
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
					if(b == -1)return minus ? -num : num;
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
		
		public String nl()
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
	}
	
	int ni() { return in.ni(); }
	int nui() { return in.nui(); }
	String nl() { return in.nl(); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}