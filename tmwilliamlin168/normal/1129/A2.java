import java.io.*;
import java.util.*;

public class D2_ToyTrain {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader inp = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        solver.solve(inp, out);
        out.close();
    }

    static class Solver {
        int n;
        private int dist(int a, int b) {
            return (b + n - a) % n;
        }

        private void solve(InputReader inp, PrintWriter out) {
            n = inp.nextInt();
            int m = inp.nextInt();
            ArrayList<Integer>[] candies = new ArrayList[n];
            for (int i = 0; i < n; i++) candies[i] = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                int a = inp.nextInt() - 1;
                int b = inp.nextInt() - 1;
                int dist = dist(a, b);
                candies[a].add(dist);
            }
            for (ArrayList<Integer> i: candies) Collections.sort(i);
            for (int i = 0; i < n; i++) {
                int total = 0;
                for (int j = 0; j < n; j++) {
                    if (candies[j].size() > 0) {
                        int needed = dist(i, j) + Math.max(0, candies[j].size() - 1) * n + candies[j].get(0);
                        total = Math.max(total, needed);
                    }
                }
                out.print(total + " ");
            }

        }
    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }
}