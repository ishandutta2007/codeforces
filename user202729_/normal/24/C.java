import java.util.Scanner;

public class A {
	static class Point {
		int x, y;
		Point(int x1, int y1) {x = x1; y = y1; }
		void reflectThrough(Point p) {
			x = 2*p.x - x; y = 2*p.y - y;
		}
		Point(Scanner in) {x = in.nextInt(); y = in.nextInt();}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		long j = in.nextLong();
		j %= 2 * n;
		Point M = new Point(in);
		Point[] A = new Point[n];
		for (int i = 0; i < n; ++i) A[i] = new Point(in);
		for (int i = 0; i < j; ++i) {
			M.reflectThrough(A[i % n]);
		}
		System.out.println(M.x + " " + M.y);
	}
	
}