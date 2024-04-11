import java.io.*;
import java.util.*;

public class F {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt(), m = in.nextInt();
        char[][] field = new char[n][m];
        for (int i = 0; i < n; i++) {
            field[i] = in.nextToken().toCharArray();
        }

        long ans = 0;

        int[][] sum = new int[Math.max(n, m) + 1][Math.max(n, m)+  1];

        for (int ROT = 0; ROT < 4; ROT++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    sum[i + 1][j + 1] = (field[i][j] == '#' ? 1 : 0)
                            + sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
                }
            }

            // left -> top/bottom
            for (int i = 1; i < n - 1; i++) {
                for (int j = 1; j < m - 1; j++) {
                    {
                        int s = sum[i + 1][j + 1] -  sum[i][j + 1];
                        if (s > 0) {
                            break;
                        }
                    }
                    // left
                    int s = sum[i + 1][j + 1] - sum[i + 1][j];
                    if (s == 0) {
                        ans++;
                    }
                    s = (sum[n][j + 1] - sum[n][j]) - s;
                    if (s == 0) {
                        ans++;
                    }
                }
            }

            int[] maxLeft = new int[n], maxRight = new int[n];

            for (int j = 0; j < n; j++) {
                int pos = 0;
                while (pos < m && field[j][pos] == '.') {
                    pos++;
                }
                maxLeft[j] = pos - 1;
            }
            for (int j = 0; j < n; j++) {
                int pos = m - 1;
                while (pos >= 0 && field[j][pos] == '.') {
                    pos--;
                }
                maxRight[j] = pos + 1;
            }

            for (int col = 1; col < m - 1; col++) {
                for (int i = 1; i < n - 1;) {
                    if (field[i][col] == '#') {
                        i++;
                        continue;
                    }

                    int j = i;
                    int countLeft = 0, countRight = 0;
                    while (j < n - 1 && field[j][col] == '.') {
                        if (maxLeft[j] >= col) {
                            countLeft++;
                        }
                        if (maxRight[j] <= col) {
                            countRight++;
                        }
                        j++;
                    }
                    
                    // left -> left
                    for (int t = i; t < j; t++ ){
                        if (maxLeft[t] >= col) {
                            int add = countLeft - 1;
                            if (t > i && maxLeft[t - 1] >= col) {
                                add--;
                            }
                            if (t + 1 < j && maxLeft[t + 1] >= col) {
                                add--;
                            }
                            ans += add;
                        }
                    }
                    // left -> right
                    ans += countLeft * countRight;
                    i = j;
                }
            }
            for (int i = 1; i < n - 1; i++) {
                if (maxLeft[i] == m - 1) {
                    ans -= (m - 2);
                    ans++;
                }
            }

            field = rotate(field);
            n = field.length;
            m = field[0].length;
        }
        
        System.err.println(ans);
        out.println(ans / 2);
    }

    private char[][] rotate(char[][] field) {
        char[][] newField = new char[field[0].length][field.length];
        for (int i = 0; i < field.length; i++) {
            for (int j = 0; j < field[0].length; j++) {
                newField[j][field.length - i - 1] = field[i][j];
            }
        }
        return newField;
    }

    void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new F().run();
    }
}