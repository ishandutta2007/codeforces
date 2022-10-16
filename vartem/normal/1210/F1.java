import java.io.*;
import java.util.*;

public class F2 {

    int mod = 1000000007;
    int[][] prob;

    public static int invInt(int a, int mod) {
        int res = 1;
        int b = mod - 2;
        while (b > 0) {
            if ((b & 1) != 0) {
                res = (int) ((long) res * a % mod);
            }
            a = (int) ((long) a * a % mod);
            b >>>= 1;
        }
        return res;
    }

    class State {
        BitSet bset;

        public State() {
            bset = new BitSet(128);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            State state = (State) o;
            return bset.equals(state.bset);
        }

        @Override
        public int hashCode() {
            return Objects.hash(bset);
        }

        void add(int mask) {
            bset.set(mask);
        }
    }

    void solve() {
        int n = in.nextInt();
        int inv100 = invInt(100, mod);
        prob = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                prob[i][j] = (int) ((long) in.nextInt() * inv100 % mod);
            }
        }
        long time = System.currentTimeMillis();
        Map<State, Integer> ans = new HashMap<>();
        {
            State s = new State();
            s.add(0);
            ans.put(s, 1);
        }
        for (int left = 0; left < n; left++) {
            Map<State, Integer> newAns = new HashMap<>();
            for (int mask = 0; mask < 1 << n; mask++) {
                long mul = 1;
                for (int i = 0; i < n; i++) {
                    if ((mask & (1 << i)) != 0) {
                        mul = mul * prob[left][i] % mod;
                    } else {
                        mul = mul * (mod + 1 - prob[left][i]) % mod;
                    }
                }

                for (Map.Entry<State, Integer> entry : ans.entrySet()) {
                    int newProb = (int) (mul * entry.getValue() % mod);
                    State newState = new State();
                    BitSet bs = entry.getKey().bset;
                    for (int ma = bs.nextSetBit(0); ma >= 0; ma = bs.nextSetBit(ma + 1)) {
                        for (int i = 0; i < n; i++) {
                            if ((mask & (1 << i)) != 0 && ((ma >> i) & 1) == 0) {
                                newState.add(ma | (1 << i));
                            }
                        }
                    }
                    if (newState.bset.cardinality() == 0) {
                        continue;
                    }
                    Integer cur = newAns.get(newState);
                    if (cur == null) {
                        newAns.put(newState, newProb);
                    } else {
                        newAns.put(newState, (newProb + cur) % mod);
                    }
                }
            }
            ans = newAns;
        }
        out.println(ans.values().iterator().next());
        System.err.println(System.currentTimeMillis() - time);
    }

    FastScanner in;
    PrintWriter out;

    void run() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();
        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public boolean hasMoreTokens() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    return false;
                }
                if (line == null) {
                    return false;
                }
                st = new StringTokenizer(line);
            }
            return true;
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public int[] nextIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

        public long[] nextLongArray(int n) {
            long[] ret = new long[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextLong();
            }
            return ret;
        }
    }


    public static void main(String[] args) throws Exception {
        new F2().run();
    }
}