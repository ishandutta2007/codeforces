import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            List<Point> odd = new ArrayList<>(), even = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int x = in.nextInt(), y = in.nextInt();
                if ((x + y) % 2 == 0) {
                    even.add(new Point((x + y), (x - y)));
                } else {
                    odd.add(new Point(x + y, x - y));
                }
            }
            out.println(solve(odd) + solve(even));
        }

        private long solve(List<Point> even) {
            if (even.size() == 0) {
                return 0;
            }
            Collections.sort(even, ((o1, o2) -> {
                if (o1.x != o2.x) {
                    return o1.x - o2.x;
                } else {
                    return o1.y - o2.y;
                }
            }));
            int odd = (even.get(0).x) & 1;
            odd ^= 1;
            long ans = 0;
            int n = even.size();
            int[] sufMin = new int[n], sufMax = new int[n], prefMin = new int[n], prefMax = new int[n];
            for (int i = 0; i < n; i++) {
                prefMin[i] = prefMax[i] = even.get(i).y;
                if (i > 0) {
                    prefMin[i] = Math.min(prefMin[i], prefMin[i - 1]);
                    prefMax[i] = Math.max(prefMax[i], prefMax[i - 1]);
                }
            }

            for (int i = n - 1; i >= 0; i--) {
                sufMin[i] = sufMax[i] = even.get(i).y;
                if (i + 1 < n) {
                    sufMin[i] = Math.min(sufMin[i], sufMin[i + 1]);
                    sufMax[i] = Math.max(sufMax[i], sufMax[i + 1]);
                }
            }
            int MAX = 300_000;
            int INF = (int) 1e9;
            int left = 0, right = 0;
            for (int coord = -MAX; coord <= MAX; coord++) {
                while (left < n && even.get(left).x < coord) {
                    left++;
                }
                while (right < n && even.get(right).x <= coord) {
                    right++;
                }

                int L = Math.max(left == 0 ? INF : prefMin[left - 1], right == n ? INF : sufMin[right]);
                int R = Math.min(left == 0 ? -INF : prefMax[left - 1], right == n ? -INF : sufMax[right]);
                if (L <= R && (coord & 1) == odd) {
                    ans += (R - L) / 2;
                }
            }
            return ans;
        }

        class Point {
            int x;
            int y;

            public Point(int x, int y) {
                this.x = x;
                this.y = y;
            }


            public String toString() {
                return "Point{" +
                        "x=" + x +
                        ", y=" + y +
                        '}';
            }

        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
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
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
}