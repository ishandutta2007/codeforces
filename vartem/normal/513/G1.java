import java.io.*;
import java.util.*;

public class G {

    int[] p;
    int k;
    
    double ans;
    
    void go(int t) {
        if (t == k) {
            for (int i = 0; i < p.length; i++) {
                for (int j = i + 1; j < p.length; j++) {
                    if (p[i] > p[j]) {
                        ans++;
                    }
                }
            }
            return;
        }
        
        for (int l = 0; l < p.length; l++) {
            for (int r = l; r < p.length; r++) {
                for (int i = l, j = r; i < j; i++, j--) {
                    int tmp = p[i];
                    p[i] = p[j];
                    p[j] = tmp;
                }
                
                go(t + 1);
                
                for (int i = l, j = r; i < j; i++, j--) {
                    int tmp = p[i];
                    p[i] = p[j];
                    p[j] = tmp;
                }
            }
        }
    }
    
    void solve() {
        int n = in.nextInt();
        k = in.nextInt();
        p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = in.nextInt() - 1;
        }
        go(0);
        
        ans /= Math.pow(n * (n + 1) / 2, k);
        out.println(ans);
    }

    FastScanner in;
    PrintWriter out;

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

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new G().run();

    }
}