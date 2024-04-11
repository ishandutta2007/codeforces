import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.io.*;

public class B {
	Scanner sc = new Scanner(System.in);
	
	void run() {
		char[] cs = sc.next().toCharArray();
		sort(cs);
		int[] num = new int[10];
		for (char c : cs) num[c - '0']++;
		int res = 0, r0 = 0;
		for (int n0 = 0; n0 <= num[0]; n0++) {
			num[0] -= n0;
			if (res < n0) {
				res = n0;
			}
			for (int i = 1; i < 10; i++) {
				int j = (10 - i) % 10;
				int[] n1 = num.clone();
				int[] n2 = num.clone();
				if (--n1[i] < 0) continue;
				if (--n2[j] < 0) continue;
				int c = 1 + n0;
				for (int k = 0; k < 10; k++) {
					int k2 = (9 - k);
					int tmp = min(n1[k], n2[k2]);
					c += tmp;
					n1[k] -= tmp;
					n2[k2] -= tmp;
				}
				if (res < c) {
					res = c;
					r0 = n0;
				}
			}
			num[0] += n0;
		}
		num[0] -= r0;
		String r1 = new StringBuilder(new String(cs)).reverse().toString(), r2 = r1;
		for (int i = 1; i < 10; i++) {
			int j = (10 - i) % 10;
			int[] n1 = num.clone();
			int[] n2 = num.clone();
			if (--n1[i] < 0) continue;
			if (--n2[j] < 0) continue;
			int c = 1 + r0;
			StringBuilder sb1 = new StringBuilder();
			StringBuilder sb2 = new StringBuilder();
			for (int k = 0; k < r0; k++) sb1.append('0');
			for (int k = 0; k < r0; k++) sb2.append('0');
			sb1.append((char)('0' + i));
			sb2.append((char)('0' + j));
			for (int k = 0; k < 10; k++) {
				int k2 = (9 - k);
				int tmp = min(n1[k], n2[k2]);
				c += tmp;
				n1[k] -= tmp;
				n2[k2] -= tmp;
				for (int a = 0; a < tmp; a++) {
					sb1.append((char)('0' + k));
					sb2.append((char)('0' + k2));
				}
			}
			if (res == c) {
				for (int k = 0; k < 10; k++) {
					while (n1[k]-- > 0) sb1.append((char)('0' + k));
					while (n2[k]-- > 0) sb2.append((char)('0' + k));
				}
				r1 = sb1.reverse().toString();
				r2 = sb2.reverse().toString();
				break;
			}
		}
		System.out.println(r1);
		System.out.println(r2);
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