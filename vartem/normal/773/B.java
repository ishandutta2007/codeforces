import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created by Meepo on 3/11/2017.
 */
public class B {
    public static void main(String[] args) {
        new B().run();
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    int[] points = {500, 1000, 1500, 2000, 2500, 3000};
    int[] total;
    int n;
    int[] v, p;
    int ans = Integer.MAX_VALUE;
    int[] choice = new int[5];

    public void go(int k, int pv, int pp, int left, int right) {
        if (left > right)
            return;
        if (k == total.length) {
            if (pv > pp) {
                if (left == 1) {
                    System.err.println(Arrays.toString(choice));
                }
                ans = Math.min(left, ans);
            }
            return;
        }

        if (v[k] == -1 && p[k] == -1) {
            go(k + 1, pv, pp, left, right);
            return;
        }

        int pow = 1;
        for (int i = 0; i < points.length; i++) {
            int npv = pv + (v[k] == -1 ? 0 : (points[i] - v[k] * (points[i] / 250)));
            int npp = pp + (p[k] == -1 ? 0 : (points[i] - p[k] * (points[i] / 250)));
            choice[k] = i;
            if (v[k] != -1) {
                int l1 = pow * total[k] - n;
                int l2 = i == points.length - 1 ? 0 :
                        n - 2 * pow * total[k] < 0 ? 0 :
                                ((n - 2 * pow * total[k]) / (2 * pow - 1) + 1);
                go(k + 1, npv, npp, Math.max(left, Math.max(l1, l2)), right);
            } else {
                int ll = pow * total[k] - n;
                int rr = 2 * pow * total[k] - n - 1;
                go(k + 1, npv, npp, Math.max(ll, left), Math.min(rr, right));
            }
            pow *= 2;
        }
    }

    public void solve() throws IOException {
        n = nextInt();
        v = new int[5];
        p = new int[5];
        total = new int[5];
        for (int i = 0; i < 5; i++) {
            v[i] = nextInt();
            total[i] += v[i] == -1 ? 0 : 1;
        }
        for (int i = 0; i < 5; i++) {
            p[i] = nextInt();
            total[i] += p[i] == -1 ? 0 : 1;
        }

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < 5; j++) {
                total[j] += nextInt() == -1 ? 0 : 1;
            }
        }

        go(0, 0, 0, 0, 1000000007);
        if (ans == Integer.MAX_VALUE) {
            out.println(-1);
        } else {
            out.println(ans);
        }
    }

    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}