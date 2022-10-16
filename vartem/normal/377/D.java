import java.io.*;
import java.util.*;

public class DOK {

    final int MAX = 350_000;
    
    public void solve() {
        int n = in.nextInt();
        int[] l = new int[n], v = new int[n], r = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = in.nextInt() - 1;
            v[i] = in.nextInt() - 1;
            r[i] = in.nextInt() - 1;
        }
        
        Segment[] byLeft = new Segment[n], byV = new Segment[n];
        for (int i = 0; i < n; i++) {
            byLeft[i] = new Segment(l[i], r[i], v[i], i);
            byV[i] = new Segment(l[i], r[i], v[i], i);
        }
        Arrays.sort(byLeft, new Comparator<Segment>() {
            @Override
            public int compare(Segment o1, Segment o2) {
                return o1.l - o2.l;
            }
        });
        Arrays.sort(byV, new Comparator<Segment>() {
            @Override
            public int compare(Segment o1, Segment o2) {
                return o1.v - o2.v;
            }
        });
        
        int best = 0;
        int bestL = 0, bestR = 0;
        SegmentTree tree = new SegmentTree(MAX);
        for (int i = 0, j = 0; i < n;) {
            int curL = byLeft[i].l;
            
            while (i < n && byLeft[i].l == curL) {
                tree.add(byLeft[i].v, byLeft[i].r, 1);
                i++;
            }
            while (j < n && byV[j].v < curL) {
                tree.add(byV[j].v, byV[j].r, -1);
                j++;
            }
            
            int max = tree.tree[0];
            int pos = tree.pos[0];
            if (max > best) {
                best = max;
                bestL = curL;
                bestR = pos;
            }
        }
        
        out.println(best);
        for (int i = 0; i < n; i++) {
            if (l[i] <= bestL && bestL <= v[i] && v[i] <= bestR && bestR <= r[i]) {
                out.print((i + 1) + " ");
            }
        }
    }
    
    class Segment {
        int l, r, v, i;

        public Segment(int l, int r, int v, int i) {
            super();
            this.l = l;
            this.r = r;
            this.v = v;
            this.i = i;
        }
    }
    
    class SegmentTree {
        int[] tree, add, pos;
        
        int size;
        public SegmentTree(int n) {
            size = n;
            tree = new int[4 * n];
            add = new int[4 * n];
            pos = new int[4 * n];
            build(0, size, 0);
        }
        
        void build(int left, int right, int i) {
            if (left + 1 == right) {
                pos[i] = left;
                return;
            }
            int mid = (left + right) >> 1;
            build(left, mid, 2 * i + 1);
            build(mid, right, 2 * i + 2);
            pos[i] = left;
        }
        
        void add(int from, int to, int val) {
            add(0, size, from, to + 1, val, 0);
        }
        
        void addValue(int i, int val) {
            tree[i] += val;
            add[i] += val;
        }
        
        void give(int i, int l, int r) {
            if (add[i] != 0) {
                if (l + 1 < r) {
                    addValue(2 * i + 1, add[i]);
                    addValue(2 * i + 2, add[i]);
                }
                add[i] = 0;
            }
        }
        
        void gather(int i) {
            if (tree[2 * i + 1] > tree[2 * i + 2]) {
                pos[i] = pos[2 * i + 1];
                tree[i] = tree[2 * i + 1];
            } else {
                pos[i] = pos[2 * i + 2];
                tree[i] = tree[2 * i + 2];
            }
        }
        
        void add(int left, int right, int l, int r, int val, int i) {
            give(i, left, right);
            if (l <= left && right <= r) {
                addValue(i, val);
                return;
            } else if (right <= l || r <= left) {
                return;
            } else {
                int mid = (left + right) >> 1;
                add(left, mid, l, r, val, 2 * i + 1);
                add(mid, right, l, r, val, 2 * i + 2);
                gather(i);
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
        new DOK().run();
    }
}