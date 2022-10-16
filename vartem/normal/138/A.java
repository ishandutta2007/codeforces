import java.io.*;
import java.util.*;

public class Literature {

	final String filename = new String("Literature").toLowerCase();

	String vowels = "aeiou";
	int k;
	
	boolean eq(String a, String b) {
		int pos1 = -1;
		int k1 = k;
		for (int i = a.length() - 1; i >= 0; i--) {
			if (vowels.indexOf(a.charAt(i)) >= 0) {
				k1--;
				if (k1 == 0) {
					pos1 = i;
					break;
				}
			}
		}
		
		int pos2 = -1;
		int k2 = k;
		for (int i = b.length() - 1; i >= 0; i--) {
			if (vowels.indexOf(b.charAt(i)) >= 0) {
				k2--;
				if (k2 == 0) {
					pos2= i;
					break;
				}
			}
		}
		if (pos1 == -1 || pos2 == -1) {
			return false;
		}
		if (a.length() - pos1 != b.length() - pos2) {
			return false;
		}
		int len = a.length() - pos1;
		for (int i = 0; i < len; i++) {
			if (a.charAt(pos1 + i) != b.charAt(pos2 + i)) {
				return false;
			}
		}
		return true;
	}
	
	String get(String a, String b, String c, String d) {
		boolean ab = eq(a, b);
		boolean bc = eq(b, c);
		boolean cd = eq(c, d);
		boolean ac = eq(a, c);
		boolean bd = eq(b, d);
		boolean ad = eq(a, d);
		if (ab && bc && cd) {
			return "aaaa";
		}
		if (ab && cd) {
			return "aabb";
		}
		if (ac && bd) {
			return "abab";
		}
		if (ad && bc) {
			return "abba";
		}
		return "-1";
	}
	
	void solve() throws Exception {
		int n = nextInt();
		k = nextInt();
		TreeSet<String> s = new TreeSet<String>();
		String ans = "aaaa";
		for (int i = 0; i < n; i++) {
			String res = get(in.readLine(), in.readLine(), in.readLine(), in.readLine());
			if (res.equals("-1")) {
				out.println("NO");
				return;
			}
			if (!res.equals("aaaa")) {
				if (ans.equals("aaaa")) {
					ans = res;
				} else {
					if (!ans.equals(res)) {
						out.println("NO");
						return;
					}
				}
			}
		}
		out.println(ans);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			//			in = new BufferedReader(new FileReader("input.txt"));
			//			out = new PrintWriter("output.txt");

			solve();

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
		new Literature().run();
	}

}