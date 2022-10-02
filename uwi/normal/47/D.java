//package round44;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D3 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	int gct = 0;
	char[] f = null;
	int m, n;
	char[][] code;
	int[] cor;
	
	void solve()
	{
		n = ni();
		m = ni();
		code = new char[m][];
		f = new char[n];
		cor = new int[m];
		for(int i = 0;i < m;i++){
			code[i] = in.next().toCharArray();
			cor[i] = ni();
		}
		rec(cor[0], 0);
		out.println(gct);
	}
	
	
	
	void rec(int r, int pos)
	{
		if(pos == n){
			if(r == 0){
				for(int i = 1;i < m;i++){
					int ct = 0;
					for(int j = 0;j < n;j++){
						if(f[j] == code[i][j])ct++;
					}
					if(ct != cor[i])return;
				}
				gct++;
			}
			return;
		}
		
		for(char c = '0';c <= '1';c++){
			f[pos] = c;
			int minus = c == code[0][pos] ? 1 : 0;
			if(r - minus >= 0){
				rec(r - minus, pos + 1);
			}
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
		new D3().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}