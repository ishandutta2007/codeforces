import java.util.Arrays;
import java.util.Scanner;

public class M {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int N = sc.nextInt();
    int K = sc.nextInt();
    int[] A = new int[N];
    for (int i = 0; i < N; i++) {
      A[i] = sc.nextInt();
    }
    Arrays.sort(A);
    int ans = 0;
    for (int i = 0; i < K; i++) {
      ans += A[i];
    }
    System.out.println(ans);
  }

}