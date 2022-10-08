import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		String s = next();
		int u = s.indexOf('R');
		int v = s.indexOf('C');
		if (u == 0 && v != -1 && u < v) {
			String a = s.substring(u + 1, v);
			String b = s.substring(v + 1);
			try {
				int aa = Integer.parseInt(a);
				int bb = Integer.parseInt(b) - 1;
				int pow = 26, len = 1;
				while (bb >= pow) {
					bb -= pow;
					pow *= 26;
					++len;
				}
				String r = "";
				for (int i = 0; i < len; ++i) {
					r = ((char)(bb % 26 + 'A')) + r;
					bb /= 26;
				}
				out.println(r + aa);
				return;
			} catch (NumberFormatException e) {
			}
		}
		u = 0;
		while (u < s.length() && Character.isLetter(s.charAt(u))) {
			++u;
		}
		String a = s.substring(0, u);
		String b = s.substring(u);
		out.println("R" + b + "C" + toInt(a));
	}

	private int toInt(String a) {
		int r = 0;
		for (int i = 0; i < a.length(); ++i) {
			r *= 26;
			r += a.charAt(i) - 'A';
		}
		int pow = 1;
		for (int i = 0; i < a.length(); ++i) {
			r += pow;
			pow *= 26;
		}
		return r;
	}

	Solution() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		eat("");
		
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			solve();
		}
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) throws IOException {
		new Solution();
	}
}