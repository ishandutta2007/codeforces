import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	static class TreeNode {
		List<TreeNode> subtrees;
		List<Integer> lengths;
		List<Integer> strs;
		
		int size() {
			int r = 1;
			for (TreeNode sub : subtrees) {
				r += sub.size();
			}
			return r;
		}
	}

	class SuffixAutomata {
		
		class Vertex {
			Vertex suffixLink = null;
			Vertex[] edges;
			int log = 0;
			
			List<Integer> terminals;
			
			int toLen = -1;
			TreeNode to;
			
			TreeNode toTree() {
				if (to != null) {
					return to;
				}
				Vertex one = null;
				int count = 0;
				for (int i = 0; i < 26; ++i) {
					if (edges[i] != null) {
						one = edges[i];
						count++;
					}
				}
				if (count == 1 && terminals == null) {
					to = one.toTree();
					toLen = one.toLen + 1;
				} else {
					to = new TreeNode();
					to.strs = terminals;
					to.subtrees = new ArrayList<TreeNode>(count);
					to.lengths = new ArrayList<Integer>(count);
					for (int i = 0; i < 26; ++i) {
						if (edges[i] != null) {
							to.subtrees.add(edges[i].toTree());
							to.lengths.add(edges[i].toLen + 1);
						}
					}
					toLen = 0;
				}
				return to;
			}
			
			public Vertex(Vertex o, int log) {
				edges = o.edges.clone();
				terminals = o.terminals == null ? null : new ArrayList<Integer>(o.terminals);
				this.log = log;
			}
			
			public Vertex(int log) {
				edges = new Vertex[26];
				terminals = null;
				this.log = log;
			}
		}
		
		Vertex root, last;
		
		public SuffixAutomata(String[] strs) {
			last = root = new Vertex(0);
			for (int it = 0; it < strs.length; ++it) {
				String str = strs[it];
				for (int i = 0; i < str.length(); i++) {
					addChar(str.charAt(i));
				}
				addTerm(it);
			}
		}

		private void addChar(char c) {
			Vertex cur = last;
			last = new Vertex(cur.log + 1);
			while (cur != null && cur.edges[c - 'a'] == null) {
				cur.edges[c - 'a'] = last;
				cur = cur.suffixLink;
			}
			if (cur != null) {
				Vertex q = cur.edges[c - 'a'];
				if (q.log == cur.log + 1) {
					last.suffixLink = q;
				} else {
					Vertex r = new Vertex(q, cur.log + 1);
					r.suffixLink = q.suffixLink;
					q.suffixLink = r;
					last.suffixLink = r;
					while (cur != null) {
						if (cur.edges[c - 'a'] == q) {
							cur.edges[c - 'a'] = r;
						} else {
							break;
						}
						cur = cur.suffixLink;
					}
				}
			} else {
				last.suffixLink = root;
			}
		}

		private void addTerm(int i) {
			Vertex cur = last;
			while (cur != null) {
				if (cur.terminals == null) {
					cur.terminals = new ArrayList<Integer>(1);
				}
				cur.terminals.add(i);
				cur = cur.suffixLink;
			}
			last = root;
		}
	}
	
	int[] p;
	int[] r;
	int[] croot;
	int[] last;
	int[] countIn;
	long[] ans;
	int ids = 0;
	
	int get(int i) {
		if (p[i] != i) {
			p[i] = get(p[i]);
		}
		return p[i];
	}
	
	int unite(int i, int j) {
		i = get(i);
		j = get(j);
		if (i == j) {
			throw new AssertionError();
		}
		if (r[i] < r[j]) {
			p[i] = j;	
		} else {
			p[j] = i;
		}
		if (r[i] == r[j]) {
			r[i]++;
		}
		return p[i];
	}
	
	void inDfs(TreeNode node) {
		int id = ids++;
		if (node.strs != null) {
			countIn[id] += node.strs.size();
			for (int i : node.strs) {
				if (last[i] != -1) {
					countIn[croot[get(last[i])]]--;
				}
				last[i] = id;
			}
		}
		for (TreeNode sub : node.subtrees) {
			int sid = ids;
			inDfs(sub);
			croot[unite(id, sid)] = id;
			countIn[id] += countIn[sid];
		}
	}

	private void ansDfs(TreeNode node, long cur, int k) {
		int id = ids++;
		if (node.strs != null) {
			for (int i : node.strs) {
				ans[i] += cur;
			}
		}
		for (int it = 0; it < node.subtrees.size(); ++it) {
			TreeNode sub = node.subtrees.get(it);
			int length = node.lengths.get(it);
			int sid = ids;
			ansDfs(sub, cur + (countIn[sid] >= k ? length : 0), k);
		}
	}
	
	Random rnd = new Random();
	
	String rnd(int len) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < len; ++i) {
			sb.append((char)('a' + rnd.nextInt(26)));
		}
		return sb.toString();
	}

	public void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
//		int n = 10000;
//		int k = 10000;
		String[] strs = new String[n];
		for (int i = 0; i < n; ++i) {
			strs[i] = next();
//			strs[i] = rnd(10);
		}
		SuffixAutomata auto = new SuffixAutomata(strs);
		TreeNode root = auto.root.toTree();
		int m = root.size();
		p = new int[m];
		r = new int[m];
		croot = new int[m];
		countIn = new int[m];
		for (int i = 0; i < m; ++i) {
			p[i] = i;
			croot[i] = i;
		}
		last = new int[n];
		Arrays.fill(last, -1);
		inDfs(root);
		ids = 0;
		ans = new long[n];
		ansDfs(root, 0L, k);
		for (int i = 0; i < n; ++i) {
			out.print(ans[i] + " ");
		}
		out.println();
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