import java.io.*;
import java.util.*;

public class C {

    FastScanner in;
    PrintWriter out;
    
    int[] st1, min1, st2, min2;
    int size1, size2;
    
    void push1(int x) {
        st1[size1] = x;
        if (size1 == 0 || x < min1[size1 - 1]) {
            min1[size1] = x;
        } else {
            min1[size1] = min1[size1 - 1];
        }
        size1++;
    }
    
    void push2(int x) {
        st2[size2] = x;
        if (size2 == 0 || x < min2[size2 - 1]) {
            min2[size2] = x;
        } else {
            min2[size2] = min2[size2 - 1];
        }
        size2++;
    }
    
    
    void poll() {
        if (size2 == 0) {
            while (size1 > 0) {
                push2(st1[--size1]);
            }
        }
        size2--;
    }
    
    int min() {
        int x = INF;
        if (size1 > 0 && min1[size1 - 1] < x) {
            x = min1[size1 - 1];
        }
        if (size2 > 0 && min2[size2 - 1] < x) {
            x = min2[size2 - 1];
        }
        return x;
    }
    
    final int INF = Integer.MAX_VALUE / 2;
    
    void solve() {
        int n = in.nextInt(), m = in.nextInt(), d = in.nextInt();
        
        long ans = 0;
        int[] a = new int[m], t = new int[m];
        for (int i = 0; i < m; i++) {
            a[i] = in.nextInt() - 1;
            ans += in.nextInt();
            t[i] = in.nextInt();
        }
        
        int[] dp = new int[n];
        int[] newDp = new int[n];
        st1 = new int[n];
        min1 = new int[n];
        st2 = new int[n];
        min2 = new int[n];
        
        int prevT = 1;
        
        int[] positions = new int[m];
        for (int j = 0; j < m; ) {
            Arrays.fill(newDp, INF);

            int curT = t[j];
            int curSize = 0;
            while (j < m && t[j] == curT) {
                positions[curSize++] = a[j];
                j++;
            }
            
            size1 = 0;
            size2 = 0;
            int dist = (int) Math.min(1L * (curT - prevT) * d, n - 1);
            for (int i = 0; i <= dist; i++) {
                push1(dp[i]);
            }
            for (int check = 0; check < n; check++) {
                newDp[check] = min();
                for (int pos = 0; pos < curSize; pos++) {
                    newDp[check] += Math.abs(check - positions[pos]);
                }
                
                if (check + dist + 1 < n) {
                    push1(dp[check + dist + 1]);
                }
                if (check - dist >= 0) {
                    poll();
                }
            }
            System.arraycopy(newDp, 0, dp, 0, n);
            prevT = curT;
        }
        
        int best = INF;
        for (int i = 0; i < n; i++) {
            best = Math.min(best, dp[i]);
        }
        out.println(ans - best);
    }

    void run() {
        try {
            in = new FastScanner();
            out = new PrintWriter(System.out);
            solve();
            out.close();
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new C().run();
    }
}