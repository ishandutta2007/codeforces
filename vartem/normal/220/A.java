import java.io.*;
import java.util.*;

public class A {

	final String filename = new String("C").toLowerCase();

	void solve() throws Exception {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		if (isSorted(a)) {
			out.println("YES");
			return;
		}
		int pos1 = -1;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				int j = i;
				while (j >= 0 && a[j] == a[i]) {
					j--;
				}
				pos1 = j + 1;
				break;
			}

		}
		int pos2 = -1;
		for (int i = n - 2; i >= 0; i--) {
			if (a[i] > a[i + 1]) {
				int j = i + 1;
				while (j < n && a[j] == a[i + 1]) {
					j++;
				}
				pos2 = j - 1;
				break;
			}
		}
		int tmp = a[pos1];
		a[pos1] = a[pos2];
		a[pos2] = tmp;
		if (isSorted(a)) {
			out.println("YES");
		} else {
			out.println("NO");
		}
	}

	boolean isSorted(int[] a) {
		for (int i = 0; i < a.length - 1; i++) {
			if (a[i] > a[i + 1]) {
				return false;
			}
		}
		return true;
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