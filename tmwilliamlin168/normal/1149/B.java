import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.FilterInputStream;
import java.io.BufferedInputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Jenish
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        ScanReader in = new ScanReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DThreeReligions solver = new DThreeReligions();
        solver.solve(1, in, out);
        out.close();
    }

    static class DThreeReligions {
        int q;
        int max = 256;
        int[][][] dp;
        int[][] nextchar;
        int n;
        StringBuffer[] sb = new StringBuffer[4];

        void change(int a, int b, int c) {
            dp[a][b][c] = Integer.MAX_VALUE / 2;
            if (a > 0)
                if (dp[a - 1][b][c] + 1 < n)
                    dp[a][b][c] = Math.min(dp[a][b][c], nextchar[(dp[a - 1][b][c]) + 1][sb[1].charAt(a - 1) - 'a']);

            if (b > 0)
                if (dp[a][b - 1][c] + 1 < n)
                    dp[a][b][c] = Math.min(dp[a][b][c], nextchar[(dp[a][b - 1][c]) + 1][sb[2].charAt(b - 1) - 'a']);

            if (c > 0)
                if (dp[a][b][c - 1] + 1 < n)
                    dp[a][b][c] = Math.min(dp[a][b][c], nextchar[(dp[a][b][c - 1]) + 1][sb[3].charAt(c - 1) - 'a']);
        }

        public void solve(int testNumber, ScanReader in, PrintWriter out) {
            n = in.scanInt();
            q = in.scanInt();
            String world = in.scanString().toLowerCase();
            nextchar = new int[n + 5][26];
            dp = new int[max + 5][max + 5][max + 5];


            sb[0] = new StringBuffer("");
            sb[1] = new StringBuffer("");
            sb[3] = new StringBuffer("");
            sb[2] = new StringBuffer("");
            for (int i = 0; i < 26; ++i) nextchar[n][i] = nextchar[n + 1][i] = Integer.MAX_VALUE / 2;
            for (int pos = n - 1; pos >= 0; --pos) {
                for (int i = 0; i < 26; ++i) {
                    nextchar[pos][i] = (world.charAt(pos) - 'a' == +i ? pos : nextchar[pos + 1][i]);
                }
            }


            dp[0][0][0] = -1;
            while (q-- > 0) {
                char type = in.scanChar();
                if (type == '+') {
                    int nu = in.scanInt();
                    char xx = in.scanChar();
                    sb[nu].append(xx);
                    int max1 = sb[1].length(), max2 = sb[2].length(), max3 = sb[3].length();
                    int min1 = nu == 1 ? max1 : 0;
                    int min2 = nu == 2 ? max2 : 0;
                    int min3 = nu == 3 ? max3 : 0;
                    for (int a = min1; a <= max1; ++a) {
                        for (int b = min2; b <= max2; ++b) {
                            for (int c = min3; c <= max3; ++c) {
                                change(a, b, c);
                            }
                        }
                    }
                } else if (type == '-') {
                    int nu = in.scanInt();
                    if (sb[nu].length() == 0) throw new RuntimeException("ERROR");
                    sb[nu].deleteCharAt(sb[nu].length() - 1);
                }
                boolean answer = dp[sb[1].length()][sb[2].length()][sb[3].length()] < n;


                if (answer) out.println("YES");
                else out.println("NO");

            }


        }

    }

    static class ScanReader {
        private byte[] buf = new byte[4 * 1024];
        private int INDEX;
        private BufferedInputStream in;
        private int TOTAL;

        public ScanReader(InputStream inputStream) {
            in = new BufferedInputStream(inputStream);
        }

        private int scan() {
            if (INDEX >= TOTAL) {
                INDEX = 0;
                try {
                    TOTAL = in.read(buf);
                } catch (Exception e) {
                    e.printStackTrace();
                }
                if (TOTAL <= 0) return -1;
            }
            return buf[INDEX++];
        }

        public char scanChar() {
            int c = scan();
            while (isWhiteSpace(c)) c = scan();
            return (char) c;
        }

        public int scanInt() {
            int I = 0;
            int n = scan();
            while (isWhiteSpace(n)) n = scan();
            int neg = 1;
            if (n == '-') {
                neg = -1;
                n = scan();
            }
            while (!isWhiteSpace(n)) {
                if (n >= '0' && n <= '9') {
                    I *= 10;
                    I += n - '0';
                    n = scan();
                }
            }
            return neg * I;
        }

        public String scanString() {
            int c = scan();
            while (isWhiteSpace(c)) c = scan();
            StringBuilder RESULT = new StringBuilder();
            do {
                RESULT.appendCodePoint(c);
                c = scan();
            } while (!isWhiteSpace(c));
            return RESULT.toString();
        }

        private boolean isWhiteSpace(int n) {
            if (n == ' ' || n == '\n' || n == '\r' || n == '\t' || n == -1) return true;
            else return false;
        }

    }
}