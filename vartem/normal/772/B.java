import java.util.*;
import java.io.*;

public class B {

	class Line {
		double a, b, c;
		public Line(int x1, int y1, int x2, int y2) {
			a = y2 - y1;
			b = x1 - x2;
			c = -(a * x1 + b * y1);
		}
		
		double dist(int x, int y) {
			double d = a * x + b * y + c;
			return Math.abs(d) / Math.sqrt(a * a + b * b);
		}
	}
	
	void solve() {
		int n = in.nextInt();
		int[] x = new int[n], y = new int[n];
		double result = Long.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			x[i] = in.nextInt();
			y[i] = in.nextInt();
		}
		
		for (int i = 0; i < n; i++) {
			Line l = new Line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
			
			
			for (int j = 0; j < n; j++) {
				if (j == i || j == (i + 1) % n) {
					continue;
				}
				result = Math.min(result, l.dist(x[j], y[j]) / 2);
			}
			
			l = new Line(x[i], y[i], x[(i + 2) % n], y[(i + 2) % n]);
			result = Math.min(result, l.dist(x[(i + 1) % n], y[(i + 1) % n]) / 2);
		}
		out.println(result);
	}

	FastScanner in;
	PrintWriter out;

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
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new B().run();
	}
}