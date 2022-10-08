import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	void run() {
		String s = sc.next();
		String t = sc.next();
		int x1 = s.charAt(0) - 'a', y1 = s.charAt(1) - '1';
		int x2 = t.charAt(0) - 'a', y2 = t.charAt(1) - '1';
		System.out.println(max(abs(x1 - x2), abs(y1 - y2)));
		while (x1 != x2 || y1 != y2) {
			int dx = Integer.signum(x2 - x1);
			int dy = Integer.signum(y2 - y1);
			x1 += dx;
			y1 += dy;
			if (dx < 0) System.out.print("L");
			if (dx > 0) System.out.print("R");
			if (dy < 0) System.out.print("D");
			if (dy > 0) System.out.print("U");
			System.out.println();
		}
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
			Locale.setDefault(Locale.US);
			try {
				System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
			} catch (Throwable e) {
			}
		}
		new Main().run();
		System.out.flush();
	}
}