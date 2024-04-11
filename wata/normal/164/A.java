import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	void run() {
		int n = sc.nextInt(), m = sc.nextInt();
		V[] vs = new V[n];
		for (int i = 0; i < n; i++) vs[i] = new V();
		for (int i = 0; i < n; i++) vs[i].state = sc.nextInt();
		for (int i = 0; i < m; i++) {
			int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
			vs[u].add(vs[v]);
		}
		Queue<V> que = new LinkedList<V>();
		for (int i = 0; i < n; i++) if (vs[i].state == 1) {
			que.offer(vs[i]);
			vs[i].from1 = true;
		}
		while (!que.isEmpty()) {
			V v = que.poll();
			for (V u : v.es) if (!u.from1) {
				que.offer(u);
				u.from1 = true;
			}
		}
		for (int i = 0; i < n; i++) if (vs[i].state == 2) {
			que.offer(vs[i]);
			vs[i].to2 = true;
		}
		while (!que.isEmpty()) {
			V v = que.poll();
			if (v.state == 1) continue;
			for (V u : v.fs) if (!u.to2) {
				que.offer(u);
				u.to2 = true;
			}
		}
		PrintWriter out = new PrintWriter(System.out);
		for (int i = 0; i < n; i++) {
			if (vs[i].from1 && vs[i].to2) {
				out.println(1);
			} else {
				out.println(0);
			}
		}
		out.flush();
		out.close();
	}
	
	class V {
		ArrayList<V> es = new ArrayList<V>(), fs = new ArrayList<V>();
		int state;
		boolean from1, to2;
		void add(V v) {
			es.add(v);
			v.fs.add(this);
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
		new A().run();
	}
}