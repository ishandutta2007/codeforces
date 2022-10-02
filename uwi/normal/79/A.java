//package round71;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int x = ni();
		int y = ni();
		while(true){
			boolean ok = false;
			for(int i = 2;i >= 0;i--){
				if(x-i >= 0 && y-(22-i*10) >= 0){
					x -= i;
					y -= 22-i*10;
					ok = true;
					break;
				}
			}
			if(!ok){
				out.println("Hanako");
				break;
			}
			ok = false;
			for(int i = 0;i <= 2;i++){
				if(x-i >= 0 && y-(22-i*10) >= 0){
					x -= i;
					y -= 22-i*10;
					ok = true;
					break;
				}
			}
			if(!ok){
				out.println("Ciel");
				break;
			}
		}
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}