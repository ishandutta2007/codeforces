import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	private long[] a;

	void solve() throws IOException {
		BigInteger x = new BigInteger(next());
//		BigInteger x = BigInteger.valueOf(10).pow(300);
		BigInteger[] ai = new BigInteger[] {BigInteger.valueOf(2)};
		BigInteger[] ai1 = new BigInteger[] {BigInteger.valueOf(13)};
		ArrayList<Integer> ansIds = new ArrayList<Integer>();
		TreeSet<BigInteger> ansVars = new TreeSet<BigInteger>();
		for (int i = 1; ai[0].compareTo(x) <= 0; ++i) {
//			System.err.println(ai[ai.length - 1]);
			for (int j = 0; j < ai.length; ++j) {
				if (ai[j].equals(x)) {
					ansIds.add(i);
					ansVars.addAll(Arrays.asList(ai));
				}
			}
			BigInteger[] newai = new BigInteger[ai.length + 1];
			for (int j = 0; j < ai.length; ++j) {
				newai[j] = ai[j].multiply(BigInteger.valueOf(12));
			}
			newai[ai.length] = ai1[ai1.length - 1].multiply(BigInteger.valueOf(13)).subtract(ai[ai.length - 1].multiply(BigInteger.valueOf(12)));
			ai = ai1;
			ai1 = newai;
		}
		ansVars.remove(x);
		if (ansIds.size() == 0) {
			out.println("NO");
		} else {
			out.println("YES");
			out.println(ansIds.size());
			for (int i : ansIds) {
				out.println(i);
			}
			out.println(ansVars.size());
			for (BigInteger i : ansVars) {
				out.println(i);
			}
			
		}
//		int n = 13;
//		a = new long[n];
//		a[0] = 2;
//		a[1] = 13;
//		rec(2);
//		System.err.println(set);
	}
	TreeSet<Long> set = new TreeSet<Long>();

	private void rec(int i) {
		if (i == a.length) {
			set.add(a[i - 1]);
			return;
		}
		a[i] = a[i - 2] * 12;
		rec(i + 1);
		a[i] = a[i - 1] * 13 - a[i - 2] * 12;
		rec(i + 1);
	}

	Solution() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		eat("");
		
		solve();
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) throws IOException {
		new Solution();
	}
}