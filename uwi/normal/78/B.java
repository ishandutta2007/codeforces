//package round70;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] c = "ROYGBIV".toCharArray();
		int n = ni();
		int[] ret = new int[n];
		for(int i = 0;i < n;i++){
			if(i <= 6){
				ret[i] = i;
			}else if(i < n-3){
				int b = 0;
				for(int j = i-3;j <= i-1;j++){
					b |= 1<<ret[j];
				}
				for(int j = 0;j < 7;j++){
					if(b>>j<<31 == 0){
						ret[i] = j;
						break;
					}
				}
			}else{
				int b = 0;
				for(int j = i-3;j <= i-1;j++){
					b |= 1<<ret[j];
				}
				for(int j = i+1;j <= i+3;j++){
					int ind = j%n;
					if(ind >= 0 && ind <= 2){
						b |= 1<<ret[ind];
					}
				}
				for(int j = 0;j < 7;j++){
					if(b>>j<<31 == 0){
						ret[i] = j;
						break;
					}
				}
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < n;i++){
			sb.append(c[ret[i]]);
		}
		out.println(sb.toString());
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