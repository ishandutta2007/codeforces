import java.io.*;
import java.util.*;

public class A {

	public void solve() {
		String s = in.nextToken(), t = in.nextToken();
		s = canonize(s);
		t = canonize(t);

		if (s.length() < t.length()) {
			out.println("<");
		} else if (s.length() > t.length()) {
			out.println(">");
		} else {

			int cmp = s.compareTo(t);
			if (cmp < 0) {
				out.println("<");
			} else if (cmp > 0) {
				out.println(">");
			} else {
				out.println("=");
			}
		}
	}

	private String canonize(String s) {
		int n = s.length();
		char[] c = new char[n + 1];
		for (int i = 0; i < n; i++) {
			c[i + 1] = s.charAt(i);
		}
		c[0] = '0';

		TreeSet<Integer> conflict = new TreeSet<>();
		for (int i = 0; i < n; i++) {
			if (c[i] == '1' && c[i + 1] == '1') {
				conflict.add(i);
			}
		}
		
		while (!conflict.isEmpty()) {
			int item = conflict.pollFirst();
			
			conflict.remove(item + 1);
			
			c[item] = c[item + 1] = '0';
			c[item - 1] = '1';
			
			if (item - 2 >= 0 && c[item - 2] == '1') {
				conflict.add(item - 2);
			}
		}
		
		
		int start = 0;
		while (start < c.length && c[start] == '0') {
			start++;
		}
		if (start == c.length) {
			return "0";
		} else {
			return new String(c).substring(start);
		}
	}

	FastScanner in;
	PrintWriter out;

	public void run() {
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

		public FastScanner(String name) {
			try {
				br = new BufferedReader(new FileReader(name));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
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
		new A().run();
	}
}