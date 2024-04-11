import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DRedaktiruemZingerColor solver = new DRedaktiruemZingerColor();
        solver.solve(1, in, out);
        out.close();
    }

    static class DRedaktiruemZingerColor {
        List<String> ops = Arrays.asList("lock", "unlock", "red", "orange", "yellow", "green", "blue", "indigo", "violet");

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            SegmentTree tree = new SegmentTree(n);
            for (int i = 0; i < n; i++) {
                int op = ops.indexOf(in.next());
                tree.set(0, n, i, op, 0);
            }
            int q = in.nextInt();
            for (int i = 0; i <= q; i++) {
                if (i > 0) {
                    int idx = in.nextInt() - 1, op = ops.indexOf(in.next());
                    tree.set(0, n, idx, op, 0);
                }
                int res = tree.col[0][0];
                out.println(res == 0 ? "blue" : ops.get(res));
            }
        }

        public class SegmentTree {
            int[][] lock;
            int[][] col;

            public SegmentTree(int n) {
                lock = new int[4 * n][2];
                col = new int[4 * n][2];
            }

            private void collect(int i) {
                int l = 2 * i + 1, r = 2 * i + 2;
                for (int start = 0; start < 2; start++) {
                    int curLock = start, curCol = 0;
                    for (int t = 1; t <= 2; t++) {
                        int newLock = lock[2 * i + t][curLock];
                        int newCol = col[2 * i + t][curLock];
                        curLock = newLock;
                        if (newCol != 0) {
                            curCol = newCol;
                        }
                    }
                    lock[i][start] = curLock;
                    col[i][start] = curCol;
                }
            }

            void set(int left, int right, int pos, int op, int i) {
                if (left == right - 1) {
                    if (op == 0) { // lock
                        lock[i][0] = lock[i][1] = 1;
                        col[i][0] = col[i][1] = 0;
                    } else if (op == 1) { // unlock
                        lock[i][0] = lock[i][1] = 0;
                        col[i][0] = col[i][1] = 0;
                    } else {
                        lock[i][0] = 0;
                        lock[i][1] = 1;
                        col[i][0] = op;
                        col[i][1] = 0;
                    }
                    return;
                }

                int mid = (left + right) >>> 1;
                if (pos < mid) {
                    set(left, mid, pos, op, 2 * i + 1);
                } else {
                    set(mid, right, pos, op, 2 * i + 2);
                }
                collect(i);
            }

        }

    }

    static class FastScanner {
        public BufferedReader br;
        public StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (line == null) {
                    throw new UnknownError();
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
}