import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();
        String s = in.next();
        int[] x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = s.charAt(i) - '0';
        }
        List<List<Integer>> a = new ArrayList<>();
        while (true) {
            List<Integer> b = new ArrayList<>();
            List<Integer> c = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (x[i] == 1) {
                    b.add(i);
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                if (x[i] == 0) {
                    c.add(i);
                }
            }
            List<Integer> d = new ArrayList<>();
            for (int i = 0; i < Math.min(b.size(), c.size()); i++) {
                if (b.get(i) < c.get(i)) {
                    d.add(b.get(i));
                    d.add(c.get(i));
                } else {
                    break;
                }
            }
            if (d.isEmpty()) {
                break;
            }
            Collections.sort(d);
            a.add(d);
            for (int i = 0; i < d.size() - 1 - i; i++) {
                x[d.get(i)] = 0;
                x[d.get(d.size() - 1 - i)] = 1;
            }
        }
        out.println(a.size());
        for (int i = 0; i < a.size(); i++) {
            out.print(a.get(i).size());
            for (int j = 0; j < a.get(i).size(); j++) {
                out.print(" " + (a.get(i).get(j) + 1));
            }
            out.println();
        }
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