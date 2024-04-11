import java.io.*;
import java.util.*;

public class A {

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
        String F = in.nextToken();
        String M = in.nextToken();
        String S = in.nextToken();
        if ((S.equals(M) && M.equals(F)) || (!F.equals(M) && !F.equals(S) && !S.equals(M))) {
            out.println('?');
            return;
        }
        
        if (S.equals("rock") && M.equals("paper") && F.equals("paper") ||
            S.equals("paper") && M.equals("scissors") && F.equals("scissors") ||
            S.equals("scissors") && M.equals("rock") && F.equals("rock") || 
            
            M.equals("rock") && S.equals("paper") && F.equals("paper") ||
            M.equals("paper") && S.equals("scissors") && F.equals("scissors") ||
            M.equals("scissors") && S.equals("rock") && F.equals("rock") || 
            
            F.equals("rock") && M.equals("paper") && S.equals("paper") ||
            F.equals("paper") && M.equals("scissors") && S.equals("scissors") ||
            F.equals("scissors") && M.equals("rock") && S.equals("rock")) {
            out.println('?');
            return;
        }
        
        if (S.equals("rock") && M.equals("scissors") && F.equals("scissors") ||
            S.equals("paper") && M.equals("rock") && F.equals("rock") ||
            S.equals("scissors") && M.equals("paper") && F.equals("paper")) {
            out.println("S");
            return;
        }

        if (F.equals("rock") && M.equals("scissors") && S.equals("scissors") ||
                F.equals("paper") && M.equals("rock") && S.equals("rock") ||
                F.equals("scissors") && M.equals("paper") && S.equals("paper")) {
                out.println("F");
                return;
            }
        
        if (M.equals("rock") && S.equals("scissors") && F.equals("scissors") ||
                M.equals("paper") && S.equals("rock") && F.equals("rock") ||
                M.equals("scissors") && S.equals("paper") && F.equals("paper")) {
                out.println("M");
                return;
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
        new A().run();
    }

}