import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int N = sc.nextInt();
    int[] A = new int[N];
    int max = 0;
    for (int i = 0; i < N; i++) {
      A[i] = sc.nextInt();
      max = Math.max(max, A[i]);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
      ans += max - A[i];
    }
    System.out.println(ans);
  }

}