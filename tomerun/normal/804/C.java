import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);
  static int N, M;
  static Node[] nodes;

  public static void main(String[] args) {
    N = sc.nextInt();
    M = sc.nextInt();
    nodes = new Node[N];
    int maxS = 0;
    int maxI = 0;
    for (int i = 0; i < N; i++) {
      int s = Integer.parseInt(sc.next());
      nodes[i] = new Node(s);
      for (int j = 0; j < s; j++) {
        nodes[i].S[j] = Integer.parseInt(sc.next()) - 1;
      }
      if (s > maxS) {
        maxS = s;
        maxI = i;
      }
    }
    for (int i = 0; i < N - 1; i++) {
      int U = Integer.parseInt(sc.next()) - 1;
      int V = Integer.parseInt(sc.next()) - 1;
      nodes[U].next.add(V);
      nodes[V].next.add(U);
    }
    int[] color = new int[M];
    int[] usedColor = new int[maxS + 1];
    Arrays.fill(usedColor, -1);
    boolean[] usedNode = new boolean[N];
    ArrayList<Node> q = new ArrayList<>(N);
    q.add(nodes[maxI]);
    usedNode[maxI] = true;
    for (int i = 0; i < N; i++) {
      Node cur = q.get(i);
      for (int s : cur.S) {
        if (color[s] != 0) {
          usedColor[color[s]] = i;
        }
      }
      int nextColor = 1;
      while (nextColor <= maxS && usedColor[nextColor] == i) {
        ++nextColor;
      }
      for (int s : cur.S) {
        if (color[s] == 0) {
          color[s] = nextColor;
          usedColor[color[s]] = i;
          while (nextColor <= maxS && usedColor[nextColor] == i) {
            ++nextColor;
          }
        }
      }
      for (int n : cur.next) {
        if (usedNode[n]) continue;
        q.add(nodes[n]);
        usedNode[n] = true;
      }
    }
    if (maxS == 0) maxS = 1;
    for (int i = 0; i < M; i++) {
      if (color[i] == 0) color[i] = 1;
    }
    PrintWriter writer = new PrintWriter(System.out);
    writer.println(maxS);
    for (int i = 0; i < M; i++) {
      writer.print(color[i] + (i == M - 1 ? "\n" : " "));
    }
    writer.flush();
  }

  static class Node {
    ArrayList<Integer> next = new ArrayList<>();
    int[] S;

    Node(int s) {
      this.S = new int[s];
    }
  }
}