//package round80;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class D3 {
	IntReader in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long y = System.currentTimeMillis();
		int n = ni();
		int[] w = new int[n];
		for(int i = 0;i < n;i++){
			w[i] = ni();
		}
		int P = ni();
		int[][] q = new int[P][3];
		for(int i = 0;i < P;i++){
			q[i][0] = ni()-1;
			q[i][1] = ni();
			q[i][2] = i;
		}
		tr(System.currentTimeMillis() - y + "ms");
		Arrays.sort(q, new Comparator<int[]>(){
			public int compare(int[] a, int[] b){
				if(a[1] - b[1] != 0)return a[1] - b[1];
				return a[0]%a[1] - b[0]%a[1];
			}
		});
		tr(System.currentTimeMillis() - y + "ms");
		
		long[] ret = new long[P];
		int prev = 0;
		long[] a = new long[n+1];
		for(int i = 0;i < P;i++){
			if(i == P-1 || q[i][1] != q[i+1][1] || (q[i][0] - q[i+1][0]) % q[i+1][1] != 0){
				if(i == prev) {
					long ls = 0;
					for(int j = q[i][0];j < n;j += q[i][1]){
						ls += w[j];
					}
					ret[q[i][2]] = ls;
				}else {
					int ap = 0;
					for(int j = q[i][0]%q[i][1];j < n;j += q[i][1]){
						a[ap++] = w[j];
					}
					for(int j = ap-2;j >= 0;j--){
						a[j] += a[j+1];
					}
					
					for(int j = prev;j <= i;j++){
						ret[q[j][2]] = a[q[j][0]/q[i][1]];
					}
				}
				
				prev = i+1;
			}
		}
//		tr(System.currentTimeMillis() - y + "ms");
		
		for(long l : ret){
			out.println(l);
		}
	}
	
	void run() throws Exception
	{
//		int n = 300000;
//		int p = 300000;
//		StringBuilder sb = new StringBuilder(n + " ");
//		Random r = new Random(1);
//		for(int i = 0;i < n;i++){
//			sb.append(r.nextInt(1000000000) + " ");
//		}
//		sb.append(p + " ");
//		int k = 0, l = 1;
//		for(int i = 0;i < p;i++){
//			sb.append((k+1) + " ");
//			sb.append(l + " ");
//			k++;
//			if(k == l) {
//				l++;
//				k = 0;
//			}
//		}
//		for(int i = 0;i < p;i++){
//			sb.append(r.nextInt(n)/5+1 + " ");
////			sb.append(r.nextInt(n)/1000+1 + " ");
//			sb.append(r.nextInt((int)Math.sqrt(n))+1 + " ");
//		}
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
		new D3().run();
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