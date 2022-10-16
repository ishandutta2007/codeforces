import java.io.*;
import java.util.*;

public class A {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int k = in.nextInt();
        
        out.println("+------------------------+");
        char[][] ok = new char[4][11];
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 4; j++) {
                if (i > 0 && j == 2) {
                    ok[j][i] = '.';
                    continue;
                }
                if (k > 0) {
                    ok[j][i] = 'O';
                    k--;
                } else {
                    ok[j][i] = '#';
                }
            }
            
        }
        
        
        String[] end = new String[] {
                "|D|)",
                "|.|",
                "..|",
                "|.|)",
        };
        
        for (int i =0; i < 4; i++) {
            out.print('|');
            for (int j = 0; j < 11; j++) {
                out.print(ok[i][j]);
                out.print('.');
            }
            out.println(end[i]);
        }

        
        out.println("+------------------------+");
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
        new A().run();
    }
}