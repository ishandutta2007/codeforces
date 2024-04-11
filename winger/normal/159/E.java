import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	static class Cube {
		int c;
		long s;
		int i;
		
		Cube(int i, int c, long s) {
			this.i = i;
			this.c = c;
			this.s = s;
		}
		
	}

	public void solve() throws IOException {
		HashMap<Integer, Integer> cs = new HashMap<Integer, Integer>();
		int n = nextInt();
		Cube[] a = new Cube[n];
		for (int i = 0; i < n; ++i) {
			int c = nextInt();
			long s = nextInt();
			if (!cs.containsKey(c)) {
				cs.put(c, cs.size());
			}
			c = cs.get(c);
			a[i] = new Cube(i + 1, c, s);
		}
		Arrays.sort(a, new Comparator<Cube>() {
			public int compare(Cube a, Cube b) {
				return b.s < a.s ? -1 : b.s > a.s ? 1 : 0;
			}
		});
		ArrayList<Cube>[] cubes = new ArrayList[cs.size()];
		for (int i = 0; i < cs.size(); ++i) {
			cubes[i] = new ArrayList<Cube>();
		}
		for (Cube c : a) {
			cubes[c.c].add(c);
		}
		Arrays.sort(cubes, new Comparator<ArrayList<Cube>>() {
			public int compare(ArrayList<Cube> o1, ArrayList<Cube> o2) {
				return o1.size() - o2.size();
			}
		});
		long[] maxSum = new long[n + 1];
		int[] maxTower = new int[n + 1];
		Arrays.fill(maxTower, -1);
		long ans = 0;
		int ansi = -1, anshi = -1, ansj = -1, anshj = -1;
		for (int i = 0; i < cs.size(); ++i) {
			ArrayList<Cube> tower = cubes[i];
			long sum = 0;
			for (int j = 0; j < tower.size(); ++j) {
				sum += tower.get(j).s;
				if (maxTower[j + 1] != -1 && maxSum[j + 1] + sum > ans) {
					ans = maxSum[j + 1] + sum;
					ansi = maxTower[j + 1];
					anshi = j + 1;
					ansj = i;
					anshj = j + 1;
				} else if (maxTower[j] != -1 && maxSum[j] + sum > ans) {
					ans = maxSum[j] + sum;
					ansi = maxTower[j];
					anshi = j;
					ansj = i;
					anshj = j + 1;
				}
			}
			sum = 0;
			for (int j = 0; j < tower.size(); ++j) {
				sum += tower.get(j).s;
				if (sum > maxSum[j + 1]) {
					maxSum[j + 1] = sum;
					maxTower[j + 1] = i;
				}
			}
		}
		out.println(ans);
		out.println(anshi + anshj);
		ArrayList<Cube> toweri = cubes[ansi];
		ArrayList<Cube> towerj = cubes[ansj];
		for (int it = 0; it < anshj; ++it) {
			out.print(towerj.get(it).i + " ");
			if (it < anshi) {
				out.print(toweri.get(it).i + " ");
			}
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
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}