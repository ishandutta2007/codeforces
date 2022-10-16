import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/**
 * Created by Meepo on 3/11/2017.
 */
public class A {
    public static void main(String[] args) {
        new A().run();
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public void solve() throws IOException {
        int n = nextInt();
        ArrayList<Integer>[] e = new ArrayList[n];
        int m = nextInt();
        for (int i = 0; i < n; i++) {
            e[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
            e[a].add(b);
            e[b].add(a);
        }

        for (int i = 0; i < n; i++) {
            e[i].add(i);
            Collections.sort(e[i]);
        }

        boolean[] checked = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (checked[i])
                continue;
            for (int v : e[i]) {
                checked[v] = true;
                if (v == i)
                    continue;
                if (e[i].size() != e[v].size()) {
                    out.println("NO");
                    return;
                }
                for (int j = 0; j < e[i].size(); j++) {
                    if (e[i].get(j).compareTo(e[v].get(j)) != 0) {
                        out.println("NO");
                        return;
                    }
                }
            }
        }
        out.println("YES");
    }

    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}