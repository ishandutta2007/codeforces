import java.io.*;
import java.util.*;

public class B {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), T = in.nextInt();
		double c = in.nextDouble();

		double[] a = new double[n], prefSum = new double[n + 1];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextDouble();
			prefSum[i + 1] = a[i] + prefSum[i];
		}
		
		double[] approx = new double[n];
		double mean = 0;
		for (int i = 0; i < n; i++) {
			mean = (mean + a[i] / T) / c;
			approx[i] = mean;
		}
		
		int m = in.nextInt();
		for (int i = 0; i < m; i++) {
			int time = in.nextInt();
			double real = (prefSum[time] - prefSum[time - T]) / T;
			out.println(real + " " + approx[time - 1] + " " + Math.abs(real - approx[time - 1]) / real);
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

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
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
		new B().run();
	}
}