import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	public void solve() throws IOException {
		int n = nextInt();
		ArrayList<String> stack = new ArrayList<String>();
		for (int i = 0; i < n; ++i) {
			String s = in.readLine();
			if ("pwd".equals(s)) {
				for (String x : stack) {
					out.print("/" + x);
				}
				out.print("/");
				out.println();
			} else {
				s = s.substring(3);
				String[] tokens = s.split("/");
				for (String x : tokens) {
					if (x.isEmpty()) {
						stack.clear();
					} else if ("..".equals(x)) {
						stack.remove(stack.size() - 1);
					} else {
						stack.add(x);
					}
				}
			}
		}
	}

	public void run() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		eat("");
		
		solve();
		
		out.close();
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
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
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}