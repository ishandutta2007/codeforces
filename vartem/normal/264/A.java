import java.io.*;
import java.util.*;

public class A {

	FastScanner in;
	PrintWriter out;
	final String fileName = "A".toLowerCase();

	
	
	void solve() {
		String s = in.next();
		Deque<Integer> d = new ArrayDeque<>();
		int n = s.length();
		d.add(n);
		for (int i = s.length() - 2; i >= 0; i--) {
			if (s.charAt(i) == 'l') {
				d.addLast(i + 1);
			} else {
				d.addFirst(i + 1);
			}
		}
		
		for (int i : d) {
			out.println(i);
		}
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