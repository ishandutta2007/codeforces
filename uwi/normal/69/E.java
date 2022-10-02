//package round63;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeMap;

public class E {
	Scanner in;
	PrintWriter out;
//	String INPUT = "6 4\r\n" +
//			"3\r\n" +
//			"3\r\n" +
//			"3\r\n" +
//			"4\r\n" +
//			"4\r\n" +
//			"2";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int k = ni();
		int[] a = new int[n];
		int[] b = new int[n];
		TreeMap<Integer, Integer> t = new TreeMap<Integer, Integer>();
		for(int i = 0;i < n;i++){
			a[i] = ni();
			t.put(a[i], 0);
		}
		int p = 0;
		int[] it = new int[n];
		for(int q : t.keySet()){
			t.put(q, p);
			it[p] = q;
			p++;
		}
		
		for(int i = 0;i < n;i++){
			b[i] = t.get(a[i]);
		}
		
		int[] c = new int[p];
		int pmax = p-1;
		for(int i = 0;i < k-1;i++){
			c[b[i]]++;
		}
		outer:
		for(int i = 0;i < n-k+1;i++){
			c[b[i+k-1]]++;
			if(c[b[i+k-1]] == 1 && b[i+k-1] > pmax){
				pmax = b[i+k-1];
			}
			for(int j = pmax;j >= 0;j--){
				if(c[j] == 1){
					out.println(it[j]);
					pmax = j;
					c[b[i]]--;
					if(c[b[i]] == 1 && b[i] > pmax)pmax = b[i];
					continue outer;
				}
			}
			out.println("Nothing");
			c[b[i]]--;
			if(c[b[i]] == 1 && b[i] > pmax)pmax = b[i];
		}
	}
	
	void run() throws Exception
	{
//		int n = 100000;
//		StringBuilder sb = new StringBuilder(n + " 1 ");
//		Random r = new Random();
//		for(int i = 0;i < n;i++){
//			sb.append(r.nextInt(100000) + " ");
//		}
//		INPUT = sb.toString();
		
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}