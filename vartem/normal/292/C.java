import java.io.*;
import java.util.*;

public class C {

	FastScanner in;
	PrintWriter out;
	final String fileName = "C".toLowerCase();
	
	boolean[] need;
	int[] a;
	
	int[] c;
	int[] cRev;
	
	void gen(int k, int len) {
		if (k == len) {
			int[] check = new int[2 * len];
			System.arraycopy(c, 0, check, 0, len);
			System.arraycopy(cRev, 0, check, len, len);
			
			check(check);
			
			
			if (len == 6) {
				return;
			}
			int[] check2 = new int[2 * len + 1];
			System.arraycopy(c, 0, check2, 0, len);
			System.arraycopy(cRev, 0, check2, len + 1, len);
			for (int i : a) {
				check2[len] = i;
				check(check2);
			}
			
			return;
		}
		
		for (int i : a) {
			c[k] = i;
			cRev[len - k - 1] = i;
			gen(k + 1, len);
		}
	}

	List<String> ans;
	int[] count;
	
	private void check(int[] check) {
		Arrays.fill(count, 0);
		for (int j = 0; j < check.length; j++) {
			count[check[j]]++;
		}
		
		for (int j = 0; j < 10; j++) {
			if (need[j] && count[j] == 0) {
				return;
			}
		}
		
		generateIps(check, 0, 0);
	}
	
	int[] ips;
	
	void generateIps(int[] check, int pos, int rmn) {
		if (rmn == 3) {
			long rmnNumber = getNum(check, pos, check.length - 1);
			if (rmnNumber > 255 || (check[pos] == 0 && check.length - pos > 1)) {
				return;
			}
			
			ips[rmn] = (int) rmnNumber;
			addAnswer();
			return;
		}
		
		for (int len = 1; len <= 3 && pos + len < check.length; len++) {
			long rmnNumber = getNum(check, pos, pos + len - 1);
			if (rmnNumber > 255 || (check[pos] == 0 && len != 1)) {
				continue;
			}
			ips[rmn] = (int) rmnNumber;
			generateIps(check, pos + len, rmn + 1);
		}
		
	}

	private void addAnswer() {
		StringBuilder sb = new StringBuilder();
		sb.append(ips[0]);
		for (int i = 1; i < 4; i++) {
			sb.append(".");
			sb.append(ips[i]);
		}
		ans.add(sb.toString());
		
	}

	private long getNum(int[] check, int l, int r) {
		int res = 0;
		for (int j = l; j <= r; j++) {
			res = res * 10 + check[j];
		}
		return res;
	}

	void solve() {
		int n = in.nextInt();
		if (n >= 7) {
			out.println(0);
			return;
		}
		ips = new int[4];
		count = new int[10];
		ans = new ArrayList<String>();
		need = new boolean[10];
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			need[a[i]] = true;
		}
		
		for (int len = 2; len <= 6; len++) {
			c = new int[len];
			cRev = c.clone();
			gen(0, len);
		}
		
		
		out.println(ans.size());
		for (String s : ans) {
			out.println(s);
		}
	}

	void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new C().run();
	}
}