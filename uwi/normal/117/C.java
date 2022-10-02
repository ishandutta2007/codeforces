//package round88;
import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;

public class C2 {
	BufferedReader br;
	PrintWriter out;
	String INPUT = "5\r\n" + 
			"00100\r\n" + 
			"10000\r\n" + 
			"01001\r\n" + 
			"11101\r\n" + 
			"11000";
	
	void solve() throws Exception
	{
		int n = Integer.parseInt(br.readLine());
		char[][] A = new char[n][n];
		for(int i = 0;i < n;i++){
			br.read(A[i]);
			br.readLine();
		}
		int[] ct = new int[n];
		BitSet bs = new BitSet();
		int[] cct = new int[n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(A[i][j] == '1'){
					ct[i]++;
				}
			}
			bs.set(ct[i]);
			cct[ct[i]]++;
		}
		if(bs.cardinality() == n){
			out.println(-1);
		}else{
			for(int j = 0;j < n;j++){
				for(int k = 0;k < n;k++){
					if(ct[j] <= ct[k] && A[j][k] == '1'){
						for(int l = 0;l < n;l++){
							if(A[k][l] == '1' && A[l][j] == '1'){
								out.printf("%d %d %d\n", j+1, k+1, l+1);
								return;
							}
						}
					}
				}
			}
			out.println(-1);
		}
	}
	
	void run() throws Exception
	{
		br = new BufferedReader(new InputStreamReader(oj ? System.in : new ByteArrayInputStream(INPUT.getBytes())));
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new C2().run();
	}
	
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}