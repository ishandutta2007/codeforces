import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class B {
	Scanner sc = new Scanner(System.in);
	
	void run() {
		int n = sc.nextInt(), k = sc.nextInt(), h = sc.nextInt();
		int[] m = new int[n];
		for (int i = 0; i < n; i++) m[i] = sc.nextInt();
		int[] v = new int[n];
		for (int i = 0; i < n; i++) v[i] = sc.nextInt();
		Entry[] es = new Entry[n];
		for (int i = 0; i < n; i++) es[i] = new Entry(m[i], v[i], i);
		sort(es);
		double left = 0, right = 1e20;
		for (int i = 0; i < 200; i++) {
			double mid = (left + right) / 2;
			int p = k;
			for (int j = n - 1; j >= 0 && p > 0; j--) {
				if (p * h <= mid * es[j].v) p--;
			}
			if (p == 0) right = mid;
			else left = mid;
		}
		int[] res = new int[k];
		int p = k;
		for (int j = n - 1; j >= 0 && p > 0; j--) {
			if (p * h <= right * es[j].v) res[--p] = es[j].id;
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < k; i++) {
			if (i > 0) sb.append(' ');
			sb.append(res[i] + 1);
		}
		System.out.println(sb);
	}
	
	class Entry implements Comparable<Entry> {
		int m, v, id;
		Entry(int m, int v, int id) {
			this.m = m;
			this.v = v;
			this.id = id;
		}
		public int compareTo(Entry o) {
			if (m != o.m) return m - o.m;
			return v - o.v;
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
		new B().run();
	}
}