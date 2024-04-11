import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);
  static final long MOD = 1_000_000_007;

  public static void main(String[] args) {
    char[] S = sc.next().toCharArray();
    int N = S.length;
    long ans = 0;
    long b = 0;
    for (int i = N - 1; i >= 0; --i) {
      if (S[i] == 'a') {
        ans += b;
        b *= 2;
        b %= MOD;
      } else {
        b++;
      }
    }
    System.out.println(ans % MOD);
  }


}