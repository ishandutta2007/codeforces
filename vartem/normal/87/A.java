import java.io.*;
import java.util.*;

public class Trains {

    int gcd(int a, int b) {
        return (a == 0)? b : gcd(b % a, a);
    }
    
    void solve() throws Exception {
        int a = nextInt();
        int b = nextInt();
        long c = (long) a * (long) b / gcd(a, b);
        long d = a;
        ArrayList<Long> ev = new ArrayList<Long>(a + b);
        while (d <= c) {
            ev.add(d);
            d += a;
        }
        d = b;
        while (d <= c) {
            ev.add(d);
            d += b;
        }
        ev.add((long) 0);
        Collections.sort(ev);
        long ans1 = 0;
        long ans2 = 0;
        for (int i = 1; i < ev.size(); i++) {
            long t = ev.get(i);
            long g = t - ev.get(i - 1);
            if (t % a == 0 && t % b == 0) {
                if (a > b)
                    ans1 += g;
                else
                    ans2 += g;
                continue;
            }
            if (t % a == 0) {
                ans1 += g;
                continue;
            } else {
                ans2 += g;
            }
        }
        if (ans1 == ans2) {
            out.println("Equal");
        } else if (ans1 > ans2) {
            out.println("Dasha");
        } else
            out.println("Masha");
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
    final String filename = new String("Trains").toLowerCase();

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
        new Trains().run();
    }

}