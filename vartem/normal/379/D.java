import java.io.*;
import java.util.*;

public class D {

    public void solve() {
        int k = in.nextInt(), x = in.nextInt(), n = in.nextInt(), m = in.nextInt();
        
        int MAX = 100;
        String[][][][] strings = new String[MAX + 1][MAX / 2 + 1][4][4];
        for (int i = 0; i < 4; i++) {
            strings[1][0][i][i] = "" + chars.charAt(i);
        }
        for (int len = 1; len < MAX; len++) {
            for (int occurs = 0; occurs <= MAX / 2; occurs++) {
                for (int first = 0; first < 4; first++ ){
                    for (int second = 0; second < 4; second++) {
                        if (strings[len][occurs][first][second] != null) {
                            for (int third = 0; third < 4; third++) {
                                int newOccurs = occurs + ((second == 0 && third == 2) ? 1 : 0);
                                if (strings[len + 1][newOccurs][first][third] == null) {
                                    strings[len + 1][newOccurs][first][third] = strings[len][occurs][first][second] + (char) ('A' + third);
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int a0 = 0; a0 < 4; a0++) {
            for (int a1 = 0; a1 < 4; a1++) {
                for (int b0 = 0; b0 < 4; b0++) {
                    for (int b1 = 0; b1 < 4; b1++) {
                        int realA1 = a1, realB1 = b1;
                        if (n == 1) {
                            realA1 = a0;
                        }
                        if (m == 1) {
                            realB1 = b0;
                        }
                        for (int count1 = 0; count1 <= 50; count1++) {
                            for (int count2 = 0; count2 <= 50; count2++) {
                                String s1 = strings[n][count1][a0][realA1];
                                String s2 = strings[m][count2][b0][realB1];
                                if (s1 == null || s2 == null) {
                                    continue;
                                }
                                if (get(n, a0, realA1, count1, m, b0, realB1, count2, k) == x) {
                                    out.println(s1);
                                    out.println(s2);
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
        out.println("Happy new year!");
    }

    String chars = "ABCD";
    
    private long get(int n, int a0, int a1, long count1, int m, int b0, int b1, long count2, int k) {
        if (k == 2) {
            return count2;
        }
        return get(m, b0, b1, count2, n + m, a0, b1, count1 + count2 + ((a1 == 0 && b0 == 2) ? 1 : 0), k - 1);
    }

    FastScanner in;
    PrintWriter out;

    public void run() {
        try {
            in = new FastScanner();
            out = new PrintWriter(System.out);
            solve();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String name) {
            try {
                br = new BufferedReader(new FileReader(name));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new D().run();
    }
}