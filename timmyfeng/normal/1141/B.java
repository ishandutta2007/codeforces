import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }

        int ans = 0, cur = 0;
        for (int i = 0; i < 2 * n; ++i) {
            if (a[i % n] == 0) {
                cur = 0;
            } else {
                ++cur;
            }
            ans = Math.max(ans, cur);
        }

        out.println(ans);

        out.close();
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream str) {
        reader = new BufferedReader(new InputStreamReader(str), 1 << 15);
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
}