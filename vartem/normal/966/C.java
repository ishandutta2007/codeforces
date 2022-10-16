import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            Random rng = new Random(123);
            while (true) {
//            int n = 10;
                int n = in.nextInt();
//            long[] b = generate(rng, n);
                long[] b = in.nextLongArray(n);
                List<Long>[] bs = Utils.listArray(60);
                for (int i = 0; i < n; i++) {
                    bs[63 - Long.numberOfLeadingZeros(b[i])].add(b[i]);
                }
                Trie[] tries = new Trie[60];
                for (int i = 0; i < 60; i++) {
                    tries[i] = new Trie(60 * bs[i].size());
                    for (long x : bs[i]) {
                        tries[i].add(x, i);
                    }
                }

                long val = 0;
                List<Long> result = new ArrayList<>();
                for (int IT = 0; IT < n; IT++) {
                    int bits = 63 - Long.numberOfLeadingZeros(val);
                    long found = -1;
                    for (int i = 0; i < bits; i++) {
                        int c = (int) ((val >> i) & 1);
                        if (c == 0) {
                            if (tries[i].size() > 0) {
                                found = tries[i].get(i, val);
                                break;
                            }
                        }
                    }
                    if (found != -1) {
                        result.add(found);
                        val ^= found;
                        continue;
                    }

                    for (int i = bits + 1; i < 60; i++) {
                        int c = (int) ((val >> i) & 1);
                        if (c == 0) {
                            if (tries[i].size() > 0) {
                                found = tries[i].get(i, val);
                                break;
                            }
                        }
                    }
                    if (found != -1) {
                        result.add(found);
                        val ^= found;
                        continue;
                    }
                    out.println("No");
//                out.println(Arrays.toString(b));
                    return;
                }
                out.println("Yes");
                for (long x : result) {
                    out.print(x + " ");
                }
                out.println();
                return;
            }
        }

        class Trie {
            int[][] next;
            int[] count;
            int states = 1;

            public Trie(int size) {
                size++;
                next = new int[2][size];
                count = new int[size];
                for (int[] i : next) {
                    Arrays.fill(i, -1);
                }
            }

            void add(long x, int start) {
                int cur = 0;
                for (int i = start; i >= 0; i--) {
                    count[cur]++;
                    int c = (int) ((x >> i) & 1);
                    if (next[c][cur] == -1) {
                        next[c][cur] = states++;
                    }
                    cur = next[c][cur];
                }
                count[cur]++;
            }

            int size() {
                return count[0];
            }

            public long get(int start, long x) {
                long result = 0;
                int cur = 0;
                for (int i = start; i >= 0; i--) {
                    if (count[cur] <= 0) {
                        throw new AssertionError();
                    }
                    count[cur]--;
                    int c = (int) ((x >> i) & 1);
                    if (i < start) {
                        if (next[c][cur] != -1 && count[next[c][cur]] > 0) {
                            // c = c;
                        } else {
                            c ^= 1;
                        }
                    } else {
                        c = 1;
                    }
                    cur = next[c][cur];
                    result = result + result + c;
                }
                count[cur]--;
                return result;
            }

        }

    }

    static class Utils {
        public static <T> List<T>[] listArray(int size) {
            List<T>[] result = new List[size];
            for (int i = 0; i < size; i++) {
                result[i] = new ArrayList<>();
            }
            return result;
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
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

        public long[] nextLongArray(int n) {
            long[] ret = new long[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextLong();
            }
            return ret;
        }

    }
}