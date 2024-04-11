import java.util.*;
import java.io.*;

public class A {

	class Pair {
		int val, id;

		public Pair(int val, int id) {
			super();
			this.val = val;
			this.id = id;
		}
		
	}
	
	void solve() {
		int n = in.nextInt();
		Pair[] a=  new Pair[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Pair(in.nextInt(), i);
		}
		Arrays.sort(a, (o1, o2) -> Integer.compare(o1.val, o2.val));
		
		boolean[] used = new boolean[n];
		List<List<Integer>> ans = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				int cur = i;
				List<Integer> cycle = new ArrayList<>();
				do {
					cycle.add(cur);
					used[cur] = true;
					cur = a[cur].id;
				} while (cur != i);
				ans.add(cycle);
			}
		}
		out.println(ans.size());
		for (List<Integer> c : ans) {
			out.print(c.size());
			for (int x : c) {
				out.print(" " + (x + 1));
			}
			out.println();
		}
	}

	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new A().run();
	}
}