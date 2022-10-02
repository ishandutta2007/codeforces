//package round29;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class D {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "3 1 2 2 3 3";
//	private String INPUT = "3 1 3 3 2 2";
//	private String INPUT = "7 1 2 1 3 2 4 2 5 3 6 3 7 7 6 5 4";
//	private String INPUT = "6 1 2 1 3 2 4 4 5 4 6 5 6 3";
//	private String INPUT = "6 1 2 1 3 2 4 4 5 4 6 5 3 6";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int[][] par = new int[n][];
		int[][] pari = new int[n][n];
		int[][] passed = new int[n][n];
		BitSet nl = new BitSet();
		Arrays.fill(pari[0], -1);
		par[0] = new int[0];
		
		int[] fs = new int[n-1];
		int[] ts = new int[n-1];
		for(int i = 0;i < n - 1;i++){
			fs[i] = ni() - 1;
			ts[i] = ni() - 1;
		}
		
		BitSet used = new BitSet();
		BitSet coned = new BitSet();
		coned.set(0);
		while(used.cardinality() < n - 1){
			for(int i = 0;i < n - 1;i++){
				if(!used.get(i)){
					int f = fs[i];
					int t = ts[i];
					if(!coned.get(f) && !coned.get(t))continue;
					if(coned.get(t)){
						int d = f;f = t;t = d;
					}
					used.set(i);
					coned.set(t);
					
					par[t] = new int[par[f].length + 1];
					System.arraycopy(par[f], 0, par[t], 0, par[f].length);
					par[t][par[f].length] = f;
					pari[t] = Arrays.copyOf(pari[f], pari[f].length);
					pari[t][f] = par[f].length;
					nl.set(f);
				}
			}
		}
		
		int nLeaves = n - nl.cardinality();
//		tr(nLeaves);
		int[] ord = new int[nLeaves];
		for(int i = 0;i < nLeaves;i++){
			ord[i] = ni() - 1;
		}
		
		StringBuilder sb = new StringBuilder();
		int prev = -1;
		for(int i = 0;i < par[ord[0]].length;i++){
			int cur = par[ord[0]][i];
			sb.append(cur + 1); sb.append(' ');
			if(prev != -1){
				passed[prev][cur]++;
				passed[cur][prev]++;
			}
			prev = cur;
		}
		for(int i = 0;i < ord.length;i++){
			{
				int cur = ord[i];
				sb.append(cur + 1); sb.append(' ');
				if(prev != -1){
					passed[prev][cur]++;
					passed[cur][prev]++;
				}
				prev = cur;
			}
			for(int j = par[ord[i]].length - 1;j >= 0;j--){
				{
					int cur = par[ord[i]][j];
					sb.append(cur + 1); sb.append(' ');
					if(prev != -1){
						passed[prev][cur]++;
						passed[cur][prev]++;
					}
					prev = cur;
				}
				if(i != ord.length - 1 && pari[ord[i+1]][par[ord[i]][j]] != -1){
					for(int k = pari[ord[i+1]][par[ord[i]][j]] + 1;k < par[ord[i+1]].length;k++){
						{
							int cur = par[ord[i+1]][k];
							sb.append(cur + 1); sb.append(' ');
							if(prev != -1){
								passed[prev][cur]++;
								passed[cur][prev]++;
							}
							prev = cur;
						}
					}
					break;
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < i;j++){
				if(passed[i][j] > 2){
					out.println(-1);
					return;
				}
			}
		}
		out.println(sb.toString());
		
	}
	
	public void run() throws Exception
	{
//		StringBuilder sb = new StringBuilder("300 ");
//		for(int i = 0;i < 299;i++){
//			sb.append((i+1) + " " + (i+2) + "\n");
//		}
//		sb.append("300");
//		INPUT = sb.toString();
		
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}