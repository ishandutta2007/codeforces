import java.io.*;
import java.util.*;

public class E {

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        Solver solver = new Solver();
        solver.solve(in, out);
        out.close();
    }

    private static class Solver {

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();

            int[] a = new int[n + 1];
            int[] pos = new int[n + 1];

            for (int i = 1; i <= n; i++) {
                a[i] = in.nextInt();
                pos[a[i]] = i;
            }

            int[] l = new int[n + 1];
            int[] r = new int[n + 1];

            Stack<Integer> stack = new Stack<>();
            for (int i = 1; i <= n; i++) {
                while (!stack.isEmpty() && stack.peek() < a[i])
                    r[stack.pop()] = i - 1;

                if (!stack.isEmpty())
                    l[a[i]] = pos[stack.peek()] + 1;
                else
                    l[a[i]] = 1;

                stack.push(a[i]);
            }
            while (!stack.isEmpty())
                r[stack.pop()] = n;

            int ans = 0;
            for (int ai = 1; ai <= n; ai++) {
                if (pos[ai] - l[ai] <= r[ai] - pos[ai]) {
                    for (int j = pos[ai] - 1; j >= l[ai]; j--) {
                        if (pos[ai] + 1 <= pos[ai - a[j]] && pos[ai - a[j]] <= r[ai])
                            ans++;
                    }
                } else {
                    for (int j = pos[ai] + 1; j <= r[ai]; j++) {
                        if (l[ai] <= pos[ai - a[j]] && pos[ai - a[j]] <= pos[ai] - 1)
                            ans++;
                    }
                }
            }

            out.println(ans);
        }
    }

    private static class InputReader {
        private BufferedReader br;
        private StringTokenizer st;

        public InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        private int nextInt() {
            return Integer.parseInt(next());
        }

        private long nextLong() {
            return Long.parseLong(next());
        }

        private double nextDouble() {
            return Double.parseDouble(next());
        }

        private String nextLine() {
            String s = "";
            try {
                s = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return s;
        }

        private String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
    }
}