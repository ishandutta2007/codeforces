//package round56;

import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int k = ni();
		int l = ni();
		int m = ni();
		char[][][] p = new char[k][l][m];
		for(int i = 0;i < k;i++){
			for(int j = 0;j < l;j++){
				p[i][j] = in.next().toCharArray();
			}
		}
		
		ArrayDeque<Pos> q = new ArrayDeque<Pos>();
		Pos po = new Pos();
		po.r = ni() - 1;
		po.c = ni() - 1;
		po.z = 0;
		q.add(po);
		int[] dr = {1,-1,0,0,0,0};
		int[] dc = {0,0,1,-1,0,0};
		int[] dz = {0,0,0,0,1,-1};
		
		p[po.z][po.r][po.c] = 'W';
		int ct = 0;
		while(!q.isEmpty()){
			Pos cur = q.poll();
			ct++;
			for(int i = 0;i < 6;i++){
				int nr = cur.r + dr[i];
				int nc = cur.c + dc[i];
				int nz = cur.z + dz[i];
				if(nr >= 0 && nr < l && nc >= 0 && nc < m && nz >= 0 && nz < k && p[nz][nr][nc] == '.'){
					p[nz][nr][nc] = 'W';
					Pos nex = new Pos();
					nex.r = nr;
					nex.c = nc;
					nex.z = nz;
					q.add(nex);
				}
			}
		}
		out.println(ct);
	}
	
	class Pos {
		public int r, c, z;
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