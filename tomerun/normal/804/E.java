import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);
  static PrintWriter writer = new PrintWriter(System.out);
  static int[][] five = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 4}, {2, 4}, {0, 4}, {2, 3}, {1, 3}, {3, 4}};
  static int[][] five2 = {{0, 1},{0, 2},{0, 3},{1, 2},{1, 3},{2, 3},{2, 4},{3, 4},{0, 4},{1, 4}};
  static int[][] four = {{0, 1}, {0, 2}, {1, 3}, {0, 3}, {1, 2}, {2, 3}};
  static int[][] four2 = {{0, 1},{0, 3},{0, 2},{1, 3},{1, 2},{2, 3}};
  static int N;

  public static void main(String[] args) {
    N = sc.nextInt();
    if (N % 4 == 2 || N % 4 == 3) {
      System.out.println("NO");
      return;
    }
    System.out.println("YES");
    for (int i = N; i > 1; i -= 4) {
      solve(i);
    }
    writer.flush();
  }

  static void solve(int n) {
    for (int i = n - 8; i >= 0; i -= 4) {
      swap(i, n - 4);
    }
    if (n % 4 == 0) {
      int[][] swaps = N / 4 % 2 == 0 ? four2 : four;
      for (int[] pair : swaps) {
        out(pair[0] + n - 4, pair[1] + n - 4);
      }
    } else {
      int[][] swaps = N / 4 % 2 == 0 ? five2 : five;
      for (int[] pair : swaps) {
        out(pair[0] == 0 ? 0 : pair[0] + n - 5, pair[1] + n - 5);
      }
    }
  }

  static void swap(int p1, int p2) {
    for (int i = 0; i < 4; i++) {
      out(p1 + i, p2 + i);
    }
    for (int i = 0; i < 4; i++) {
      out(p1 + i, p2 + (i + 1) % 4);
    }
    for (int i = 0; i < 4; i++) {
      out(p1 + i, p2 + (i + 2) % 4);
    }
    for (int i = 0; i < 4; i++) {
      out(p1 + i, p2 + (i + 3) % 4);
    }
  }

  static void out(int a, int b) {
    writer.println((a + 1) + " " + (b + 1));
  }

}