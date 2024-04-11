import java.util.*;
import java.io.*;

public class Berpizza {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int q = sc.nextInt();
        Pair [] time = new Pair[(int) 5e5 + 6];
        int earliest = 0;
        int arrived = 0;
        TreeSet<Pair> set = new TreeSet<>();
        for (int i = 0; i < q; i++) {
            int type = sc.nextInt();
            if (type == 1) {
                int m = sc.nextInt();
                time[arrived] = new Pair(arrived, m);
                set.add(time[arrived]);
                arrived++;
            } else if (type == 2) {
                set.remove(time[earliest]);
                out.print((earliest + 1) + " ");
                time[earliest] = null;
                while (earliest <= arrived && time[earliest] == null) earliest++;
            } else {
                Pair first = set.first();
                out.print((first.t + 1) + " ");
                int removed = first.t;
                set.remove(first);
                time[removed] = null;
                if (removed == earliest) {
                    while (earliest <= arrived && time[earliest] == null) earliest++;
                }
            }
        }
        out.close();
    }

    static class Pair implements Comparable<Pair> {
        int t; int m;
        Pair(int t, int m) {
            this.t = t; this.m = m;
        }

        @Override
        public int compareTo(Pair o) {
            if (o.m == m) return Integer.compare(t, o.t);
            else return Integer.compare(o.m, m);
        }
    }


    static void sort(int[] a) {
        ArrayList<Integer> q = new ArrayList<>();
        for (int i : a) q.add(i);
        Collections.sort(q);
        for (int i = 0; i < a.length; i++) a[i] = q.get(i);
    }

    static void sort(long[] a) {
        ArrayList<Long> q = new ArrayList<>();
        for (long i : a) q.add(i);
        Collections.sort(q);
        for (int i = 0; i < a.length; i++) a[i] = q.get(i);
    }


    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
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
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }


    }

}