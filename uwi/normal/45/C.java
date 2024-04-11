//package school3;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.TreeSet;

public class C {
	Scanner in;
	PrintWriter out;
//	String INPUT = "4 BGBG 4 2 4 3";
//	String INPUT = "4 BBGG 4 2 4 3";
//	String INPUT = "4 BBGG 4 6 1 5";
//	String INPUT = "4 BGBB 1 1 2 3";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		char[] bg = in.next().toCharArray();
		int[] h = new int[n];
		for(int i = 0;i < n;i++){
			h[i] = ni();
		}
		int[] next = new int[n];
		int[] prev = new int[n];
		for(int i = 0;i < n;i++){
			next[i] = i + 1;
			prev[i] = i - 1;
			if(i == n - 1)next[i] = -1;
//			if(i == 0)prev[i] = -1;
		}
		
		final int[] hs = new int[n];
		for(int i = 0;i < n - 1;i++){
			hs[i] = Math.abs(h[i+1] - h[i]);
		}
		
		TreeSet<Integer> ts = new TreeSet<Integer>(new Comparator<Integer>(){
			public int compare(Integer a, Integer b)
			{
				if(hs[a] != hs[b])return hs[a] - hs[b];
				return a - b;
			}
		});
		
		for(int i = 0;i < n - 1;i++){
			if(bg[i] != bg[i+1])ts.add(i);
		}
		
		StringBuilder sb = new StringBuilder();
		int ct = 0;
		while(ts.size() > 0){
			int cur = ts.pollFirst();
			sb.append((cur + 1) + " ");
			if(next[cur] == -1)throw new Error();
			sb.append((next[cur] + 1) + "\n");
			ct++;
			ts.remove(next[cur]);
			
			int p = prev[cur];
			int x = next[cur] != -1 ? next[next[cur]] : -1;
			if(p != -1)next[p] = x;
			if(x != -1)prev[x] = p;
			if(x == -1){
				ts.remove(p);
			}
			if(p != -1 && x != -1){
				if(bg[p] != bg[x]){
					ts.remove(p);
					hs[p] = Math.abs(h[x] - h[p]);
					ts.add(p);
				}else{
					ts.remove(p);
				}
			}
		}
		out.println(ct);
		out.println(sb);
	}
	
	class Datum
	{
		public int hs;
		public int ind;
		public Datum(int hs, int ind)
		{
			this.hs = hs;
			this.ind = ind;
		}
	}
	
	void run() throws Exception
	{
//		int n = 200000;
//		StringBuilder sb = new StringBuilder(n + " ");
//		Random r = new Random();
//		for(int i = 0;i < n;i++){
//			sb.append(r.nextInt(2) == 0 ? 'B' : 'G');
//		}
//		sb.append('\n');
//		for(int i = 0;i < n;i++){
//			sb.append(r.nextInt(1000000) + " ");
//		}
//		INPUT = sb.toString();
		
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}