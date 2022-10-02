//package yandex2011.q1;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] x = in.next().toCharArray();
		int n = x.length;
		char[] s = new char[n+1];
		int p = 0;
		
		for(int i = 0;i < n;i++){
			if(p >= 1 && s[p-1] == x[i]){
				p--;
			}else{
				s[p++] = x[i];
			}
		}
		out.println(new String(s, 0, p));
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
		new A2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}