import java.io.*;

public class CF494A {

    public static void solve(Input in, PrintWriter out) throws IOException {
        String s = in.next();
        int n = s.length();
        int stack = 0;
        int add0 = 1;
        int count = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s.charAt(i) == '#') {
                count++;
                stack++;
            } else if (s.charAt(i) == ')') {
                stack++;
            } else if (s.charAt(i) == '(') {
                if (stack == 0) {
                    if (count == 0) {
                        out.println(-1);
                        return;
                    }
                    stack++;
                    add0++;
                }
                stack--;
            } else {
                throw new AssertionError();
            }
        }
        if (stack != 0) {
            out.println(-1);
            return;
        }
        for (int i = 1; i < count; ++i) {
            out.println(1);
        }
        out.println(add0);
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