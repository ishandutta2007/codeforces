import java.io.*;
import java.util.*;

public class B {

    MyScanner in;
    PrintWriter out;
    final static String filename = "";

    class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner(String file) {
            try {
                br = new BufferedReader(new FileReader(file));
                st = new StringTokenizer("");
            } catch (FileNotFoundException e) {
                e.printStackTrace();
                System.exit(1);
            }
        }

        public MyScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
            st = new StringTokenizer("");
        }

        String nextToken() {
            try {
                while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(br.readLine());

            } catch (IOException e) {
                e.printStackTrace();
                System.exit(1);
            }

            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(this.nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(this.nextToken());
        }

        long nextLong() {
            return Long.parseLong(this.nextToken());
        }

        void close() throws IOException {
            br.close();
        }
    }

    int[] a;
    int n;

    void solve() throws IOException {
        n = in.nextInt();
        int m = in.nextInt();
        
        int[][] g = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0 ; j < m; j++)
                g[i][j] = in.nextInt();
        
        int a = in.nextInt();
        int b = in.nextInt();
        int min = Integer.MAX_VALUE;
        
        for (int n1 = 0; n1 <= n - a; n1++)
            for (int m1 = 0; m1 <= m - b; m1++) {
                int res = 0;
                for (int i = n1; i < n1 + a; i++) 
                    for (int j = m1 ; j < m1 + b; j++)
                        res += g[i][j];
                if (res < min)
                    min = res;                      
            }   
        
        
        for (int n1 = 0; n1 <= n - b; n1++)
            for (int m1 = 0; m1 <= m - a; m1++) {
                int res = 0;
                for (int i = n1; i < n1 + b; i++) 
                    for (int j = m1 ; j < m1 + a; j++)
                        res += g[i][j];
                if (res < min)
                    min = res;                      
            }   
        
        out.println(min);
    }

    void run() {
        try {
            in = new MyScanner(System.in);
            out = new PrintWriter(System.out);

            solve();

            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }

    }

    public static void main(String[] args) {
        new B().run();
    }

}