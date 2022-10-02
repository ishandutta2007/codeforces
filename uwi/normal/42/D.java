//package round41;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class D3 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		if(n == 3){
			out.println("0 3 4");
			out.println("3 0 5");
			out.println("4 5 0");
			return;
		}
		int[][] e = new int[n][n];
		e[0][1] = e[1][0] = 1;
		e[0][2] = e[2][0] = 2;
		e[1][2] = e[2][1] = 3;
		
		for(int i = 3;i < n;i++){
			int max = 0;
			BitSet bs = new BitSet();
			for(int j = 1;j < i;j++){
				for(int k = j + 1;k < i;k++){
					max = Math.max(max, e[j][k]);
					bs.set(e[j][k]);
				}
			}
			outer:
			for(int p = bs.nextClearBit(1);p <= max + 1;p = bs.nextClearBit(p+1)){
				e[0][i] = e[i][0] = p;
				for(int j = 1;j < i;j++){
					int u = j == 1 ? 2 : 1;
					e[j][i] = e[i][j] = e[j][u] + p - e[0][u];
					if(bs.get(e[i][j]))continue outer;
				}
				break;
			}
		}
//		e[1][2] = p;
//
//		for(int a = 0;a < n;a++){
//			for(int b = a + 1;b < n;b++){
//				for(int c = 0;c < n;c++){
//					for(int d = c+1;d < n;d++){
//						if(a == c && b == d)continue;
//						if(e[a][b] > 0 && e[c][d] > 0){
//						}
//					}
//				}
//			}
//		}
		
//		for(int a = 0;a < n;a++){
//			for(int b = a+1;b < n;b++){
//				for(int c = 0;c < n;c++){
//					for(int d = c+1;d < n;d++){
//						if(!(a == c && b == d) && e[a][b] == e[c][d]){
//							out.println("INVALID");
////							out.println();
////							continue outer;
//						}
//					}
//				}
//			}
//		}
//		int min = 99999;
//		int max = 0;
//		for(int i = 0;i < n;i++){
//			for(int j = i + 1;j < n;j++){
//				min = Math.min(min, e[i][j]);
//				max = Math.max(max, e[i][j]);
//			}
//		}
//		if(max - min >= 1000){
//			out.println("INVALID");
////			continue outer;
//		}
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < n;j++){
//				if(i != j){
//					e[i][j] -= min - 1;
//				}
//			}
//		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				out.print(e[i][j] + " ");
			}
			out.println();
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