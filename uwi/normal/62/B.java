//package round58;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int k = ni();
		char[] ad = in.next().toCharArray();
		int[][] pos = new int[26][];
		int[] pp = new int[26];
		for(int i = 0;i < k;i++){
			int cc = ad[i]-'a';
			pp[cc]++;
		}
		for(int i = 0;i < 26;i++){
			pos[i] = new int[pp[i]];
		}
		for(int i = k-1;i >= 0;i--){
			int cc = ad[i]-'a';
			pos[cc][--pp[cc]] = i;
		}
		
		for(int i = 0;i < n;i++){
			char[] str = in.next().toCharArray();
			long d = 0;
			for(int j = 0;j < str.length;j++){
				int cc = str[j] - 'a';
				if(pos[cc].length == 0){
					d += str.length;
				}else{
					int ind = Arrays.binarySearch(pos[cc], j);
					if(ind >= 0){
					}else{
						int inf = -ind-2;
						int sup = -ind-1;
						int min = 999999;
						if(inf >= 0)min = Math.min(min, j - pos[cc][inf]);
						if(sup < pos[cc].length)min = Math.min(min, pos[cc][sup] - j);
						d += min;
					}
				}
			}
			out.println(d);
		}
	}
	
	void run() throws Exception
	{
//		int n = 400;
//		int m = 400;
//		StringBuilder sb = new StringBuilder(n + " " + m + " ");
//		Random r = new Random();
//		for(int i = 0;i < n+1;i++){
//			for(int j = 0;j < m;j++){
//				sb.append((char)(r.nextInt('z'-'a')+'a'));
//			}
//			sb.append("\r\n");
//		}
//		INPUT = sb.toString();
		
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}