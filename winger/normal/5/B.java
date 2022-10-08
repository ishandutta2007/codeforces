import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int max = 0;
		ArrayList<String> ws = new ArrayList<String>();
		while (true) {
			String line = in.readLine();
			if (line == null) {
				break;
			}
			ws.add(line);
			max = Math.max(max, line.length());
		}
		print('*', max + 2);
		out.println();
		boolean add = false;
		for (String s : ws) {
			int t = max - s.length();
			int l, r;
			if (add) {
				l = (t + 1) / 2;
				r = t / 2;
			} else {
				l = t / 2;
				r = (t + 1) / 2;
			}
			add ^= t % 2 == 1;
			out.print('*');
			print(' ', l);
			out.print(s);
			print(' ', r);
			out.println('*');
		}
		print('*', max + 2);
		out.println();
	}

	private void print(char c, int n) {
		for (int i = 0; i < n; ++i) {
			out.print(c);
		}
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