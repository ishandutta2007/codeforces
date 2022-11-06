import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int N = sc.nextInt();
    int[] A = new int[N];
    int sum = 0;
    for (int i = 0; i < N; i++) {
      A[i] = sc.nextInt();
      sum += A[i];
    }
    if (sum != 0) {
      System.out.println("YES");
      System.out.println(1);
      System.out.println(1 + " " + N);
      return;
    }
    int subsum = 0;
    for (int i = 0; i < N; i++) {
      subsum += A[i];
      if (subsum != 0) {
        System.out.println("YES");
        System.out.println(2);
        System.out.println(1 + " " + (i + 1));
        System.out.println((i + 2) + " " + N);
        return;
      }
    }
    System.out.println("NO");
  }

}