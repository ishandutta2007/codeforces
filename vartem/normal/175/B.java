import java.io.*;
import java.util.*;

public class B {

	final String filename = new String("B").toLowerCase();

	void solve() throws Exception {
		Map<String, Integer> result = new HashMap<String, Integer>();
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			String name=  nextToken();
			int res = nextInt();
			if (!result.containsKey(name)) {
				result.put(name, res);
			}
			int prevRes = result.get(name);
			result.put(name, Math.max(res, prevRes));
		}
		String[] ans1 = new String[result.size()];
		String[] ans2 = new String[result.size()];
		int temp = 0;
		n = result.size();
		for (String name1 : result.keySet()) {
			int res1 = result.get(name1);
			int countWorse = 0;
			ans1[temp] = name1;
			
			for (String name2 : result.keySet()) {
				int res2 = result.get(name2);
				if (res1 < res2) {
					countWorse++;
				}
			}
			if (countWorse * 100 > 50 * n) {
				ans2[temp] = "noob";
			} else if (countWorse * 100 > 20 * n) {
				ans2[temp] = "random";
			} else if (countWorse * 100 > 10 * n) {
				ans2[temp] = "average";
			} else if (countWorse * 100 > n) {
				ans2[temp] = "hardcore";
			} else {
				ans2[temp] = "pro";
			}
			temp++;
		}
		out.println(result.size());
		for (int i = 0; i < result.size(); i++) {
			out.println(ans1[i] + " " + ans2[i]);
		}
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
		new B().run();
	}

}