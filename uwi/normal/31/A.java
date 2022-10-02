//package round31;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "5 1 8 1 5 1";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(i != j){
					for(int k = j + 1;k < n;k++){
						if(i != k){
							if(a[i] == a[j] + a[k]){
								out.println((i + 1) + " " + (j+1)+" " + (k+1));
								return;
							}
						}
					}
				}
			}
		}
		out.println(-1);
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
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}