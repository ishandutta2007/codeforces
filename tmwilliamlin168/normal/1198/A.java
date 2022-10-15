import java.awt.*;
import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
 
import static java.lang.Math.*;
 
public class Main {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer("");
    PrintWriter pw = new PrintWriter(System.out);
 
    public Main() throws FileNotFoundException {
    }
 
    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
 
    String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
 
    long nextLong() throws IOException {
        return Long.parseLong(next());
    }
 
    public static void main(String[] args) throws IOException {
        new Main().run();
    }
 
    void run() throws IOException {
        int n = nextInt();
        int i = nextInt() * 8;
        int k = i / n;
        int r = 0;
        int K = 1;
        int[] a = new int[n];
        TreeMap<Integer, Integer> ts = new TreeMap<>();
        for (int j = 0; j < n; j++) {
            int e = nextInt();
            if (!ts.containsKey(e))
                a[j] = e;
            ts.put(e, ts.getOrDefault(e, 0) + 1);
        }
        int size = ts.size();
        Arrays.sort(a);
        int u = 0;
        while (a[u] == 0) u++;
        while (r < k) {
            K *= 2;
            r++;
            if (K >= ts.size()) {
                pw.println(0);
                pw.close();
                return;
            }
        }
        int[] sum = new int[size + 1];
        for (int j = 0; j < size; j++) {
            sum[j + 1] = sum[j] + ts.get(a[j + u]);
        }
        int ans = Integer.MAX_VALUE;
        for (int j = 0; j < size - K + 1; j++) {
            ans = min(ans, sum[size] - sum[j + K] + sum[j]);
        }
        pw.print(ans);
        pw.close();
    }
 
    class Pair {
        long ves;
        int from, to;
 
        public Pair(long a, int c, int b) {
            ves = a;
            from = c;
            to = b;
        }
    }
 
    static class PairComp implements Comparator<Pair> {
 
        @Override
        public int compare(Pair o1, Pair o2) {
            return Long.compare(o1.ves, o2.ves);
        }
    }
}