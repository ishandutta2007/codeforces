import java.io.*;
import java.util.*;

public class F {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), m = in.nextInt();
		String s = in.nextToken(), t = in.nextToken();
		List<Integer> ans = new ArrayList<Integer>();

		int[] a = encode(t), b = encode(s);
		int[][] nextS = calcNext(s), nextT = calcNext(t);

		int[] pref = new int[a.length];
		for (int i = 1; i < a.length; i++) {
			int k = pref[i - 1];
			while (k > 0 && !eq(a, i - k, i, a, k)) {
				k = pref[k - 1];
			}
			if (eq(a, i - k, i, a, k)) {
				k++;
			}
			pref[i] = k;
		}

		int k = 0;
		for (int i = 0; i < b.length; i++) {
			while (k > 0 && !eq(b, i - k, i, a, k)) {
				k = pref[k - 1];
			}
			if (eq(b, i - k, i, a, k)) {
				k++;
			}
			if (k == a.length) {
				ans.add(i - a.length + 1);
				k = pref[k - 1];
			}
		}

		List<Integer> realAns = new ArrayList<Integer>();
		for (int pos : ans) {
			int[] mapS = new int[26];
			int[] mapT = new int[26];
			boolean ok = true;
			Arrays.fill(mapS, -1);
			Arrays.fill(mapT, -1);
			
			for (int l = 0; l < 26; l++) {
				int ps = nextS[l][pos];
				if (ps - pos >= t.length()) {
					continue;
				}
				
				int corrT = t.charAt(ps - pos) - 'a';
				if (mapT[corrT] != -1) {
					ok = false;
					break;
				}
				mapT[corrT] = l;
				mapS[l] = corrT;
			}
			
			for (int i = 0; i < 26; i++) {
				if (mapT[i] == -1) {
					continue;
				}
				int j = mapT[i];
				if ((mapS[i] != -1 && mapS[i] != j) || (mapT[j] != -1 && mapT[j] != i)) {
					ok = false;
					break;
				}
			}
			
			if (ok) {
				realAns.add(pos);
			}
		}
		out.println(realAns.size());
		for (int i = 0; i < realAns.size(); i++) {
			out.print((realAns.get(i) + 1) + " ");
		}
	}

	private int[][] calcNext(String s) {
		int[][] next = new int[26][s.length()];
		int[] last = new int[26];
		Arrays.fill(last, s.length());

		for (int i = 0; i < 26; i++) {
			next[i][s.length() - 1] = s.length();
		}
		for (int i = s.length() - 1; i >= 0; i--) {
			if (i + 1 < s.length()) {
				for (int j = 0; j < 26; j++) {
					next[j][i] = next[j][i + 1];
				}
			}
			next[s.charAt(i) - 'a'][i] = i;
		}
		return next;
	}

	boolean eq(int[] fst, int l, int r, int[] snd, int pos) {
		int val1 = -1;
		if (fst[r] != -1 && fst[r] <= r - l) {
			val1 = fst[r];
		}
		return val1 == snd[pos];
	}

	int[] encode(String s) {
		int[] last = new int[256];
		Arrays.fill(last, -1);
		int[] a = new int[s.length()];
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			if (last[c] == -1) {
				a[i] = -1;
			} else {
				a[i] = i - last[c];
			}
			last[c] = i;
		}
		return a;
	}

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new F().run();
	}
}