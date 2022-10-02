//package round67;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D {
	IntReader in;
	PrintWriter out;
//	String INPUT = "1 2 5 9 5 -15 5 7 1 1";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int[][] p = new int[n][];
		for(int i = 0;i < n;i++){
			int l = ni();
			p[i] = new int[l];
			for(int j = 0;j < l;j++){
				p[i][j] = ni();
			}
		}
		
		int[] s = new int[m];
		boolean[] aped = new boolean[n];
		for(int i = 0;i < m;i++){
			s[i] = ni() - 1;
			aped[s[i]] = true;
		}
		
		int[] left = new int[n];
		int[] right = new int[n];
		int[] all = new int[n];
		boolean[] lp = new boolean[n];
		boolean[] rp = new boolean[n];
		long gmax = Long.MIN_VALUE;
		for(int i = 0;i < n;i++){
			if(aped[i]){
				int[] lsum = new int[p[i].length+1];
				{
					int max = Integer.MIN_VALUE;
					int sum = 0;
					for(int j = 0;j < p[i].length;j++){
						sum += p[i][j];
						max = Math.max(max, sum);
						lsum[j+1] = sum;
					}
					if(max == Integer.MIN_VALUE){
						lp[i] = false;
						left[i] = 0;
					}else{
						lp[i] = true;
						left[i] = max;
					}
				}
				{
					int max = Integer.MIN_VALUE;
					int sum = 0;
					for(int j = p[i].length-1;j >= 0;j--){
						sum += p[i][j];
						max = Math.max(max, sum);
					}
					if(max == Integer.MIN_VALUE){
						rp[i] = false;
						right[i] = 0;
					}else{
						rp[i] = true;
						right[i] = max;
					}
				}
				
				int smax = -99999999;
				int lsummin = 0;
				for(int j = 1;j <= p[i].length;j++){
					smax = Math.max(smax, lsum[j] - lsummin);
					if(lsum[j] < lsummin)lsummin = lsum[j];
				}
				gmax = Math.max(gmax, smax);
				all[i] = lsum[p[i].length];
			}
		}
		
		long[] lsummr = new long[m+1];
		long[] llsum = new long[m+1];
		for(int i = 0;i < m;i++){
			llsum[i+1] = llsum[i] + all[s[i]];
			lsummr[i+1] = llsum[i+1] - right[s[i]];
		}
//		tr(left);
//		tr(right);
//		tr(all);
//		tr(llsum);
//		tr(lsummr);
//		tr(gmax);
		
		long lsummrmin = 0;
		for(int i = 1;i < m;i++){
			gmax = Math.max(gmax, (i == m ? 0 : left[s[i]]) + llsum[i] - lsummrmin);
//			tr(i, lsummrmin);
			if(lsummr[i] < lsummrmin)lsummrmin = lsummr[i];
		}
		for(int i = 0;i < m-1;i++){
//			tr(lp[s[i]], rp[s[i+1]]);
			if(lp[s[i]] && rp[s[i+1]]){
				gmax = Math.max(gmax, right[s[i]] + left[s[i+1]]);
			}
		}
		out.println(gmax);
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