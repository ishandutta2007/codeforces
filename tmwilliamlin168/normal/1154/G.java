import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Indrajit Sinha
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskG solver = new TaskG();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskG {
		int n;
		PrintWriter out;

		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int t, i, j, tt, k;
			this.out = out;
			n = in.nextInt();
			int a[] = new int[n];
			ArrayList<Integer> ts[] = new ArrayList[10000001];
			boolean tx[] = new boolean[10000001];
			int mu = 0;
			for (int ii = 0; ii < n; ii++) {
				a[ii] = in.nextInt();
				mu = Math.max(a[ii], mu);
				if (!tx[a[ii]]) {
					ts[a[ii]] = new ArrayList<>();
					tx[a[ii]] = true;
				}
				if (ts[a[ii]].size() < 2)
					ts[a[ii]].add(ii);
			}
			long lcm = Long.MAX_VALUE;
			int ind1 = -1;
			int ind2 = -1;
			for (i = 1; i <= mu; i++) {
				ArrayList<Integer> er = new ArrayList<>();
				for (j = i; j <= mu; j += i) {
					if (er.size() == 2)
						break;
					if (!tx[j])
						continue;
					for (Integer it : ts[j]) {
						er.add(it);
						if (er.size() == 2)
							break;
					}
				}
				if (er.size() == 2) {
					long hh = (long) a[er.get(0)] * a[er.get(1)] / i;
					if (hh < lcm) {
						lcm = hh;
						ind1 = Math.min(er.get(0), er.get(1));
						ind2 = Math.max(er.get(0), er.get(1));
					}
				}
			}
			p(ind1 + 1);
			pn(ind2 + 1);
		}

		void pn(int zx) {
			out.println(zx);
		}

		void p(int zx) {
			out.print(zx + " ");
		}

	}

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
			if (numChars == -1) {
				throw new UnknownError();
			}
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new UnknownError();
				}
				if (numChars <= 0) {
					return -1;
				}
			}
			return buf[curChar++];
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public String next() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			StringBuffer res = new StringBuffer();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));

			return res.toString();
		}

		private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

	}
}