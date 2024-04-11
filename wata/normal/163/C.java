import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
	
	void run() {
		int n = sc.nextInt(), L = sc.nextInt(), v1 = sc.nextInt(), v2 = sc.nextInt();
		long[] a = new long[n * 2 + 1];
		for (int i = 0; i < n; i++) a[i] = sc.nextInt();
		for (int i = 0; i < n; i++) a[n + i] = 2 * L + a[i];
		a[2 * n] = L * 10L;
		double x = (double)v2 * L / (v1 + v2);
		double s = a[0];
		int t = 0;
		while (a[t] < s + x) t++;
		double[] res = new double[n + 1];
		for (int i = 0; i < n; ) {
			if (a[t] - (s + x) < a[i + 1] - s) {
				res[t - i - 1] += a[t] - (s + x);
				s += a[t] - (s + x);
				t++;
			} else {
				res[t - i - 1] += a[i + 1] - s;
				s = a[++i];
			}
		}
		for (int i = 0; i <= n; i++) {
			out.printf("%.12f%n", res[i] / (2 * L));
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
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new C().run();
	}
}