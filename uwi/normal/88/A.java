//package round73;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Div2A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	String[] T = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};
	
	void solve()
	{
		int[] ts = new int[3];
		for(int i = 0;i < 3;i++){
			String t = in.next();
			for(int j = 0;j < T.length;j++){
				if(t.equals(T[j])){
					ts[i] = j;
					break;
				}
			}
		}
		
		if(
				!check(ts[0], ts[1], ts[2]) &&
				!check(ts[0], ts[2], ts[1]) &&
				!check(ts[1], ts[0], ts[2]) &&
				!check(ts[1], ts[2], ts[0]) &&
				!check(ts[2], ts[0], ts[1]) &&
				!check(ts[2], ts[1], ts[0])
				){
			out.println("strange");
		}
	}
	
	boolean check(int a, int b, int c)
	{
		int ab = (b-a+12)%12;
		int bc = (c-b+12)%12;
		int ac = (c-a+12)%12;
		if(ab == 4 && bc == 3 && ac == 7){
			out.println("major");
			return true;
		}
		if(ab == 3 && bc == 4 && ac == 7){
			out.println("minor");
			return true;
		}
		return false;
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
		new Div2A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}