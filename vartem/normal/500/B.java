import java.io.*;
import java.util.*;

public class B {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = in.nextInt();
        }
        
        boolean[][] a = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            String s = in.nextToken();
            for (int j = 0; j < n; j++) {
                a[i][j] = s.charAt(j) == '1';
            }
            a[i][i] = true;
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] |= a[i][k] & a[k][j];
                }
            }
        }
        
        
        boolean[] was = new boolean[n];
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            if (!was[i]) {
                
                List<Integer> pos = new ArrayList<Integer>();
                List<Integer> vals = new ArrayList<Integer>();
                
                for (int j = 0; j < n; j++) {
                    if (a[i][j]) {
                        pos.add(j);
                        vals.add(p[j]);
                        was[j] = true;
                    }
                }
                
                Collections.sort(vals);
                for (int j = 0; j < pos.size(); j++) {
                    ans[pos.get(j)] = vals.get(j);
                }
                
            }
        }
        
        for (int i = 0; i < n; i++) {
            out.print(ans[i] + " ");
        }
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