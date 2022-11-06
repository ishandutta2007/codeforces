import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    long N = sc.nextLong();
    long p = 1;
    long c = 2;
    for (int i = 1; ; i++) {
      long n = p + c;
      if (c <= N && N < n){
        System.out.println(i);
        return;
      }
      p = c;
      c = n;
    }
  }

}