//package round59;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[][] a = new char[5][];
		for(int i = 0;i < 5;i++){
			a[i] = in.nextLine().toCharArray();
		}
		int start = (
				(a[0][2] == 'O' ? 1<<0 : 0) |
				(a[0][4] == 'O' ? 1<<1 : 0) |
				(a[0][6] == 'O' ? 1<<2 : 0) |
				(a[1][1] == 'O' ? 1<<3 : 0) |
				(a[1][3] == 'O' ? 1<<4 : 0) |
				(a[1][5] == 'O' ? 1<<5 : 0) |
				(a[1][7] == 'O' ? 1<<6 : 0) |
				(a[2][0] == 'O' ? 1<<7 : 0) |
				(a[2][2] == 'O' ? 1<<8 : 0) |
				(a[2][4] == 'O' ? 1<<9 : 0) |
				(a[2][6] == 'O' ? 1<<10 : 0) |
				(a[2][8] == 'O' ? 1<<11 : 0) |
				(a[3][1] == 'O' ? 1<<12 : 0) |
				(a[3][3] == 'O' ? 1<<13 : 0) |
				(a[3][5] == 'O' ? 1<<14 : 0) |
				(a[3][7] == 'O' ? 1<<15 : 0) |
				(a[4][2] == 'O' ? 1<<16 : 0) |
				(a[4][4] == 'O' ? 1<<17 : 0) |
				(a[4][6] == 'O' ? 1<<18 : 0)
				);
		List<Integer> move = new ArrayList<Integer>();
		int[][] hex = new int[][]{
				{1,2,3,0,0},
				{4,5,6,7,0},
				{8,9,10,11,12},
				{0,13,14,15,16},
				{0,0,17,18,19}
		};
		
		int[] dr = {1,1,0};
		int[] dc = {0,1,1};
		for(int i = 0;i < 5;i++){
			for(int j = 0;j < 5;j++){
				if(hex[i][j] > 0){
					move.add(1<<(hex[i][j]-1));
					for(int k = 0;k < 3;k++){
						int base = 1<<(hex[i][j]-1);
						for(int r = i+dr[k], c = j+dc[k];r < 5 && c < 5 && hex[r][c] > 0;r += dr[k], c += dc[k]){
							base |= 1<<(hex[r][c]-1);
							move.add(base);
						}
					}
				}
			}
		}
		Collections.sort(move);
		int[] movv = new int[move.size()];
		for(int i = 0;i < move.size();i++){
			movv[i] = move.get(i);
		}
		
		boolean[] win = new boolean[1<<19];
		win[0] = false;
		for(int i = 1;i <= start;i++){
			outer:
			for(int j = 0;j < movv.length;j++){
				int mv = movv[j];
				if(mv > i)break;
				if((i&mv) == mv){
					if(!win[i^mv]){
						win[i] = true;
						break outer;
					}
				}
			}
		}
		
		out.println(win[start] ? "Karlsson" : "Lillebror");
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
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}