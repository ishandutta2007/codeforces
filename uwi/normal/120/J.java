import java.io.ByteArrayInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class J {
	InputStream is;
	PrintWriter out;
	String INPUT = "5\r\n" + 
			"-3 -8\r\n" + 
			"-9 10\r\n" + 
			"-9 0\r\n" + 
			"-9 -2\r\n" + 
			"-6 5";
	
	void solve()
	{
		int n = ni();
		int[][] co = new int[n][4];
		for(int i = 0;i < n;i++) {
			co[i][0] = ni();
			co[i][1] = ni();
			co[i][2] = i+1;
			if(co[i][0] >= 0) {
				if(co[i][1] >= 0) {
					co[i][3] = 1;
				}else {
					co[i][3] = 3;
				}
			}else {
				if(co[i][1] >= 0) {
					co[i][3] = 2;
				}else {
					co[i][3] = 4;
				}
			}
			co[i][0] = Math.abs(co[i][0]);
			co[i][1] = Math.abs(co[i][1]);
		}
		
		Arrays.sort(co, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		
		mind = 10000*10000*20;
		mins = (int)Math.sqrt(mind);
		dac(co, 0, n-1);
		out.println(co[min1][2] + " " + (5-co[min1][3]) + " " + co[min2][2] + " " + co[min2][3]);
	}
	
	int mind;
	int mins;
	int min1;
	int min2;
	int[] alive = new int[10001];
	
	void dac(int[][] co, int low, int high) // 0:dist,1,2:pair
	{
		if(low >= high)return;
		
		int mid = (low+high)/2;
		dac(co, low, (low+high)/2);
		dac(co, (low+high)/2+1, high);
		Arrays.fill(alive, -1);
		for(int i = mid+1;i <= high && co[i][0] <= co[mid][0] + mins;i++) {
			if(alive[co[i][1]] == -1) {
				alive[co[i][1]] = i;
			}
		}
		for(int i = mid;i >= low && co[i][0] >= co[mid][0] - mins;i--) {
			int inf = Math.max(co[i][1] - mins, 0);
			int sup = Math.min(co[i][1] + mins, 10000);
			for(int j = inf;j <= sup;j++) {
				if(alive[j] >= 0) {
					int D = (co[i][0]-co[alive[j]][0])*(co[i][0]-co[alive[j]][0])+(co[i][1]-co[alive[j]][1])*(co[i][1]-co[alive[j]][1]);
					if(D < mind) {
						mind = D;
						mins = (int)Math.sqrt(mind);
						min1 = i;
						min2 = alive[j];
					}
				}
			}
		}
	}
	
	void run() throws Exception
	{
//		StringBuilder sb = new StringBuilder(100000 + " ");
//		Random gen = new Random();
//		for(int i = 0;i < 100000;i++) {
//			sb.append(gen.nextInt(20000)-10000 + " ");
//			sb.append(gen.nextInt(20000)-10000 + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? new FileInputStream("input.txt") : new ByteArrayInputStream(INPUT.getBytes());
		out = oj ? new PrintWriter("output.txt") : new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new J().run();
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
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}