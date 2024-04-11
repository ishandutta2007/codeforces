import java.io.*;
import java.util.*;

public class B {

    FastScanner in;
    PrintWriter out;
    

    void solve() {
        int n = in.nextInt(), m = in.nextInt();
        String s = in.nextToken(), t = in.nextToken();
        
        int k = n * m;
        boolean[][] a = new boolean[k][k];
        
        for (int i = 0; i < k; i++) {
            a[i][i] = true;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (i + 1 < n && t.charAt(j) == 'v') {
                    a[i * m + j][(i + 1) * m + j] = true;
                }
                if (i - 1 >= 0 && t.charAt(j) == '^') {
                    a[i * m + j][(i - 1) * m + j] = true;
                }

                if (j + 1 < m && s.charAt(i) == '>') {
                    a[i * m + j][i * m + j + 1] = true;
                }
                if (j - 1 >= 0 && s.charAt(i) == '<') {
                    a[i * m + j][i * m + j - 1] = true;
                }
            }
        }
        
        for (int x = 0; x < k; x++) {
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    a[i][j] |= a[i][x] & a[x][j];
                }
            }
        }
        

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (!a[i][j]) {
                    out.println("NO");
                    return;
                }
            }
        }
        out.println("YES");
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
        new B().run();
    }
}