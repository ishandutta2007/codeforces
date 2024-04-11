import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class J {
  static Scanner sc = new Scanner(System.in);
  static int[][] cost;

  public static void main(String[] args) {
    int N = sc.nextInt();
    cost = new int[N][N];
    for (int i = 0; i < N-1; i++) {
      int U = sc.nextInt();
      int V = sc.nextInt();
      int C = sc.nextInt();
      cost[U][V] = cost[V][U] = C;
    }
    int[] d = new int[N];
    Arrays.fill(d, -1);
    d[0] = 0;
    ArrayList<Integer> q = new ArrayList<>();
    q.add(0);
    for (int i = 0; i < q.size(); i++) {
      int cur = q.get(i);
      for (int j = 0; j < N; j++) {
        if (cost[cur][j] == 0) continue;
        if (d[j] != -1) continue;
        d[j] = d[cur] + cost[cur][j];
        q.add(j);
      }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
      ans = Math.max(ans, d[i]);
    }
    System.out.println(ans);
  }

  static class Edge {
    int to, cost;

    public Edge(int to, int cost) {
      this.to = to;
      this.cost = cost;
    }
  }

}