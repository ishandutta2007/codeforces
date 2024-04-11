//package round136;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		int[][] q = new int[m][];
		for(int i = 0;i < m;i++){
			q[i] = new int[]{ni()-1, ni()-1, i};
		}
		final int sq = (int)Math.sqrt(n);
		Arrays.sort(q, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] / sq == b[0] / sq){
					return a[1] - b[1];
				}else{
					return a[0] - b[0];
				}
			}
		});
		
		int s = 0, t = -1;
		int[] ct = new int[100001];
		int cct = 0;
		int[] ret = new int[m];
		for(int i = 0;i < m;i++){
			while(t < q[i][1]){
				t++;
				if(a[t] <= 100000){
					ct[a[t]]++;
					if(ct[a[t]] == a[t])cct++;
					if(ct[a[t]] == a[t]+1)cct--;
				}
			}
			while(s > q[i][0]){
				s--;
				if(a[s] <= 100000){
					ct[a[s]]++;
					if(ct[a[s]] == a[s])cct++;
					if(ct[a[s]] == a[s]+1)cct--;
				}
			}
			while(t > q[i][1]){
				if(a[t] <= 100000){
					ct[a[t]]--;
					if(ct[a[t]] == a[t])cct++;
					if(ct[a[t]] == a[t]-1)cct--;
				}
				t--;
			}
			while(s < q[i][0]){
				if(a[s] <= 100000){
					ct[a[s]]--;
					if(ct[a[s]] == a[s])cct++;
					if(ct[a[s]] == a[s]-1)cct--;
				}
				s++;
			}
			
			ret[q[i][2]] = cct;
		}
		
		for(int i = 0;i < m;i++){
			out.println(ret[i]);
		}
	}
	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " " + m + " " );
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(10000)+1 + " ");
//		}
//		for(int i = 0;i < m;i++){
//			int a = gen.nextInt(n)+1;
//			int b = gen.nextInt(n)+1;
//			if(a > b){
//				int d = a; a = b; b = d;
//			}
//			sb.append(a + " " + b + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
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