import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
	
	void run() {
		int n = sc.nextInt(), m = sc.nextInt(), x = sc.nextInt(), y = sc.nextInt();
		int[] a = new int[n], b = new int[m];
		for (int i = 0; i < n; i++) a[i] = sc.nextInt();
		for (int i = 0; i < m; i++) b[i] = sc.nextInt();
		int[] ans = new int[n];
		fill(ans, -1);
		int num = 0;
		int p = 0, q = 0;
		while (p < n && q < m) {
			if (a[p] - x > b[q]) q++;
			else if (a[p] + y < b[q]) p++;
			else {
				ans[p] = q;
				p++;
				q++;
				num++;
			}
		}
		System.out.println(num);
		for (int i = 0; i < n; i++) if (ans[i] >= 0) {
			out.println((i + 1) + " " + (ans[i] + 1));
		}
		out.flush();
	}
	
	class Scanner {
		InputStream in;
		byte[] buf = new byte[1 << 10];
		int p, m;
		boolean[] isSpace = new boolean[128];
		Scanner(InputStream in) {
			this.in = in;
			isSpace[' '] = isSpace['\n'] = isSpace['\r'] = isSpace['\t'] = true;
		}
		int read() {
			if (m == -1) return -1;
			if (p >= m) {
				p = 0;
				try {
					m = in.read(buf);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
				if (m <= 0) return -1;
			}
			return buf[p++];
		}
		boolean hasNext() {
			int c = read();
			while (c >= 0 && isSpace[c]) c = read();
			if (c == -1) return false;
			p--;
			return true;
		}
		String next() {
			if (!hasNext()) throw new InputMismatchException();
			StringBuilder sb = new StringBuilder();
			int c = read();
			while (c >= 0 && !isSpace[c]) {
				sb.append((char)c);
				c = read();
			}
			return sb.toString();
		}
		int nextInt() {
			if (!hasNext()) throw new InputMismatchException();
			int c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9') throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (c >= 0 && !isSpace[c]);
			return res * sgn;
		}
		long nextLong() {
			if (!hasNext()) throw new InputMismatchException();
			int c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9') throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (c >= 0 && !isSpace[c]);
			return res * sgn;
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new A().run();
	}
}