import java.io.*;
import java.util.*;

public class D {

    FastScanner in;
    PrintWriter out;

    List<Integer>[] graph;
    List<Integer> stack;
    int[] start;

    void go(int u) {
        for (; start[u] < graph[u].size(); ) {
            int v = graph[u].get(start[u]++);
            go(v);
        }
        stack.add(u);
    }

    void solve() {
        int n = in.nextInt();
        String[] s = new String[n];
        Map<String, Integer> all = new HashMap<>();
        for (int i = 0; i < n; i++) {
            s[i] = in.nextToken();
            all.put(s[i].substring(0, 2), 0);
            all.put(s[i].substring(1), 0);
        }

        int m = 0;
        String[] strs = new String[all.size()];
        for (String t : all.keySet()) {
            all.put(t, m);
            strs[m] = t;
            m++;
        }

        graph = new List[m];
        for (int i = 0; i < m; i++) {
            graph[i] = new ArrayList<Integer>();
        }
        start = new int[m];
        int[] inDeg = new int[m], outDeg = new int[m];

        for (int i = 0; i < n; i++) {
            int id1 = all.get(s[i].substring(0, 2));
            int id2 = all.get(s[i].substring(1));
            graph[id2].add(id1);
            inDeg[id2]++;
            outDeg[id1]++;
        }
        
        int oddOut = -1, oddIn = -1;
        for (int i = 0; i < m; i++) {
            if (inDeg[i] == outDeg[i]) {
                continue;
            } else 
            if (inDeg[i] == outDeg[i] + 1) {
                if (oddIn != -1) {
                    out.println("NO");
                    return;
                }
                oddIn = i;
            } else 
            if (outDeg[i] == inDeg[i] + 1) {
                if (oddOut != -1) {
                    out.println("NO");
                    return;
                }
                oddOut = i;
            } else {
                out.println("NO");
                return;
            }
        }
        if (oddOut == -1) {
            oddOut = oddIn = 0;
        }
        stack = new ArrayList<>();
        go(oddIn);
        if (stack.size() != n + 1) {
            out.println("NO");
            return;
        }
        
    
        out.println("YES");
        out.print(strs[stack.get(0)]);
        for (int i = 1; i < stack.size(); i++) {
            out.print(strs[stack.get(i)].charAt(1));
        }
        out.println();
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
        new D().run();
    }
}