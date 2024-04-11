//package round68;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int k = ni();
		in.next();
		int dir = in.next().equals("head") ? -1 : 1;
		char[] r = in.next().toCharArray();
		
		int q = r.length;
		for(int i = 0;i < q;i++){
			if(dir == -1 && k == 1)dir = 1;
			if(dir == 1 && k == n)dir = -1;
			
			k += dir;
			if(r[i] == '0'){
				if(m == 1 && m+dir == 0 && k > 1)continue;
				if(m == n && m+dir == n+1 && k < n)continue;
				m += dir;
				if(m == 0 || m == n+1){
					out.println("Controller " + (i+1));
					return;
				}
			}else{
				if(dir == -1){
					m = n;
				}else{
					m = 1;
				}
			}
		}
		out.println("Stowaway");
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}