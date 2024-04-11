import java.io.*;
import java.util.*;

public class B {

	final String filename = new String("B").toLowerCase();

	double[] solve3(double s, double a, double b, double c) throws Exception {
		if (a == 0) {
			double[] res = solve2(s, b, c);
			return new double[] { 0, res[0], res[1] };
		}
		if (b == 0) {
			double[] res = solve2(s, a, c);
			return new double[] { res[0], 0, res[1] };
		}
		if (c == 0) {
			double[] res = solve2(s, a, b);
			return new double[] { res[0], res[1], 0 };
		}
		double sum = a + b + c;
		double x = a * s / sum;
		double y = b * s / sum;
		double z = c * s / sum;
		return new double[] { x, y, z };
	}

	double[] solve2(double s, double a, double b) throws Exception {
		if (a == 0) {
			return new double[] { 0, s };
		}
		if (b == 0) {
			return new double[] { s, 0 };
		}
		double x = a * s / (a + b);
		double y = b * s / (a + b);
		return new double[] { x, y };
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");

			double s = nextInt();
			double a = nextInt(), b = nextInt(), c = nextInt();
			double[] res = solve3(s, a, b, c);
			out.println(res[0] + " " + res[1] + " " + res[2]);

			// System.err.println(Math.log(res[0]) + Math.log(res[1]) +
			// Math.log(res[2]));

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