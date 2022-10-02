//package manthan;


import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D {
	IntReader in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		int[] b = new int[n];
		int[] f = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		for(int i = 0;i < n;i++){
			b[ni()-1] = i;
		}
		for(int i = 0;i < n;i++){
			f[i] = b[a[i]-1]+1;
		}
		tr(f);
		
		int ret = 0;
		int[] h = new int[n + 1];
		for(int i = 0;i < n;i++){
			int ind = Arrays.binarySearch(h, 0, ret + 1, -f[i]);
			if(ind < 0){
				ind = -ind-2;
				h[ind+1] = -f[i];
				if(ind >= ret)ret++;
			}
		}
		
		out.println(ret+1);
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