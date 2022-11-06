import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int N = sc.nextInt();
    ArrayList<ArrayList<Long>> B = new ArrayList<>();
    for (int i = 0; i <= 60; i++) {
      B.add(new ArrayList<>());
    }
    for (int i = 0; i < N; i++) {
      long b = Long.parseLong(sc.next());
      B.get(63 - Long.numberOfLeadingZeros(b)).add(b);
    }
    long[] ans = new long[0];
    boolean ok = true;
    for (int i = 60; i >= 0; i--) {
      long[] next = new long[ans.length + B.get(i).size()];
      int posb = 0;
      int posn = 0;
      int count = 0;
      for (int j = 0; j < ans.length; j++) {
        if (count % 2 == 0 && posb < B.get(i).size()) {
          next[posn++] = B.get(i).get(posb++);
          ++count;
        }
        next[posn++] = ans[j];
        if ((ans[j] & (1L << i)) != 0) ++count;
      }
      if (count % 2== 0 && posb < B.get(i).size()) {
        next[posn++] = B.get(i).get(posb++);
      }
      if (posb < B.get(i).size()) {
        ok = false;
        break;
      }
      ans = next;
    }
    PrintWriter writer = new PrintWriter(System.out);
    if (ok) {
      writer.println("Yes");
      for (int i = 0; i < ans.length; i++) {
        writer.print(ans[i] + (i == ans.length - 1 ? "\n" : " "));
      }
    } else {
      writer.println("No");
    }
    writer.flush();
  }

}