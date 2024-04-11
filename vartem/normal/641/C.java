import java.io.*;
import java.util.StringTokenizer;

public class C2 {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt(), q = in.nextInt();
        int[] a1 = new int[n / 2], a2 = new int[n / 2];
        for (int i = 0; i < n / 2; i++) {
            a1[i] = 2 * i;
            a2[i] = 2 * i + 1;
        }
        int shift1 = 0, shift2 = 0;
        for (int i = 0; i < q; i++) {
            int t = in.nextInt();
            if (t == 1) {
                int s = -in.nextInt();
                if (s < 0) {
                    s = n + s;
                }
                if (s % 2 != 0) {
                    int[] tmpA = a1;
                    a1 = a2;
                    a2 = tmpA;
                    int tmp = shift1;
                    shift1 = shift2;
                    shift2 = tmp;
                    shift2++;
                }
                shift1 = (shift1 + s / 2) % (n / 2);
                shift2 = (shift2 + s / 2) % (n / 2);
            } else {
                int[] tmpA = a1;
                a1 = a2;
                a2 = tmpA;
                int tmp = shift1;
                shift1 = shift2;
                shift2 = tmp;
            }
        }

        for (int i = 0; i < n / 2; i++) {
            out.print((a1[(shift1 + i) % (n / 2)] + 1) + " ");
            out.print((a2[(shift2 + i) % (n / 2)] + 1) + " ");
        }
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
        new C2().runIO();
    }
}