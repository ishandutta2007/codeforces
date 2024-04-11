//package round3;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String st = in.next();
		String go = in.next();
		
		int sc = st.charAt(0)-'a';
		int sr = 7-(st.charAt(1)-'1');
		int gc = go.charAt(0)-'a';
		int gr = 7-(go.charAt(1)-'1');
		
		int[] dr = {1,0,-1,0,1,1,-1,-1};
		int[] dc = {0,1,0,-1,1,-1,1,-1};
		String[] p = {"D", "R", "U", "L", "RD", "LD", "RU", "LU"};
		String[][] path = new String[8][8];
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(sr*8+sc);
		path[sr][sc] = "";
		
		while(!q.isEmpty()) {
			int cur = q.poll();
			int r = cur/8;
			int c = cur%8;
			for(int i = 0;i < 8;i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if(nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && path[nr][nc] == null) {
					path[nr][nc] = path[r][c] + " " + p[i];
					q.add(nr*8+nc);
				}
			}
		}
		
		if(sr == gr && sc == gc) {
			out.println(0);
		}else {
			String[] sp = path[gr][gc].substring(1).split(" ");
			out.println(sp.length);
			for(String s : sp) {
				out.println(s);
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}