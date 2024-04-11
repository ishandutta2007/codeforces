import java.io.*;
import java.util.*;

public class CopyOfPermutations {

	final String filename = new String("Permutations").toLowerCase();

	void solve() throws Exception {
		String s = in.readLine();
		int n = s.length();
		int[] cnt = new int[10];
		for (int i = 0; i < n; i++) {
			cnt[(int) (s.charAt(i) - '0')]++;
		}

		int bestAns = 0;
		int bestZeros = 0;
		int bestFirst = 0;

		for (int zeros = 0; zeros <= cnt[0]; zeros++) {
			for (int first = 1; first < 10; first++) {
				int[] cnt1 = cnt.clone();
				int[] cnt2 = cnt.clone();
				cnt1[0] -= zeros;
				cnt2[0] -= zeros;
				int curAns = zeros;
				boolean ok = false;
				if (cnt1[first] > 0 && cnt2[10 - first] > 0) {
					cnt1[first]--;
					cnt2[10 - first]--;
					curAns++;
					
					ok = true;
					for (int i = 0; i < 10; i++) {
						curAns += Math.min(cnt1[i], cnt2[9 - i]);
					}
				}
				if (curAns > bestAns) {
					bestAns = curAns;
					bestZeros = zeros;
					if (ok)
						bestFirst = first;
					else
						bestFirst = -1;
				}
			}
		}

		if (bestAns == 0) {
			out.println(s);
			out.println(s);
		} else {
			ArrayList<Integer> ans1 = new ArrayList<Integer>();
			ArrayList<Integer> ans2 = new ArrayList<Integer>();
			int[] cnt1 = cnt.clone();
			int[] cnt2 = cnt.clone();
			for (int i = 0; i < bestZeros; i++) {
				ans1.add(0);
				ans2.add(0);
			}
			cnt1[0] -= bestZeros;
			cnt2[0] -= bestZeros;

			if (bestFirst != -1) {
				ans1.add(bestFirst);
				ans2.add(10 - bestFirst);
				cnt1[bestFirst]--;
				cnt2[10 - bestFirst]--;

				for (int i = 0; i < 10; i++) {
					int j = 9 - i;
					while (cnt1[i] > 0 && cnt2[j] > 0) {
						ans1.add(i);
						ans2.add(j);
						cnt1[i]--;
						cnt2[j]--;
					}
				}
			}
			for (int i = 0; i < 10; i++) {
				while (cnt1[i] > 0) {
					ans1.add(i);
					cnt1[i]--;
				}
				while (cnt2[i] > 0) {
					ans2.add(i);
					cnt2[i]--;
				}
			}

			Collections.reverse(ans1);
			Collections.reverse(ans2);

			for (int i : ans1) {
				out.print(i);
			}
			out.println();
			for (int i : ans2) {
				out.print(i);
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
		new CopyOfPermutations().run();
	}

}