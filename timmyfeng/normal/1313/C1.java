import java.io.*;
import java.util.*;
import javafx.util.*;

public class Solution {
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		A solver = new A();
		solver.solve(in, out);
		out.close();
	}

	static class A {
		public void solve(InputReader in, PrintWriter out) {
			int n = in.nextInt();
			int[] m = new int[n];
			for (int i = 0; i < n; ++i) {
				m[i] = in.nextInt();
			}

			Stack<Pair<Integer, Integer>> stk = new Stack<>();
			long[] val1 = new long[n];
			long cur = 0;
			for (int i = 0; i < n; ++i) {
				int len = 1;
				while (!stk.empty() && stk.peek().getKey() > m[i]) {
					len += stk.peek().getValue();
					cur -= (long)stk.peek().getKey() * stk.peek().getValue();
					stk.pop();
				}
				cur += (long)m[i] * len;
				stk.push(new Pair<Integer, Integer>(m[i], len));
				val1[i] = cur;
			}

			stk = new Stack<>();
			long[] val2 = new long[n];
			cur = 0;
			for (int i = n - 1; i >= 0; --i) {
				int len = 1;
				while (!stk.empty() && stk.peek().getKey() > m[i]) {
					len += stk.peek().getValue();
					cur -= (long)stk.peek().getKey() * stk.peek().getValue();
					stk.pop();
				}
				cur += (long)m[i] * len;
				stk.push(new Pair<Integer, Integer>(m[i], len));
				val2[i] = cur;
			}

			long mx = 0;
			int ans = 0;
			for (int i = 0; i < n; ++i) {
				long res = val1[i] + val2[i] - m[i];
				if (res > mx) {
					mx = res;
					ans = i;
				}
			}

			for (int i = ans; i > 0; --i) {
				if (m[i - 1] > m[i]) {
					m[i - 1] = m[i];
				}
			}
			for (int i = ans; i + 1 < n; ++i) {
				if (m[i + 1] > m[i]) {
					m[i + 1] = m[i];
				}
			}

			for (int i : m) {
				out.print(i + " ");
			}
			out.println();
		}
	}

	static class InputReader {
		public BufferedReader read;
		public StringTokenizer token;

		public InputReader(InputStream str) {
			read = new BufferedReader(new InputStreamReader(str), 1 << 15);
		}

		public String next() {
			while (token == null || !token.hasMoreTokens()) {
				try {
					token = new StringTokenizer(read.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return token.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}