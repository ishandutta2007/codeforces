import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Set;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.io.FileNotFoundException;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
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
        CWorldOfDarkraftBattleForAzathoth solver = new CWorldOfDarkraftBattleForAzathoth();
        solver.solve(1, in, out);
        out.close();
    }

    static class CWorldOfDarkraftBattleForAzathoth {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt(), p = in.nextInt();
            int[] a = new int[n], costA = new int[n];
            Item[] weapons = new Item[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
                costA[i] = in.nextInt();
                weapons[i] = new Item(i, a[i]);
            }
            Set<Integer> values = new TreeSet<>();
            int[] b = new int[m], costB = new int[m];
            for (int i = 0; i < m; i++) {
                b[i] = in.nextInt();
                costB[i] = in.nextInt();
                values.add(b[i]);
            }
            Item[] mobs = new Item[p];
            int[] x = new int[p], y = new int[p], z = new int[p];
            for (int i = 0; i < p; i++) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
                z[i] = in.nextInt();
                mobs[i] = new Item(i, x[i]);
                values.add(y[i]);
            }
            int[] compressed = new int[values.size()];
            int ptr = 0;
            for (int i : values) {
                compressed[ptr++] = i;
            }

            for (int i = 0; i < m; i++) {
                b[i] = Arrays.binarySearch(compressed, b[i]);
            }
            for (int i = 0; i < p; i++) {
                y[i] = Arrays.binarySearch(compressed, y[i]);
            }

            int C = compressed.length;
            long[] bestArmor = new long[C];
            long INF = Long.MAX_VALUE / 3;
            Arrays.fill(bestArmor, INF);
            for (int i = 0; i < m; i++) {
                bestArmor[b[i]] = Math.min(bestArmor[b[i]], costB[i]);
            }
            SegmentTree tree = new SegmentTree(C);
            for (int i = 0; i < C; i++) {
                tree.add(i, i + 1, -bestArmor[i]);
            }

            Arrays.sort(weapons);
            Arrays.sort(mobs);
            int j = 0;
            long bestAns = -INF;
            for (int i = 0; i < n; i++) {
                Item curWeapon = weapons[i];
                while (j < mobs.length && mobs[j].value < curWeapon.value) {
                    int ind = mobs[j++].ind;
                    tree.add(y[ind] + 1, C, z[ind]);
                }

                bestAns = Math.max(bestAns, tree.max[0] - costA[curWeapon.ind]);
            }
            out.println(bestAns);
        }

        class SegmentTree {
            long[] add;
            long[] max;
            int size;

            public SegmentTree(int size) {
                this.size = size;
                add = new long[4 * size];
                max = new long[4 * size];
            }

            public void add(int l, int r, long value) {
                add(0, size, l, r, value, 0);
            }

            private void add(int left, int right, int l, int r, long value, int i) {
                if (l <= left && right <= r) {
                    addValue(i, value);
                    return;
                }
                if (r <= left || right <= l) {
                    return;
                }
                push(i);
                int mid = (left + right) >>> 1;
                add(left, mid, l, r, value, (i << 1) + 1);
                add(mid, right, l, r, value, (i << 1) + 2);
                max[i] = Math.max(max[(i << 1) + 1], max[(i << 1) + 2]);
            }

            private void push(int i) {
                if (add[i] != 0) {
                    addValue((i << 1) + 1, add[i]);
                    addValue((i << 1) + 2, add[i]);
                    add[i] = 0;
                }
            }

            private void addValue(int i, long value) {
                add[i] += value;
                max[i] += value;
            }

        }

        class Item implements Comparable<Item> {
            int ind;
            int value;

            public Item(int ind, int value) {
                this.ind = ind;
                this.value = value;
            }

            public int compareTo(Item item) {
                if (value != item.value) {
                    return value - item.value;
                }
                return ind - item.ind;
            }

        }

    }

    static class FastScanner {
        public BufferedReader br;
        public StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
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

    }
}