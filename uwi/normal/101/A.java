//package round79;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] x = in.next().toCharArray();
		int n = ni();
		int[][] ct = new int[26][2];
		for(int i = 0;i < 26;i++){
			ct[i][1] = i;
		}
		for(int i = 0;i < x.length;i++){
			ct[x[i]-'a'][0]++;
		}
		
		Arrays.sort(ct, new Comparator<int[]>(){
			public int compare(int[] a, int[] b)
			{
				return a[0] - b[0];
			}
		});
		
		int left = n;
		int erase = 0;
		int ok = 0;
		for(int i = 0;i < 26;i++){
			if(ct[i][0] <= left){
				left -= ct[i][0];
				erase |= 1<<ct[i][1];
			}else{
				if(ct[i][0] > 0){
					ok++;
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < x.length;i++){
			if(erase<<31-(x[i]-'a')>=0){
				sb.append(x[i]);
			}
		}
		
		out.println(ok);
		out.println(sb);
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