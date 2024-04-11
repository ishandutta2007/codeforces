import java.io.*;

public class memsqlA {

    public static void solve(Input in, PrintWriter out) throws IOException {
        String s = in.next();
        int n = in.nextInt();
        int[] counts = new int[26];
        for (char c : s.toCharArray()) {
            counts[c - 'a']++;
        }
        int l = 0, r = s.length() + 1;
        while (l < r - 1) {
            int mid = (l + r) / 2;
            int sm = 0;
            for (int i = 0; i < 26; ++i) {
                sm += (counts[i] + mid - 1) / mid;
            }
            if (sm <= n) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (r == s.length() + 1) {
            out.println(-1);
        } else {
            out.println(r);
            StringBuilder ans = new StringBuilder();
            for (int i = 0; i < 26; ++i) {
                for (int t = 0; t < (counts[i] + r - 1) / r; ++t) {
                    ans.append((char)('a' + i));
                }
            }
            while (ans.length() < n) {
                ans.append('a');
            }
            out.println(ans);
        }
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