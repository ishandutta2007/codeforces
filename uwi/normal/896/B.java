//package round449;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int C = ni();
		int[] a = new int[n];
		Arrays.fill(a, -1);
		int p = 0, q = n-1;
		outer:
		while(!ok(a)){
			if(m == 0){
				throw new RuntimeException();
			}
			m--;
			int v = ni();
			if(v <= C/2){
				if(p >= 1 && v < a[p-1]){
					for(int i = p;;i--){
						if(i == 0 || a[i-1] <= v){
							a[i] = v;
							out.println(i+1);
							out.flush();
							continue outer;
						}
					}
				}else{
					a[p] = v;
					out.println(p+1);
					out.flush();
					p++;
					continue outer;
				}
			}else{
				if(q < n-1 && v > a[q+1]){
					for(int i = q;;i++){
						if(i == n-1 || a[i+1] >= v){
							a[i] = v;
							out.println(i+1);
							out.flush();
							continue outer;
						}
					}
				}else{
					a[q] = v;
					out.println(q+1);
					out.flush();
					q--;
					continue outer;
				}
			}
		}
	}
	
	boolean ok(int[] a)
	{
		for(int v : a){
			if(v == -1)return false;
		}
		for(int i = 0;i < a.length-1;i++){
			if(a[i] > a[i+1])return false;
		}
		return true;
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}