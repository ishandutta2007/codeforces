import java.util.Arrays;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    long N = sc.nextInt();
    long M = sc.nextInt();
    long K = sc.nextLong();
    long X = sc.nextInt() - 1;
    long Y = sc.nextInt() - 1;
    if (N == 2) {
      if (X == 1) {
        Y += M;
      }
      X = 0;
      N = 1;
      M *= 2;
    }
    long min, max, him;
    if (N == 1) {
      long rep = M;
      long rest = K - K / M * M;
      min = K / M;
      max = rest == 0 ? min : min + 1;
      him = min + (rest > Y ? 1 : 0);
    } else {
      long rep = (2 * N - 2) * M;
      long cycle = K / rep;
      long rest = K - K / rep * rep;
      long[][] count = new long[(int) N][(int) M];
      Arrays.fill(count[0], cycle);
      Arrays.fill(count[(int) N - 1], cycle);
      for (int i = 1; i < N - 1; i++) {
        Arrays.fill(count[i], cycle * 2);
      }
      for (int i = 0; i < N && rest > 0; i++) {
        for (int j = 0; j < M && rest > 0; j++, --rest) {
          count[i][j]++;
        }
      }
      for (int i = (int) N - 2; i >= 0 && rest > 0; i--) {
        for (int j = 0; j < M && rest > 0; j++, --rest) {
          count[i][j]++;
        }
      }
      min = 1L << 60;
      max = 0;
      him = 0;
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          min = Math.min(min, count[i][j]);
          max = Math.max(max, count[i][j]);
          if (i == X && j == Y) him = count[i][j];
        }
      }
    }
    System.out.println(max + " " + min + " " + him);
  }

}