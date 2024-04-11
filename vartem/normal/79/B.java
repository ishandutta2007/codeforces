import java.io.*;
import java.util.*;

public class Field {

	MyScanner in;
	PrintWriter out;
	final static String filename = new String("Field").toLowerCase();

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
	int n, m;

	int get(int i, int j) {
		return (i - 1) * m + j - 1;
	}
	
	void solve() throws IOException {
		n = in.nextInt();
		m = in.nextInt();
		int k = in.nextInt();
		int t = in.nextInt();
		int[] a = new int[k];
		for (int i = 0; i < k; i++) 
			a[i] = get(in.nextInt(), in.nextInt());
		Arrays.sort(a);
		for (int i = 0; i < t; i++) {
			int g = get(in.nextInt(), in.nextInt());
			int l = 0;
			int r = k;
			while (r - l > 1) {
				int h = (l + r) / 2;
				if (a[h] > g)
					r = h;
				else
					l = h;
			}
			
			if (a[l] == g) {
				out.println("Waste");
			} else {
				int cnt = (g - l);
				if (a[l] <= g)
					cnt--;
				cnt = (cnt % 3);
				if (cnt == 0) 
					out.println("Carrots");
				else if (cnt == 1) 
					out.println("Kiwis");
				else
					out.println("Grapes");
			}
		}
		
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
		new Field().run();
	}

}