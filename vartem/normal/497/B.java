import java.io.*;
import java.util.*;

public class B {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        List<Integer> win1 = new ArrayList<>(), win2 = new ArrayList<>();
        int[] a = new int[n];
        int[] sum1 = new int[n + 1], sum2 = new int[n + 1];

        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            if (a[i] == 1) {
                sum1[i + 1]++;
                win1.add(i + 1);
            } else {
                sum2[i + 1]++;
                win2.add(i + 1);
            }
            sum1[i + 1] += sum1[i];
            sum2[i + 1] += sum2[i];
        }

        List<Pair> ans = new ArrayList<>();
        int INF = Integer.MAX_VALUE / 2;
        for (int t = 1; t <= n; t++) {
            int pos = 0;
            int sets1 = 0, sets2 = 0;

            int lastWin = -1;

            while (true) {
                int pts1 = sum1[pos], pts2 = sum2[pos];
                int next1 = INF, next2 = INF;

                if (pts1 + t <= win1.size()) {
                    next1 = win1.get(pts1 + t - 1);
                }
                if (pts2 + t <= win2.size()) {
                    next2 = win2.get(pts2 + t - 1);
                }

                if (next1 == INF && next2 == INF) {
                    break;
                }
                
                if (next1 < next2) {
                    lastWin = 1;
                    sets1++;
                    pos = next1;
                } else {
                    lastWin = 2;
                    sets2++;
                    pos = next2;
                }
            }
            
            if (pos == n) {
                if (lastWin == 1 && sets1 > sets2 || lastWin == 2 && sets2 > sets1) {
                    ans.add(new Pair(Math.max(sets1, sets2), t));
                }
            }

        }
        
        Collections.sort(ans);
        out.println(ans.size());
        for (int i = 0; i < ans.size(); i++) {
            out.println(ans.get(i).x + " " + ans.get(i).y);
        }
    }
    
    class Pair implements Comparable<Pair> {
        int x, y;

        public Pair(int x, int y) {
            super();
            this.x = x;
            this.y = y;
        }
        
        @Override
        public int compareTo(Pair o) {
            if (x != o.x) {
                return Integer.compare(x, o.x);
            }
            return Integer.compare(y, o.y);
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
        new B().run();
    }
}