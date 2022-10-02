//package round76;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int a = ni() - 1;
		int b = ni() - 1;
		if(a / m == b / m){
			out.println(1);
			return;
		}else if(b/m == a/m+1){
			if(a%m==0 && b==n-1){
				out.println(1);
				return;
			}
			if(a%m==0 && b%m==m-1){
				out.println(1);
			}else{
				out.println(2);
			}
		}else{
			if(a % m == 0){
				if(b == n-1){
					out.println(1);
				}else if(b % m == m-1){
					out.println(1);
				}else{
					out.println(2);
				}
				return;
			}else{
				if(b % m == m-1 || b == n-1){
					out.println(2);
				}else{
					if(a%m-b%m==1){
						out.println(2);
					}else{
						out.println(3);
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}