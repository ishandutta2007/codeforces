import java.util.Scanner;

public class G {

  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    char[] s = sc.next().toCharArray();
    char[] e = "heidi".toCharArray();
    int p = 0;
    for (int i = 0; i < s.length && p < e.length; i++) {
      if (s[i] == e[p]) ++p;
    }
    System.out.println(p == e.length ? "YES" : "NO");
  }

}