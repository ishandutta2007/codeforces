//package yandex;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	// ", "
	// " ..."
	// "32  56"
	void solve()
	{
		String line = in.nextLine();
		line = line.replaceAll("(?<=[0-9]) +(?=[0-9])", "_");
		line = line.replace(" ", "");
		line = line.replace(",", ", ");
		line = line.replace("...", " ...");
		line = line.replace("  ", " ");
		line = line.replace("_", " ");
		out.println(line.trim());
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