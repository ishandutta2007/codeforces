import java.util.Arrays;
import java.util.Scanner;

public class H {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int N = sc.nextInt();
    int[][] c = new int[10][10];
    for (int i = 0; i < c[0].length; i++) {
      c[0][i] = i + 1;
    }
    for (int i = 1; i < c.length; i++) {
      c[i][0] = 1;
      for (int j = 1; j < c[i].length; j++) {
        c[i][j] = c[i][j - 1] + c[i - 1][j];
      }
    }
    int[] count = new int[c.length];
    for (int i = c[0].length - 1; i >= 0; i--) {
      count[i] = N / c[c.length - 1][i];
      N %= c[c.length - 1][i];
    }
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < count.length; i++) {
      for (int j = 0; j < c.length; j++) {
        sb.append((char)('a' + j));
      }
      for (int j = 0; j < count[i]; j++) {
        sb.append((char)('a' + c[0].length));
      }
    }
    sb.append(' ');
    for (int i = 0; i <= c.length; i++) {
      sb.append((char)('a' + i));
    }
    System.out.println(sb);
  }
}