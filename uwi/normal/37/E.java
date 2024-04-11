//package round37;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
//	String INPUT = "2 3 WWW WWW";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		char[][] s = new char[n][m];
		for(int i = 0;i < n;i++){
			s[i] = in.next().toCharArray();
		}
		int mink = Integer.MAX_VALUE;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				mink = Math.min(mink, flip(s, i, j, n, m));
			}
		}
		out.println(mink);
	}
	
	int flip(char[][] s, int x, int y, int n, int m)
	{
		int[] dx = {-1, 0, 1, 0};
		int[] dy = {0, 1, 0, -1};
		BitSet used = new BitSet();
		BitSet nnext;
		BitSet cur = new BitSet();
		cur.set(x*50+y);
		char cc = s[x][y];
		for(int d = 1;;d++){
			nnext = new BitSet();
			while(!cur.isEmpty()){
				BitSet next = new BitSet();
				used.or(cur);
				for(int i = cur.nextSetBit(0);i != -1;i = cur.nextSetBit(i+1)){
					int u = i / 50;
					int v = i % 50;
					
					for(int j = 0;j < 4;j++){
						int nu = u + dx[j];
						int nv = v + dy[j];
						if(nu >= 0 && nu < n && nv >= 0 && nv < m && !used.get(nu*50+nv)){
							if(s[nu][nv] == cc){
								next.set(nu*50+nv);
							}else{
								nnext.set(nu*50+nv);
							}
						}
					}
				}
				cur = next;
			}
			if(nnext.isEmpty())return cc == 'B' ? d : d-1;
			cur = nnext;
			cc = cc == 'W' ? 'B' : 'W';
		}
	}
	
	void run() throws Exception
	{
//		StringBuilder sb = new StringBuilder("50 50 ");
//		for(int i = 0;i < 50;i++){
//			if(i % 2 == 0){
//				sb.append("BWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBW\n");
//			}else{
//				sb.append("WBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWB\n");
//			}
//		}
//		INPUT = sb.toString();
		
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
	static String join(int[] a, int d){StringBuilder sb = new StringBuilder();for(int v : a){sb.append(v + d + " ");}return sb.toString();}
}