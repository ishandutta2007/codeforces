import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);
  static char[][] f = new char[4][];

  public static void main(String[] args) {
    for (int i = 0; i < 4; i++) {
      f[i] = sc.next().toCharArray();
    }
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (f[i][j] == '.') {
          f[i][j] = 'x';
          if (win()) {
            System.out.println("YES");
            return;
          }
          f[i][j] = '.';
        }
      }
    }
    System.out.println("NO");
  }

  static boolean win() {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (align(i, j, 0, 1)) return true;
        if (align(i, j, 1, 0)) return true;
        if (align(i, j, 1, 1)) return true;
        if (align(i, j, 1, -1)) return true;
      }
    }
    System.out.println();
    return false;
  }

  static boolean align(int r, int c, int dr, int dc) {
    if (r + dr * 2 >= 4 || c + dc * 2 >= 4 || c + dc * 2 < 0) return false;
    return f[r][c] == 'x' && f[r + dr][c + dc] == 'x' && f[r + 2 * dr][c + 2 * dc] == 'x';
  }

}