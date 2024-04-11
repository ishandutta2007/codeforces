import java.io.*;
import java.util.*;

public class OldPeykan {

	final String filename = new String("OldPeykan").toLowerCase();

	void solve() throws Exception {
		int m = nextInt();
		int k = nextInt();
		int n = m + 1;
		int[] d = new int[m];
		for (int i  = 0; i < m; i++) {
			d[i] = nextInt();
		}
		int[] s = new int[m];
		for (int i = 0; i < m; i++) {
			s[i] = nextInt();
		}
		long ans=  0;
		int curFuel = 0;
		int maxFuel = 0;
		for (int i = 0; i < m; i++) {
			int dist = d[i];
			maxFuel = Math.max(maxFuel, s[i]);
			curFuel += s[i];
			while (curFuel < dist) {
				curFuel += maxFuel;
				ans += k;
			}
			curFuel -= dist;
			ans += dist;
		}
		
		out.println(ans);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");

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
		new OldPeykan().run();
	}

}