import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class B {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int N = sc.nextInt();
    int K = sc.nextInt();
    int[] A = new int[N];
    ArrayList<ArrayList<Integer>> next = new ArrayList<>();
    for (int i = 0; i < N; i++) {
      A[i] = Integer.parseInt(sc.next()) - 1;
      next.add(new ArrayList<>());
      next.get(i).add(1 << 29);
    }
    for (int i = N - 1; i >= 0; i--) {
      next.get(A[i]).add(i);
    }
    PriorityQueue<Integer> q = new PriorityQueue<>((Integer i1, Integer i2) -> {
      ArrayList<Integer> l1 = next.get(i1);
      ArrayList<Integer> l2 = next.get(i2);
      return -Integer.compare(l1.get(l1.size() - 1), l2.get(l2.size() - 1));
    });

    int ans = 0;
    for (int i = 0; i < N; i++) {
      if (q.contains(A[i])) {
        q.remove(A[i]);
        next.get(A[i]).remove(next.get(A[i]).size() - 1);
        q.add(A[i]);
      } else {
        ++ans;
        next.get(A[i]).remove(next.get(A[i]).size() - 1);
        if (q.size() == K) {
          q.poll();
        }
        q.add(A[i]);
      }
    }
    System.out.println(ans);
  }

}