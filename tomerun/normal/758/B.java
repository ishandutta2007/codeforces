import java.util.Arrays;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    char[] s = sc.next().toCharArray();
    int[] count = new int[4];
    Arrays.fill(count, -1);
    int unknown = -1;
    for (int i = 0; i < 4; i++) {
      char color = ' ';
      int n = 0;
      for (int j = i; j < s.length; j += 4) {
        if (s[j] == '!') {
          ++n;
        } else {
          color = s[j];
        }
      }
      int pos = "RBYG".indexOf(color);
      if (pos < 0) {
        unknown = n;
      } else {
        count[pos] = n;
      }
    }
    for (int i = 0; i < 4; i++) {
      if (count[i] < 0) {
        count[i] = unknown;
      }
    }
    System.out.println(count[0] + " " + count[1] + " " + count[2] + " " + count[3]);
  }

}