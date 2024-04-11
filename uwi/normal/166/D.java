//package round113;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class D2 {
	InputStream is;
	PrintWriter out;
//	String INPUT = "3 3 1 9 3 6 5 3 7 1 8 5 9 2 ";
//	String INPUT = "4 1 1 8 2 8 4 5 5 4 4 1 5 4 9 4 4 1";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] sh = new int[n][3]; // shoes
		for(int i = 0;i < n;i++){
			sh[i][0] = ni(); // cost
			sh[i][1] = ni(); // size
			sh[i][2] = i;
		}
		
		int m = ni();
		int[][] cu = new int[m][3]; // customer
		for(int i = 0;i < m;i++){
			cu[i][0] = ni(); // money
			cu[i][1] = ni(); // size
			cu[i][2] = i;
		}
		
		Arrays.sort(sh, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1] - b[1];
			}
		});
		Arrays.sort(cu, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[1] != b[1])return a[1] - b[1];
				return -(a[0] - b[0]);
			}
		});
		
		int[][] ca = new int[m][3];
		int curs = -1;
		int cur = -1;
		int[] cap = new int[m];
//		tr(cu);
		for(int i = 0;i < m;i++){
			if(cu[i][1] != curs){
				curs = cu[i][1];
				cur++;
				ca[cur][0] = curs;
			}
			if(cap[cur] < 2){
				ca[cur][1+cap[cur]++] = i;
			}
		}
		ca = Arrays.copyOf(ca, cur+1);
//		tr(ca);
//		tr(cap);
		
		long[][] dp = new long[n+1][2]; // top is used or unused
		int[][] buyer = new int[n+1][2];
		for(int i = 0;i <= n;i++){
			dp[i][0] = Long.MIN_VALUE/2;
			dp[i][1] = Long.MIN_VALUE/2;
			buyer[i][0] = -1;
			buyer[i][1] = -1;
		}
		dp[0][1] = Long.MIN_VALUE/2;
		dp[0][0] = 0;
		int q = 0;
		int preq = -1;
		for(int i = 1;i <= n;i++){
			while(q < ca.length && ca[q][0] < sh[i-1][1])q++;
			boolean excur = q < ca.length && ca[q][0] == sh[i-1][1];
			boolean exprev = q-1 >= 0 && ca[q-1][0] == sh[i-1][1]-1;
			boolean neip = preq >= 0 && exprev && ca[preq][0] == ca[q-1][0];
//			tr(i, neip, exprev, excur);
			long o = Math.max(dp[i-1][0], dp[i-1][1]);
			dp[i][0] = o;
			if(neip){
				// 0->0
				if(cu[ca[q-1][1]][0] >= sh[i-1][0]){
					long v = dp[i-1][0] + sh[i-1][0];
					if(v > dp[i][0]){
						dp[i][0] = v;
						buyer[i][0] = ca[q-1][1];
					}
				}
				// 1->0
				if(cap[q-1] == 2 && cu[ca[q-1][2]][0] >= sh[i-1][0]){
					long v = dp[i-1][1] + sh[i-1][0];
					if(v > dp[i][0]){
						dp[i][0] = v;
						buyer[i][0] = ca[q-1][2];
					}
				}
			}else if(exprev){
				// 0->0
				if(cu[ca[q-1][1]][0] >= sh[i-1][0]){
					long v = o + sh[i-1][0];
					if(v > dp[i][0]){
						dp[i][0] = v;
						buyer[i][0] = ca[q-1][1];
					}
				}
			}
			
			if(excur){
				// 0,1->1
				if(cu[ca[q][1]][0] >= sh[i-1][0]){
					long v = o + sh[i-1][0];
					if(v > dp[i][1]){
						dp[i][1] = v;
						buyer[i][1] = ca[q][1];
					}
				}
				if(cap[q] == 2 && cu[ca[q][2]][0] >= sh[i-1][0]){
					long v = o + sh[i-1][0];
					if(v >= dp[i][0]){
						dp[i][0] = v;
						buyer[i][0] = ca[q][2];
					}
				}
			}
			
			preq = q;
		}
		
//		tr(ca);
//		for(long[] row : dp){
//			tr(row);
//		}
//		tr(buyer);
		int l = 0;
		if(dp[n][0] < dp[n][1])l = 1;
		out.println(Math.max(dp[n][0], dp[n][1]));
//		if(true)return;
		
		int[][] ar = new int[n][2];
		int arp = 0;
		for(int i = n;i >= 1;i--){
			if(buyer[i][l] != -1){
				ar[arp][0] = sh[i-1][2]+1;
				ar[arp][1] = cu[buyer[i][l]][2]+1;
				arp++;
			}
			
			if(dp[i-1][1] == dp[i][l]-sh[i-1][0] && buyer[i-1][1] != buyer[i][l]){
				l = 1;
			}else if(dp[i-1][1] == dp[i][l]){
				l = 1;
			}else{
				l = 0;
			}
		}
		
		out.println(arp);
		for(int i = 0;i < arp;i++){
			out.println(ar[i][1] + " " + ar[i][0]);
		}
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
		new D2().run();
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