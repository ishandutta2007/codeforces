import java.io.*;
import java.util.*;

public class Colliders {

	final String filename = new String("Colliders").toLowerCase();

	ArrayList<Integer> getDivisors(int k) {
		ArrayList<Integer> ans = new ArrayList<Integer>();
		for (int i = 2; i * i <= k; i++) {
			if (k % i == 0) {
				ans.add(i);
				while (k % i == 0) {
					k /= i;
				}
			}
		}
		if (k != 1) {
			ans.add(k);
		}
		return ans;
	}

	void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		boolean[] on = new boolean[n + 1];

		int cutOff = 2 * (int) Math.ceil(Math.sqrt(n));
		int[] used = new int[cutOff + 1];
		HashMap<Integer, Integer> bigPrimes = new HashMap<Integer, Integer>();
		for (int i = 0; i < m; i++) {
			char op = nextToken().charAt(0);
			int what = nextInt();
			ArrayList<Integer> divs = getDivisors(what);
			if (op == '+') {
				if (on[what]) {
					out.println("Already on");
					continue;
				}
				
				boolean ok = true;
				int conflict = -1;
				for (int j : divs) {
					if (j <= cutOff) {
						if (used[j] > 0) {
							ok = false;
							conflict = used[j];
							break;
						}
					} else {
						if (bigPrimes.containsKey(j)) {
							ok = false;
							conflict = bigPrimes.get(j);
							break;
						}
					}
				}
				
				if (!ok) {
					out.println("Conflict with " + conflict);
				} else {
					out.println("Success");
					on[what] = true;
					for (int j : divs) {
						if (j <= cutOff) {
							used[j] = what;
						} else {
							bigPrimes.put(j, what);
						}
					}
				}
				
				
			} else {
				if (!on[what]) {
					out.println("Already off");
				} else {
					out.println("Success");
					on[what] = false;
					for (int j : divs) {
						if (j <= cutOff) {
							used[j] = 0;
						} else {
							bigPrimes.remove(j);
						}
					}
				}
			}
		}
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
		new Colliders().run();
	}

}