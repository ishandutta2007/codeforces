//package round65;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		for(int p = 1;p <= n/3;p++){
			if(n % p == 0){
				outer:
				for(int i = 0;i < p;i++){
					for(int j = i;j < n;j += p){
						if(a[j] == 0){
							continue outer;
						}
					}
					out.println("YES");
					return;
				}
			}
		}
		out.println("NO");
	}
	
	void run() throws Exception
	{
//		int n = 100000;
//		StringBuilder sb = new StringBuilder(n + " ");
//		Random r = new Random();
//		for(int i = 0;i < n;i++){
//			sb.append(r.nextInt(2) + " ");
//		}
//		INPUT = sb.toString();
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}