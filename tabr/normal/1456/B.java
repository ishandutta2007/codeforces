import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n - 1; i++) {
            int b = a[i] ^ a[i + 1];
            if (i != 0 && b < a[i - 1]) {
                out.println(1);
                return;
            }
            if (i != n - 2 && b > a[i + 2]) {
                out.println(1);
                return;
            }
        }
        int ans = n;
        for (int i = 0; i < n; i++) {
            int b = 0;
            for (int j = i; j < n; j++) {
                b ^= a[j];
                if (i != 0 && b < a[i - 1]) {
                    ans = Math.min(ans, j - i);
                }
                if (j != n - 1 && b > a[j + 1]) {
                    ans = Math.min(ans, j - i);
                }
                int c = 0;
                for (int k = j + 1; k < n; k++) {
                    c ^= a[k];
                    if (b > c) {
                        ans = Math.min(ans, k - i - 1);
                    }
                }
            }
        }
        if (ans == n) {
            ans = -1;
        }
        out.println(ans);
    }

    public static void main(String[] args) throws java.lang.Exception {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
//        int tt = in.nextInt();
        int tt = 1;
        for (int qq = 1; qq <= tt; qq++) {
            solve(in, out);
        }
        out.close();
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
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

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}