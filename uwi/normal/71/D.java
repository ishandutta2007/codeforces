//package round65;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
//	String INPUT = "4 6\r\n" +
//			"2S 3S 4S 7S 8S AS\r\n" +
//			"5H 6H 7H J2 TC AC\r\n" +
//			"8H 9H TH 7C 8C 9C\r\n" +
//			"2D 2C 3C 4C 5C 6C";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		char[][] suit = new char[n][m];
		char[][] rank = new char[n][m];
		boolean[][] used = new boolean[128][128];
		int[][] jc = new int[10][3];
		BitSet jjj = new BitSet();
		int jn = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				char[] c = in.next().toCharArray();
				rank[i][j] = c[0];
				suit[i][j] = c[1];
				if(c[1] >= '1' && c[1] <= '2'){
					jc[c[1]-'1'][0] = i;
					jc[c[1]-'1'][1] = j;
					jc[c[1]-'1'][2] = c[1];
					jjj.set(c[1]-'1');
					jn++;
				}
				used[suit[i][j]][rank[i][j]] = true;
			}
		}
		
		char[] SUITS = "CDHS".toCharArray();
		char[] RANKS = "23456789TJQKA".toCharArray();
		if(jn == 0){
			if(check(n, m, suit, rank, "There are no jokers."))return;
		}else if(jn == 1){
			for(char s1 : SUITS){
				for(char r1 : RANKS){
					if(!used[s1][r1]){
						int ind = jjj.nextSetBit(0);
						suit[jc[ind][0]][jc[ind][1]] = s1;
						rank[jc[ind][0]][jc[ind][1]] = r1;
						if(check(n, m, suit, rank, "Replace J" + (ind+1) + " with " + r1 + s1 + "."))return;
					}
				}
			}
		}else if(jn == 2){
			for(char s1 : SUITS){
				for(char r1 : RANKS){
					if(!used[s1][r1]){
						suit[jc[0][0]][jc[0][1]] = s1;
						rank[jc[0][0]][jc[0][1]] = r1;
						used[s1][r1] = true;
						for(char s2 : SUITS){
							for(char r2 : RANKS){
								if(!used[s2][r2]){
									suit[jc[1][0]][jc[1][1]] = s2;
									rank[jc[1][0]][jc[1][1]] = r2;
									if(check(n, m, suit, rank, "Replace J1 with " + r1 + s1 + " and J2 with " + r2 + s2 + "."))return;
								}
							}
						}
						used[s1][r1] = false;
					}
				}
			}
		}
		out.println("No solution.");
	}

	boolean check(int n, int m, char[][] suit, char[][] rank, String sentence)
	{
		boolean[][] ok = new boolean[n-2][m-2];
		for(int i = 0;i < n-2;i++){
			for(int j = 0;j < m-2;j++){
				BitSet bs = new BitSet();
				BitSet br = new BitSet();
				for(int k = 0;k < 3;k++){
					for(int l = 0;l < 3;l++){
						bs.set(suit[i+k][j+l]);
						br.set(rank[i+k][j+l]);
					}
				}
				if(bs.cardinality() == 1 || br.cardinality() == 9){
					ok[i][j] = true;
				}
			}
		}
		
		for(int i = 0;i < n-2;i++){
			for(int j = 0;j < m-2;j++){
				if(ok[i][j]){
					for(int k = 0;k < n-2;k++){
						outer:
						for(int l = 0;l < m-2;l++){
							for(int u = 0;u <= 2;u++){
								for(int v = 0;v <= 2;v++){
									if(i <= k+u && k+u <= i+2 && j <= l+v && l+v <= j+2)continue outer;
								}
							}
							if(ok[k][l]){
								out.println("Solution exists.");
								out.println(sentence);
								out.println("Put the first square to (" + (i+1) + ", " + (j+1) + ").");
								out.println("Put the second square to (" + (k+1) + ", " + (l+1) + ").");
								return true;
							}
						}
					}
				}
			}
		}
		return false;
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