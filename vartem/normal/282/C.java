import java.io.*;
import java.util.*;

public class C {

	final String filename = new String("C").toLowerCase();

	boolean solve(String a, String b) throws Exception {
		if (a.length() != b.length()) {
			return false;
		}

		if (a.length() == 1) {
			return a.equals(b);
		}
		if (a.equals(b)) {
			return true;
		}

		int ones1 = 0, ones2 = 0;
		for (int i = 0; i < a.length(); i++) {
			ones1 += (a.charAt(i) - '0');
			ones2 += (b.charAt(i) - '0');
		}

		if (ones1 == 0 || ones2 == 0) {
			return false;
		}

		return true;
	}

	boolean solveStupid(String a, String b) {
		Set<String> vis = new HashSet<String>();
		Queue<String> queue = new ArrayDeque<>();
		queue.add(a);
		vis.add(a);
		while (!queue.isEmpty()) {
			String cur = queue.poll();
			if (cur.equals(b)) {
				return true;
			}
			for (int i = 0; i < cur.length() - 1; i++) {
				char[] c = cur.toCharArray();
				int x = c[i] - '0';
				int y = c[i + 1] - '0';
				int p = x ^ y;
				int q = x | y;

				c[i] = (char) (p + '0');
				c[i + 1] = (char) (q + '0');
				String newCur = new String(c);
				if (!vis.contains(newCur)) {
					vis.add(newCur);
					queue.add(newCur);
				}

				c[i] = (char) (q + '0');
				c[i + 1] = (char) (p + '0');
				newCur = new String(c);
				if (!vis.contains(newCur)) {
					vis.add(newCur);
					queue.add(newCur);
				}
			}
		}
		return false;
	}

	public void run() {
		try {
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

			if (solve(nextToken(), nextToken())) {
				out.println("YES");
			} else {
				out.println("NO");
 }

//			int n = 8;
//			for (int IT = 0; IT < 10000; IT++) {
//				String a = randomString(n);
//				String b = randomString(n);
//				if (solve(a, b) != solveStupid(a, b)) {
//					System.err.println(IT);
//					System.err.println(a + " " + b);
//					System.err.println(solve(a, b));
//					System.err.println(solveStupid(a, b));
//					break;
//				}
//			}

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	Random rng = new Random(123);

	private String randomString(int n) {
		String ans = "";
		for (int i = 0; i < n; i++) {
			ans += (char) ('0' + rng.nextInt(2));
		}
		return ans;
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
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
		new C().run();
	}

}