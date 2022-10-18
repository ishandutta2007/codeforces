import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();
        String s = in.next();
        int[][] a = new int[3][n + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                a[j][i + 1] = a[j][i];
            }
            a[s.charAt(i) - 'a'][i + 1]++;
        }
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) != 'a') {
                continue;
            }
            for (int j = i + 1; j < Math.min(i + 10, n); j++) {
                if (a[0][j + 1] - a[0][i] > Math.max(a[1][j + 1] - a[1][i], a[2][j + 1] - a[2][i])) {
                    ans = Math.min(ans, j - i + 1);
                }
            }
        }
        if (ans == n + 1) {
            ans = -1;
        }
        out.println(ans);
    }

    public static void main(String[] args) throws java.lang.Exception {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        int tt = in.nextInt();
//        int tt = 1;
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