//package test1;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		char[][] b = new char[n][m];
		for(int i = 0;i < n;i++){
			b[i] = in.next().toCharArray();
		}
		
		int[] h = new int[n];
		for(int i = 0;i < n;i++){
			int ct = 0;
			for(int j = 0;j < m;j++){
				if(b[i][j] == '*')ct++;
			}
			h[i] = ct;
		}
		int[] v = new int[m];
		for(int j = 0;j < m;j++){
			int ct = 0;
			for(int i = 0;i < n;i++){
				if(b[i][j] == '*')ct++;
			}
			v[j] = ct;
		}
		
		long ret = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] == '*'){
					ret += (h[i] - 1) * (v[j] - 1);
				}
			}
		}
		out.println(ret);
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}