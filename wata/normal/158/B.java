import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class B {
	Scanner sc = new Scanner(System.in);
	
	void run() {
		int n = sc.nextInt();
		int[] num = new int[5];
		for (int i = 0; i < n; i++) num[sc.nextInt()]++;
		int res = num[4] + num[3];
		num[1] -= num[3];
		res += num[2] / 2;
		if (num[2] % 2 != 0) {
			num[1] -= 2;
			res++;
		}
		if (num[1] > 0) res += (num[1] + 3) / 4;
		System.out.println(res);
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
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new B().run();
	}
}