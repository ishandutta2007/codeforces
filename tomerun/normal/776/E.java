import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    long N = sc.nextLong();
    long K = sc.nextLong();
    for (long i = 0; i < (K + 1) / 2; i++) {
      N = totient(N);
      if (N == 1) break;
    }
    System.out.println(N % 1000000007);
  }

  static long totient(long v) {
    long d = 1;
    for (long i = 2; i * i <= v; i++) {
      if (v % i == 0) {
        v /= i;
        long pow = i;
        while (v % i == 0) {
          pow *= i;
          v /= i;
        }
        d *= pow - pow / i;
      }
    }
    if (v > 1) d *= v - 1;
    return d;
  }
}