import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	static class Stuff implements Comparable<Stuff> {
		int id;
		long cost;
		
		public Stuff(int id, long cost) {
			super();
			this.id = id;
			this.cost = cost;
		}

		@Override
		public int compareTo(Stuff o) {
			return cost < o.cost ? -1 : cost > o.cost ? 1 : 0;
		}
		
	}
	
	public void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		List<Stuff> a = new ArrayList<Solution.Stuff>();
		List<Stuff> b = new ArrayList<Solution.Stuff>();
		long sum = 0;
		for (int i = 0; i < n; ++i) {
			Stuff s = new Stuff(i + 1, nextLong());
			sum += 2 * s.cost;
			if (nextInt() == 1) {
				a.add(s);
			} else {
				b.add(s);
			}
		}
		Collections.sort(a);
		Collections.sort(b);
		List<Integer>[] ans = new List[k];
		for (int i = 0; i < k; ++i) {
			ans[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < k - 1 && i < a.size(); ++i) {
			sum -= a.get(a.size() - i - 1).cost;
			ans[i].add(a.get(a.size() - i - 1).id);
		}
		if (a.size() >= k) {
			if (b.isEmpty()) {
				sum -= a.get(0).cost;
			} else {
				sum -= Math.min(a.get(0).cost, b.get(0).cost);
			}
		}
		int t = a.size();
		for (int i = 0; i < a.size() - (k - 1); ++i) {
			ans[Math.min(k - 1, t++)].add(a.get(i).id);
		}
		for (int i = 0; i < b.size(); ++i) {
			ans[Math.min(k - 1, t++)].add(b.get(i).id);
		}
		out.printf("%.1f%n", sum / 2.);
		boolean[] col = new boolean[n];
		int total = 0;
		for (int i = 0; i < k; ++i) {
			if (ans[i].isEmpty()) {
				throw new AssertionError();
			}
			total += ans[i].size();
			out.print(ans[i].size() + " ");
			for (int j : ans[i]) {
				if (col[j - 1]) {
					throw new AssertionError();
				}
				col[j - 1] = true;
				out.print(j + " ");
			}
			out.println();
		}
		if (total != n) {
			throw new AssertionError();
		}
	}

	public void run() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		eat("");
		
		solve();
		
		out.close();
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}