import java.io.*;
import java.util.*;

public class B {

	final String filename = new String("B").toLowerCase();

	void solve() throws Exception {
		int a = nextInt();
		int b = nextInt();
		int m = nextInt();
		int r = nextInt();
		int[] vis = new int[m];
		int time = 1;
		while (vis[r] == 0) {
			vis[r] = time++;
			r = (a * r + b) % m;
		}
		out.println(time - vis[r]);
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