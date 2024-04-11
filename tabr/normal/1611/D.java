import java.text.CollationElementIterator;
import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void solve(InputReader in, PrintWriter out) {
        int n = in.readInt();
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = in.readInt();
            b[i]--;
        }
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = in.readInt();
            p[i]--;
        }
        int[] q = new int[n];
        for (int i = 0; i < n; i++) {
            q[p[i]] = i;
        }
        int[] w = new int[n];
        int mn = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == i) {
                continue;
            }
            w[i] = q[i] - q[b[i]];
            mn = Math.min(mn, w[i]);
        }
        if (mn < 0) {
            out.println(-1);
        } else {
            for (int i : w) {
                out.print(i + " ");
            }
            out.println();
        }
    }

    public static void main(String[] args) throws java.lang.Exception {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        int tt = in.readInt();
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

        public String read() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int readInt() {
            return Integer.parseInt(read());
        }

        public long readLong() {
            return Long.parseLong(read());
        }

        public double readDouble() {
            return Double.parseDouble(read());
        }
    }
}