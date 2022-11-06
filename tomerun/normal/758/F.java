import java.util.Arrays;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    long N = sc.nextInt();
    long L = sc.nextInt();
    long R = sc.nextInt();
    long ans = 0;
    if (N == 1) {
      ans = R - L + 1;
    } else if (N == 2) {
      ans = (R - L + 1) * (R - L);
    } else {
      int[] sum = new int[(int) R + 1];
      int[] pow = new int[5000];
      Arrays.fill(pow, -1);
      int upper = 0;
      for (int i = 1; ; i++) {
        long p = pow(i, N - 1);
        if (p > R) {
          upper = i;
          break;
        }
        sum[(int) p] = 1;
        pow[i] = (int) p;
      }
      boolean[][] common = new boolean[upper][upper];
      for (int i = 2; i < upper; i++) {
        for (int j = 1; j * i < upper; j++) {
          for (int k = 1; k <= j; k++) {
            common[i * k][i * j] = common[i * j][i * k] = true;
          }
        }
      }
      for (int i = 1; i < sum.length; i++) {
        sum[i] += sum[i - 1];
      }
      for (long i = 1; ; i++) {
        long p = pow(i, N - 1);
        if (p > R) break;
        for (long a0 = (L - 1) / p + 1; a0 * p <= R; a0++) {
          int hi = (int) (R / a0);
          int lo = (int) ((L - 1) / a0);
          ans += sum[hi] - sum[lo] - 1;
//          System.out.println(i + " " + (a0 * p) + " " + ans);
          for (int j = 2; ; j++) {
            if (pow[j] == -1 || pow[j] > hi) break;
            if (pow[j] <= lo || j == i) continue;
            if (common[(int)i][j]) ans -= 1;
          }
//          System.out.println(i + " " + (a0 * p) + " " + ans);
        }
      }
    }
    System.out.println(ans);
  }

  static long pow(long base, long p) {
    if (p == 0) return 1;
    if (p == 1) return base;
    long ret = pow(base, p / 2);
    ret *= ret;
    if (ret > 10000000) return 20000000;
    if (p % 2 == 1) ret *= base;
    if (ret > 10000000) return 20000000;
    return ret;
  }

}