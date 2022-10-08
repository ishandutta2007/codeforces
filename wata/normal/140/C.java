import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	
	void run() {
		int n = sc.nextInt();
		int[] r = new int[n];
		for (int i = 0; i < n; i++) r[i] = sc.nextInt();
		sort(r);
		int lb = 0, ub = n + 1;
		while (ub - lb > 1) {
			int mid = (lb + ub) / 2;
			int num = 0;
			for (int i = 0; i < n; ) {
				int s = i;
				while (i < n && r[i] == r[s]) i++;
				num += min(mid, i - s);
			}
			if (num >= mid * 3) {
				lb = mid;
			} else {
				ub = mid;
			}
		}
		System.out.println(lb);
		int[] is = new int[n];
		int num = 0;
		for (int i = 0; i < n; ) {
			int s = i;
			while (i < n && r[i] == r[s]) i++;
			for (int j = s; j < i && j < s + lb; j++) {
				is[num++] = r[j];
			}
		}
		for (int i = 0; i < lb; i++) {
			System.out.println(is[i + lb * 2] + " " + is[i + lb] + " " + is[i]);
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