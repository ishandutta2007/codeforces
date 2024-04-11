//package round50;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int a = ni();
		int b = ni();
		char[][] m = new char[a][b];
		for(int i = 0;i < a;i++){
			m[i] = in.next().toCharArray();
		}
		
		int minxy = 99999;
		int minx = 999;
		int miny = 999;
		int ct = 0;
		for(int x = 1;x <= a;x++){
			if(a % x != 0)continue;
			outer:
			for(int y = 1;y <= b;y++){
				if(b % y != 0)continue;
				Set<String> set = new HashSet<String>();
				for(int k = 0;k < a;k += x){
					for(int l = 0;l < b;l += y){
						StringBuilder sb = new StringBuilder();
						for(int s = 0;s < x;s++){
							for(int t = 0;t < y;t++){
								sb.append(m[k+s][l+t]);
							}
						}
						if(set.contains(sb.toString())){
							continue outer;
						}
						StringBuilder rev = sb.reverse();
						if(set.contains(rev.toString())){
							continue outer;
						}
						if(x == y){
							StringBuilder sb2 = new StringBuilder();
							for(int s = 0;s < y;s++){
								for(int t = x - 1;t >= 0;t--){
									sb2.append(m[k+t][l+s]);
								}
							}
							if(set.contains(sb2.toString())){
								continue outer;
							}
							StringBuilder rev2 = sb2.reverse();
							if(set.contains(rev2.toString())){
								continue outer;
							}
						}
						set.add(sb.toString());
					}
				}
//				tr(x + " " + y);
				ct++;
				if(minxy > x * y || (minxy == x * y && minx > x)){
					minxy = x * y;
					minx = x;
					miny = y;
				}
			}
		}
		out.println(ct);
		out.println(minx + " " + miny);
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}