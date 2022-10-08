import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class C {
    Scanner sc = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out);
    
    void run() {
        int n = sc.nextInt();
        Node[] vs = new Node[n];
        for (int i = 0; i < n; i++) vs[i] = new Node();
        for (int i = 0; i < n; i++) {
            int p = sc.nextInt() - 1;
            if (p >= 0) {
                vs[i].parent = vs[p];
            }
            vs[i].val = sc.nextInt();
        }
        Node root = null;
        for (int i = 0; i < n; i++) {
            if (vs[i].parent != null) {
                if (vs[i].val < vs[i].parent.val) {
                    vs[i].parent.left = vs[i];
                } else {
                    vs[i].parent.right = vs[i];
                }
            } else {
                root = vs[i];
            }
        }
        Node[] list = new Node[n];
        int s = 0, t = 1;
        list[0] = root;
        root.s = Integer.MIN_VALUE;
        root.t = Integer.MAX_VALUE;
        ArrayList<Node> leafl = new ArrayList<Node>();
        while (s < t) {
            Node v = list[s++];
            if (v.left != null) {
                v.left.depth = v.depth + 1;
                v.right.depth = v.depth + 1;
                v.left.s = v.s;
                v.left.t = v.val - 1;
                v.right.s = v.val + 1;
                v.right.t = v.t;
                list[t++] = v.left;
                list[t++] = v.right;
            } else {
                leafl.add(v);
            }
        }
        Node[] leaf = leafl.toArray(new Node[0]);
        sort(leaf);
        for (int i = n - 1; i >= 0; i--) {
            Node v = list[i];
            if (v.left == null) {
                v.ll = v.rr = v.val;
            } else {
                v.ll = v.left.ll;
                v.rr = v.right.rr;
            }
        }
        for (int i = 0; i < n; i++) {
            Node v = list[i];
            if (v.left != null) {
                v.left.sum = v.sum + v.right.ll;
                v.right.sum = v.sum + v.left.rr;
            }
        }
        int k = sc.nextInt();
        for (int i = 0; i < k; i++) {
            int x = sc.nextInt();
            Node v = new Node();
            v.s = x;
            int p = binarySearch(leaf, v);
            if (p < 0) p = -p - 2;
            out.printf("%.10f%n", (double)leaf[p].sum / leaf[p].depth);
        }
        out.flush();
    }
    
    class Node implements Comparable<Node> {
        Node parent;
        int val;
        Node left, right;
        int s, t, depth;
        long sum;
        int ll, rr;
        public int compareTo(Node o) {
            if (s < o.s) return -1;
            if (s > o.s) return 1;
            return 0;
        }
    }
    
    void debug(Object...os) {
        System.err.println(deepToString(os));
    }
    
    public static void main(String[] args) {
        new C().run();
    }
}