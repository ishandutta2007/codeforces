import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class B {
	Scanner sc = new Scanner(System.in);
	
	void run() {
		int n = sc.nextInt();
		int[][] p = new int[n + 1][n];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < n; j++) {
				p[i][sc.nextInt() - 1] = j;
			}
		}
		for (int i = 0; i < n; i++) {
			int most = n, q = -1, r = -1;
			for (int j = 0; j < n; j++) {
				if (i != j && (q < 0 || p[n][q] > p[n][j])) q = j;
				if (q >= 0 && most > p[i][q]) {
					most = p[i][q];
					r = j;
				}
			}
			if (i > 0) System.out.print(" ");
			System.out.print(r + 1);
		}
		System.out.println();
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
		new B().run();
	}
}