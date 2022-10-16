import java.io.*;
import java.util.*;

public class B {

    int gcd(int a, int b){ 
        if (a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }
    
    void solve() {
        int n = in.nextInt();
        int[] l = new int[n], c = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            c[i] = in.nextInt();
        }
        
        Map<Integer, Integer> dp = new HashMap<>();
        Map<Integer, Integer> tmp = new HashMap<>();
        dp.put(0, 0);
        
        
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            tmp.clear();
            tmp.putAll(dp);
            
            for (Map.Entry<Integer, Integer> entry : dp.entrySet()) {
                int newK = gcd(entry.getKey(), l[i]);
                int newV = entry.getValue() + c[i];
                if (newK == 1) {
                    ans = Math.min(ans, newV);
                } else {
                    if (!tmp.containsKey(newK) || tmp.get(newK) > newV) {
                        tmp.put(newK, newV);
                    }
                }
            }
            
            {
                Map<Integer, Integer> sw = tmp;
                tmp = dp;
                dp = sw;
            }
        }
        
        if (ans == Integer.MAX_VALUE) {
            ans = -1;
        }
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
        new B().run();

    }
}