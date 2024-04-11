import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Vadim Semenov
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static final class TaskA {
        public void solve(int __, InputReader in, PrintWriter out) {
            int x2 = in.nextInt();
            out.println(solve(x2));
//        long tl = 0;
//        int worst = 0;
//        int worstAnswer = 0;
//        for (int x2 = 1000000; x2 > 3; --x2) {
//            if (x2 % 1000 == 0) System.err.println(tl);
//            long start = System.currentTimeMillis();
//            int answer = solve(x2);
//            long finish = System.currentTimeMillis();
//            if (finish - start > tl) {
//                tl = finish - start;
//                worst = x2;
//                worstAnswer = answer;
//                System.err.println("new worst: " + tl + " " + worst + " " + worstAnswer);
//            }
//        }
//        System.err.println(tl);
        }

        private int solve(int x2) {
            int[] d = new int[x2 + 1];
            d[1] = 1;
            for (int i = 2; i < d.length; ++i) {
                if (d[i] == 0) {
                    for (int j = i; j < d.length; j += i) {
                        d[j] = i;
                    }
                }
            }
            int min = findPrev(x2, d);
            int answer = min;
            for (int i = min; i < x2; ++i) {
                answer = Math.min(answer, findPrev(i, d));
            }
            if (answer < 3) {
                throw new RuntimeException("Polundra");
            }
            return answer;
        }

        private int findPrev(int x2, int[] d) {
            int n = x2;
            int min = n;
            while (n > 1) {
                int prime = d[n];
                min = Math.min(min, Math.max(prime + 1, x2 - prime + 1));
                n /= prime;
            }
            return min;
        }

    }

    static class InputReader {
        private final BufferedReader reader;
        private StringTokenizer tokenizer;

        public InputReader(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(readLine());
            }
            return tokenizer.nextToken();
        }

        public String readLine() {
            String line;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            return line;
        }

    }
}