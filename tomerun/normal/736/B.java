import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int N = sc.nextInt();
    System.out.println(solve(N));
  }

  static int solve(int N) {
    if (isPrime(N)) return 1;
    if (N % 2 == 0) return 2;
    if (isPrime(N - 2)) return 2;
    return 3;
  }

  static boolean isPrime(int N) {
    if (N == 2) return true;
    if (N % 2 == 0) return false;
    for (long i = 2; i * i <= N; i++) {
      if (N % i == 0) return false;
    }
    return true;
  }

}