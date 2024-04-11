import java.io.*;
import java.util.*;

public class C {

	FastScanner in;
	PrintWriter out;

	class Point implements Comparable<Point> {
		double x, y;

		public Point(double x, double y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Point o) {
			if (x != o.x) {
				return Double.compare(x, o.x);
			}
			return Double.compare(y, o.y);
		}

		@Override
		public String toString() {
			return "Point [x=" + x + ", y=" + y + "]";
		}
	}
	
	double vectMul(Point a, Point b, Point c) {
		return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	}

	void solve() {
		int n = in.nextInt();
		Point target = new Point(in.nextLong(), in.nextLong());
		Point[] a = new Point[n + 3];
		double maxX = 0, maxY = 0;
		for (int i = 0; i < n; i++) {
			a[i] = new Point(in.nextLong(), in.nextLong());
			maxX = Math.max(maxX, a[i].x);
			maxY = Math.max(maxY, a[i].y);
		}
		a[n] = new Point(0, 0);
		a[n + 1] = new Point(0, maxY);
		a[n + 2] = new Point(maxX, 0);
		Point[] hull = convexHull(a);
		double left = 0, right = 1e9;
		for (int IT = 0; IT < 75; IT++) {
			double mid = (left + right) / 2;
			Point p = new Point(target.x / mid,target.y / mid);
			
			boolean ok = true;
			for (int i = 0; i < hull.length - 1; i++) {
				if (vectMul(p, hull[i], hull[i + 1]) < 0) {
					ok = false;
					break;
				}
			}
			if (ok ){
				right = mid;
			} else {
				left = mid;
			}
		}
		out.println((left + right) / 2);
	}
	Point[] convexHull(Point[] a) {
		Arrays.sort(a);
		int n = a.length;
		Point[] down = new Point[n], up = new Point[n];
		int downPtr = 0, upPtr = 0;
		for (int i = 0; i < a.length; i++) {
			Point p = a[i];
			while (downPtr > 1 && vectMul(down[downPtr - 2], down[downPtr - 1], p) <= 0) {
				downPtr--;
			}
			down[downPtr++] = p;
		}
		
		for (int i = a.length - 1; i >= 0; i--) {
			Point p = a[i];
			while (upPtr > 1 && vectMul(up[upPtr - 2], up[upPtr - 1], p) <= 0) {
				upPtr--;
			}
			up[upPtr++] = p;
		}
		Point[] result = new Point[upPtr + downPtr - 1];
		int ptr = 0;
		for (int i = 0; i < downPtr - 1; i++) {
			result[ptr++] = (down[i]);
		}
		for (int j = 0; j < upPtr; j++) {
			result[ptr++] = (up[j]);
		}
		return result;
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
		new C().run();
	}
}