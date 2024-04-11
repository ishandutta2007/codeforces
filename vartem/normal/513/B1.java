import java.io.*;
import java.util.*;

public class BOK {

    void solve() {
        int n = in.nextInt();
        long m = in.nextLong() - 1;
        
        List<Integer> ans =  go(0, n, m);
        for (int i = 0; i < ans.size(); i++) {
            out.print((ans.get(i) + 1) + " ");
        }
    }
    
    List<Integer> go(int now, int n, long m) {
        if (now == n) {
            return new ArrayList<>();
        }
        
        long cnt = 1 << (n - now - 1);
        if (m < cnt / 2) {
            List<Integer> ans = go(now + 1, n, m);
            ans.add(0, now);
            return ans;
        } else {
            m -= cnt / 2;
            List<Integer> ans = go(now + 1, n, m);
            ans.add(now);
            return ans;
        }
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
        new BOK().run();

    }
}