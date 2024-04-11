//package round25;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	private Scanner in;
	private PrintWriter out;
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int[] u = new int[n];
		int fe = -1, fo = -1;
		int ne = -1, no = -1;
		for(int i = 0;i < n;i++){
			u[i] = ni();
			if(u[i] % 2 == 0){
				if(fe == -1){
					fe = i + 1;
				}else{
					ne = i + 1;
				}
			}else{
				if(fo == -1){
					fo = i + 1;
				}else{
					no = i + 1;
				}
			}
		}
		if(ne > 0){
			out.println(fo);
		}else{
			out.println(fe);
		}
	}
	
	public void run() throws Exception
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
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}