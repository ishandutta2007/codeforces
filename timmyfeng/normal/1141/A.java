import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt(), m = in.nextInt();
        if (m % n != 0) {
            out.println(-1);
        } else {
            m /= n;
            int ans = 0;
            while (m % 3 == 0) {
                m /= 3;
                ++ans;
            }
            while (m % 2 == 0) {
                m /= 2;
                ++ans;
            }
            out.println(m == 1 ? ans : -1);
        }

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