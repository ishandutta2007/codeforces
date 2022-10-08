import java.io.*;
import java.util.*;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;


	public void solve() throws IOException {
		int x = nextInt();
		int y = nextInt();
		while (true) {
			if (x >= 2 && y >= 2) {
				x -= 2;
				y -= 2;
			} else if (x >= 1 && y >= 12) {
				x -= 1;
				y -= 12;
			} else if (x >= 0 && y >= 22) {
				x -= 0;
				y -= 22;
			} else {
				out.println("Hanako");
				break;
			}
			if (x >= 0 && y >= 22) {
				x -= 0;
				y -= 22;
			} else if (x >= 1 && y >= 12) {
				x -= 1;
				y -= 12;
			} else if (x >= 2 && y >= 2) {
				x -= 2;
				y -= 2;
			} else {
				out.println("Ciel");
				break;
			}
		}
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			eat("");
			
			solve();
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			failed = true;
		}
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
	
	static boolean failed = false;
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Thread th = new Thread(new Solution());
		th.start();
		try {
			th.join();
		} catch (InterruptedException iex) {
		}
		if (failed) {
			throw new RuntimeException();
		}
	}
	
}