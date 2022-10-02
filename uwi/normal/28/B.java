//package round28;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class B {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "5 5 4 3 2 1 1 1 1 1 1";
//	private String INPUT = "7 4 2 5 1 3 7 6 4 6 6 1 6 6 1";
//	private String INPUT = "7 4 3 5 1 2 7 6 4 6 6 1 6 6 1";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int[] p = new int[n];
		int[] f = new int[n];
		for(int i = 0;i < n;i++){
			p[i] = ni() - 1;
		}
		for(int i = 0;i < n;i++){
			f[i] = ni();
		}
		
		boolean[][] linked = new boolean[n][n];
		
		for(int i = 0;i < n;i++){
			linked[i][i] = true;
			if(i+f[i] < n){
				linked[i][i+f[i]] = true;
				linked[i+f[i]][i] = true;
			}
			if(i-f[i] >= 0){
				linked[i][i-f[i]] = true;
				linked[i-f[i]][i] = true;
			}
		}
		
		while(true){
			boolean nf = false;
			for(int i = 0;i < n;i++){
				for(int j = 0;j < i;j++){
					if(!linked[i][j]){
						for(int k = 0;k < n;k++){
							if(linked[i][k] && linked[k][j]){
								linked[i][j] = true;
								linked[j][i] = true;
								nf = true;
								break;
							}
						}
					}
				}
			}
			if(!nf)break;
		}
		
		BitSet used = new BitSet();
		for(int i = 0;i < n;i++){
			if(!used.get(i)){
				BitSet clus = new BitSet();
				BitSet now = new BitSet();
				for(int j = 0;j < n;j++){
					if(linked[i][j]){
						used.set(j);
						clus.set(j);
						now.set(p[j]);
					}
				}
//				tr(clus, now);
				if(!clus.equals(now)){
					out.println("NO");
					return;
				}
			}
		}
		out.println("YES");
		return;
	}
	
	public void run() throws Exception
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
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}