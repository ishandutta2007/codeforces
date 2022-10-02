//package round70;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String line1 = in.nextLine();
		String line2 = in.nextLine();
		String line3 = in.nextLine();
		if(ct(line1) == 5 && ct(line2) == 7 && ct(line3) == 5){
			out.println("YES");
		}else{
			out.println("NO");
		}
	}
	
	int ct(String a)
	{
		int ct = 0;
		for(int i = 0;i < a.length();i++){
			char c = a.charAt(i);
			if(c ==  'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
				ct++;
			}
		}
		return ct;
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