import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    String[] v = new String[2];
    v[0] = sc.next();
    v[1] = sc.next();
    int N = sc.nextInt();
    System.out.println(v[0] + " " + v[1]);
    for (int i = 0; i < N; i++) {
      String o = sc.next();
      String n = sc.next();
      if (o.equals(v[0])) {
        v[0] = n;
      } else {
        v[1] = n;
      }
      System.out.println(v[0] + " " + v[1]);
    }
  }

}