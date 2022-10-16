import java.io.*;
import java.util.*;

public class D2 {

    FastScanner in;
    PrintWriter out;
    
    int gcd(int a, int b) {
        if (a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }
    
    class STable {
        int[][] gcd;
        int size;
        
        public STable(int[] a) {
            this.size = a.length;
            gcd = new int[20][size];
            
            
            gcd[0] = a.clone();
            for (int i = 1; i < 20; i++) {
                for (int j = 0; j < a.length; j++) {
                    int nxt = Math.min(a.length - 1, j + (1 << (i - 1)));
                    gcd[i][j] = gcd(gcd[i - 1][j], gcd[i - 1][nxt]);
                }
            }
        }
        
        int get(int from, int to) {
            int cnt = to - from + 1;
            int log = 31 - Integer.numberOfLeadingZeros(cnt);
            return gcd(gcd[log][from], gcd[log][to - (1 << log) + 1]);
        }
        
        
    }

    void solve() {
        int n = in.nextInt();
        int[] a=  new int[n];
        
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        
        STable st = new STable(a);
        Map<Integer, Long> cache = new HashMap<Integer, Long>();
        
        for (int i = 0; i < n; i++) {
            
            int curR = i;
            
            while (curR < n) {
                int l = curR, r = n;
                
                int gg = st.get(i, curR);
                while (l + 1 < r) {
                    int m = (l + r) >> 1;
                    
                    if (gg == st.get(i, m)) {
                        l = m;
                    } else {
                        r = m;
                    }
                }
                
                if (cache.containsKey(gg)) {
                    cache.put(gg, cache.get(gg) + l - curR + 1);
                } else {
                    cache.put(gg, (long) (l - curR + 1));
                }
                curR = r;
            }
        }
        
        
        int Q = in.nextInt();
        for (int q = 0; q < Q; q++) {
            int x = in.nextInt();
            if (cache.containsKey(x)) {
                out.println(cache.get(x));
            } else {
                out.println(0);
            }
        }
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
        new D2().run();
    }
}