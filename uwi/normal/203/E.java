//package round128;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), d = ni();
		long s = ni();
		int[][] a = new int[n][];
		for(int i = 0;i < n;i++){
			a[i] = new int[]{ni(), ni(), ni()};
		}
		// c f l
		
		int[][] can = new int[n][];
		int[][] not = new int[n][];
		int cp = 0, np = 0;
		int ncan = 0;
		long zeroall = 0;
		for(int i = 0;i < n;i++){
			zeroall += a[i][0];
			if(a[i][0] > 0){
				ncan++;
				if(a[i][2] >= d){
					can[cp++] = a[i];
				}
			}else if(a[i][2] >= d){
				not[np++] = a[i];
			}
		}
		
		int maxnum = 0;
		long optfu = 0;
		Arrays.sort(a, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1] - b[1];
			}
		});
		{
			int num = 0;
			long fu = 0;
			for(int i = 0;i < n;i++){
				if(a[i][2] >= d && fu + a[i][1] <= s){
					num++;
					fu += a[i][1];
				}
			}
			maxnum = num;
			optfu = fu;
		}
		
		if(cp > 0){
			can = Arrays.copyOf(can, cp);
			not = Arrays.copyOf(not, np);
			Arrays.sort(can, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[1] - b[1];
				}
			});
			Arrays.sort(not, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[1] - b[1];
				}
			});
			long[] notsum = new long[np+1];
			for(int i = 0;i < np;i++){
				notsum[i+1] = notsum[i] + 2*not[i][1];
			}

			long fu = 0;
			for(int i = 0;i < cp;i++){
				fu += can[i][1];
				if(fu > s)break;
				long canride = zeroall - ncan + (i+1);
				long left = n-ncan-canride;
				int num;
				long v;
				if(left <= 0){
					num = n;
					v = fu;
				}else{
					int ind = Arrays.binarySearch(notsum, 2*(s-fu)+1);
					if(ind < 0)ind = -ind-2;
					num = ncan + (int)canride + (int)Math.min(ind, left);
					v = fu + notsum[ind]/2;
				}
				if(num > maxnum){
					maxnum = num;
					optfu = v;
				}else if(num == maxnum && v < optfu){
					optfu = v;
				}
			}
		}
		out.println(maxnum + " " + optfu);
	}
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new E3().run();
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
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}