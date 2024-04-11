import java.io.*;
import java.util.*;

public class C {

    FastScanner in;
    PrintWriter out;

    class Segment implements Comparable<Segment> {
        int l, r, k;
        int id;

        public Segment(int l, int r, int k, int id) {
            super();
            this.l = l;
            this.r = r;
            this.k = k;
            this.id = id;
        }
        
        @Override
        public int compareTo(Segment o) {
            if (l != o.l) {
                return Integer.compare(l, o.l);
            }
            return -Integer.compare(r, o.r);
        }

    }

    void solve() {
        int n = in.nextInt();
        Segment[] a = new Segment[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Segment(in.nextInt() - 1, in.nextInt() - 1, 0, i);
        }
        int m = in.nextInt();
        Segment[] b = new Segment[m];
        for (int i = 0; i < m; i++) {
            b[i] = new Segment(in.nextInt() - 1, in.nextInt() - 1,
                    in.nextInt(), i);
        }
        int[] match = new int[n];
        Arrays.fill(match, -1);
        Arrays.sort(a);
        Arrays.sort(b);

        
        TreeSet<Segment> tset = new TreeSet<>(new Comparator<Segment>() {
            @Override
            public int compare(Segment o1, Segment o2) {
                if (o1.r != o2.r) {
                    return Integer.compare(o1.r, o2.r);
                }
                return Integer.compare(o1.id, o2.id);
            }
        });
        
        Segment tmp = new Segment(0, 0, 0, -1);
        int ptr = 0;
        for (Segment seg : a) {
            while (ptr < m && b[ptr].l <= seg.l) {
                tset.add(b[ptr++]);
            }
            
            tmp.r = seg.r;
            Segment cur = tset.ceiling(tmp);
            if (cur == null) {
                out.println("NO");
                return;
            }
            tset.remove(cur);
            cur.k--;
            match[seg.id] = cur.id;
            if (cur.k > 0) {
                tset.add(cur);
            }
        }
        
        
        out.println("YES");
        for (int i = 0; i < n; i++) {
            out.print((match[i] + 1) + " ");
        }
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
        new C().run();
    }
}