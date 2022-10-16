import java.io.*;
import java.util.*;

public class B {

    FastScanner in;
    PrintWriter out;

    class Trie {
        int[][] next;
        int states;

        public Trie(int maxSize) {
            next = new int[26][maxSize];
            for (int[] i : next) {
                Arrays.fill(i, -1);
            }

            states = 1;
        }

        void addString(String s) {
            int state = 0;
            for (char c : s.toCharArray()) {
                c -= 'a';
                if (next[c][state] == -1) {
                    next[c][state] = states++;
                }
                state = next[c][state];
            }
        }

        boolean canWin(int u) {
            boolean ans = false;
            for (int i = 0; i < 26; i++) {
                if (next[i][u] != -1) {
                    ans |= !canWin(next[i][u]);
                }
            }
            return ans;
        }

        boolean canLose(int u) {
            boolean ans = false, wasTrans = false;
            for (int i = 0; i < 26; i++) {
                if (next[i][u] != -1) {
                    ans |= !canLose(next[i][u]);
                    wasTrans = true;
                }
            }
            if (!wasTrans) {
                ans = true;
            }
            return ans;
        }

    }

    void solve() {
        int n = in.nextInt(), k = in.nextInt();
        String[] words = new String[n];
        int maxStates = 1;
        for (int i = 0; i < n; i++) {
            words[i] = in.next();
            maxStates += words[i].length();
        }

        Trie trie = new Trie(maxStates);
        for (String s : words) {
            trie.addString(s);
        }

        boolean firstCanWin = trie.canWin(0), firstCanLose = trie.canLose(0);

        boolean[][] mat = new boolean[][] { { firstCanLose, firstCanWin },
                { !firstCanLose, !firstCanWin } };

        boolean[][] move = pow(mat, k - 1);

        if ((move[0][0] && firstCanWin) || (move[0][1] && !firstCanWin)) {
            out.println("First");
        } else {
            out.println("Second");
        }
    }

    private boolean[][] pow(boolean[][] mat, int i) {
        if (i == 0) {
            return new boolean[][] { { true, false }, { false, true } };
        }

        if ((i & 1) == 1) {
            boolean[][] ans = pow(mat, i - 1);
            return mul(ans, mat);
        } else {
            boolean[][] ans = pow(mat, i / 2);
            return mul(ans, ans);
        }
    }

    private boolean[][] mul(boolean[][] first, boolean[][] second) {
        boolean[][] ret = new boolean[2][2];
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    ret[i][j] |= first[i][k] & second[k][j];
                }
            }
        }
        return ret;
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

        FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (line == null)
                    return null;
                st = new StringTokenizer(line);
            }
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

    public static void main(String[] args) {
        new B().run();
    }
}