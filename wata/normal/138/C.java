import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	
	void run() {
		int n = sc.nextInt(), m = sc.nextInt();
		int[] as = new int[n], hs = new int[n], ls = new int[n], rs = new int[n];
		TreeSet<Integer> set = new TreeSet<Integer>();
		for (int i = 0; i < n; i++) {
			as[i] = sc.nextInt();
			hs[i] = sc.nextInt();
			ls[i] = sc.nextInt();
			rs[i] = sc.nextInt();
			set.add(as[i] + 1);
			set.add(as[i] + hs[i] + 1);
			set.add(as[i]);
			set.add(as[i] - hs[i]);
		}
		set.add(-2010000000);
		set.add(2010000000);
		Integer[] xs = set.toArray(new Integer[0]);
		Seg seg = new Seg(xs.length);
		for (int i = 0; i < n; i++) {
			seg.query(binarySearch(xs, as[i] + 1), binarySearch(xs, as[i] + hs[i] + 1), 1.0 - rs[i] * 0.01);
			seg.query(binarySearch(xs, as[i] - hs[i]), binarySearch(xs, as[i]), 1.0 - ls[i] * 0.01);
		}
		double res = 0;
		for (int i = 0; i < m; i++) {
			int b = sc.nextInt(), z = sc.nextInt();
			int x = binarySearch(xs, b);
			if (x < 0) x = -x - 2;
			res += z * seg.query(x);
		}
		System.out.printf("%.10f%n", res);
	}
	
	class Seg {
		int N;
		double[] prob;
		Seg(int n) {
			N = Integer.highestOneBit(n) << 1;
			prob = new double[N * 2 + 1];
			fill(prob, 1.0);
		}
		double query(int k) {
			double res = 1;
			for (int i = N + k; i > 0; i >>= 1) {
				res *= prob[i];
			}
			return res;
		}
		void query(int s, int t, double p) {
			while (0 < s && s + (s & -s) <= t) {
				int i = (N + s) / (s & -s);
				prob[i] *= p;
				s += s & -s;
			}
			while (s < t) {
				int i = (N + t) / (t & -t) - 1;
				prob[i] *= p;
				t -= t & -t;
			}
		}
	}
	
	class Scanner {
		InputStream in;
		byte[] buf = new byte[1 << 10];
		int p, n;
		boolean[] isSpace = new boolean[128];
		Scanner(InputStream in) {
			this.in = in;
			isSpace[' '] = isSpace['\n'] = isSpace['\r'] = isSpace['\t'] = true;
		}
		int read() {
			if (n == -1) return -1;
			if (p >= n) {
				p = 0;
				try {
					n = in.read(buf);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
				if (n <= 0) return -1;
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
		new C().run();
	}
}