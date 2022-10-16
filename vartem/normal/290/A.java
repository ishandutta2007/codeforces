import java.io.*;
import java.util.*;

public class A {

	FastScanner in;
	PrintWriter out;
	final String fileName = "A".toLowerCase();
	
	String[] ans = new String[]{
			"Washington",
			"Adams",
			"Jefferson",
			"Madison",
			"Monroe",
			"Adams",
			"Jackson",
			"Van Buren",
			"Harrison",
			"Tyler",
			"Polk",
			"Taylor",
			"Fillmore",
			"Pierce",
			"Buchanan",
			"Lincoln",
			"Johnson",
			"Grant",
			"Hayes",
			"Garfield",
			"Arthur",
			"Cleveland",
			"Harrison",
			"Cleveland",
			"McKinley",
			"Roosevelt",
			"Taft",
			"Wilson",
			"Harding",
			"Coolidge",
			"Hoover",
			"Roosevelt",
			"Truman",
			"Eisenhower",
			"Kennedy",
			"Johnson",
			"Nixon",
			"Ford",
			"Carter",
			"Reagan",
			};


	void solve() {
		int n = in.nextInt() - 1;
		out.println(ans[n]);
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