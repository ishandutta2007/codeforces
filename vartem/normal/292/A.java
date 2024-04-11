import java.io.*;
import java.util.*;

public class A {

	FastScanner in;
	PrintWriter out;
	final String fileName = "A".toLowerCase();

	void solve() {
		int n = in.nextInt();
		int maxQueue = 0;
		
		int lastTime = 0;
		int msgs = 0;
		
		for (int i = 0; i < n; i++) {
			int t = in.nextInt();
			int c = in.nextInt();
			
			msgs = Math.max(0, msgs - (t - lastTime));
			msgs += c;
			maxQueue = Math.max(msgs, maxQueue);
			lastTime = t;
		}
		
		out.println((lastTime + msgs) + " " + maxQueue);
	}

	void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
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
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new A().run();
	}
}