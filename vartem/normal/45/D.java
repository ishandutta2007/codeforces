import java.io.*;
import java.util.*;

public class D {

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
        int[] l = new int[n];
        int[] r = new int[n];
        
        for (int i = 0; i < n; i++) {
            l[i] = in.nextInt();
            r[i] = in.nextInt();
        }
        int[] ans = new int[n];
        boolean[] used = new boolean[n];
        
        for (int i = 0; i < n; i++) {
            int min = -1;
            for (int j = 0; j < n; j++) {
                if ((used[j] == false) && (min == -1 || l[j] < l[min] || (l[j] == l[min] && r[j] < r[min]))) {
                    min = j;
                }
            }
            
            ans[min] = l[min];
            used[min] = true;
            for (int j = 0; j < n; j++)
                if (used[j] == false && l[j] == l[min])
                    l[j]++;
            
        }
        
        for (int i = 0; i < n; i++)
            out.print(ans[i] + " ");
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
        new D().run();
    }

}