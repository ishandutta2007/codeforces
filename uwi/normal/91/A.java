//package round75;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "abc xyz";
	
	void solve()
	{
		char[] a = in.next().toCharArray();
		int n = a.length;
		int[][] next = new int[26][n];
		int[] firsts = new int[26];
		Arrays.fill(firsts, -1);
		for(int i = 0;i < 26;i++){
			int j;
			for(j = 0;j < n && a[j] != 'a'+i;j++);
			if(j == n){
				Arrays.fill(next[i], -1);
			}else{
				int first = j;
				firsts[i] = first;
				for(int k = n-1;k >= 0;k--){
					next[i][k] = first;
					if(a[k] == 'a'+i){
						first = k;
					}
				}
			}
		}
		char[] b = in.next().toCharArray();
		int pos = firsts[b[0]-'a'];
		if(pos == -1){
			out.println(-1);
			return;
		}
		int use = 1;
		for(int i = 1;i < b.length;i++){
			int npos = next[b[i]-'a'][pos];
			if(npos == -1){
				out.println(-1);
				return;
			}
			if(npos <= pos)use++;
			pos = npos;
		}
		
		out.println(use);
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}