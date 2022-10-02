//package round41;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C3 {
	Scanner in;
	PrintWriter out;
//	String INPUT = "2 3 2 2";
//	String INPUT = "2010 2011 2012 2013";
	String INPUT = "";
	
	void solve()
	{
		int[] a = new int[]{ni(), ni(), ni(), ni()};
		StringBuilder sb = new StringBuilder();
		
		while(true){
			int max = 1;
			int maxi = -1;
			for(int i = 0;i < 4;i++){
				if(max < a[i]){
					max = a[i];
					maxi = i;
				}
			}
			if(maxi == -1)break;
			
			int m = maxi;
			int l = (maxi + 3) % 4;
			int r = (maxi + 1) % 4;
			if(a[l] % 2 == a[m] % 2){
				if(a[m] % 2 == 0){
					a[l] /= 2;
					a[m] /= 2;
					sb.append("/" + (l+1) + "\n");
				}else{
					a[l] = (a[l] + 1) / 2;
					a[m] = (a[m] + 1) / 2;
					sb.append("+" + (l+1) + "\n");
					sb.append("/" + (l+1) + "\n");
				}
			}else if(a[r] % 2 == a[m] % 2){
				if(a[m] % 2 == 0){
					a[r] /= 2;
					a[m] /= 2;
					sb.append("/" + (m+1) + "\n");
				}else{
					a[r] = (a[r] + 1) / 2;
					a[m] = (a[m] + 1) / 2;
					sb.append("+" + (m+1) + "\n");
					sb.append("/" + (m+1) + "\n");
				}
			}else{
				if(a[m] % 2 == 0){
					// oeo
					a[l] = (a[l] + 1) / 2;
					a[m] = (a[m] + 2) / 2;
					a[r]++;
					sb.append("+" + (l+1) + "\n");
					sb.append("+" + (m+1) + "\n");
					sb.append("/" + (l+1) + "\n");
				}else{
					// eoe
					a[l] = a[l] / 2;
					a[m] = (a[m] + 1) / 2;
					a[r]++;
					sb.append("+" + (m+1) + "\n");
					sb.append("/" + (l+1) + "\n");
				}
			}
		}
		out.println(sb);
	}
	
	int gct = 0;
	
	void rec(int[] a, int p)
	{
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
		new C3().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}