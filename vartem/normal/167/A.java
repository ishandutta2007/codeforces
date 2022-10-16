import java.io.*;
import java.util.*;

public class A {

	final String filename = new String("A").toLowerCase();

	final double eps = 1e-8;
	
	double getTime(double a, double maxV, double dist) {
		double t1 = maxV / a;
		if (t1 * t1 * a / 2 + eps > dist) {
			return Math.sqrt(2 * dist / a);
		}
		dist -= t1 * t1 * a / 2;
		return t1 + (dist / maxV);
	}
	
	void solve() throws Exception {
		int n = nextInt();
		double a = nextInt();
		double dist = nextInt();
		double[] t = new double[n], v = new double[n];
		for (int i = 0; i < n; i++) {
			t[i] = nextInt();
			v[i] = nextInt();
		}
		
		double[] time = new double[n];
		time[0] = t[0] + getTime(a, v[0], dist);
		for (int i = 1; i < n; i++) {
			double curTime = t[i] + getTime(a, v[i], dist);
			time[i] = Math.max(time[i - 1], curTime);
		}
		
		for (double d : time) {
			out.println(d);
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
		new A().run();
	}

}