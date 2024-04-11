import java.io.*;

public class CF494B {

    final static long mod = 1000000007;

    public static void solve(Input in, PrintWriter out) throws IOException {
        String s = in.next();
        String t = in.next();
        int[] pf = new int[t.length() + 1];
        for (int i = 2; i <= t.length(); ++i) {
            pf[i] = pf[i - 1];
            while (pf[i] > 0 && t.charAt(pf[i]) != t.charAt(i - 1)) {
                pf[i] = pf[pf[i]];
            }
            if (t.charAt(pf[i]) == t.charAt(i - 1)) {
                ++pf[i];
            }
        }
        long[] d = new long[s.length() + 1];
        long[] sumd = new long[s.length() + 1];
        d[0] = 1;
        int pf1 = 0;
        int last = 0;
        long cur = 0;
        for (int i = 1; i <= s.length(); ++i) {
            sumd[i] = (sumd[i - 1] + d[i - 1]) % mod;
            while (pf1 > 0 && (pf1 == t.length() || t.charAt(pf1) != s.charAt(i - 1))) {
                pf1 = pf[pf1];
            }
            if (t.charAt(pf1) == s.charAt(i - 1)) {
                ++pf1;
            }
            if (pf1 == t.length()) {
                cur = (cur + (sumd[i - t.length() + 1] + mod - sumd[last])) % mod;
                last = i - t.length() + 1;
            }
            d[i] = (d[i - 1] + cur) % mod;
        }
        out.println((d[s.length()] + mod - 1) % mod);
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        solve(new Input(new BufferedReader(new InputStreamReader(System.in))), out);
        out.close();
    }

    static class Input {
        BufferedReader in;
        StringBuilder sb = new StringBuilder();

        public Input(BufferedReader in) {
            this.in = in;
        }

        public Input(String s) {
            this.in = new BufferedReader(new StringReader(s));
        }

        public String next() throws IOException {
            sb.setLength(0);
            while (true) {
                int c = in.read();
                if (c == -1) {
                    return null;
                }
                if (" \n\r\t".indexOf(c) == -1) {
                    sb.append((char)c);
                    break;
                }
            }
            while (true) {
                int c = in.read();
                if (c == -1 || " \n\r\t".indexOf(c) != -1) {
                    break;
                }
                sb.append((char)c);
            }
            return sb.toString();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}