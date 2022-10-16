import java.io.*;
import java.util.*;

public class Stones {

	final String filename = new String("Stones").toLowerCase();

	final int MAX = 100000;
	
	void solve() throws Exception {
		int n = nextInt();
		Integer[] a = new Integer[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		Arrays.sort(a, new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				return -o1.compareTo(o2);
			}
		});
		int q = nextInt();
		long[] prefSum = new long[n];
		for (int i = 0; i < n; i++) {
			prefSum[i] = a[i];
			if (i > 0) {
				prefSum[i] += prefSum[i - 1];
			}
		}
		long[] ans = new long[MAX + 1];
		Arrays.fill(ans, -1);
		for (int i = 0; i < q; i++) {
			int k = nextInt();
			if (ans[k] != -1) {
				out.print(ans[k] + " ");
				continue;
			}
			long res = 0;
			long start = 0;
			long curPow = 1;
			long curMul = 0;
			while (start < n) {
				long end = Math.min(start + curPow, n);
				end--;
				long sum = prefSum[(int) end];
				if (start > 0) {
					sum -= prefSum[(int) (start - 1)];
				}
				res += sum * curMul;
					
				start = end + 1;
				curPow *= k;
				curMul++;
			}
			ans[k] = res;
			out.print(res + " ");
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
		new Stones().run();
	}

}