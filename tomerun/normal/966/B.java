import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);
  static PrintWriter writer = new PrintWriter(System.out);
  static Machine[] C;
  static ArrayList<Integer> a1 = new ArrayList<>();
  static ArrayList<Integer> a2 = new ArrayList<>();

  public static void main(String[] args) {
    int N = sc.nextInt();
    long X1 = sc.nextInt();
    long X2 = sc.nextInt();
    C = new Machine[N];
    for (int i = 0; i < N; i++) {
      long c = Integer.parseInt(sc.next());
      C[i] = new Machine(c, i + 1);
    }
    Arrays.sort(C);
    if (!solve(X1, X2)) {
      solve(X2, X1);
      ArrayList<Integer> tmp = a1;
      a1 = a2;
      a2 = tmp;
    }
    if (a1.isEmpty()) {
      writer.println("No");
    } else {
      writer.println("Yes");
      writer.println(a1.size() + " " + a2.size());
      for (int i = 0; i < a1.size(); i++) {
        writer.print(a1.get(i) + (i == a1.size() - 1 ? "\n" : " "));
      }
      for (int i = 0; i < a2.size(); i++) {
        writer.print(a2.get(i) + (i == a2.size() - 1 ? "\n" : " "));
      }
    }
    writer.flush();
  }

  static boolean solve(long x1, long x2) {
    int pos = C.length - 1;
    for (; pos >= 0; pos--) {
      long sum = C[pos].c * (C.length - pos);
      if (sum >= x1) break;
    }
    int pos2 = pos - 1;
    for (; pos2 >= 0; pos2--) {
      long sum = C[pos2].c * (pos - pos2);
      if (sum >= x2) {
        for (int i = pos; i < C.length; i++) {
          a1.add(C[i].i);
        }
        for (int i = pos2; i < pos; i++) {
          a2.add(C[i].i);
        }
        return true;
      }
    }
    return false;
  }

  static class Machine implements Comparable<Machine> {
    long c;
    int i;

    public Machine(long c, int i) {
      this.c = c;
      this.i = i;
    }

    @Override
    public int compareTo(Machine o) {
      return Long.compare(this.c, o.c);
    }
  }

}