import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    private static final long INF = (long)1e18;

    private static class Node {
        long mina;
        long lazy;

        public Node(long mina, long lazy) {
            this.mina = mina;
            this.lazy = lazy;
        }
    }

    private static void buildTree(ArrayList<Integer> a, ArrayList<Node> segtree, int left, int right, int index)
    {
        if (left == right)
        {
            segtree.get(index).mina = a.get(left);
            return;
        }
        int mid = (left + right) / 2;

        buildTree(a, segtree, left, mid, 2 * index + 1);
        buildTree(a, segtree, mid + 1, right, 2 * index + 2);

        segtree.get(index).mina = Math.min(segtree.get(2 * index + 1).mina, segtree.get(2 * index + 2).mina);
    }


    private static void updateQuery_minRangeLazy(ArrayList<Node> segtree, int left, int right, int from, int to, int delta, int index)
    {
        if (left > right)
            return;

        //make sure all propagation is done at index. If not update tree
        //at index and mark its children for lazy propagation.
        if (segtree.get(index).lazy != 0)
        {
            segtree.get(index).mina += segtree.get(index).lazy;
            if (left != right)
            { // not a leaf node
                segtree.get(2 * index + 1).lazy += segtree.get(index).lazy;
                segtree.get(2 * index + 2).lazy += segtree.get(index).lazy;
            }
            segtree.get(index).lazy = 0;
        }

        //no overlap condition
        if (from > right || to < left)
            return;

        //total overlap condition
        if (from <= left && to >= right)
        {
            segtree.get(index).mina += delta;
            if (left != right)
            {
                segtree.get(2 * index + 1).lazy += delta;
                segtree.get(2 * index + 2).lazy += delta;
            }
            return;
        }

        //otherwise partial overlap so look both left and right.
        int mid = (left + right) / 2;
        updateQuery_minRangeLazy(segtree, left, mid, from, to, delta, 2 * index + 1);
        updateQuery_minRangeLazy(segtree, mid + 1, right, from, to, delta, 2 * index + 2);

        segtree.get(index).mina = Math.min(segtree.get(2 * index + 1).mina, segtree.get(2 * index + 2).mina);
    }

    private static long minRangeLazy(ArrayList<Node> segtree, int left, int right, int from, int to, int index)
    {
        if (left > right)
            return INF;

        //make sure all propagation is done at index. If not update tree
        //at index and mark its children for lazy propagation.
        if (segtree.get(index).lazy != 0)
        {
            segtree.get(index).mina += segtree.get(index).lazy;
            if (left != right)
            { // not a leaf node
                segtree.get(2 * index + 1).lazy += segtree.get(index).lazy;
                segtree.get(2 * index + 2).lazy += segtree.get(index).lazy;
            }
            segtree.get(index).lazy = 0;
        }

        //no overlap condition
        if (from > right || to < left)
            return INF;

        //total overlap condition
        if (from <= left && to >= right)
            return segtree.get(index).mina;

        //partial overlap
        int mid = (left + right) / 2;
        return Math.min(minRangeLazy(segtree, left, mid, from, to, 2 * index + 1),
                minRangeLazy(segtree, mid + 1, right, from, to, 2 * index + 2));
    }

    private static void circularUpdate(int n, ArrayList<Node> segtree, int from, int to, int delta) {
        if (from <= to)
        {
            updateQuery_minRangeLazy(segtree, 0, n - 1, from, to, delta, 0);
            return;
        }

        updateQuery_minRangeLazy(segtree, 0, n - 1, from, n - 1, delta, 0);
        updateQuery_minRangeLazy(segtree, 0, n - 1, 0, to, delta, 0);
    }

    private static long circularQuery(int n, ArrayList<Node> segtree, int from, int to) {
        if (from <= to)
            return minRangeLazy(segtree, 0, n - 1, from, to, 0);

        return Math.min(minRangeLazy(segtree, 0, n - 1, from, n - 1, 0),
                minRangeLazy(segtree, 0, n - 1, 0, to, 0));
    }

    private static double logb( double a, double b )
    {
        return Math.log(a) / Math.log(b);
    }

    private static double log2( double a )
    {
        return logb(a,2);
    }

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();

        ArrayList<Integer> a = new ArrayList<Integer>();
        for(int i = 0; i < n; ++i)
            a.add(in.nextInt());

        //Height of segment tree
        int h = (int)Math.ceil(log2(n));

        //Maximum size of segment tree
        int sizetree = 2 * (int)Math.pow(2, h) - 1;

        ArrayList<Node> segtree = new ArrayList<>();
        for(int i = 0; i < sizetree; ++i)
            segtree.add(new Node(0, 0));

        buildTree(a, segtree, 0, n - 1, 0);

        int q = in.nextInt();
        String line = in.nextLine();

        for(int i = 0; i < q; ++i)
        {
            line = in.nextLine();
            StringTokenizer st = new StringTokenizer(line);

            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            if (st.hasMoreTokens()) {
                int delta = Integer.parseInt(st.nextToken());
                circularUpdate(n, segtree, from, to, delta);
            } else
                out.println(circularQuery(n, segtree, from, to));
        }

        out.close();
    }
}