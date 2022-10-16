import java.io.*;
import java.util.*;

public class A {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int hp1 = in.nextInt(), atk1 = in.nextInt(), def1 = in.nextInt();
        int hp2 = in.nextInt(), atk2 = in.nextInt(), def2 = in.nextInt();

        int hpCost = in.nextInt(), atkCost = in.nextInt(), defCost = in
                .nextInt();

        int min = Integer.MAX_VALUE;
        for (int buyAtk = 0; buyAtk <= 300; buyAtk++) {
            for (int buyDef = 0; buyDef <= 300; buyDef++) {
                int cur = buyAtk * atkCost + buyDef * defCost;
                
                int dec1 = Math.max(0, atk2 - def1 - buyDef);
                int dec2 = Math.max(0, atk1 - def2 + buyAtk);
                
                if (dec2 == 0) {
                    continue;
                }
                
                int time = (hp2 + dec2 - 1) / dec2;
                int needHp = Math.max(hp1, time * dec1 + 1);
                cur += (needHp - hp1) * hpCost;
                
                min = Math.min(min, cur);
            }
        }
        out.println(min);
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
        new A().run();
    }
}