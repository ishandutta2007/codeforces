import java.io.*;
import java.util.*;

public class Solution implements Runnable {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	static class Vector {
		final double x, y;
		
		Vector(double x, double y) {
			this.x = x;
			this.y = y;
		}
		
		double len2() {
			return x * x + y * y;
		}
		
		double len() {
			return Math.sqrt(len2());
		}
		
		double phi() {
			return Math.atan2(y, x);
		}
		
		Vector rotate(double alpha) {
			double s = Math.sin(alpha);
			double c = Math.cos(alpha);
			return new Vector(c * x + s * y, -s * x + c * y);
		}
		
		Vector sub(Vector b) {
			return new Vector(x - b.x, y - b.y);
		}
		
		@Override
		public String toString() {
			return x + "," + y;
		}
	}
	
	static double vMul(Vector a, Vector b) {
		return a.x * b.y - a.y * b.x;
	}

	private void solve() throws IOException {
		int n = nextInt();
		Vector[] p = new Vector[n + 1];
		double sq = 0.;
		for (int i = 0; i < n; ++i) {
			p[i] = new Vector(nextDouble(), nextDouble());
		}
		p[n] = p[0];
		for (int i = 0; i < n; ++i) {
			sq += vMul(p[i], p[i + 1]);
		}
		if (sq < 0) {
			Vector[] pp = new Vector[n];
			for (int i = 0; i < n; ++i) {
				pp[i] = p[n - i - 1];
			}
			p = pp;
		}
		{
			Vector[] pp = new Vector[3 * n + 1];
			for (int i = 0; i < pp.length; ++i) {
				pp[i] = p[i % n];
			}
			p = pp;
		}
		int l = 0;
		for (int i = 0; i < n; ++i) {
			if (cmp(p[i].x, p[l].x) < 0 || cmp(p[i].x, p[l].x) == 0 && cmp(p[i].y, p[l].y) < 0) {
				l = i;
			}
		}
		int r = l;
		double sum = 0.;
		while (cmp(p[r + 1].y, p[r].y) < 0) {
			sum += vMul(p[r], p[r + 1]);
			++r;
		}
		double curAlpha = 0.;
		double ans = Double.POSITIVE_INFINITY;
		while (r < p.length - 1) {
			if (l > r) {
				throw new AssertionError();
			}
			double alphal = p[l + 1].sub(p[l]).phi() + Math.PI / 2.;
			double alphar = p[r + 1].sub(p[r]).phi();
			while (cmp(alphal, curAlpha) < 0) {
				alphal += 2. * Math.PI;
			}
			while (cmp(alphar, curAlpha) < 0) {
				alphar += 2. * Math.PI;
			}
			double nextAlpha = Math.min(alphal, alphar);
			ans = Math.min(ans, value(sum, p[l], p[r], curAlpha));
			if (cmp(alphal, alphar) < 0) {
				sum -= vMul(p[l], p[l + 1]);
				l++;
			} else {
				sum += vMul(p[r], p[r + 1]);
				r++;
			}
			curAlpha = nextAlpha;
		}
		out.println(ans / 2.);
	}

	private double value(double sum, Vector vl, Vector vr, double alpha) {
		vl = vl.rotate(alpha);
		vr = vr.rotate(alpha);
		double res = -sum - ((vr.x - vl.x) * vr.y + (vl.y - vr.y) * vl.x);
		if (cmp(res, 0.) < 0) {
			throw new AssertionError();
		}
		return res;
	}

	static int cmp(double a, double b) {
		final double EPS = 1e-8;
		if (Math.abs(a - b) < EPS) {
			return 0;
		}
		return Double.compare(a, b);
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			eat("");
			
			solve();
			
			in.close();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}
	}

	private void eat(String line) {
		st = new StringTokenizer(line);
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

	public static void main(String[] args) {
		new Thread(new Solution()).start();
	}

}