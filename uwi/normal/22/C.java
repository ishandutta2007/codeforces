//package round22;


import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "5 6 3";
//	private String INPUT = "6 100 1";
//	private String INPUT = "100000 100000 5000";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int m = ni();
		int v = ni();
		
		if(m < n - 1){
			out.println(-1);
			return;
		}
		
		long msup = (long)(n - 1) * (long)(n - 2) / 2 + 1;
		if(m > msup){
			out.println(-1);
			return;
		}
		
		v--;
		int t = v == 0 ? 1 : 0;
		
		int p = 0;
		for(int i = 0;i < n;i++){
			if(i != v){
				out.println((v + 1) + " " + (i + 1));
				p++;
			}
		}
		if(p == m)return;
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				if(i == t || j == t || i == v || j == v)continue;
				out.println((i + 1) + " " + (j + 1));
				if((++p) == m)return;
			}
		}
		
//		out.println((v + 1) + " " + (t + 1));
//		int p = 1;
//		if(p == m)return;
//		for(int i = 0;i < n;i++){
//			for(int j = i + 1;j < n;j++){
//				if(i == t || j == t)continue;
//				out.println((i + 1) + " " + (j + 1));
//				if((++p) == m)return;
//			}
//		}
	}
	
	public void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(new StringReader(INPUT));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}