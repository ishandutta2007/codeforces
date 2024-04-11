//package school3;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
//	String INPUT = "3 4 2 3 1 1 2 3 4 1 2 3 4";
//	String INPUT = "8 6 7 6 4 2 3 5 5 7 10 4 3 8 9 1 1 1 1 2 2 2";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int[] next = new int[n];
		
		for(int i = 0;i < n;i++){
			next[i] = ni() - 1;
		}
		int[] v = new int[m];
		for(int i = 0;i < m;i++){
			v[i] = ni();
		}
		int[] b = new int[m];
		for(int i = 0;i < m;i++){
			b[i] = ni();
		}
		
		int[] jump = new int[n];
		Arrays.fill(jump, 1);
		
		int res = 0;
		BitSet dead = new BitSet();
		int[] visited = new int[n];
		for(int i = 0;i < m;i++){
			int a = ((v[i] + res - 1) % n);
			
			BitSet bv = new BitSet();
			int cur = a;
			int ct = 0;
			int j;
			for(j = 0;j < b[i];){
				visited[cur] = j;
				bv.set(cur);
				if(!dead.get(cur)){
					dead.set(cur);
					ct++;
				}
				j += jump[cur];
				cur = next[cur];
				if(bv.get(cur)){
					break;
				}
			}
//			tr(i, b[i], j, bv.cardinality());
			for(int k = bv.nextSetBit(0);k != -1;k = bv.nextSetBit(k+1)){
				jump[k] = j - visited[k];
				next[k] = cur;
			}
			
			res = ct;
			out.println(res);
		}
	}
	
	public static int[] makeNextList(int[] a, int sup)
	{
		int n = a.length;
		int[] mnext = new int[sup];
		Arrays.fill(mnext, -1);
		int[] next = new int[n];
		for(int i = n - 1;i >= 0;i--){
			next[i] = mnext[a[i]];
			mnext[a[i]] = i;
		}
		return next;
	}
	
	void run() throws Exception
	{
//		int n = 100000;
//		int m = 100000;
//		StringBuilder sb = new StringBuilder(n + " " + m + " ");
//		Random r = new Random();
//		for(int i = 0;i < n;i++){
//			sb.append(r.nextInt(100000) + 1 + " ");
//		}
//		for(int i = 0;i < m;i++){
//			sb.append(r.nextInt(10000000) + 1 + " ");
//		}
//		for(int i = 0;i < m;i++){
//			sb.append(r.nextInt(10000000) + 1 + " ");
//		}
//		INPUT = sb.toString();
		
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