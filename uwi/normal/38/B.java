//package round38;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
//	String INPUT = "a8 d4";
	String INPUT = "";
	
	void solve()
	{
		char[] rook = in.next().toCharArray();
		char[] knight = in.next().toCharArray();
		int[][] m = new int[8][8];
		
		int rr = rook[1] - '1';
		int rc = rook[0] - 'a';
		for(int i = 0;i < 8;i++){
			m[rr][i] = 1;
			m[i][rc] = 1;
		}
		
		int kr = knight[1] - '1';
		int kc = knight[0] - 'a';
		int[] dx = {-1, 1, 2, 2, 1, -1, -2, -2};
		int[] dy = {-2, -2, -1, 1, 2, 2, 1, -1};
		m[kr][kc] = 1;
		for(int i = 0;i < 8;i++){
			int r = kr + dx[i];
			int c = kc + dy[i];
			if(r >= 0 && r < 8 && c >= 0 && c < 8){
				m[r][c] = 1;
			}
		}
		
		for(int i = 0;i < 8;i++){
			int r = rr + dx[i];
			int c = rc + dy[i];
			if(r >= 0 && r < 8 && c >= 0 && c < 8){
				m[r][c] = 1;
			}
		}
		
		int ct = 0;
		for(int i = 0;i < 8;i++){
			for(int j = 0;j < 8;j++){
				if(m[i][j] == 0)ct++;
			}
		}
		out.println(ct);
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}