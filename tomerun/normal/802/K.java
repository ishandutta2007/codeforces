import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class K {
  static Scanner sc = new Scanner(System.in);
  static Node[] nodes;
  static int N, K;

  public static void main(String[] args) {
    N = sc.nextInt();
    K = sc.nextInt();
    nodes = new Node[N];
    for (int i = 0; i < N; i++) {
      nodes[i] = new Node(i);
    }
    for (int i = 0; i < N - 1; i++) {
      int U = sc.nextInt();
      int V = sc.nextInt();
      int C = sc.nextInt();
      nodes[U].edges.add(new Edge(V, C));
      nodes[V].edges.add(new Edge(U, C));
    }
    boolean[] visited = new boolean[N];
    visited[0] = true;
    int[] order = new int[N];
    int pos = 1;
    for (int i = 0; i < N; i++) {
      for (Edge e : nodes[order[i]].edges) {
        if (e.to == nodes[order[i]].parent) continue;
        nodes[e.to].parent = order[i];
        order[pos++] = e.to;
      }
    }
    for (int i = N - 1; i >= 0; --i) {
      nodes[order[i]].solve();
    }
    System.out.println(nodes[0].sumEnd);
  }

  static class Edge {
    int to, cost;

    public Edge(int to, int cost) {
      this.to = to;
      this.cost = cost;
    }
  }

  static class Node {
    int id, sum, sumEnd;
    ArrayList<Edge> edges = new ArrayList<>();
    int parent = -1;

    Node(int id) {
      this.id = id;
    }

    void solve() {
      long[] v = new long[edges.size()];
      boolean[] used = new boolean[edges.size()];
      for (int i = 0; i < edges.size(); i++) {
        Edge e = edges.get(i);
        Node n = nodes[e.to];
        if (this.parent == n.id) continue;
        v[i] = (((long) n.sum + e.cost) << 32) | i;
      }
      Arrays.sort(v);
//      System.err.println(Arrays.toString(v));
      for (int i = 0; i < Math.min(v.length, K - 1); i++) {
        this.sum += v[v.length - 1 - i] >> 32;
        used[(int) v[v.length - 1 - i]] = true;
      }

      for (int i = 0; i < edges.size(); i++) {
        Edge e = edges.get(i);
        Node n = nodes[e.to];
        if (this.parent == n.id) continue;
        if (used[i]) {
          int tmp = this.sum - n.sum + n.sumEnd;
          if (v.length >= K) {
            tmp += v[v.length - K] >> 32;
          }
          sumEnd = Math.max(sumEnd, tmp);
        } else {
          sumEnd = Math.max(sumEnd, this.sum + n.sumEnd + e.cost);
        }
      }
//      System.err.println(id + " " + sum + " " + sumEnd);
    }
  }

}