//package tech2016.elim1;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;

public class CC {
	BufferedReader br;
	PrintWriter out;
	String INPUT = "";
	
	int get(int i, int j) throws Exception
	{
		out.println("? " + i + " " + j);
		out.flush();
		return Integer.parseInt(br.readLine());
	}
	
	void solve() throws Exception
	{
		int n = Integer.parseInt(br.readLine());
		int a12 = get(1, 2);
		int a23 = get(2, 3);
		int a13 = get(1, 3);
		int sum = (a12+a23+a13)/2;
		int[] a = new int[n];
		a[0] = sum-a23;
		a[1] = sum-a13;
		a[2] = sum-a12;
		for(int i = 3;i < n;i++){
			a[i] = get(1, i+1) - a[0];
		}
		out.print("!");
		for(int i = 0;i < n;i++){
			out.print(" " + a[i]);
		}
		out.println();
	}
	
	void run() throws Exception
	{
		long S = System.currentTimeMillis();
		br = new BufferedReader(INPUT.isEmpty() ? new InputStreamReader(System.in) : new StringReader(INPUT));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
		long G = System.currentTimeMillis();
		tr(G-S+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new CC().run();
	}
	
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}