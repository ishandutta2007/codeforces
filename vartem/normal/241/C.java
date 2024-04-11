import java.io.*;
import java.util.*;

public class MirrorBox {

	final String filename = new String("MirrorBox").toLowerCase();

	final int LENGTH = 100000;
	final int HEIGHT = 100;

	final int MAX_REFL = 150;

	class Segment {
		char t;
		int x1, x2;
		int score;
		public Segment(char t, int x1, int x2, int score) {
			super();
			this.t = t;
			this.x1 = x1;
			this.x2 = x2;
			this.score = score;
		}
		@Override
		public String toString() {
			return "Segment [t=" + t + ", x1=" + x1 + ", x2=" + x2 + ", score="
					+ score + "]";
		}

		
	}

	class Point {
		double x, y;

		public Point(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {
			return "Point [x=" + x + ", y=" + y + "]";
		}

	}

	boolean intersects(Point first, Point last, Segment s, int y) {
		double fst = (last.y - first.y) / (last.x - first.x) * (s.x1 - first.x)
				+ first.y;
		double snd = (last.y - first.y) / (last.x - first.x) * (s.x2 - first.x)
				+ first.y;
		if ((fst - y) * (snd - y) <= 0) {
			return true;
		}
		return false;
	}

	void solve() throws Exception {
		int hL = nextInt();
		int hR = nextInt();
		int n = nextInt();

		Segment[] s = new Segment[n];
		for (int i = 0; i < n; i++) {
			int sc = nextInt();
			char c = nextToken().charAt(0);
			int x1 = nextInt();
			int x2 = nextInt();
			s[i] = new Segment(c, x1, x2, sc);
		}
		int bestAns = 0;
		for (int i = -MAX_REFL; i <= MAX_REFL; i++) {
			int lastX = LENGTH;
			int lastY;
			if (i < 0) {
				lastY = (i - 1) / 2 * 2 * HEIGHT;
				if (i % 2 == 0) {
					lastY += hR;
				} else {
					lastY += 2 * HEIGHT - hR;
				}
			} else {
				lastY = (i / 2) * 2 * HEIGHT;
				if (i % 2 == 0) {
					lastY += hR;
				} else {
					lastY += 2 * HEIGHT - hR;
				}
			}

			int firstX = 0, firstY = hL;
			Point first = new Point(firstX, firstY);
			Point last = new Point(lastX, lastY);
			
			if (i == 0) {
				continue;
			}
			boolean ok = true;
			int score = 0;
			boolean[] inter = new boolean[n];
			if (i < 0) {
				
				for (int j = 0; j > i; j--) {
					boolean hasInter = false;
					for (int k = 0; k < n; k++) {
						Segment segm = s[k];
						if ((segm.t == 'F') == ((j % 2) == 0)) {
							int y = HEIGHT * j;
							if (intersects(first, last, segm, y)) {
								if (inter[k]) {
									ok = false;
								}
								hasInter = true;
								score += segm.score;
								inter[k] = true;
							}
						}
					}
					if (!hasInter) {
						ok = false;
					}
				}
				
				if (ok) {
					bestAns = Math.max(bestAns, score);
				}
			} else {
				for (int j = 1; j <= i; j++) {
					boolean hasInter = false;
					for (int k = 0; k < n; k++) {
						Segment segm = s[k];
						if ((segm.t == 'F') == ((j % 2) == 0)) {
							int y = HEIGHT * j;
							if (intersects(first, last, segm, y)) {
								if (inter[k]) {
									ok = false;
								}
								hasInter = true;
								score += segm.score;
								inter[k] = true;
							}
						}
					}
					if (!hasInter) {
						ok = false;
					}
				}
			}
			if (ok) {
				bestAns = Math.max(bestAns, score);
			}
		}
		out.println(bestAns);
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
		new MirrorBox().run();
	}

}