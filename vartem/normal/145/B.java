import java.io.*;
import java.util.*;

public class CopyOfB {

	final String filename = new String("B").toLowerCase();

	boolean check(String a, int[] b) {
		for (char c : a.toCharArray()) {
			if (c == '4')
				b[0]--;
			else
				b[1]--;
		}
		for (int i = 0; i < a.length() - 1; i++) {
			String tmp = a.charAt(i) + "" + a.charAt(i + 1);
			if (tmp.equals("47")) {
				b[2]--;
			}
			if (tmp.equals("74")) {
				b[3]--;
			}
		}
		for (int i : b)
			if (i != 0)
				return false;
		return true;
	}

	String solve(int[] a) throws Exception {
		if (Math.abs(a[2] - a[3]) > 1) {
			return "-1";
		}
		StringBuilder sb = new StringBuilder();
		StringBuilder sb1 = new StringBuilder();
		if (a[2] > a[3]) {
			for (int i = 0; i < a[2]; i++) {
				sb.append("4");
				if (i == 0) {
					for (int j = 0; j < a[0] - a[2]; j++) {
						sb.append("4");
					}
				}
				sb.append("7");
				if (i == a[2] - 1) {
					for (int j = 0; j < a[1] - a[2]; j++) {
						sb.append("7");
					}
				}
			}
		} else if (a[3] > a[2]) {
			for (int i = 0; i < a[3]; i++) {
				sb.append("7");
				if (i == a[3] - 1) {
					for (int j = 0; j < a[1] - a[3]; j++) {
						sb.append("7");
					}
				}
				sb.append("4");
				if (i == 0) {
					for (int j = 0; j < a[0] - a[3]; j++) {
						sb.append("4");
					}
				}
			}
		} else {
			for (int j = 0; j < a[0] - a[2] - 1; j++) {
				sb.append("4");
			}
			for (int i = 0; i < a[2]; i++) {
				sb.append("4");
				sb.append("7");
				if (i == a[2] - 1) {
					for (int j = 0; j < a[1] - a[2]; j++) {
						sb.append("7");
					}
				}
			}
			sb.append("4");

			for (int i = 0; i < a[3]; i++) {
				sb1.append("7");
				sb1.append("4");
				if (i == 0) {
					for (int j = 0; j < a[0] - a[2]; j++) {
						sb1.append("4");
					}
				}
			}
			for (int j = 0; j < a[1] - a[2]; j++) {
				sb1.append("7");
			}
		}
		String res = sb.toString();
		String res1 = sb1.toString();
		if (check(res, a.clone())) {
			return res;
		} else if (check(res1, a.clone())) {
			return res1;
		} else {
			return "-1";
		}
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");

			out.println(solve(new int[]{nextInt(), nextInt(), nextInt(), nextInt()}));

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new CopyOfB().run();
	}

}