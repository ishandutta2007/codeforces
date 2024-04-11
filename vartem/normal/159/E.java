import java.io.*;
import java.util.*;

public class ZebraTowers {

	final String filename = new String("ZebraTowers").toLowerCase();

	class Cube implements Comparable<Cube> {
		int size, color, id;

		public Cube(int size, int color, int id) {
			this.size = size;
			this.color = color;
			this.id = id;
		}
		
		@Override
		public int compareTo(Cube o) {
			if (size != o.size) {
				return o.size - size;
			}
			return id - o.id;
		}
	}

	void solve() throws Exception {
		int n = nextInt();
		int[] size = new int[n];
		int[] color = new int[n];
		TreeMap<Integer, Integer> tm = new TreeMap<Integer, Integer>();
		for (int i = 0; i < n; i++) {
			color[i] = nextInt();
			size[i] = nextInt();
			tm.put(color[i], 0);
		}
		int tmp = 0;
		for (int i : tm.keySet()) {
			tm.put(i, tmp++);
		}
		for (int i = 0; i < n; i++) {
			color[i] = tm.get(color[i]);
		}
		int colorsCount = tm.size();
		
		final ArrayList<Cube>[] cubes = new ArrayList[colorsCount];
		for (int i = 0; i < colorsCount; i++) {
			cubes[i] = new ArrayList<ZebraTowers.Cube>();
		}
		
		for (int i = 0; i < n; i++) {
			cubes[color[i]].add(new Cube(size[i], color[i], i + 1));
		}
		
		Integer[] indices = new Integer[colorsCount];
		for (int i = 0; i < colorsCount; i++) {
			Collections.sort(cubes[i]);
			indices[i] = i;
		}
		Arrays.sort(indices, new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return cubes[o2].size() - cubes[o1].size();
			}
		});
		
		long[] longest = new long[n + 1];
		int[] longestID = new int[n + 1];
		Arrays.fill(longest, -1);
		
		long best = 0;
		int count1 = -1, count2 = -1;
		int best1 = -1, best2 = -1;
		
		for (int i = 0; i < colorsCount; i++) {
			int curColor = indices[i];
			int count = cubes[curColor].size();
			
			long sum = 0;
			for (Cube c : cubes[curColor]) {
				sum += c.size;
			}
			long curBest = Math.max(longest[count - 1], longest[count]);
			curBest = Math.max(curBest, longest[count + 1]);
			if (curBest != -1) {
				if (best < curBest + sum) {
					int otherCount;
					if (curBest == longest[count - 1]) {
						otherCount = count - 1;
					} else if (curBest == longest[count]) {
						otherCount = count;
					} else {
						otherCount = count + 1;
					}
					
					best = curBest + sum;
					count1 = count;
					count2 = otherCount;
					best1 = curColor;
					best2 = longestID[otherCount];
				}
			}
			
			sum = 0;
			for (int j = 0; j < cubes[curColor].size(); j++) {
				sum += cubes[curColor].get(j).size;
				if (longest[j + 1] < sum) {
					longest[j + 1] = sum;
					longestID[j + 1] = curColor;
				}
			}
		}
		
		out.println(best);
		out.println(count1 + count2);
		if (count1 > count2) {
			out.print(cubes[best1].get(count1 - 1).id + " ");
		}
		for (int i = 0; i < Math.min(count1, count2); i++) {
			out.print(cubes[best2].get(i).id + " " + cubes[best1].get(i).id + " ");
		}
		if (count2 > count1) {
			out.print(cubes[best2].get(count2 - 1).id + " ");
		}
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");

			solve();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new ZebraTowers().run();
	}

}