import java.lang.reflect.Array;
import java.text.CollationElementIterator;
import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void solve(InputReader in, PrintWriter out) {
        int n = in.readInt();
        long s = in.readLong();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.readLong();
        }
        long[] pref = new long[n + 1];
        pref[0] = 0;
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        long[] mn = new long[n + 10];
        int[] pos = new int[n + 10];
        Arrays.fill(mn, (long) -1e18);
        pos[0] = n + 1;
        int id = 1;
        int ans = 0;
        int front = -1;
        for (int i = n - 1; i >= 0; i--) {
            while (mn[id - 1] >= pref[i + 1]) {
                id--;
            }
            pos[id] = i + 1;
            mn[id] = pref[i + 1];
            id++;
            long t = pref[i] - s;
            int lo = -1, hi = id;
            while (hi - lo > 1) {
                int mid = (hi + lo) / 2;
                if (mn[mid] >= t) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            if (hi == id) {
                continue;
            }
            int k = pos[lo] - 1;
//            System.err.println(k + " " + i + " " + t + " " + id + " " + lo);
//            for (int j = 0; j < id; j++) {
//                System.err.print(mn[j] + " ");
//            }
//            System.err.println();
//            for (int j = 0; j < id; j++) {
//                System.err.print(pos[j] + " ");
//            }
//            System.err.println();
            if (k - i > 0 && ans < k - i) {
                ans = k - i;
                front = i;
            }
        }
        if (ans == 0) {
            out.println(-1);
        } else {
            out.println((front + 1) + " " + (front + ans));
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