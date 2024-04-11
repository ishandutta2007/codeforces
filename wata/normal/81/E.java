import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.io.*;

public class E {
    Scanner sc = new Scanner(System.in);
    
    void run() {
        int n = sc.nextInt();
        V[] vs = new V[n];
        for (int i = 0; i < n; i++) vs[i] = new V(i);
        for (int i = 0; i < n; i++) {
            vs[i].parent = vs[sc.nextInt() - 1];
            vs[i].parent.child.add(vs[i]);
            vs[i].sex = sc.nextInt();
        }
        int t = 0, e = 0;
        for (V v : vs) if (!v.used) {
            V root = v;
            while (!root.visit) {
                root.visit = true;
                root = root.parent;
            }
            v = root;
            do {
                v.loop = true;
                v = v.parent;
            } while (v != root);
            ArrayList<V> list = new ArrayList<E.V>();
            int m = 0;
            root.used = true;
            list.add(root);
            while (m < list.size()) {
                v = list.get(m++);
                for (V u : v.child) if (!u.used) {
                    u.used = true;
                    list.add(u);
                }
            }
            root.dp2[0][1] = root.dp2[1][0] = -(1L << 60);
            for (int i = list.size() - 1; i >= 0; i--) {
                v = list.get(i);
                if (v.loop) {
                    for (int j = 0; j < 2; j++) {
                        long sum = 0;
                        for (V u : v.child) {
                            if (u.loop) sum += max(u.dp2[j][0], u.dp2[j][1]);
                            else sum += max(u.dp[0], u.dp[1]);
                        }
                        v.dp2[j][0] = sum;
                        for (V u : v.child) {
                            if (u.loop) v.dp2[j][1] = max(v.dp2[j][1], sum + (1L << 32) + abs(v.sex - u.sex) + u.dp2[j][0] - max(u.dp2[j][0], u.dp2[j][1]));
                            else v.dp2[j][1] = max(v.dp2[j][1], sum + (1L << 32) + abs(v.sex - u.sex) + u.dp[0] - max(u.dp[0], u.dp[1]));
                        }
                    }
                } else {
                    long sum = 0;
                    for (V u : v.child) sum += max(u.dp[0], u.dp[1]);
                    v.dp[0] = sum;
                    for (V u : v.child) v.dp[1] = max(v.dp[1], sum + (1L << 32) + abs(v.sex - u.sex) + u.dp[0] - max(u.dp[0], u.dp[1]));
                }
            }
            int q;
            if (root.dp2[0][0] < root.dp2[1][1]) root.p = q = 1;
            else root.p = q = 0;
            t += (int)(root.dp2[q][root.p] >> 32);
            e += (int)(root.dp2[q][root.p]);
            for (int i = 0; i < list.size(); i++) {
                v = list.get(i);
                if (v.loop) {
                    for (V u : v.child) {
                        if (u.loop) {
                            if (u.dp2[q][0] < u.dp2[q][1]) {
                                u.p = 1;
                            } else {
                                u.p = 0;
                            }
                        } else {
                            if (u.dp[0] < u.dp[1]) {
                                u.p = 1;
                            } else {
                                u.p = 0;
                            }
                        }
                    }
                    if (v.p == 1) {
                        for (V u : v.child) {
                            if (u.loop) {
                                if (v.dp2[q][1] == v.dp2[q][0] + (1L << 32) + abs(v.sex - u.sex) + u.dp2[q][0] - max(u.dp2[q][0], u.dp2[q][1])) {
                                    u.p = 0;
                                    v.pair = u;
                                    u.pair = v;
                                    break;
                                }
                            } else {
                                if (v.dp2[q][1] == v.dp2[q][0] + (1L << 32) + abs(v.sex - u.sex) + u.dp[0] - max(u.dp[0], u.dp[1])) {
                                    u.p = 0;
                                    v.pair = u;
                                    u.pair = v;
                                    break;
                                }
                            }
                        }
                    }
                } else {
                    for (V u : v.child) {
                        if (u.dp[0] < u.dp[1]) {
                            u.p = 1;
                        } else {
                            u.p = 0;
                        }
                    }
                    if (v.p == 1) {
                        for (V u : v.child) {
                            if (v.dp[1] == v.dp[0] + (1L << 32) + abs(v.sex - u.sex) + u.dp[0] - max(u.dp[0], u.dp[1])) {
                                u.p = 0;
                                v.pair = u;
                                u.pair = v;
                                break;
                            }
                        }
                    }
                }
                if (i == 0) {
                    root.dp2 = new long[2][2];
                    root.dp2[0][1] = root.dp2[1][0] = -(1L << 60);
                }
            }
        }
        System.out.println(t + " " + e);
        for (int i = 0; i < n; i++) if (vs[i].pair != null && vs[i].pair.id > i) {
            System.out.println((i + 1) + " " + (vs[i].pair.id + 1));
        }
    }
    
    class V {
        ArrayList<V> child = new ArrayList<V>();
        V parent;
        int id, sex;
        boolean used, visit, loop;
        long[] dp = new long[2];
        long[][] dp2 = new long[2][2];
        V pair = null;
        int p;
        V(int id) {
            this.id = id;
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
                throw new IOError(e);
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
        new E().run();
    }
}