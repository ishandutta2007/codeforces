//package round72;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class Div2C {
	IntReader in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] c = new int[n];
		int[] r = new int[n];
		for(int i = 0;i < n;i++) {
			c[i] = ni();
			r[i] = ni();
		}
		int[] ord = pairSort2(c);
		
		int nh = 0;
		int[] hed = new int[n];
		Arrays.fill(hed, -1);
		int m = ni();
		for(int i = 0;i < m;i++) {
			int x = ni();
			int y = ni();
			
			int inf = 0;
			int sup = n;
			while(sup - inf > 1) {
				int mid = (inf+sup)/2;
				if(x < c[ord[mid]]) {
					sup = mid;
				}else {
					inf = mid;
				}
			}
			
			for(int j = inf;j <= sup;j++) {
				if(j >= 0 && j < n) {
					long dx = c[ord[j]]-x;
					long dy = y;
					if(dx*dx+dy*dy <= (long)r[ord[j]]*r[ord[j]] && hed[ord[j]] == -1) {
						hed[ord[j]] = i + 1;
						nh++;
					}
				}
			}
		}
		out.println(nh);
		for(int i = 0;i < n;i++) {
			out.print(hed[i] + " ");
		}
		out.println();
	}
	
	public static int[] pairSort2(int[] a)
	{
		int n = a.length;
		long[] ind = new long[n];
		for(int i = 0;i < n;i++)ind[i] = (long)a[i]<<32 | i;
		Arrays.sort(ind);
		int[] ret = new int[n];
		for(int i = 0;i < n;i++)ret[i] = (int)ind[i];
		return ret;
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
		new Div2C().run();
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}