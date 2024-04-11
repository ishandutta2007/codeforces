import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Main {

    static FastScanner sc = new FastScanner(System.in);
    static Node[] nodes;
    static int ans = Integer.MAX_VALUE;
    static boolean giveup = false;

    public static void main(String[] args) {
        int N = sc.nextInt();
        nodes = new Node[N];
        for (int i = 0; i < N; i++) {
            nodes[i] = new Node(i);
        }
        for (int i = 0; i < N - 1; i++) {
            int U = sc.nextInt() - 1;
            int V = sc.nextInt() - 1;
            nodes[U].next.add(nodes[V]);
            nodes[V].next.add(nodes[U]);
        }
        int[] order = new int[N];
        for (int i = 0, pos = 1; i < N; i++) {
            Node cur = nodes[order[i]];
            for (Node node : cur.next) {
                if (cur.parent == node.idx) continue;
                order[pos++] = node.idx;
                node.parent = cur.idx;
            }
        }
        for (int i = N - 1; i >= 0 && !giveup; i--) {
            nodes[order[i]].upward();
        }
        for (int i = 0; i < N && !giveup; i++) {
            nodes[order[i]].downward();
        }
        System.out.println((ans == Integer.MAX_VALUE || giveup) ? -1 : ans);
    }

    static class Node {
        int idx;
        ArrayList<Node> next = new ArrayList<>();
        int parent = -1;
        HashMap<Integer, Integer> dists = new HashMap<>();

        public Node(int idx) {
            this.idx = idx;
        }

        void upward() {
            if (this.next.size() == 1) {
                this.dists.put(0, 1);
            }
            for (Node node : this.next) {
                if (node.idx == this.parent) continue;
                for (Map.Entry<Integer, Integer> e : node.dists.entrySet()) {
                    int key = e.getKey() + 1;
                    Integer v = this.dists.get(key);
                    this.dists.put(key, (v == null ? 0 : v) + e.getValue());
                }
            }
            if (this.dists.size() > 30) giveup = true;
        }

        void downward() {
//            System.out.println(this.idx);
//            System.out.println(this.dists);
            int l1 = -1;
            int l2 = -1;
            boolean ok = true;
            for (Node n : this.next) {
                int l = -1;
                if (n.idx == this.parent) {
                    for (Map.Entry<Integer, Integer> e : n.dists.entrySet()) {
                        int key = e.getKey() + 1;
                        int value = e.getValue();
                        if (key >= 2) {
                            Integer v = this.dists.get(key - 2);
                            if (v != null) value -= v;
                        }
                        if (value > 0) {
                            if (l == -1) {
                                l = key;
                            } else {
                                ok = false;
                                break;
                            }
                        }
                    }
                    if (!ok) break;
                } else {
                    if (n.dists.size() > 1) {
                        ok = false;
                        break;
                    }
                    l = n.dists.keySet().toArray(new Integer[0])[0] + 1;
                }
                if (l == l1 || l == l2) continue;
                if (l1 == -1) {
                    l1 = l;
                } else if (l2 == -1) {
                    l2 = l;
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                int d;
                if (l2 == -1) {
                    d = l1;
                } else {
                    d = l1 + l2;
                }
                ans = Math.min(ans, d / Integer.lowestOneBit(d));
            }
            if (this.parent != -1 && this.next.size() > 1) {
                Node p = nodes[this.parent];
                ArrayList<Integer> keys = new ArrayList<>();
                ArrayList<Integer> values = new ArrayList<>();
                for (Map.Entry<Integer, Integer> e : p.dists.entrySet()) {
                    int key = e.getKey() + 1;
                    int value = e.getValue();
                    if (key >= 2) {
                        Integer v = this.dists.get(key - 2);
                        if (v != null) value -= v;
                    }
                    if (value > 0) {
                        keys.add(key);
                        values.add(value);
                    }
                }
                for (int i = 0; i < keys.size(); i++) {
                    int key = keys.get(i);
                    int value = values.get(i);
                    Integer v = this.dists.get(key);
                    this.dists.put(key, (v == null ? 0 : v) + value);
                }
            }

        }
    }

    static class FastScanner {
        Reader input;

        FastScanner() {
            this(System.in);
        }

        FastScanner(InputStream stream) {
            this.input = new BufferedReader(new InputStreamReader(stream));
        }

        int nextInt() {
            return (int) nextLong();
        }

        long nextLong() {
            try {
                int sign = 1;
                int b = input.read();
                while ((b < '0' || '9' < b) && b != '-' && b != '+') {
                    b = input.read();
                }
                if (b == '-') {
                    sign = -1;
                    b = input.read();
                } else if (b == '+') {
                    b = input.read();
                }
                long ret = b - '0';
                while (true) {
                    b = input.read();
                    if (b < '0' || '9' < b) return ret * sign;
                    ret *= 10;
                    ret += b - '0';
                }
            } catch (IOException e) {
                e.printStackTrace();
                return -1;
            }
        }

        double nextDouble() {
            try {
                double sign = 1;
                int b = input.read();
                while ((b < '0' || '9' < b) && b != '-' && b != '+') {
                    b = input.read();
                }
                if (b == '-') {
                    sign = -1;
                    b = input.read();
                } else if (b == '+') {
                    b = input.read();
                }
                double ret = b - '0';
                while (true) {
                    b = input.read();
                    if (b < '0' || '9' < b) break;
                    ret *= 10;
                    ret += b - '0';
                }
                if (b != '.') return sign * ret;
                double div = 1;
                b = input.read();
                while ('0' <= b && b <= '9') {
                    ret *= 10;
                    ret += b - '0';
                    div *= 10;
                    b = input.read();
                }
                return sign * ret / div;
            } catch (IOException e) {
                e.printStackTrace();
                return Double.NaN;
            }
        }

        char nextChar() {
            try {
                int b = input.read();
                while (Character.isWhitespace(b)) {
                    b = input.read();
                }
                return (char) b;
            } catch (IOException e) {
                e.printStackTrace();
                return 0;
            }
        }

        String nextStr() {
            try {
                StringBuilder sb = new StringBuilder();
                int b = input.read();
                while (Character.isWhitespace(b)) {
                    b = input.read();
                }
                while (b != -1 && !Character.isWhitespace(b)) {
                    sb.append((char) b);
                    b = input.read();
                }
                return sb.toString();
            } catch (IOException e) {
                e.printStackTrace();
                return "";
            }
        }
    }
}