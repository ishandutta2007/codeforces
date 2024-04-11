//package round26;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B3 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] l = in.next().toCharArray();
		int d = 1000000;
		int[] first = new int[2000001];
		Arrays.fill(first, -1);
		int len = 0;
		for(int i = 0;i < l.length;i++){
			if(first[d] == -1)first[d] = i;
			if(l[i] == '('){
				d++;
			}else{
				first[d] = -1;
				d--;
				if(first[d] != -1){
					len+=2;
				}
			}
		}
		out.println(len);
	}
	
	void run() throws Exception
	{
//		StringBuilder sb = new StringBuilder();
//		for(int i = 0;i < 500000;i++){
//			sb.append('(');
//		}
//		for(int i = 0;i < 500000;i++){
//			sb.append(')');
//		}
//		INPUT = sb.toString();
		
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new B3().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}