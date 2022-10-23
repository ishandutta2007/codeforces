import java.io.*;
import java.util.*;

public class B {

    FastScanner in;
    PrintWriter out;

    int[] dx = new int[] { -1, 0, 1, 0 };
    int[] dy = new int[] { 0, 1, 0, -1 };

    void solve() {
        int n = in.nextInt(), m = in.nextInt();
        char[][] field = new char[n][m];
        for (int i = 0; i < n; i++) {
            field[i] = in.nextToken().toCharArray();
        }

        int[][] deg = new int[n][m];
        int[] queue = new int[2 * n * m];
        int head = 0, tail = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] == '*') {
                    continue;
                }
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (0 <= ni && ni < n && 0 <= nj && nj < m
                            && field[ni][nj] == '.') {
                        deg[i][j]++;
                    }
                }
                if (deg[i][j] == 1) {
                    queue[tail++] = i;
                    queue[tail++] = j;
                }
            }
        }

        while (head < tail) {
            int i = queue[head++], j = queue[head++];
            if (field[i][j] != '.') {
                continue;
            }

            int foundI = -1, foundJ = -1;
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if (0 <= ni && ni < n && 0 <= nj && nj < m
                        && field[ni][nj] == '.') {
                    foundI = ni;
                    foundJ = nj;
                    break;
                }
            }
            if (foundI == -1 || foundJ == -1) {
                out.println("Not unique");
                return;
            }

            if (foundI == i) {
                field[i][Math.min(j, foundJ)] = '<';
                field[i][Math.max(j, foundJ)] = '>';
            } else {
                field[Math.min(i, foundI)][j] = '^';
                field[Math.max(i, foundI)][j] = 'v';

            }
            for (int d = 0; d < 4; d++) {
                int ni = foundI + dx[d], nj = foundJ + dy[d];
                if (0 <= ni && ni < n && 0 <= nj && nj < m
                        && field[ni][nj] == '.') {
                    deg[ni][nj]--;
                    if (deg[ni][nj] == 1) {
                        queue[tail++] = ni;
                        queue[tail++] = nj;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] == '.') {
                    out.println("Not unique");
                    return;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            out.println(new String(field[i]));
        }
    }

    void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String nextToken() {
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
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new B().run();
    }
}