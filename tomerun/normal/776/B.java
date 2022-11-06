import java.util.Arrays;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int N = sc.nextInt();
    int[] ans = new int[N + 2];
    Arrays.fill(ans, 1);
    for (int i = 2; i < N + 2; i++) {
      if (ans[i] == 1) {
        for (int j = i * 2; j < N + 2; j += i) {
          ans[j] = 2;
        }
      }
    }
    System.out.println(N <= 2 ? 1 : 2);
    System.out.print(ans[2]);
    for (int i = 3; i < N + 2; i++) {
      System.out.print(" " + ans[i]);
    }
    System.out.println();
  }

}