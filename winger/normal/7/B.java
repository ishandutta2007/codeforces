import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	static class Segment {
		int id, len, start;
		
		Segment(int id, int start, int len) {
			this.id = id;
			this.len = len;
			this.start = start;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int curId = 0;
		HashMap<Integer, Segment> map = new HashMap<Integer, Segment>();
		ArrayList<Segment> segs = new ArrayList<Segment>();
		segs.add(new Segment(-1, 0, 0));
		segs.add(new Segment(-1, m, 0));
		for (int it = 0; it < n; ++it) {
			String op = next();
			if ("alloc".equals(op)) {
				int len = nextInt();
				int i = 0;
				while (i < segs.size() - 1 && segs.get(i + 1).start - segs.get(i).start - segs.get(i).len < len) {
					++i;
				}
				if (i == segs.size() - 1) {
					out.println("NULL");
				} else {
					Segment seg = new Segment(++curId, segs.get(i).start + segs.get(i).len, len);
					segs.add(i + 1, seg);
					map.put(curId, seg);
					out.println(curId);
				}
			} else if ("erase".equals(op)) {
				int x = nextInt();
				if (map.containsKey(x)) {
					segs.remove(map.remove(x));
				} else {
					out.println("ILLEGAL_ERASE_ARGUMENT");
				}
			} else if ("defragment".equals(op)) {
				for (int i = 1; i < segs.size() - 1; ++i) {
					segs.get(i).start = segs.get(i - 1).start + segs.get(i - 1).len;
				}
			} else {
				throw new AssertionError();
			}
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