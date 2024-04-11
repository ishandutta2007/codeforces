import java.util.ArrayList;
import java.util.Scanner;

public class Main {
  static final long MOD = 1_000_000_007;
  static Scanner sc = new Scanner(System.in);
  static int N, K;
  static Node[] nodes;
  static boolean[][] E;

  public static void main(String[] args) {
    N = sc.nextInt();
    K = sc.nextInt();
    if (K == 0) {
      System.out.println(1);
      return;
    }
    E = new boolean[N][N];
    for (int i = 0; i < N - 1; i++) {
      int U = sc.nextInt() - 1;
      int V = sc.nextInt() - 1;
      E[U][V] = E[V][U] = true;
    }
    nodes = new Node[N];
    for (int i = 0; i < N; i++) {
      nodes[i] = new Node(i);
    }
    nodes[0].setChild(-1);
    nodes[0].solve();
//    for (Node n : nodes) {
//      System.out.println(Arrays.toString(n.c));
//    }
    long ans = 0;
    for (int i = 0; i <= K; i++) {
      ans += nodes[0].c[i];
    }
    System.out.println(ans % MOD);
  }

  static class Node {
    int id;
    long[] c;
    ArrayList<Node> child = new ArrayList<>();

    Node(int id) {
      c = new long[K * 2 + 1];
      this.id = id;
    }

    void setChild(int parent) {
      for (int i = 0; i < N; i++) {
        if (E[id][i] && i != parent) {
          child.add(nodes[i]);
          nodes[i].setChild(id);
        }
      }
    }

    void solve() {
      if (child.isEmpty()) {
        c[0] = c[K + 1] = 1;
        return;
      }
      long[][] dp = new long[child.size()][K * 2 + 1];
      for (Node c : child) {
        c.solve();
      }
      dp[0] = child.get(0).c;
      for (int i = 1; i < child.size(); i++) {
        for (int j = 0; j <= K * 2; j++) {
          for (int k = 0; k <= K * 2; k++) {
            int set = j + k + 1 <= K * 2 ? Math.min(j, k) : Math.max(j, k);
            dp[i][set] += dp[i - 1][j] * child.get(i).c[k];
            dp[i][set] %= MOD;
          }
        }
      }
      long sum = dp[child.size() - 1][K * 2];
      for (int i = 0; i < K * 2; i++) {
        c[i + 1] = dp[child.size() - 1][i];
        sum += dp[child.size() - 1][i];
      }
      c[0] = sum % MOD;
    }

  }

}