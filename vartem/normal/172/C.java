import java.io.*;
import java.util.*;

public class C {

	final String filename = new String("C").toLowerCase();

	class Student {
		int time, x, id;

		public Student(int time, int x, int id) {
			this.time = time;
			this.x = x;
			this.id = id;
		}

		@Override
		public String toString() {
			return "Student [time=" + time + ", x=" + x + ", id=" + id + "]";
		}

	}

	void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		Student[] students = new Student[n];
		for (int i = 0; i < n; i++) {
			students[i] = new Student(nextInt(), nextInt(), i);
		}
		int[] ans = new int[n];
		int time = 0;
		for (int i = 0; i < n; i += m) {
			List<Student> s = new ArrayList<Student>();
			Student last = null;
			for (int j = i; j < n && j < i + m; j++) {
				s.add(students[j]);
				last = students[j];
			}
			time = Math.max(time, last.time);
			Collections.sort(s, new Comparator<Student>() {

				@Override
				public int compare(Student o1, Student o2) {
					return o1.x - o2.x;
				}
			});
			int lastX = 0;
			for (int j = 0; j < s.size(); ) {
				time += s.get(j).x - lastX;
				int k = j;
				while (k < s.size() && s.get(k).x == s.get(j).x) {
					k++;
				}
				for (int t = j; t < k; t++) {
					ans[s.get(t).id] = time;
				}
				
				int count = (k - j);
				time += (count + 2) / 2;
				lastX = s.get(j).x;
				j = k;
			}
			time += lastX;
		}
		for (int i : ans) {
			out.print(i + " ");
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
		new C().run();
	}

}