//package round89;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class C2 {
	Scanner in;
	PrintWriter out;
//	String INPUT = "6 5 898196";
//	String INPUT = "10 6 0001112223";
	String INPUT = "7 5 1222211";
	
	void solve()
	{
		int n = ni();
		int k = ni();
		char[] s = in.next().toCharArray();
		int[] ct = new int[10];
		for(char c : s){
			ct[c-'0']++;
		}
		
		int opt = 0;
		long mincost = Integer.MAX_VALUE;
		int[][] us = new int[10][10];
		Integer[] ord = new Integer[10];
		for(int j = 0;j <= 9;j++)ord[j] = j;
		for(int i = 0;i <= 9;i++){
			final int ii = i;
			Arrays.sort(ord, new Comparator<Integer>(){
				public int compare(Integer a, Integer b){
					int da = Math.abs(a-ii);
					int db = Math.abs(b-ii);
					if(da != db)return da - db;
					return -(a - b);
				}
			});
			
			int left = k;
			long cost = 0;
			for(int j = 0;j <= 9 && left > 0;j++){
				int use = Math.min(left, ct[ord[j]]);
				us[i][ord[j]] = use;
				cost += Math.abs(ord[j]-i)*use;
				left -= use;
			}
			if(cost < mincost){
				mincost = cost;
				opt = 1<<i;
			}else if(cost == mincost){
				opt |= 1<<i;
			}
		}
		
		out.println(mincost);
		String gmin = null;
		for(int i = 0;i <= 9;i++){
			if(opt<<31-i<0){
				char[] t = Arrays.copyOf(s, s.length);
				for(int j = 0;j < t.length;j++){
					if(us[i][t[j]-'0'] > 0){
						if(t[j]-'0'<i){
							if(ct[t[j]-'0'] == us[i][t[j]-'0']){
								t[j] = (char)('0' + i);
								us[i][t[j]-'0']--;
							}
							ct[t[j]-'0']--;
						}else{
							us[i][t[j]-'0']--;
							t[j] = (char)('0' + i);
						}
					}
				}
				if(gmin == null){
					gmin = new String(t);
				}else{
					String st = new String(t);
					if(st.compareTo(gmin) < 0){
						gmin = st;
					}
				}
			}
		}
		out.println(gmin);
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new C2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}