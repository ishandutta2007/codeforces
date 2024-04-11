import java.util.Scanner;

public class Main {

	private static int h;
	private static int w;
	private static int cnt;
	private static char[][] a;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		h = in.nextInt();
		w = in.nextInt();
		a = new char[h][];
		for (int i = 0; i < h; ++i) {
			a[i] = in.next().toCharArray();
			count(i);
		}
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (validPlusShape(i, j)) {
					System.out.println("YES");
					return;
				}
			}
		}
		System.out.println("NO");
	}

	private static boolean validPlusShape(int i, int j) {
		if (i == h || j == w || a[i][j] != '*') return false;
		return up(i - 1, j) + down(i + 1, j) + left(j - 1, i) + right(j + 1, i) + 1 == cnt;
	}

	private static void count(int i) {
		for (int j = 0; j < w; ++j) cnt += (a[i][j] == '*' ? 1 : 0);
	}

	private static int up(int r, int c) {
		return check(r, 0, -1, c, true);
	}

	private static int down(int r, int c) {
		return check(r, h, 1, c, true);
	}

	private static int left(int r, int c) {
		return check(r, 0, -1, c, false);
	}

	private static int right(int r, int c) {
		return check(r, w, 1, c, false);
	}

	private static int check(int r, int nd, int dir, int c, boolean row) {
		int k = 0;
		for (int i = r; ((dir > 0) == (i < nd)); i += dir) {
			if (a[row ? i : c][row ? c : i] != '*') break;
			if (a[row ? i : c][row ? c : i] == '*') ++k;
		}
		return k == 0 ? -999999 : k;
	}
}