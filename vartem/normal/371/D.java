import java.io.*;
import java.util.*;

public class D {

    public void solve() {
        int n = in.nextInt();
        long[] a = new long[n + 1];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        a[n] = Long.MAX_VALUE;
        
        long[] cur = new long[n + 1];
        
        DSU dsu = new DSU(n + 1);
        int m = in.nextInt();
        while (m-- > 0) {
            int t = in.nextInt();
            if (t == 1) {
                int p = in.nextInt() - 1, x = in.nextInt();
                
                while (x > 0) {
                    long curAdd = Math.min(a[p] - cur[p], x);
                    cur[p] += curAdd;
                    x -= curAdd;
                    
                    if (cur[p] == a[p]) {
                        dsu.union(p, p + 1);    
                    }
                    
                    if (x == 0) {
                        break;
                    }
                    
                    p = dsu.max[dsu.get(p + 1)];
                }
            } else {
                out.println(cur[in.nextInt() - 1]);
            }
        }
    }
    
    class DSU {
        int[] p, r, max;
        public DSU(int n) {
            p = new int[n];
            r = new int[n];
            max = new int[n];
            for (int i =0 ; i < n; i++) {
                p[i] = i;
                max[i] = i;
            }
        }
        
        int get(int v) {
            if (p[v] == v) {
                return v;
            }
            return p[v] = get(p[v]);
        }
        
        void union(int a, int b) {
            a = get(a); b = get(b);
            if (a == b) {
                return;
            }
            
            if (r[a] == r[b]) {
                r[a]++;
            }
            if (r[a] > r[b]) {
                p[b] = a;
                max[a] = Math.max(max[a], max[b]);
            } else {
                p[a] = b;
                max[b] = Math.max(max[a], max[b]);
            }
        }
    }

    FastScanner in;
    PrintWriter out;

    public void run() {
        try {
            in = new FastScanner();
            out = new PrintWriter(System.out);
            solve();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String name) {
            try {
                br = new BufferedReader(new FileReader(name));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
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
        new D().run();
    }
}