import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	void run() {
		long res = 0, num = 0;
		for (;;) {
			String str = sc.nextLine();
			if (str == null) break;
			str = str.trim();
			if (str.startsWith("+")) {
				num++;
			} else if (str.startsWith("-")) {
				num--;
			} else if (str.indexOf(':') >= 0) {
				str = str.substring(str.indexOf(':') + 1);
				res += str.length() * num;
			}
		}
		System.out.println(res);
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