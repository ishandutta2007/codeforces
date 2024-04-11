
import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	static class Profile {
		int[] ar;
		
		Profile(int[] ar) {
			this.ar = ar;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + Arrays.hashCode(ar);
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Profile other = (Profile) obj;
			if (!Arrays.equals(ar, other.ar))
				return false;
			return true;
		}
	}

	public void solve() throws IOException {
		long n = nextLong();
		int m = nextInt();
		char[] cs = new char[m];
		int[] ms = new int[m];
		int mul = 1;
		boolean[] need = new boolean[26];
		for (int i = 0; i < m; ++i) {
			cs[i] = next().charAt(0);
			ms[i] = nextInt();
			mul *= ms[i];
			need[cs[i] - 'A'] = true;
		}
		HashMap<Profile, Integer> map = new HashMap<Profile, Integer>();
		List<Profile> list = new ArrayList<Profile>();
		int[] counter = new int[m];
		for (int i = 0; i < mul; ++i) {
			Profile p = new Profile(counter.clone());
			list.add(p);
			map.put(p, map.size());
			for (int j = 0; j < m; ++j) {
				counter[j]++;
				if (counter[j] == ms[j]) {
					counter[j] = 0;
				} else {
					break;
				}
			}
		}
		int[][] mat = new int[mul][mul];
		for (int i = 0; i < mul; ++i) {
			for (char c = 'A'; c <= 'Z'; ++c) {
				if (!need[c - 'A']) {
					continue;
				}
				counter = list.get(i).ar.clone();
				for (int j = 0; j < m; ++j) {
					if (c == cs[j]) {
						counter[j] = (counter[j] + 1) % ms[j];
					}
				}
				mat[i][map.get(new Profile(counter))]++;
			}
		}
		mat = pow(mat, n);
		int ans = 0;
		loop: for (int i = 0; i < mul; ++i) {
			boolean[] ok = new boolean[26];
			counter = list.get(i).ar;
			for (int j = 0; j < m; ++j) {
				ok[cs[j] - 'A'] |= counter[j] == 0;
			}
			for (int j = 0; j < 26; ++j) {
				if (!ok[j] && need[j]) {
					continue loop;
				}
			}
			ans = (ans + mat[0][i]) % 12345;
		}
		out.println(ans);
	}

	private int[][] pow(int[][] a, long pow) {
		int[][] b = new int[a.length][a.length];
		for (int i = 0; i < a.length; ++i) {
			b[i][i] = 1;
		}
		while (pow > 0) {
			if (pow % 2 == 1) {
				b = mul(b, a);
			}
			pow /= 2;
			a = mul(a, a);
		}
		return b;
	}

	private int[][] mul(int[][] a, int[][] b) {
		int[][] c = new int[a.length][a.length];
		for (int i = 0; i < a.length; ++i) {
			for (int j = 0; j < a.length; ++j) {
				long sum = 0;
				for (int t = 0; t < a.length; ++t) {
					sum += a[i][t] * b[t][j];
				}
				c[i][j] = (int)(sum % 12345);
			}
		}
		return c;
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