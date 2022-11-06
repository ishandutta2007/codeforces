import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int N = sc.nextInt();
    int K = sc.nextInt();
    int[] A = new int[N];
    long[] sum = new long[N + 1];
    for (int i = 0; i < N; i++) {
      A[i] = Integer.parseInt(sc.next());
      sum[i + 1] = sum[i] + A[i];
    }
    long pow = 1;
    long ans = 0;
    HashSet<Long> used = new HashSet<>();
    HashMap<Long, Integer> map = new HashMap<>();
    while (Math.abs(pow) <= N * 1_000_000_000L) {
      used.add(pow);
      map.clear();
      map.put(0L, 1);
      for (int i = 0; i < N; i++) {
        if (map.containsKey(sum[i + 1] - pow)) {
          ans += map.get(sum[i + 1] - pow);
        }
        if (map.containsKey(sum[i + 1])) {
          map.put(sum[i + 1], map.get(sum[i + 1]) + 1);
        } else {
          map.put(sum[i + 1], 1);
        }
      }
      pow *= K;
      if (used.contains(pow)) break;
    }
    System.out.println(ans);
  }

}