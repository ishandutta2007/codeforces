import java.io.*;
import java.util.*;

public class NewSets {
    boolean[] used;
    int n;
    ArrayList<Integer> ans;
    int[][] a;

    void dfs(int i) {
        ans.add(i);
        used[i] = true;
        for (int j = 1; j < 201; j++)
            if (a[i][j] == n - 1 && !used[j])
                dfs(j);
    }

    void solve() throws Exception {
        n = nextInt();
        int nn = (n) * (n - 1) / 2;
        TreeSet<Integer> all = new TreeSet<Integer>();
        a = new int[201][201];
        if (n == 2) {
            int t = nextInt();
            out.println("1 " + nextInt());
            out.print((t - 1) + " ");
            for (int i = 0; i < t - 1; i++)
                out.print(nextInt() + " ");
            out.println();
            return;
        }
        for (int i = 0; i < nn; i++) {
            int cnt = nextInt();
            int[] r = new int[cnt];
            for (int j = 0; j < cnt; j++) {
                r[j] = nextInt();
                all.add(r[j]);
            }
            for (int j = 0; j < cnt; j++)
                for (int k = j + 1; k < cnt; k++) {
                    a[r[j]][r[k]]++;
                    a[r[k]][r[j]]++;
                }
        }
        used = new boolean[201];
        for (int i : all) {
            if (used[i])
                continue;
            ans = new ArrayList<Integer>();
            dfs(i);
            out.print(ans.size() + " ");
            for (int j : ans)
                out.print(j + " ");
            out.println();
        }

    }

    void run() {
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;
    final String filename = new String("Sets").toLowerCase();

    String nextToken() throws Exception {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(in.readLine());
        return st.nextToken();
    }

    int nextInt() throws Exception {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws Exception {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws Exception {
        return Double.parseDouble(nextToken());
    }

    public static void main(String[] args) {
        new NewSets().run();
    }

}