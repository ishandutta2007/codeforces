import java.io.*;
import java.util.*;

public class A {

	final String filename = new String("A").toLowerCase();

	void solve() throws Exception {
		int n = nextInt();
		int count = 0;
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			if (s.indexOf('+') >= 0) {
				count++;
			} else {
				count--;
			}
		}
		
		out.println(count);
	}

	public void run() {
		try {
			//in = new BufferedReader(new FileReader("input.txt"));
			//out = new PrintWriter("output.txt");
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

			solve();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
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
		new A().run();
	}

}