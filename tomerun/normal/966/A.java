import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int N = sc.nextInt();
    int M = sc.nextInt();
    int CL = sc.nextInt();
    int CE = sc.nextInt();
    int V = sc.nextInt();
    int[] L = new int[CL];
    int[] E = new int[CE];
    for (int i = 0; i < CL; i++) {
      L[i] = Integer.parseInt(sc.next());
    }
    for (int i = 0; i < CE; i++) {
      E[i] = Integer.parseInt(sc.next());
    }
    PrintWriter writer = new PrintWriter(System.out);
    int Q = sc.nextInt();
    for (int i = 0; i < Q; i++) {
      int y1 = Integer.parseInt(sc.next());
      int x1 = Integer.parseInt(sc.next());
      int y2 = Integer.parseInt(sc.next());
      int x2 = Integer.parseInt(sc.next());
      int lx = Math.min(x1, x2);
      int hx = Math.max(x1, x2);
      int ly = Math.min(y1, y2);
      int hy = Math.max(y1, y2);
      int lpl = -Arrays.binarySearch(L, lx) - 1;
      int lph = -Arrays.binarySearch(L, hx) - 2;
      int epl = -Arrays.binarySearch(E, lx) - 1;
      int eph = -Arrays.binarySearch(E, hx) - 2;
      int ans = 1000000000;
      int et = (hy - ly + V - 1) / V;
      if (y1 == y2) {
        ans = hx - lx;
      }
      if (lpl <= lph) {
        ans = Math.min(ans, hx - lx + hy - ly);
      }
      if (epl <= eph) {
        ans = Math.min(ans, hx - lx + et);
      }
      if (lpl > 0) {
        ans = Math.min(ans, lx - L[lpl - 1] + hx - L[lpl - 1] + hy - ly);
      }
      if (lph + 1 >= 0 && lph < L.length - 1) {
        ans = Math.min(ans, L[lph + 1] - lx + L[lph + 1] - hx + hy - ly);
      }
      if (epl > 0) {
        ans = Math.min(ans, lx - E[epl - 1] + hx - E[epl - 1] + et);
      }
      if (eph + 1 >= 0 && eph < E.length - 1) {
        ans = Math.min(ans, E[eph + 1] - lx + E[eph + 1] - hx + et);
      }
      writer.println(ans);
    }
    writer.flush();
  }

}