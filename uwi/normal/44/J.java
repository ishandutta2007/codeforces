//package school2;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class J {
	Scanner in;
	PrintWriter out;
//	String INPUT = "2 2 wb bw";
//	String INPUT = "6 10 .w.wbw.wbw wbwbw.w.w. bw.wbwbwbw w.wbw.wbwb ...wbw.w.w ..wbw.wbw.";
//	String INPUT = "1 3 ...";
//	String INPUT = "1 1 .";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		char[][] bb = new char[n][m];
		for(int i = 0;i < n;i++){
			bb[i] = in.next().toCharArray();
		}
		char[][] ret = new char[n][m];
		for(int i = 0;i < n;i++){
			Arrays.fill(ret[i], '.');
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(bb[i][j] == 'b'){
					if(i > 0 && i + 1 < n && bb[i-1][j] == 'w' && bb[i+1][j] == 'w'){
						bb[i-1][j] = '.';
						bb[i][j] = '.';
						bb[i+1][j] = '.';
						BitSet used = new BitSet();
						if(j > 0)used.set(ret[i][j-1]);
						if(j + 1 < m)used.set(ret[i][j+1]);
						if(j > 0)used.set(ret[i-1][j-1]);
						if(j + 1 < m)used.set(ret[i-1][j+1]);
						if(i >= 2)used.set(ret[i-2][j]);
						char c = (char)used.nextClearBit('a');
						ret[i-1][j] = c;
						ret[i][j] = c;
						ret[i+1][j] = c;
					}else if(j > 0 && j + 1 < m && bb[i][j-1] == 'w' && bb[i][j+1] == 'w'){
						bb[i][j-1] = '.';
						bb[i][j] = '.';
						bb[i][j+1] = '.';
						BitSet used = new BitSet();
						if(i >= 1)used.set(ret[i-1][j-1]);
						if(i >= 1)used.set(ret[i-1][j]);
						if(i >= 1)used.set(ret[i-1][j+1]);
						if(j >= 2)used.set(ret[i][j-2]);
						if(j + 2 < m)used.set(ret[i][j+2]);
						char c = (char)used.nextClearBit('a');
						ret[i][j-1] = c;
						ret[i][j] = c;
						ret[i][j+1] = c;
					}else{
						out.println("NO");
						return;
					}
				}
			}
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(bb[i][j] != '.'){
					out.println("NO");
					return;
				}
			}
		}
		
		out.println("YES");
		for(int i = 0;i < n;i++){
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
		new J().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}