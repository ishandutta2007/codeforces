//package mailru.r3;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni()*2, m = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		int[] ips = new int[n];
		Arrays.fill(ips, -1);
		int[] ps = new int[2*m];
		for(int i = 0;i < 2*m;i++){
			ps[i] = ni()-1;
			ips[ps[i]] = i;
		}
		int t = ni();
		if(t == 1){
			boolean[] seled = new boolean[n];
			for(int i = 0;i < n;i++){
				if(ips[i] != -1 && !seled[i]){
					int op = ps[ips[i]^1];
					if(a[i] > a[op]){
						out.println(i+1); out.flush();
					}else{
						out.println(op+1); out.flush();
					}
					ni();
					seled[op] = seled[i] = true;
				}
			}
			int[][] as = new int[n][];
			for(int i = 0;i < n;i++){
				as[i] = new int[]{a[i], i};
			}
			Arrays.sort(as, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[0] - b[0];
				}
			});
			for(int i = n-1;i >= 0;i--){
				if(!seled[as[i][1]]){
					seled[as[i][1]] = true;
					out.println(as[i][1]+1); out.flush();
					seled[as[i][1]] = true;
					
					int op = ni()-1;
					seled[op] = true;
				}
			}
		}else{
			boolean[] seled = new boolean[n];
			int[][] as = new int[n][];
			for(int i = 0;i < n;i++){
				as[i] = new int[]{a[i], i};
			}
			Arrays.sort(as, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[0] - b[0];
				}
			});
			
			outer:
			for(int i = 0;i < n/2;i++){
				int op = ni()-1;
				seled[op] = true;
				if(ips[op] >= 0 && !seled[ps[ips[op]^1]]){
					out.println(ps[ips[op]^1]+1); out.flush();
					seled[ps[ips[op]^1]] = true;
				}else{
					for(int j = 0;j < n;j++){
						if(ips[j] != -1 && !seled[j]){
							int lop = ps[ips[j]^1];
							if(a[j] > a[lop]){
								out.println(j+1); out.flush();
							}else{
								out.println(lop+1); out.flush();
							}
							seled[lop] = seled[j] = true;
							continue outer;
						}
					}
					for(int j = n-1;j >= 0;j--){
						if(!seled[as[j][1]]){
							seled[as[j][1]] = true;
							out.println(as[j][1]+1); out.flush();
							seled[as[j][1]] = true;
							continue outer;
						}
					}
				}
			}
		}
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}