import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class D {
	Scanner sc = new Scanner(System.in);
	
	void run() {
		int n = sc.nextInt(), k = sc.nextInt();
		V[] vs = new V[n];
		for (int i = 0; i < n; i++) vs[i] = new V();
		for (int i = 0; i < n - 1; i++) {
			int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
			vs[u].add(vs[v]);
			vs[v].add(vs[u]);
		}
		System.out.println(count(vs[0], k));
	}
	
	long[] num = new long[1000];
	
	long count(V v, int k) {
		size(v, null);
		v = choose(v, null, v.size);
		v.used = true;
		long res = 0;
		for (V u : v) if (!u.used) {
			res += count(u, k);
		}
		v.used = false;
		dist(v, null, 0, 1);
		for (V u : v) if (!u.used) {
			dist(u, v, 1, -1);
			res += count(u, v, k - 1);
		}
		num[0] = 0;
		return res;
	}
	
	long count(V v, V p, int k) {
		if (k < 0) return 0;
		long res = num[k];
		for (V u : v) if (!u.used && u != p) res += count(u, v, k - 1);
		return res;
	}
	
	void dist(V v, V p, int d, int add) {
		if (d >= num.length) return;
		num[d] += add;
		for (V u : v) if (!u.used && u != p) dist(u, v, d + 1, add);
	}
	
	int size(V v, V p) {
		v.size = 1;
		for (V u : v) if (!u.used && u != p) v.size += size(u, v);
		return v.size;
	}
	
	V choose(V v, V p, int n) {
		for (V u : v) if (!u.used && u != p && u.size * 2 > n) return choose(u, v, n);
		return v;
	}
	
	class V extends ArrayList<V> {
		boolean used;
		int size;
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
		new D().run();
	}
}