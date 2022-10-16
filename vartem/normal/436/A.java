import java.io.*;
import java.util.*;

public class A {

    class Candy {
        int height, weight;

        public Candy(int height, int weight) {
            super();
            this.height = height;
            this.weight = weight;
        }

    }

    public void solve() {
        int n = in.nextInt(), x = in.nextInt();

        List<Candy>[] candies = new List[2];
        for (int i = 0; i < 2; i++) {
            candies[i] = new ArrayList<>();
        }

        for (int i = 0; i < n; i++) {
            int type = in.nextInt();
            candies[type].add(new Candy(in.nextInt(), in.nextInt()));
        }

        int ans = Math.max(solve(candies[0], candies[1], x), solve(candies[1], candies[0], x));
        out.println(ans);
    }

    private int solve(List<Candy> a, List<Candy> b, int x) {
        int turn = 0;
        boolean[] used1 = new boolean[a.size()], used2 = new boolean[b.size()];

        int ans = 0;
        while (true) {
            Candy best = null;
            if (turn == 0) {
                int id = -1;
                for (int i = 0; i < a.size(); i++) {
                    if (!used1[i] && a.get(i).height <= x) {
                        if (id == -1 || a.get(id).weight < a.get(i).weight) {
                            id = i;
                        }
                    }
                }
                if (id != -1) {
                    used1[id] = true;
                    best = a.get(id);
                }

            } else {
                int id = -1;
                for (int i = 0; i < b.size(); i++) {
                    if (!used2[i] && b.get(i).height <= x) {
                        if (id == -1 || b.get(id).weight < b.get(i).weight) {
                            id = i;
                        }
                    }
                }
                if (id != -1) {
                    used2[id] = true;
                    best = b.get(id);
                }
            }
            if (best == null) {
                return ans;
            } else {
                ans++;
                x += best.weight;
                turn = 1 - turn;
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
        new A().run();
    }
}