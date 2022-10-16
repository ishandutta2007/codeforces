import java.io.*;
import java.util.*;

public class Homework {

	final String filename = new String("Homework").toLowerCase();

	class Pair {
		char c;
		int occ;

		Pair(char c, int occ) {
			this.c = c;
			this.occ = occ;
		}
	}

	void solve() throws Exception {
		String s = nextToken();
		int k = nextInt();
		char[][] a = new char[k][2];
		for (int i = 0; i < k; i++) {
			a[i] = nextToken().toCharArray();
		}
		ArrayList<Pair> b = new ArrayList<Homework.Pair>();
		int n = s.length();
		for (int i = 0; i < n;) {
			int j = i;
			while (j < n && s.charAt(j) == s.charAt(i)) {
				j++;
			}
			b.add(new Pair(s.charAt(i), j - i));
			i = j;
		}
		int ans = 0;
		for (int j = 0; j < k; j++) {
			for (int i = 0; i < b.size();) {
				int t = i + 1;
				while (t < b.size()
						&& ((a[j][0] == b.get(t - 1).c && a[j][1] == b.get(t).c) || (a[j][1] == b
								.get(t - 1).c && a[j][0] == b.get(t).c))) {
					t++;
				}
				int sumOdd = 0, sumEven = 0;
				for (int f = i; f < t; f += 2) {
					sumEven += b.get(f).occ;
				}
				for (int f = i + 1; f < t; f += 2) {
					sumOdd += b.get(f).occ;
				}
				ans += Math.min(sumEven, sumOdd);
				
				i = t;
			}
		}
		out.println(ans);
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
		new Homework().run();
	}

}