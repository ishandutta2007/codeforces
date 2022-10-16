import java.io.*;
import java.util.*;

public class A {

	public void solve() {
		int n = in.nextInt();
		int[] x = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.nextInt();
		}
		Arrays.sort(x);
		
		List<Integer> curW = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int min = Integer.MAX_VALUE;
			for (int j : curW) {
				min = Math.min(min, j);
			}
			if (min <= x[i]) {
				curW.remove((Integer) min);
				curW.add(min + 1);
			} else {
				curW.add(1);
			}
		}
		out.println(curW.size());
	}

	FastScanner in;
	PrintWriter out;

	public void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String name) {
			try {
				br = new BufferedReader(new FileReader(name));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
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