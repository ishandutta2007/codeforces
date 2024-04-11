import java.io.*;
import java.util.*;

public class A {

    final int[] dx = new int[] { 1, 0, -1, 0 };
    final int[] dy = new int[] { 0, 1, 0, -1 };

    public void solve() {
        int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
        char[][] field = new char[n][];
        int[] q = new int[2 * n * m];
        int head = 0, tail = 0;
        for (int i = 0; i < n; i++) {
            field[i] = in.nextToken().toCharArray();
        }

        boolean[][] used = new boolean[n][m];
        boolean[][] ans = new boolean[n][m];
        boolean ok = true;
        int countFree = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] == '.') {
                    countFree++;
                    if (ok) {
                        q[tail++] = i;
                        q[tail++] = j;
                        used[i][j] = true;
                        ok = false;
                    }
                }
            }
        }
        k = countFree - k;
        while (head < tail) {
            int i = q[head++], j = q[head++];
            if (k == 0) {
                break;
            }
            ans[i][j] = true;
            k--;
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if (0 <= ni && ni < n && 0 <= nj && nj < m && field[ni][nj] == '.') {
                    if (!used[ni][nj]) {
                        used[ni][nj] = true;
                        q[tail++] = ni;
                        q[tail++] = nj;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] == '#' || ans[i][j]) {
                    out.print(field[i][j]);
                } else {
                    out.print('X');
                }
            }
            out.println();
        }
    }

    FastScanner in;
    PrintWriter out;

    public void run() {
        try {
            in = new FastScanner();
            out = new PrintWriter(System.out);
            solve();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String name) {
            try {
                br = new BufferedReader(new FileReader(name));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new A().run();
    }
}