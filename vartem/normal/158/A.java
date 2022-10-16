import java.io.*;
import java.util.*;

public class NextRound {

	final String filename = new String("NextRound").toLowerCase();

	void solve() throws Exception {
		int n = nextInt();
		int k = nextInt() - 1;
		Integer[] a = new Integer[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		Arrays.sort(a, new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return o2 - o1;
			}
		});
		
		int cnt = 0;
		for (int i : a) {
			if (i > 0 && i >= a[k]) {
				cnt++;
			}
		}
		out.println(cnt);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");

			solve();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new NextRound().run();
	}

}