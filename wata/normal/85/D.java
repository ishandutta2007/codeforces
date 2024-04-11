import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class D {
    Scanner sc = new Scanner(System.in);
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    void run() {
        int n = sc.nextInt();
        int[] op = new int[n], val = new int[n];
        TreeSet<Integer> set = new TreeSet<Integer>();
        for (int i = 0; i < n; i++) {
            String s = sc.next();
            if (s.charAt(0) == 'a') {
                op[i] = 0;
                val[i] = sc.nextInt();
                set.add(val[i]);
            } else if (s.charAt(0) == 'd') {
                op[i] = 1;
                val[i] = sc.nextInt();
            } else {
                op[i] = 2;
            }
        }
        xs = toi(set.toArray(new Integer[0]));
        int m = xs.length;
        Node seg = new Node(0, m);
        for (int i = 0; i < n; i++) {
            if (op[i] == 0) {
                seg.insert(binarySearch(xs, val[i]));
            } else if (op[i] == 1) {
                seg.delete(binarySearch(xs, val[i]));
            } else {
                out.println(seg.sum[2]);
            }
        }
        out.flush();
    }
    
    int[] xs;
    
    class Node {
        int s, t;
        Node left, right;
        int num;
        long[] sum = new long[5];
        Node(int s, int t) {
            this.s = s;
            this.t = t;
            if (t - s > 1) {
                left = new Node(s, (s + t) / 2);
                right = new Node((s + t) / 2, t);
            }
        }
        void insert(int i) {
            num++;
            if (left == null) {
                sum[0] += xs[i];
            } else {
                if (i < (s + t) / 2) {
                    left.insert(i);
                } else {
                    right.insert(i);
                }
                for (int j = 0; j < 5; j++) {
                    sum[j] = left.sum[j] + right.sum[((j - left.num) % 5 + 5) % 5];
                }
            }
        }
        void delete(int i) {
            num--;
            if (left == null) {
                sum[0] -= xs[i];
            } else {
                if (i < (s + t) / 2) {
                    left.delete(i);
                } else {
                    right.delete(i);
                }
                for (int j = 0; j < 5; j++) {
                    sum[j] = left.sum[j] + right.sum[((j - left.num) % 5 + 5) % 5];
                }
            }
        }
    }
    
    int[] toi(Integer[] Is) {
        int n = Is.length;
        int[] is = new int[n];
        for (int i = 0; i < n; i++) is[i] = Is[i];
        return is;
    }
    
    void debug(Object...os) {
        System.err.println(deepToString(os));
    }
    
    public static void main(String[] args) {
        new D().run();
    }
}