//package round59;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int a = ni();
		int b = ni();
		int c = ni();
		int d = ni();
		int n = ni();
		int[] t = new int[n];
		for(int i = 0;i < n;i++){
			t[i] = ni();
		}
		
		int lr = Math.max(b, d);
		int lc = a+c;
		char[][] ret = new char[lr][lc];
		for(int i = 0;i < lr;i++){
			for(int j = 0;j < lc;j++){
				ret[i][j] = '.';
			}
		}
		
		int sc = 0, sr;
		int dir;
		if(a % 2 == 1){
			sr = b-1;
			dir = -1;
		}else{
			sr = 0;
			dir = 1;
		}
		
		int p = 0;
		int ct = 0;
		while(sc < lc){
			ret[sr][sc] = (char)('a'+p);
			ct++;
			if(ct >= t[p]){
				p++;
				ct = 0;
			}
			
			if(dir == -1){
				if(sr == 0){
					sc++;
					dir = 1;
				}else{
					sr--;
				}
			}else{
				if(sc < a){
					if(sr == b - 1){
						sc++;
						dir = -1;
					}else{
						sr++;
					}
				}else{
					if(sr == d - 1){
						sc++;
						dir = -1;
					}else{
						sr++;
					}
				}
			}
		}
		
		out.println("YES");
		for(int i = 0;i < lr;i++){
			out.println(new String(ret[i]));
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