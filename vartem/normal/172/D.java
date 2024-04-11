import java.io.*;
import java.util.*;

public class D {

	final String filename = new String("D").toLowerCase();

	void solve() throws Exception {
		int a = nextInt();
		int n = nextInt();
		int[] max = new int[n];
		for (int i = 1; i * i < a + n; i++) {
			int sq = i * i;
			int j = sq;
			while (j < a + n) {
				if (j >= a) {
					max[j - a] = sq;
				}
				j += sq;
			}
		}
		
		long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += (long) (a + i) / (long) max[i];
		}
		out.println(ans);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			//			in = new BufferedReader(new FileReader("input.txt"));
			//			out = new PrintWriter("output.txt");

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
		new D().run();
	}

}