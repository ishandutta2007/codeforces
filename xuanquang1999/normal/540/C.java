import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }

    static int dx[] = {-1, 0, 1, 0};
    static int dy[] = {0, 1, 0, -1};
    static int n, m, r1, c1, r2, c2;
    static String[] s;
    static boolean reachable[][];

    static boolean inBound(int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }

    static void DFS(int x, int y) {
        reachable[x][y] = true;
        if ((x != r1 || y != c1) && s[x].charAt(y) == 'X')
            return;
        for (int dir = 0; dir < 4; ++dir) {
            int u = x + dx[dir], v = y + dy[dir];
            if (inBound(u, v) && !reachable[u][v])
                DFS(u, v);
        }
    }

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        n = sc.nextInt();
        m = sc.nextInt();
        s = new String[n];
        for (int i = 0; i < n; ++i)
            s[i] = sc.next();

        r1 = sc.nextInt() - 1;
        c1 = sc.nextInt() - 1;
        r2 = sc.nextInt() - 1;
        c2 = sc.nextInt() - 1;
        reachable = new boolean[n][m];

        DFS(r1, c1);

        boolean ans = reachable[r2][c2];
        if (s[r2].charAt(c2) == '.' || (r2 == r1 && c2 == c1)) {
            int cnt = 0;
            for (int dir = 0; dir < 4; ++dir) {
                int x = r2 + dx[dir], y = c2 + dy[dir];
                if (inBound(x, y) && (s[x].charAt(y) == '.' || (x == r1 && y == c1)))
                    ++cnt;
            }
            if (r1 == r2 && c1 == c2) ++cnt;
            ans &= (cnt >= 2);
        }

        System.out.println((ans) ? "YES" : "NO");
    }
}