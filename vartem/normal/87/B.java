import java.io.*;
import java.util.*;

public class Types {

	void solve() throws Exception {
		int n = nextInt();
		HashMap<String, Integer> hm = new HashMap<String, Integer>();
		hm.put("void", 0);
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			if (s.equals("typeof")) {
				String t = nextToken();

				int a = 0;
				int st = 0;
				int j = 0;
				while (t.charAt(j) == '&') {
					j++;
					a++;
				}

				int k = t.length() - 1;
				while (t.charAt(k) == '*') {
					k--;
					st++;
				}

				String old = t.substring(j, k + 1);

				if (!hm.containsKey(old))
					out.println("errtype");
				else {
					int f = hm.get(old);
					if (f == -1 || f + st - a < 0)
						out.println("errtype");
					else {
						out.print("void");
						for (int g = 0; g < f + st - a; g++)
							out.print('*');
						out.println();
					}
				}
			} else {
				String t = nextToken();
				String newt = nextToken();
				int a = 0;
				int st = 0;
				int j = 0;
				while (t.charAt(j) == '&') {
					j++;
					a++;
				}

				int k = t.length() - 1;
				while (t.charAt(k) == '*') {
					k--;
					st++;
				}

				String old = t.substring(j, k + 1);
				if (!hm.containsKey(old)) {
					hm.put(newt, -1);
					continue;
				} else {
					int f = hm.get(old);
					if (f == -1 || f - a + st < 0)
						hm.put(newt, -1);
					else
						hm.put(newt, f + st - a);
				}
			}
		}
	}

	void run() {
		try {
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
	StringTokenizer st;
	PrintWriter out;
	final String filename = new String("Types").toLowerCase();

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
		new Types().run();
	}

}