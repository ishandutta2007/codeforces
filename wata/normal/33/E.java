import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = false;//System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    int toi(String s) {
        return Integer.parseInt(s.substring(0, 2)) * 60 + Integer.parseInt(s.substring(3));
    }
    
    String tos(int i) {
        return String.format("%d %02d:%02d", i / (24 * 60) + 1, i / 60 % 24, i % 60);
    }
    
    int INF = 1 << 29;
    int N = 24 * 60 * 30 + 2;
    
    void run() {
        int m = sc.nextInt(), n = sc.nextInt(), k = sc.nextInt();
        String[] ss = new String[m];
        for (int i = 0; i < m; i++) ss[i] = sc.next();
        Map<String, Integer> map = new HashMap<String, Integer>();
        for (int i = 0; i < m; i++) {
            map.put(ss[i], sc.nextInt());
        }
        int[] sum = new int[N];
        fill(sum, 1);
        for (int i = 0; i < 4; i++) {
            String s = sc.next();
            int from = toi(s.substring(0, 5));
            int to = toi(s.substring(6));
            while (to < N) {
                for (int j = from; j <= to; j++) {
                    sum[j] = 0;
                }
                from += 24 * 60;
                to += 24 * 60;
            }
        }
        for (int i = 1; i < N; i++) {
            sum[i] += sum[i - 1];
        }
        int M = sum[N - 1] + 2;
        int[] times = new int[M];
        times[M - 1] = INF;
        for (int i = N - 1; i >= 0; i--) times[sum[i]] = i;
        Entry[] es = new Entry[n];
        for (int i = 0; i < n; i++) {
            String s = sc.next();
            int t = 24 * 60 * (sc.nextInt() - 1) + toi(sc.next());
            int money = sc.nextInt();
            if (map.containsKey(s)) es[i] = new Entry(i + 1, map.get(s), t, money);
            else es[i] = new Entry(i + 1, INF, t, money);
        }
        sort(es);
        int[][] dp = new int[n + 1][M];
        int[][] prev = new int[n + 1][M];
        for (int i = 0; i < dp.length; i++) fill(dp[i], -1);
        dp[0][1] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < M; j++) if (dp[i][j] >= 0) {
                if (dp[i + 1][j] < dp[i][j]) {
                    dp[i + 1][j] = dp[i][j];
                    prev[i + 1][j] = j;
                }
                int j2 = j + es[i].need - 1;
                if (j2 < times.length && times[j2] < es[i].until) {
                    if (dp[i + 1][j2 + 1] < dp[i][j] + es[i].money) {
                        dp[i + 1][j2 + 1] = dp[i][j] + es[i].money;
                        prev[i + 1][j2 + 1] = j;
                    }
                }
            }
        }
        int res = 0, j = 0;
        for (int i = 0; i < M; i++) if (res < dp[n][i]) {
            res = dp[n][i];
            j = i;
        }
        System.out.println(res);
        ArrayList<String> list = new ArrayList<String>();
        for (int i = n; i > 0; i--) {
            if (j > prev[i][j]) {
                list.add(String.format("%d %s %s", es[i - 1].id, tos(times[prev[i][j]]), tos(times[j - 1])));
            }
            j = prev[i][j];
        }
        System.out.println(list.size());
        Collections.reverse(list);
        for (String s : list) System.out.println(s);
    }
    
    class Entry implements Comparable<Entry> {
        int id;
        int need;
        int until;
        int money;
        Entry(int id, int need, int until, int money) {
            this.id = id;
            this.need = need;
            this.until = until;
            this.money = money;
        }
        public int compareTo(Entry o) {
            return until - o.until;
        }
    }
    
    class Scanner {
        BufferedReader br;
        StringTokenizer st;
        Scanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
            eat("");
        }
        void eat(String s) {
            st = new StringTokenizer(s);
        }
        String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        boolean hasNext() {
            while (!st.hasMoreTokens()) {
                String s = nextLine();
                if (s == null) return false;
                eat(s);
            }
            return true;
        }
        String next() {
            hasNext();
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
    
    void debug(Object...os) {
        System.err.println(deepToString(os));
    }
    
    public static void main(String[] args) {
        if (LOCAL) {
            try {
                System.setIn(new FileInputStream("in.txt"));
            } catch (Throwable e) {
                LOCAL = false;
            }
        }
        if (!LOCAL) {
            try {
                System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
            } catch (Throwable e) {
            }
        }
        new Main().run();
        System.out.flush();
    }
}