//package round87;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B2 {
	Scanner in;
	PrintWriter out;
//	String INPUT = "5 3 GGG GWG GGG GGG WGG";
	String INPUT = "3 3 GWG GGG WGW";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		char[][] b = new char[n][];
		for(int i = 0;i < n;i++){
			b[i] = in.next().toCharArray();
		}
		
		int[] le = new int[n];
		int[] ri = new int[n];
		Arrays.fill(le, 99999);
		Arrays.fill(ri, -1);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] == 'W'){
					if(le[i] == 99999)le[i] = j;
					ri[i] = j;
				}
			}
		}
		
		int ct = 0;
		int row = 0;
		int cur = 0;
		while(true){
			int i;
			for(i = row+1;i < n && ri[i] == -1;i++);
			if(i == n){
				if(ri[row] != -1){
					if(row % 2 == 0){
						ct += ri[row] - cur;
					}else{
						ct += cur - le[row];
					}
				}
				break;
			}
			
			if((i-row) % 2 == 1){
				if(row % 2 == 0){
					int nex = Math.max(ri[row], ri[i]);
					ct += nex - cur + (i-row);
					cur = nex;
				}else{
					int nex = Math.min(le[row], le[i]);
					ct += cur - nex + (i-row);
					cur = nex;
				}
			}else{
				if(row % 2 == 0){
					ct += ri[row] - cur + Math.abs(ri[row] - le[i]) + (i-row);
					cur = le[i];
				}else{
					ct += cur - le[row] + Math.abs(ri[i] - le[row]) + (i-row);
					cur = ri[i];
				}
			}
			row = i;
		}
		out.println(ct);
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new B2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}