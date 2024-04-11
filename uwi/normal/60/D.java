//package round56;


import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;

public class D {
	IntReader in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		Arrays.sort(a);
		
		DisjointSet ds = new DisjointSet(n);
		int[] seg = new int[10000];
		seg[0] = 0;
		seg[1] = 1;
		seg[2] = 1;
		seg[3] = 1;
		int p = 4;
		while(p >= 4){
			int mn = seg[p-4] + seg[p-2];
			int md = seg[p-3] + seg[p-1];
			if(2*mn*md <= 10000000 && md*md-mn*mn <= 10000000){
				if(((mn^md)&1)==1){
					int x = md*md-mn*mn;
					int y = 2*md*mn;
					int z = md*md+mn*mn;
					int ix = Arrays.binarySearch(a, x);
					int iy = Arrays.binarySearch(a, y);
					int iz = Arrays.binarySearch(a, z);
					if(ix >= 0 && iy >= 0){
						ds.union(ix, iy);
					}
					if(iy >= 0 && iz >= 0){
						ds.union(iy, iz);
					}
					if(iz >= 0 && ix >= 0){
						ds.union(iz, ix);
					}
				}
				seg[p] = seg[p-2];
				seg[p+1] = seg[p-1];
				seg[p-2] = mn;
				seg[p-1] = md;
				p += 2;
			}else{
				p -= 2;
			}
		}
		
		BitSet bs = new BitSet();
		for(int i = 0;i < n;i++){
			bs.set(ds.root(i));
		}
		out.println(bs.cardinality());
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
		
	}
	
	void run() throws Exception
	{
//		int n = 1000000;
//		StringBuilder sb = new StringBuilder(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append((10000000-i) + " ");
//		}
//		INPUT = sb.toString();
//
		in = INPUT.isEmpty() ? new IntReader(System.in) : new IntReader(new ByteArrayInputStream(INPUT.getBytes()));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
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