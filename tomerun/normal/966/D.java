import java.io.PrintWriter;
import java.util.*;

public class Main {
  static Scanner sc = new Scanner(System.in);
  static ArrayList<ArrayList<Integer>> g = new ArrayList<>();
  static int N, M;
  static ArrayList<Integer> ans = new ArrayList<>();
  static int[] depth;

  public static void main(String[] args) {
    N = sc.nextInt();
    M = sc.nextInt();
    for (int i = 0; i < N; i++) {
      g.add(new ArrayList<>());
    }
    boolean[] f = new boolean[N];
    for (int i = 0; i < M; i++) {
      int u = Integer.parseInt(sc.next()) - 1;
      int v = Integer.parseInt(sc.next()) - 1;
      if (u == 0) f[v] = true;
      if (v == 0) f[u] = true;
      g.get(u).add(v);
      g.get(v).add(u);
    }
    shortest();
    if (ans.isEmpty() || ans.size() > 5) {
      for (int i = 1; i < N; i++) {
        for (int j : g.get(i)) {
          if (j != 0 && f[i] && !f[j]) {
            ans.clear();
            ans.add(0);
            ans.add(i);
            ans.add(j);
            ans.add(0);
            ans.add(N - 1);
          }
        }
      }
    }
    if (ans.isEmpty() || ans.size() > 6) {
      boolean[] visited = new boolean[N];
      LOOP:
      for (int i = 1; i < N; i++) {
        if (!f[i] || visited[i]) continue;
        ArrayList<Integer> clique = new ArrayList<>();
        ArrayList<HashSet<Integer>> set = new ArrayList<>();
        clique.add(i);
        set.add(new HashSet<>(g.get(i)));
        for (int n : g.get(i)) {
          if (n == 0) continue;
          visited[n] = true;
          for (int j = 1; j < set.size(); ++j) {
            if (!set.get(j).contains(n)) {
              ans.clear();
              ans.add(0);
              ans.add(clique.get(j));
              ans.add(i);
              ans.add(n);
              ans.add(clique.get(j));
              ans.add(N - 1);
              break LOOP;
            }
          }
          clique.add(n);
          set.add(new HashSet<>(g.get(n)));
        }
        for (int j = 1; j < clique.size(); j++) {
          for (int n : g.get(clique.get(j))) {
            if (n == 0 || n == i) continue;
            if (!set.get(0).contains(n)) {
              ans.clear();
              ans.add(0);
              ans.add(i);
              ans.add(clique.get(j));
              ans.add(n);
              ans.add(i);
              ans.add(N - 1);
              break LOOP;
            }
          }
        }
      }
    }
    PrintWriter writer = new PrintWriter(System.out);
    if (ans.isEmpty()) {
      writer.println(-1);
    } else {
      writer.println(ans.size() - 1);
      for (int i = 0; i < ans.size(); i++) {
        writer.print((ans.get(i) + 1) + (i == ans.size() - 1 ? "\n" : " "));
      }
    }
    writer.flush();
  }

  static void dfs(int s, boolean[] visited) {
    System.err.println("dfs start:" + s);
    ArrayList<Frame> stack = new ArrayList<>();
    Frame f = new Frame();
    f.vs.add(s);
    stack.add(f);
    while (!stack.isEmpty()) {
      f = stack.get(stack.size() - 1);
      System.err.println("dfs:" + stack.size() + " " + f.vs + " " + f.idx);
      if (f.idx > 0) depth[f.vs.get(f.idx - 1)] = -1;
      if (f.idx == f.vs.size()) {
        stack.remove(stack.size() - 1);
        continue;
      }
      int v = f.vs.get(f.idx++);
      if (depth[v] != -1) {
        System.err.println(v + " " + stack.size() + " " + depth[v] + " " + Arrays.toString(depth));
        int len = stack.size() - depth[v];
        if (ans.isEmpty() || ans.size() > len) {
          ans.clear();
          ans.add(0);
          for (int d = depth[v]; d < stack.size(); ++d) {
            ans.add(stack.get(d).vs.get(stack.get(d).idx - 1));
          }
          ans.add(N - 1);
        }
        continue;
      }
      if (visited[v]) continue;
      visited[v] = true;
      depth[v] = stack.size() - 1;
      Frame nf = new Frame();
      for (int nv : g.get(v)) {
        if (nv != 0) nf.vs.add(nv);
      }
      stack.add(nf);
    }
  }

  static class Frame {
    ArrayList<Integer> vs = new ArrayList<>();
    int idx;
  }

  static void shortest() {
    int[] prev = new int[N];
    Arrays.fill(prev, -1);
    ArrayList<Integer> cur = new ArrayList<>();
    cur.add(0);
    while (!cur.isEmpty()) {
      ArrayList<Integer> next = new ArrayList<>();
      for (int v : cur) {
        for (int u : g.get(v)) {
          if (prev[u] != -1) continue;
          prev[u] = v;
          next.add(u);
        }
      }
      cur = next;
    }
    if (prev[N - 1] != -1) {
      int v = N - 1;
      ans.add(v);
      while (v != 0) {
        v = prev[v];
        ans.add(v);
      }
      Collections.reverse(ans);
    }
  }

}