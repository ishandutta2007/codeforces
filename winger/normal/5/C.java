import java.io.*;
import java.util.*;

public class Solution {

	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		String s = next();
		int maxCount = 1, max = 0;
		ArrayList<Integer> startStack = new ArrayList<Integer>();
		startStack.add(-1);
		for (int i = 0; i < s.length(); ++i) {
			if (s.charAt(i) == '(') {
				startStack.add(i);
			} else {
				if (startStack.size() == 1) {
					startStack.set(0, i);
				} else {
					startStack.remove(startStack.size() - 1);
					int len = i - startStack.get(startStack.size() - 1);
					if (len > max) {
						max = len;
						maxCount = 0;
					}
					if (len == max) {
						++maxCount;
					}
				}
			}
		}
		out.println(max + " " + maxCount);
	}

	Solution() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);

		eat("");

		solve();

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