import java.io.*;
import java.util.*;

public class C {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			String string = in.nextToken();
			String[] s = string.split("\\.");
			int ip = 0;
			for (String str : s) {
				ip = (ip << 8) | (Integer.parseInt(str));
			}
			a[i] = ip;
		}
		
		shuffle(a);
		Arrays.sort(a);
		
		for (int ones = 1; ones <= 32; ones++) {
			int count = 1;
			int mask = (-1) << (32 - ones);
			for (int i = 1; i < n; i++) {
				if ((a[i] & mask) != (a[i - 1] & mask)) {
					count++;
				}
			}
			if (count == k) {
				out.println(toIp(mask));
				return;
			}
		}
		
		out.println(-1);
	}

	private String toIp(int ones) {
		String ans = "";
		ans = (ones & 255) + "";
		ones >>>= 8;
		for (int i = 1; i < 4; i++) {
			int cur = (ones & 255);
			ones >>>= 8;
			ans = cur + "." + ans;
		}
		return ans;
	}

	private void shuffle(int[] a) {
		Random rng = new Random(12321);
		for (int i = 1; i < a.length; i++) {
			int t = rng.nextInt(i + 1);
			int tmp = a[i];
			a[i] = a[t];
			a[t] = tmp;
		}
	}

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new C().run();
	}
}