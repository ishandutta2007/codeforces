import java.io.*;
import java.util.*;

public class C {
    FastScanner in;
    PrintWriter out;

    int MAX = 1_000_000 + 1;
    int ALPH = 26;

    int[][] next;
    int[] id;
    int states = 0;

    void prepare() {
        next = new int[ALPH][MAX];
        for (int[] i : next) {
            Arrays.fill(i, -1);
        }
        states++;
        id = new int[MAX];
        Arrays.fill(id, -1);
    }

    void add(String s, int n) {
        int cur = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int c = Character.toLowerCase(s.charAt(i)) - 'a';
            if (next[c][cur] == -1) {
                next[c][cur] = states++;
            }
            cur = next[c][cur];
        }
        id[cur] = n;
    }

    void solve() {
        prepare();
        int n = in.nextInt();
        String s = in.next();
        int m = in.nextInt();
        String[] a = new String[m];
        for (int i = 0; i < m; i++) {
            a[i] = in.next();
            add(a[i], i);
        }

        int[] prev = new int[n + 1];
        Arrays.fill(prev, -1);
        prev[0] = -2;

        for (int i = 0; i < n; i++) {
            if (prev[i] == -1) {
                continue;
            }

            int cur = 0;
            for (int j = i; j < n; j++) {
                cur = next[s.charAt(j) - 'a'][cur];
                if (cur == -1) {
                    break;
                }
                if (id[cur] != -1) {
                    prev[j + 1] = id[cur];
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        int cur = n;
        while (cur > 0) {
            result.add(prev[cur]);
            cur -= a[prev[cur]].length();
        }
        Collections.reverse(result);
        for (int i = 0; i < result.size(); i++) {
            out.print(a[result.get(i)]);
            if (i + 1 < result.size()) {
                out.print(' ');
            } else {
                out.println();
            }
        }
    }

    void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
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
        new C().runIO();
    }
}