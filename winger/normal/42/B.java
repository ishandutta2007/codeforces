import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int r1 = nextPos();
		int r2 = nextPos();
		int wk = nextPos();
		int bk = nextPos();
		int r1x = r1 / 8;
		int r1y = r1 % 8;
		int r2x = r2 / 8;
		int r2y = r2 % 8;
		int wkx = wk / 8;
		int wky = wk % 8;
		int bkx = bk / 8;
		int bky = bk % 8;
		for (int dx = -1; dx <= 1; ++dx) {
			for (int dy = -1; dy <= 1; ++dy) {
				int x = bkx + dx;
				int y = bky + dy;
				if (x >= 0 && x < 8 && y >= 0 && y < 8 &&
					(!attacks(r1x, r1y, wkx, wky, x, y) || x == r1x && y == r1y) &&
					(!attacks(r2x, r2y, wkx, wky, x, y) || x == r2x && y == r2y) &&
					Math.max(Math.abs(x - wkx), Math.abs(y - wky)) > 1) {
					out.println("OTHER");
					return;
				}
			}
		}
		out.println("CHECKMATE");
	}

	private boolean attacks(int rx, int ry, int wkx, int wky, int x, int y) {
		if (rx == x && (rx != wkx || wky < Math.min(y, ry) || wky > Math.max(y, ry))) {
			return true;
		}
		if (ry == y && (ry != wky || wkx < Math.min(x, rx) || wkx > Math.max(x, rx))) {
			return true;
		}
		return false;
	}

	private int nextPos() throws IOException {
		String s = next();
		return (s.charAt(0) - 'a') * 8 + s.charAt(1) - '1';
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