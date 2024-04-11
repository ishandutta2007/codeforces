//package round57;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.TreeSet;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] f = new int[n-1];
		int[] t = new int[n-1];
		int[] w = new int[n-1];
		int[][] b = new int[n][];
		int[] bp = new int[n];
		long sum = 0;
		for(int i = 0;i < n-1;i++){
			f[i] = ni()-1;
			t[i] = ni()-1;
			bp[f[i]]++;
			bp[t[i]]++;
			w[i] = ni();
			sum += w[i];
		}
		for(int i = 0;i < n;i++){
			bp[i]*=2;
			b[i] = new int[bp[i]];
		}
		for(int i = 0;i < n-1;i++){
			b[f[i]][--bp[f[i]]] = w[i];
			b[f[i]][--bp[f[i]]] = t[i];
			b[t[i]][--bp[t[i]]] = w[i];
			b[t[i]][--bp[t[i]]] = f[i];
		}
		
		final int[] td = new int[n];
		Arrays.fill(td, Integer.MAX_VALUE / 3);
		TreeSet<Integer> q = new TreeSet<Integer>(new Comparator<Integer>() {
			public int compare(Integer a, Integer b) {
				if(td[a] - td[b] != 0)
					return td[a] - td[b];
				return a - b;
			}
		});
		q.add(0);
		td[0] = 0;

		while (q.size() > 0){
			int cur = q.pollFirst();

			for(int i = 0;i < b[cur].length;i += 2){
				int next = b[cur][i];
				int nd = td[cur] + b[cur][i + 1];
				if(nd < td[next]){
					q.remove(next);
					td[next] = nd;
					q.add(next);
				}
			}
		}
		
		int max = 0;
		for(int i = 0;i < n;i++){
			max = Math.max(max, td[i]);
		}
		
		out.println(sum*2-max);
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
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}