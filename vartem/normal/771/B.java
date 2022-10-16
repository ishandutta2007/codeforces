import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
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

    public void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        String[] names = new String[n];

        for (int i = 0; i < n; i++) {
            names[i] = "" + (char) ('A' + i / 26) + (char) ('a' + i % 26);
        }

        boolean[] s = new boolean[n - k + 1];
        for (int i = 0; i < s.length; i++) {
            s[i] = nextToken().equals("YES");
        }

        int l = 0;
        String[] ans = new String[n];
        for (int i = 0; i < k - 1; i++) {
            ans[i] = names[l++];
        }
        for (int i = k - 1; i < n; i++) {
            if (s[i - k + 1]) {
                ans[i] = names[l++];
            } else {
                ans[i] = ans[i - k + 1];
            }
        }

        for (int i = 0; i < n; i++) {
            out.print(ans[i] + " ");
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