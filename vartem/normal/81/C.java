import java.io.*;
import java.util.*;

public class Score {

    class Pair implements Comparable<Pair> {
        int x, i;

        public Pair(int x, int i) {
            this.x = x;
            this.i = i;
        }

        @Override
        public int compareTo(Pair o) {
            if (a > b) {
                if (x != o.x)
                    return x - o.x;
                else
                    return i - o.i;
            } else {
                if (x != o.x)
                    return o.x - x;
                else
                    return i - o.i;
            }
        }
    }

    int a, b;

    void solve() throws Exception {
        int n = nextInt();
        a = nextInt();
        b = nextInt();
        int[] t = new int[n];
        for (int i = 0; i < n; i++)
            t[i] = nextInt();
        if (a == b) {
            for (int i = 0; i < n / 2; i++)
                out.print("1 ");
            for (int i = n / 2; i < n; i++)
                out.print("2 ");
        } else {
            Pair[] r = new Pair[n];
            for (int i = 0; i < n; i++)
                r[i] = new Pair(t[i], i);
            int[] ans = new int[n];
            Arrays.sort(r);
            for (int i = 0; i < n; i++)
                ans[i] = 2;
            for (int i = 0; i < a; i++)
                ans[r[i].i] = 1;
            for (int i = 0; i < n; i++)
                out.print(ans[i] + " ");
        }
    }

    void run() {
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;
    final String filename = new String("Score").toLowerCase();

    String nextToken() throws Exception {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(in.readLine());
        return st.nextToken();
    }

    int nextInt() throws Exception {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws Exception {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws Exception {
        return Double.parseDouble(nextToken());
    }

    public static void main(String[] args) {
        new Score().run();
    }

}