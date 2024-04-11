import java.io.*;
import java.util.*;

public class J {

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
        int[][] a = new int[n][m];
        
        if (n == 1 && m == 1) {
            out.print(1);
            return;
        }
        
        if (n == 1 && m < 4) {
            out.println(-1);
            return;
        }
        
        if (m == 1 && n < 4) {
            out.println(-1);
            return;
        }
        
        if (m == 2 && n == 2) {
            out.println(-1);
            return;
        }
        
        if (m == 1 && n == 4) {
            out.println(3);
            out.println(1);
            out.println(4);
            out.println(2);
            return;
        }
        
        if (m == 4 && n == 1) {
            out.print("3 1 4 2");
            return;
        }
        
        if (n == 1) {
            for (int i = 0; i < m; i = i + 2) 
                a[0][i / 2] = i + 1;
            
            for (int i = 1; i < m; i = i + 2)
                a[0][((m + 1) / 2) + (i / 2)] = i + 1;
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    out.print(a[i][j] + " ");
                }
                out.println();
            }
            return;
        }   
        
        if (m == 1) {
            for (int i = 0; i < n; i = i + 2) 
                a[i / 2][0] = i + 1;
            for (int i = 1; i < n; i = i + 2)
                a[((n + 1) / 2) + (i / 2)][0] = i + 1;
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    out.print(a[i][j] + " ");
                }
                out.println();
            }           
            return;
        }   
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                out.print(((i + 1) + ((j + i) % m) * n) + " ");
            }
            out.println();
        }
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
        new J().run();
    }

}