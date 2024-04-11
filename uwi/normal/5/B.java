//package round5;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		List<String> l = new ArrayList<String>();
		int ml = 0;
		while(in.hasNextLine()) {
			String line = in.nextLine();
			ml = Math.max(ml, line.length());
			l.add(line);
		}
		
		for(int i = 0;i < ml+2;i++) {
			out.print("*");
		}
		out.println();
		boolean lr = true;
		for(int i = 0;i < l.size();i++) {
			out.print("*");
			int marl = (ml-l.get(i).length())/2;
			int marr = ml-l.get(i).length()-marl;
			if(marl < marr) {
				if(!lr) {
					int d = marl; marl = marr; marr = d;
				}
				lr = !lr;
			}
			for(int j = 0;j < marl;j++)out.print(" ");
			out.print(l.get(i));
			for(int j = 0;j < marr;j++)out.print(" ");
			out.print("*");
			out.println();
		}
		for(int i = 0;i < ml+2;i++) {
			out.print("*");
		}
		out.println();
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
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}