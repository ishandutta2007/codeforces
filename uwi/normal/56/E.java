//package round52;


import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class E3 {
	IntReader in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		final int[] x = new int[n];
		int[] h = new int[n];
		for(int i = 0;i < n;i++){
			x[i] = ni();
			h[i] = ni();
		}
		
		Integer[] ord = new Integer[n];
		for(int i = 0;i < n;i++)ord[i] = i;
		Comparator<Integer> comp = new Comparator<Integer>() {
			public int compare(Integer a, Integer b) {
				return x[a] - x[b];
			}
		};
		Arrays.sort(ord, comp);
		
		int[] ef = new int[n];
		for(int i = 0;i < n;i++){
			int inf = i;
			int sup = n;
			while(sup - inf > 1){
				int mid = (inf+sup)/2;
				if(x[ord[mid]] <= x[ord[i]] + h[ord[i]] - 1){
					inf = mid;
				}else{
					sup = mid;
				}
			}
			ef[i] = inf;
		}
		
		int[] iord = new int[n];
		for(int i = 0;i < n;i++){
			iord[ord[i]] = i;
		}
		
		int[] efx = new int[n];
		for(int i = n - 1;i >= 0;i--){
			int max = ef[i];
//			for(int j = i + 1;j <= ef[i];j++){
//				max = Math.max(max, efx[ord[j]]);
//			}
			for(int j = i + 1;j <= max && j < n;j++){
				max = Math.max(max, efx[ord[j]]);
				j = efx[ord[j]];
			}
			efx[ord[i]] = max;
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < n;i++){
			sb.append(efx[i]-iord[i]+1);
			sb.append(" ");
		}
		out.println(sb);
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
		new E3().run();
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