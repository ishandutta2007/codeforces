import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class B {
    Scanner sc = new Scanner(System.in);
    
    void run() {
        int n = sc.nextInt();
        P[] ps = new P[n];
        for (int i = 0; i < n; i++) ps[i] = new P(sc.nextInt(), sc.nextInt());
        sort(ps);
        TreeSet<P> set = new TreeSet<P>();
        for (int i = 0; i < n; i++) set.add(ps[i]);
        rec(ps, 0, n, set);
        System.out.println(set.size());
        for (P p : set) {
            System.out.println(p);
        }
    }
    
    void rec(P[] ps, int s, int t, TreeSet<P> set) {
        if (s + 1 == t) return;
        int mid = (s + t) / 2;
        rec(ps, s, mid, set);
        rec(ps, mid, t, set);
        P left = ps[mid - 1], right = ps[mid];
        int x = (left.x + right.x) / 2;
        for (int i = s; i < t; i++) set.add(new P(x, ps[i].y));
    }
    
    class P implements Comparable<P> {
        int x, y;
        P(int x, int y) {
            this.x = x;
            this.y = y;
        }
        public int compareTo(P o) {
            if (x != o.x) return x - o.x;
            return y - o.y;
        }
        public String toString() {
            return x + " " + y;
        }
    }
    
    void debug(Object...os) {
        System.err.println(deepToString(os));
    }
    
    public static void main(String[] args) {
        new B().run();
    }
}