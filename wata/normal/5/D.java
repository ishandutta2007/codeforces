import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	void run() {
		double a = sc.nextDouble(), v = sc.nextDouble();
		double L = sc.nextDouble(), d = sc.nextDouble(), w = sc.nextDouble();
		w = min(w, v);
		double t = 0;
		if (w * w / (2 * a) <= d) {
			if ((v * v + 2 * v * (v - w) - (v - w) * (v - w)) / (2 * a) <= d) {
				t = (2 * v - w) / a + (d - (v * v + 2 * v * (v - w) - (v - w) * (v - w)) / (2 * a)) / v;
			} else {
				double A = a, B = w, C = (w * w) / (2 * a) - d;
				t = w / a + (-B + sqrt(max(0, B * B - A * C))) / A * 2;
			}
			if ((2 * w * (v - w) + (v - w) * (v - w)) / (2 * a) <= L - d) {
				t += (v - w) / a + (L - d - (2 * w * (v - w) + (v - w) * (v - w)) / (2 * a)) / v;
			} else {
				double A = a, B = w, C = -2 * (L - d);
				t += (-B + sqrt(max(0, B * B - A * C))) / A;
			}
		} else if (v * v / (2 * a) <= L) {
			t = v / a + (L - (v * v / (2 * a))) / v;
		} else {
			t = sqrt(2 * L / a);
		}
		System.out.printf("%.10f%n", t);
	}
	
	class Scanner {
		BufferedReader br;
		StringTokenizer st;
		Scanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
			eat("");
		}
		void eat(String s) {
			st = new StringTokenizer(s);
		}
		String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		boolean hasNext() {
			while (!st.hasMoreTokens()) {
				String s = nextLine();
				if (s == null) return false;
				eat(s);
			}
			return true;
		}
		String next() {
			hasNext();
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		if (LOCAL) {
			try {
				System.setIn(new FileInputStream("in.txt"));
			} catch (Throwable e) {
				LOCAL = false;
			}
		}
		if (!LOCAL) {
			try {
				Locale.setDefault(Locale.US);
				System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
			} catch (Throwable e) {
			}
		}
		new Main().run();
		System.out.flush();
	}
}