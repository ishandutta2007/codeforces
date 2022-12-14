
import java.util.Scanner;

public class D {
	static class Point {
		int x, y;
		Point(int x1, int y1) {x = x1; y = y1; }
		void reflectThrough(Point p) {
			// return new Point(2 * p.x - x, 2 * p.y - y);
			x = 2*p.x - x; y = 2*p.y - y;
		}
		Point(Scanner in) {x = in.nextInt(); y = in.nextInt();}
		@Override
		public String toString() {return "(" + x + ", " + y + ")";}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int nRed = in.nextInt();
		int nBlue = in.nextInt();
		Point[] redPts = new Point[nRed], bluePts = new Point[nBlue];
		for (int i = 0; i < nRed; ++i) redPts[i] = new Point(in);
		for (int i = 0; i < nBlue; ++i) bluePts[i] = new Point(in);
		int[][] nPointDown = new int[nRed][nRed];
		for (int p1 = 0; p1 < nRed; ++p1) {
			for (int p2 = 0; p2 < nRed; ++p2) {
				if (p1 == p2) continue;
				if (redPts[p1].x > redPts[p2].x) {
					nPointDown[p1][p2] = -1;
					continue;
				}
				nPointDown[p1][p2] = 0;
				for (int b = 0; b < nBlue; ++b) {
					if (redPts[p1].x <= bluePts[b].x && bluePts[b].x < redPts[p2].x &&
							(long)(bluePts[b].x-redPts[p1].x) * (redPts[p2].y-redPts[p1].y) >
							(long)(bluePts[b].y-redPts[p1].y) * (redPts[p2].x-redPts[p1].x)
							) {
						++nPointDown[p1][p2];
						// System.out.println(b + " " + nPointDown[p1][p2]);
					}
				}
				// System.out.println(redPts[p1] + " " + redPts[p2] + " -> " + nPointDown[p1][p2]);
			}
		}
		for (int p1 = 0; p1 < nRed; ++p1)
			for (int p2 = 0; p2 < nRed; ++p2)
				if (nPointDown[p1][p2] == -1)
					nPointDown[p1][p2] = -nPointDown[p2][p1];

		int result = 0; // cannot too large
		for (int p1 = 0; p1 < nRed; ++p1) {
			for (int p2 = 1+p1; p2 < nRed; ++p2) {
				for (int p3 = 1+p2; p3 < nRed; ++p3) {
					if (0 == nPointDown[p1][p2] + nPointDown[p2][p3] + nPointDown[p3][p1])
						++result;
				}
			}
		}
		System.out.println(result);
	}
	
}