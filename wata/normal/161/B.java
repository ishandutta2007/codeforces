import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class B {
	Scanner sc = new Scanner(System.in);
	
	void run() {
		int n = sc.nextInt(), k = sc.nextInt();
		int[] cs = new int[n], ts = new int[n];
		for (int i = 0; i < n; i++) {
			cs[i] = sc.nextInt() * 2;
			ts[i] = sc.nextInt();
		}
		Entry[] es = new Entry[n];
		for (int i = 0; i < n; i++) es[i] = new Entry(cs[i], i);
		sort(es);
		int n1 = 0;
		for (int i = 0; i < n; i++) {
			if (ts[i] == 1) n1++;
		}
		long res = 0;
		for (int i = 0; i < n; i++) res += cs[i];
		int[] id = new int[n];
		if (n1 >= k) {
			int p = k;
			for (Entry e : es) {
				if (ts[e.p] == 1) {
					p = max(0, p - 1);
					id[e.p] = p;
				} else {
					id[e.p] = 0;
				}
			}
			for (int i = 0; i < k; i++) {
				int min = Integer.MAX_VALUE;
				for (int j = 0; j < n; j++) if (id[j] == i) min = min(min, cs[j]);
				res -= min / 2;
			}
		} else {
			int p = 0;
			for (int i = 0; i < n; i++) if (ts[i] == 1) {
				id[i] = p++;
				res -= cs[i] / 2;
			}
			for (int i = 0; i < n; i++) if (ts[i] == 2) {
				id[i] = p++;
				if (p >= k) p = k - 1;
			}
		}
		System.out.println(res / 2 + "." + (res % 2 == 0 ? "0" : "5"));
		for (int i = 0; i < k; i++) {
			int m = 0;
			for (int j = 0; j < n; j++) if (id[j] == i) m++;
			System.out.print(m);
			for (int j = 0; j < n; j++) if (id[j] == i) {
				System.out.print(" " + (j + 1));
			}
			System.out.println();
		}
	}
	
	class Entry implements Comparable<Entry> {
		int v, p;
		Entry(int v, int p) {
			this.v = v;
			this.p = p;
		}
		public int compareTo(Entry o) {
			return o.v - v;
		}
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
		new B().run();
	}
}