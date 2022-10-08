
import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	static class Node {
		int a, b;
		
		Node(int a, int b) {
			this.a = a;
			this.b = b;
		}
		
		Node p;
		String pOp;
		
		void print(PrintWriter out) {
			if (p != null) {
				p.print(out);
				out.println(pOp);
			}
		}
	}

	public void solve() throws IOException {
		int n = nextInt();
		int[][] col = new int[n + 1][n + 1];
		for (int[] ar : col) {
			Arrays.fill(ar, -1);
		}
		col[1][0] = 0;
		ArrayDeque<Node> q = new ArrayDeque<Node>();
		q.addFirst(new Node(1, 0));
		while (!q.isEmpty()) {
			Node u = q.removeLast();
//			System.err.println(u.a + " " + u.b + " " + col[u.a][u.b]);
			if (u.a == n || u.b == n) {
				out.println(col[u.a][u.b]);
				u.print(out);
				return;
			}
			for (int k : new int[] {1, 2, 4, 8}) {
				for (int op1 = 0; op1 < 2; ++op1) {
					for (int op2 = 0; op2 < 2; ++op2) {
						Node v = new Node((op1 == 0 ? u.a : u.b) + k * (op2 == 0 ? u.a : u.b), u.b);
						if (v.a <= n && v.b <= n && col[v.a][v.b] == -1) {
							col[v.a][v.b] = col[u.a][u.b] + 1;
							v.p = u;
							v.pOp = "lea eax, [" + (op1 == 0 ? "eax" : "ebx") + " + " + (k == 1 ? "" : k + "*") + (op2 == 0 ? "eax" : "ebx") + "]";
							q.addFirst(v);
						}
					}
				}
				for (int op1 = 0; op1 < 2; ++op1) {
					for (int op2 = 0; op2 < 2; ++op2) {
						Node v = new Node(u.a, (op1 == 0 ? u.a : u.b) + k * (op2 == 0 ? u.a : u.b));
						if (v.a <= n && v.b <= n && col[v.a][v.b] == -1) {
							col[v.a][v.b] = col[u.a][u.b] + 1;
							v.p = u;
							v.pOp = "lea ebx, [" + (op1 == 0 ? "eax" : "ebx") + " + " + (k == 1 ? "" : k + "*") + (op2 == 0 ? "eax" : "ebx") + "]";
							q.addFirst(v);
						}
					}
				}
			}
		}
		throw new AssertionError();
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