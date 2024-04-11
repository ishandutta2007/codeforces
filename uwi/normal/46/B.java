//package round43;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		HashMap<String, Integer> MAP = new HashMap<String, Integer>();
		MAP.put("S", 0);
		MAP.put("M", 1);
		MAP.put("L", 2);
		MAP.put("XL", 3);
		MAP.put("XXL", 4);
		String[] IMAP = {"S", "M", "L", "XL", "XXL"};
		
		int[] n = new int[5];
		for(int i = 0;i < 5;i++)n[i] = ni();
		int k = ni();
		int[] sz = new int[k];
		for(int i = 0;i < k;i++){
			sz[i] = MAP.get(in.next());
		}
		
		int[] Q = {0, 1, -1, 2, -2, 3, -3, 4, -4};
		for(int i = 0;i < k;i++){
			for(int j = 0;j < 9;j++){
				int ns = sz[i] + Q[j];
				if(ns >= 0 && ns <= 4 && n[ns] > 0){
					n[ns]--;
					out.println(IMAP[ns]);
					break;
				}
			}
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}