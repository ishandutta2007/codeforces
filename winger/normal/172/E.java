import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	static class Tree {
		int tag;
		Tree[] subtrees;
		
		Tree(int tag) {
			this.tag = tag;
		}
		
		int query(int[] q, int i) {
			int ret = 0;
			if (i < q.length && tag == q[i]) {
				++i;
			}
			if (i == q.length) {
				if (tag == q[i - 1]) {
					ret++;
				}
			}
			for (Tree sub: subtrees) {
				ret += sub.query(q, i);
			}
			return ret;
		}
	}
	
	int index;
	ArrayList<Integer> tags;
	HashMap<String, Integer> tagsMap = new HashMap<String, Integer>();
	
	Tree parse() {
		int start = tags.get(index++);
		Tree tree = new Tree(start);
		ArrayList<Tree> sub = new ArrayList<Tree>();
		while (tags.get(index) != -start) {
			sub.add(parse());
		}
		index++;
		tree.subtrees = (Tree[]) sub.toArray(new Tree[sub.size()]);
		return tree;
	}
	
	int get(String s) {
		if (!tagsMap.containsKey(s)) {
			tagsMap.put(s, tagsMap.size() + 1);
		}
		return tagsMap.get(s);
	}

	public void solve() throws IOException {
		String s = next();
		tags = new ArrayList<Integer>();
		tags.add(1000000000);
		for (int i = 0; i < s.length(); ) {
			boolean close = false;
			boolean closed = false;
			i++;
			if (s.charAt(i) == '/') {
				close = true;
				i++;
			}
			StringBuilder sb = new StringBuilder();
			while (s.charAt(i) != '>') {
				if (s.charAt(i) == '/') {
					i++;
					closed = true;
				} else {
					sb.append(s.charAt(i++));
				}
			}
			i++;
			int tag = get(sb.toString());
			if (closed) {
				tags.add(tag);
				tags.add(-tag);
			} else {
				tags.add(close ? -tag : tag);
			}
		}
		tags.add(-1000000000);
		Tree t = parse();
		int qs = nextInt();
		loop: for (int it = 0; it < qs; ++it) {
			String[] qStr = in.readLine().split(" ");
			int[] q = new int[qStr.length];
			for (int i = 0; i < q.length; ++i) {
				if (!tagsMap.containsKey(qStr[i])) {
					out.println(0);
					continue loop;
				}
				q[i] = tagsMap.get(qStr[i]);
			}
			out.println(t.query(q, 0));
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
	
	static boolean failed = false;
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}