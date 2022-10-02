//package round54;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		String[] nm = new String[n];
		int sum = 0;
		for(int i = 0;i < n;i++){
			nm[i] = in.next();
			sum += nm[i].length();
		}
		char sep = in.next().charAt(0);
		int len = sum / (n/2)+1;
		
		int[] np = new int[11];
		for(int i = 0;i < n;i++){
			np[nm[i].length()]++;
		}
		
		String[][] w = new String[11][];
		for(int i = 0;i < 11;i++){
			w[i] = new String[np[i]];
		}
		for(int i = 0;i < n;i++){
			w[nm[i].length()][--np[nm[i].length()]] = nm[i];
		}
		for(int i = 0;i < 11;i++){
			Arrays.sort(w[i]);
		}
		
		String[] str = new String[n/2];
		int p = 0;
		for(int i = 1, j = len-2;i <= j;i++,j--){
			if(i < j){
				for(int k = 0;k < w[i].length;k++){
					String sa = w[i][k] + sep + w[j][k];
					String sb = w[j][k] + sep + w[i][k];
					if(sa.compareTo(sb) < 0){
						str[p++] = sa;
					}else{
						str[p++] = sb;
					}
				}
			}else{
				for(int k = 0;k < w[i].length;k+=2){
					str[p++] = w[i][k]+sep+w[i][k+1];
				}
			}
		}
		
		Arrays.sort(str);
		for(String s : str){
			out.println(s);
		}
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
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}