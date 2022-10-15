//Created by Aminul on 3/7/2019.

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class F1 {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = in.nextInt(), m = in.nextInt();
        TreeSet<Integer> set[] = new TreeSet[n + 1];
        for (int i = 0; i <= n; i++) {
            set[i] = new TreeSet<>();
        }
        int maxDegreeNode = 0;
        for (int i = 1; i <= m; i++) {
            int u = in.nextInt(), v = in.nextInt();
            set[u].add(v);
            set[v].add(u);
            if (set[u].size() > set[maxDegreeNode].size()) {
                maxDegreeNode = u;
            }
            if (set[v].size() > set[maxDegreeNode].size()) {
                maxDegreeNode = v;
            }
        }


        DSU dsu = new DSU(n + 1);
        for (int v : set[maxDegreeNode]) {
            if (dsu.union(maxDegreeNode, v)) {
                pw.println(maxDegreeNode + " " + v);
            }
        }

        for (int u = 1; u <= n; u++) {
            for (int v : set[u]) {
                if (dsu.union(u, v)) {
                    pw.println(u + " " + v);
                }
            }
        }

        pw.close();
    }

    static void debug(Object... obj) {
        System.err.println(Arrays.deepToString(obj));
    }

    static class DSU {
        int parent[], size[], n;

        DSU(int N) {
            n = N;
            parent = new int[N];
            size = new int[N];
            for (int i = 0; i < N; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        DSU(int[] p) {
            parent = p;
            n = p.length;
        }

        int find(int i) {
            int p = parent[i];
            if (i == p) return i;
            return parent[i] = find(p);
        }

        boolean equiv(int u, int v) {
            return find(u) == find(v);
        }

        boolean union(int u, int v) {
            u = find(u);
            v = find(v);
            if (u == v) return false;
            if (size[u] > size[v]) {
                int t = u;
                u = v;
                v = t;
            }
            parent[u] = v;
            size[v] += size[u];
            return true;
        }

        int count() {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (i == find(i)) cnt++;
            }
            return cnt;
        }
    }
}