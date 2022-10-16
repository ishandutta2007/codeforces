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
        int k = in.nextInt();
        String s = in.nextToken();
        int[][] a = new int[26][300000];
        for (int i = 0; i < 26; i++) {
            char c = (char)('a' + i);
            int[] p = new int[300000];
            int cnt = 0;
            for (int j = 0; j < k; j++)
                if (s.charAt(j) == c)
                    p[cnt++] = j;
            int t = 0;
            for (int j = 0; j < 300000; j++) {
                if (t + 1 < cnt && Math.abs(p[t + 1] - j) < Math.abs(p[t] - j))
                    t++;
                if (cnt > 0)
                    a[c - 'a'][j] = Math.abs(p[t] - j);
                else
                    a[c - 'a'][j] = -1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            String r = in.nextToken();
            long f = 0;
            for (int j = 0; j < r.length(); j++)
                if (a[r.charAt(j) - 'a'][j] == -1)
                    f += r.length();
                else
                    f += a[r.charAt(j) - 'a'][j];
            
            out.println(f);
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
        new B().run();
    }

}