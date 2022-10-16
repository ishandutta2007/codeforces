import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Bre {

	FastScanner in;
	PrintWriter out;

	void solve() throws IOException {
		String s = in.br.readLine();

		Matcher m = Pattern.compile("([(\\w)\\?\\!\\.\\,]+)|(\".*?\")").matcher(s);
		while (m.find()) {
			String str = m.group();
			if (str.charAt(0) == '"') {
				str = str.substring(1, str.length() - 1);
			}
			out.println("<" + str + ">");
		}
	}

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		try {
			solve();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String nextToken() {
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
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new Bre().run();
	}
}