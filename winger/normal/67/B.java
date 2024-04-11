import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int[] b = new int[n];
		for (int i = 0; i < n; ++i) {
			b[i] = nextInt();
		}
		ArrayList<Integer> a = new ArrayList<Integer>();
		for (int i = n - 1; i >= 0; --i) {
			for (ListIterator<Integer> it = a.listIterator(); ;) {
				if (b[i] == 0) {
					it.add(i);
					break;
				}
				int x = it.next();
				if (x >= i + k) {
					b[i]--;
				}
			}
		}
		for (int i : a) {
			out.print((i + 1) + " ");
		}
		out.println();
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