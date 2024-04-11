import java.io.*;
import java.util.*;

public class A {

	final String filename = new String("A").toLowerCase();

	void solve() throws Exception {
		int n = nextInt();
		int[] a = new int[n], b = new int[n];
		int[] posA = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() - 1;
			
		}
		for (int i = 0; i < n; i++) {
			b[i] = nextInt() - 1;
			posA[b[i]] = i;
		}
		int last = -1;
		for (int i = 0; i < n; i++) {
			if (posA[a[i]] < last) {
				out.println(n - i);
				return;
			}
			last = posA[a[i]];
		}
		out.println(0);
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
		new A().run();
	}

}