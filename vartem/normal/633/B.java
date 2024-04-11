import java.io.*;
import java.util.*;

public class B {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int need = in.nextInt();
        List<Integer> result = new ArrayList<>();
        int MAX = 1_000_000;
        for (int i = 0; i < MAX; i++) {
            int mult = 0;
            int n = i / 5;
            while (n > 0) {
                mult += n;
                n /= 5;
            }
            if (mult == need) {
                result.add(i);
            }
        }
        out.println(result.size());
        for (int i : result) {
            out.print(i + " ");
        }
        out.println();
    }

    void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new B().runIO();
    }
}