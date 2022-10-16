import java.io.*;
import java.util.*;

public class C {
    
    class Edge {
        int to;
        boolean bad;
        public Edge(int to, boolean bad) {
            super();
            this.to = to;
            this.bad = bad;
        }
        
    }

    List<Edge>[] graph;
    
    boolean[] take;
    
    boolean dfs(int u, int p) {
        
        boolean hasChild = false;
        for (Edge e : graph[u]) {
            if (e.to == p) {
                continue;
            }
            
            if (dfs(e.to, u)) {
                hasChild = true;
            } else {
                if (e.bad) {
                    take[e.to] = true;
                    hasChild = true;
                }
            }
        }
        return hasChild;
    }
    
    public void solve() {
        int n =in.nextInt();
        graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < n - 1; i++) {
            int from = in.nextInt() - 1, to = in.nextInt() - 1;
            boolean bad = in.nextInt() == 2;
            
            graph[from].add(new Edge(to, bad));
            graph[to].add(new Edge(from, bad));
        }
        
        take = new boolean[n];
        dfs(0, -1);
        
        int size = 0;
        for (boolean b : take) {
            size += b ? 1 : 0;
        }
        out.println(size);
        for (int i = 0; i < n; i++) {
            if (take[i]) {
                out.print((i + 1) + " ");
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
        new C().run();
    }
}