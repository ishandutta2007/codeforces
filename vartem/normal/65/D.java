import java.io.*;
import java.util.*;

public class D {

	MyScanner in;
	PrintWriter out;
	final static String filename = "";

	class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner(String file) {
			try {
				br = new BufferedReader(new FileReader(file));
				st = new StringTokenizer("");
			} catch (FileNotFoundException e) {
				e.printStackTrace();
				System.exit(1);
			}
		}

		public MyScanner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
			st = new StringTokenizer("");
		}

		String nextToken() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(br.readLine());

			} catch (IOException e) {
				e.printStackTrace();
				System.exit(1);
			}

			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(this.nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(this.nextToken());
		}

		long nextLong() {
			return Long.parseLong(this.nextToken());
		}

		void close() throws IOException {
			br.close();
		}
	}

	int[] a;
	int n;
	
	class Node implements Comparable<Node>{
		int[] a;
		public Node(int[] b) {
			a = b;
		}
		
		@Override
		public int compareTo(Node arg0) {
			for (int i = 0; i < 4; i++)
				if (a[i] != arg0.a[i])
					return a[i] - arg0.a[i];
			return 0;
		}
	}

	void solve() throws IOException {
		n = in.nextInt();
		String s = in.nextToken();
		char[] a = s.toCharArray();
		String[] f = {"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"};
		TreeSet<Node> ts = new TreeSet<Node>();
		int[] cur = {0, 0, 0, 0};
		ts.add(new Node(cur));
		for (int i = 0; i < n; i++) {
			if (a[i] == '?') {
				TreeSet<Node> nts = new TreeSet<Node>();
				for (Iterator j = ts.iterator(); j.hasNext();) {
					Node node = (Node) j.next();
					int min = Integer.MAX_VALUE;
					for (int k = 0; k < 4; k++)
						min = Math.min(min, node.a[k]);
					for (int k = 0; k < 4; k++) {
						Node d = new Node(cur);
						d.a = node.a.clone();
						if (d.a[k] == min) {
							d.a[k]++;
							nts.add(d);
						}
					}
					ts = nts;
				}
			} else {
				int h = -1;
				if (a[i] == 'G')
					h = 0;
				else if (a[i] == 'H')
					h = 1;
				else if (a[i] == 'R')
					h = 2;
				else if (a[i] == 'S')
					h = 3;
				TreeSet<Node> nts = new TreeSet<Node>();
				for (Iterator j = ts.iterator(); j.hasNext();) {
					Node node = (Node) j.next();
					Node d = new Node(cur);
					d.a = node.a.clone();
					d.a[h]++;
					nts.add(d);
				}
				
				ts = nts;
			}
		}
		boolean[] ans = new boolean[4];
		for (Iterator i = ts.iterator(); i.hasNext();) {
			Node node = (Node) i.next();
			int min = Integer.MAX_VALUE;
			for (int k = 0; k < 4; k++)
				min = Math.min(min, node.a[k]);
			for (int k = 0; k < 4; k++) 
				if (node.a[k] == min)
					ans[k] = true;
		}
		
		for (int i = 0; i < 4; i++)
			if (ans[i])
				out.println(f[i]);
	}

	void run() {
		try {
			in = new MyScanner(System.in);
			out = new PrintWriter(System.out);

			solve();

			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}

	}

	public static void main(String[] args) {
		new D().run();
	}

}