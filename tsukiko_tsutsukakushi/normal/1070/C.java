import java.util.*;

public class C {

    public static final int MOD998 = 998244353;
    public static final int MOD100 = 1000000007;

    public static void main(String[] args) throws Exception {
        ContestScanner sc = new ContestScanner();
        ContestPrinter cp = new ContestPrinter();
        int N = sc.nextInt();
        int K = sc.nextInt();
        int M = sc.nextInt();
        HashSet<Integer> set = new HashSet<>();
        int[][] data = sc.nextIntMatrix(M, 4);
        for (int n = 0; n < M; n++) {
            set.add(data[n][3]);
        }
        set.add(0);
        int[] former = new int[set.size()];
        int n = 0;
        for (int i : set) {
            former[n] = i;
            n++;
        }
        Arrays.sort(former);
        HashMap<Integer, Integer> map = new HashMap<>();
        for (n = 0; n < former.length; n++) {
            map.put(former[n], n);
        }
        SegTree<long[]> seg = new SegTree<long[]>(new long[set.size()][2],
                (a, b) -> new long[] { a[0] + b[0], a[1] + b[1] }, new long[2]);
        LinkedList<int[]> event = new LinkedList<>();
        for (int[] d : data) {
            event.add(new int[] { d[0] - 1, d[2], d[3] });
            event.add(new int[] { d[1], -d[2], d[3] });
        }
        event.sort(Comparator.comparingInt(a -> a[0]));
        long costsum = 0;
        long cost = 0;
        for (n = 0; n < N; n++) {
            boolean flag = false;
            while (!event.isEmpty() && event.getFirst()[0] == n) {
                int[] eve = event.removeFirst();
                long[] old = seg.get(map.get(eve[2]));
                seg.set(map.get(eve[2]), new long[] { old[0] + eve[1], old[1] + (long) eve[1] * eve[2] });
                flag = true;
            }
            if (flag) {
                int maxright = seg.maxRight(0, a -> a[0] <= K);
                long[] giri = seg.prod(0, maxright);
                cost = giri[1];
                if (maxright < set.size()) {
                    cost += (K - giri[0]) * former[maxright];
                }
            }
            costsum += cost;
        }
        cp.println(costsum);
        cp.close();
    }

    static class SegTree<S> {
        final int MAX;

        final int N;
        final java.util.function.BinaryOperator<S> op;
        final S E;

        final S[] data;

        @SuppressWarnings("unchecked")
        public SegTree(int n, java.util.function.BinaryOperator<S> op, S e) {
            this.MAX = n;
            int k = 1;
            while (k < n)
                k <<= 1;
            this.N = k;
            this.E = e;
            this.op = op;
            this.data = (S[]) new Object[N << 1];
            java.util.Arrays.fill(data, E);
        }

        public SegTree(S[] dat, java.util.function.BinaryOperator<S> op, S e) {
            this(dat.length, op, e);
            build(dat);
        }

        private void build(S[] dat) {
            int l = dat.length;
            System.arraycopy(dat, 0, data, N, l);
            for (int i = N - 1; i > 0; i--) {
                data[i] = op.apply(data[i << 1 | 0], data[i << 1 | 1]);
            }
        }

        public void set(int p, S x) {
            exclusiveRangeCheck(p);
            data[p += N] = x;
            p >>= 1;
            while (p > 0) {
                data[p] = op.apply(data[p << 1 | 0], data[p << 1 | 1]);
                p >>= 1;
            }
        }

        public S get(int p) {
            exclusiveRangeCheck(p);
            return data[p + N];
        }

        public S prod(int l, int r) {
            if (l > r) {
                throw new IllegalArgumentException(String.format("Invalid range: [%d, %d)", l, r));
            }
            inclusiveRangeCheck(l);
            inclusiveRangeCheck(r);
            S sumLeft = E;
            S sumRight = E;
            l += N;
            r += N;
            while (l < r) {
                if ((l & 1) == 1)
                    sumLeft = op.apply(sumLeft, data[l++]);
                if ((r & 1) == 1)
                    sumRight = op.apply(data[--r], sumRight);
                l >>= 1;
                r >>= 1;
            }
            return op.apply(sumLeft, sumRight);
        }

        public S allProd() {
            return data[1];
        }

        public int maxRight(int l, java.util.function.Predicate<S> f) {
            inclusiveRangeCheck(l);
            if (!f.test(E)) {
                throw new IllegalArgumentException("Identity element must satisfy the condition.");
            }
            if (l == MAX)
                return MAX;
            l += N;
            S sum = E;
            do {
                l >>= Integer.numberOfTrailingZeros(l);
                if (!f.test(op.apply(sum, data[l]))) {
                    while (l < N) {
                        l = l << 1;
                        if (f.test(op.apply(sum, data[l]))) {
                            sum = op.apply(sum, data[l]);
                            l++;
                        }
                    }
                    return l - N;
                }
                sum = op.apply(sum, data[l]);
                l++;
            } while ((l & -l) != l);
            return MAX;
        }

        public int minLeft(int r, java.util.function.Predicate<S> f) {
            inclusiveRangeCheck(r);
            if (!f.test(E)) {
                throw new IllegalArgumentException("Identity element must satisfy the condition.");
            }
            if (r == 0)
                return 0;
            r += N;
            S sum = E;
            do {
                r--;
                while (r > 1 && (r & 1) == 1)
                    r >>= 1;
                if (!f.test(op.apply(data[r], sum))) {
                    while (r < N) {
                        r = r << 1 | 1;
                        if (f.test(op.apply(data[r], sum))) {
                            sum = op.apply(data[r], sum);
                            r--;
                        }
                    }
                    return r + 1 - N;
                }
                sum = op.apply(data[r], sum);
            } while ((r & -r) != r);
            return 0;
        }

        private void exclusiveRangeCheck(int p) {
            if (p < 0 || p >= MAX) {
                throw new IndexOutOfBoundsException(
                        String.format("Index %d out of bounds for the range [%d, %d).", p, 0, MAX));
            }
        }

        private void inclusiveRangeCheck(int p) {
            if (p < 0 || p > MAX) {
                throw new IndexOutOfBoundsException(
                        String.format("Index %d out of bounds for the range [%d, %d].", p, 0, MAX));
            }
        }

        // **************** DEBUG **************** //

        private int indent = 6;

        public void setIndent(int newIndent) {
            this.indent = newIndent;
        }

        @Override
        public String toString() {
            return toSimpleString();
        }

        public String toDetailedString() {
            return toDetailedString(1, 0);
        }

        private String toDetailedString(int k, int sp) {
            if (k >= N)
                return indent(sp) + data[k];
            String s = "";
            s += toDetailedString(k << 1 | 1, sp + indent);
            s += "\n";
            s += indent(sp) + data[k];
            s += "\n";
            s += toDetailedString(k << 1 | 0, sp + indent);
            return s;
        }

        private static String indent(int n) {
            StringBuilder sb = new StringBuilder();
            while (n-- > 0)
                sb.append(' ');
            return sb.toString();
        }

        public String toSimpleString() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int i = 0; i < N; i++) {
                sb.append(data[i + N]);
                if (i < N - 1)
                    sb.append(',').append(' ');
            }
            sb.append(']');
            return sb.toString();
        }
    }
    //////////////////
    // My Library //
    //////////////////

    static class EdgeData {
        private int capacity;
        private int[] from, to, weight;
        private int p = 0;
        private boolean weighted;

        public EdgeData(boolean weighted) {
            this(weighted, 500000);
        }

        public EdgeData(boolean weighted, int initial_capacity) {
            capacity = initial_capacity;
            from = new int[capacity];
            to = new int[capacity];
            weight = new int[capacity];
            this.weighted = weighted;
        }

        public void addEdge(int u, int v) {
            if (weighted) {
                System.err.println("The graph is weighted!");
                return;
            }
            if (p == capacity) {
                int[] newfrom = new int[capacity * 2];
                int[] newto = new int[capacity * 2];
                System.arraycopy(from, 0, newfrom, 0, capacity);
                System.arraycopy(to, 0, newto, 0, capacity);
                from = newfrom;
                to = newto;
                capacity *= 2;
            }
            from[p] = u;
            to[p] = v;
            p++;
        }

        public void addEdge(int u, int v, int w) {
            if (!weighted) {
                System.err.println("The graph is NOT weighted!");
                return;
            }
            if (p == capacity) {
                int[] newfrom = new int[capacity * 2];
                int[] newto = new int[capacity * 2];
                int[] newweight = new int[capacity * 2];
                System.arraycopy(from, 0, newfrom, 0, capacity);
                System.arraycopy(to, 0, newto, 0, capacity);
                System.arraycopy(weight, 0, newweight, 0, capacity);
                from = newfrom;
                to = newto;
                weight = newweight;
                capacity *= 2;
            }
            from[p] = u;
            to[p] = v;
            weight[p] = w;
            p++;
        }

        public int[] getFrom() {
            int[] result = new int[p];
            System.arraycopy(from, 0, result, 0, p);
            return result;
        }

        public int[] getTo() {
            int[] result = new int[p];
            System.arraycopy(to, 0, result, 0, p);
            return result;
        }

        public int[] getWeight() {
            int[] result = new int[p];
            System.arraycopy(weight, 0, result, 0, p);
            return result;
        }

        public int size() {
            return p;
        }
    }

    ////////////////////////////////
    // Atcoder Library for Java //
    ////////////////////////////////

    static class MathLib {
        private static long safe_mod(long x, long m) {
            x %= m;
            if (x < 0)
                x += m;
            return x;
        }

        private static long[] inv_gcd(long a, long b) {
            a = safe_mod(a, b);
            if (a == 0)
                return new long[] { b, 0 };
            long s = b, t = a;
            long m0 = 0, m1 = 1;
            while (t > 0) {
                long u = s / t;
                s -= t * u;
                m0 -= m1 * u;
                long tmp = s;
                s = t;
                t = tmp;
                tmp = m0;
                m0 = m1;
                m1 = tmp;
            }
            if (m0 < 0)
                m0 += b / s;
            return new long[] { s, m0 };
        }

        public static long gcd(long a, long b) {
            a = java.lang.Math.abs(a);
            b = java.lang.Math.abs(b);
            return inv_gcd(a, b)[0];
        }

        public static long lcm(long a, long b) {
            a = java.lang.Math.abs(a);
            b = java.lang.Math.abs(b);
            return a / gcd(a, b) * b;
        }

        public static long pow_mod(long x, long n, int m) {
            assert n >= 0;
            assert m >= 1;
            if (m == 1)
                return 0L;
            x = safe_mod(x, m);
            long ans = 1L;
            while (n > 0) {
                if ((n & 1) == 1)
                    ans = (ans * x) % m;
                x = (x * x) % m;
                n >>>= 1;
            }
            return ans;
        }

        public static long[] crt(long[] r, long[] m) {
            assert (r.length == m.length);
            int n = r.length;

            long r0 = 0, m0 = 1;
            for (int i = 0; i < n; i++) {
                assert (1 <= m[i]);
                long r1 = safe_mod(r[i], m[i]), m1 = m[i];
                if (m0 < m1) {
                    long tmp = r0;
                    r0 = r1;
                    r1 = tmp;
                    tmp = m0;
                    m0 = m1;
                    m1 = tmp;
                }
                if (m0 % m1 == 0) {
                    if (r0 % m1 != r1)
                        return new long[] { 0, 0 };
                    continue;
                }

                long[] ig = inv_gcd(m0, m1);
                long g = ig[0], im = ig[1];

                long u1 = m1 / g;
                if ((r1 - r0) % g != 0)
                    return new long[] { 0, 0 };

                long x = (r1 - r0) / g % u1 * im % u1;

                r0 += x * m0;
                m0 *= u1;
                if (r0 < 0)
                    r0 += m0;
                // System.err.printf("%d %d\n", r0, m0);
            }
            return new long[] { r0, m0 };
        }

        public static long floor_sum(long n, long m, long a, long b) {
            long ans = 0;
            if (a >= m) {
                ans += (n - 1) * n * (a / m) / 2;
                a %= m;
            }
            if (b >= m) {
                ans += n * (b / m);
                b %= m;
            }

            long y_max = (a * n + b) / m;
            long x_max = y_max * m - b;
            if (y_max == 0)
                return ans;
            ans += (n - (x_max + a - 1) / a) * y_max;
            ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
            return ans;
        }

        public static java.util.ArrayList<Long> divisors(long n) {
            java.util.ArrayList<Long> divisors = new ArrayList<>();
            java.util.ArrayList<Long> large = new ArrayList<>();

            for (long i = 1; i * i <= n; i++)
                if (n % i == 0) {
                    divisors.add(i);
                    if (i * i < n)
                        large.add(n / i);
                }
            for (int p = large.size() - 1; p >= 0; p--) {
                divisors.add(large.get(p));
            }
            return divisors;
        }
    }

    static class Multiset<T> extends java.util.TreeMap<T, Long> {
        public Multiset() {
            super();
        }

        public Multiset(java.util.List<T> list) {
            super();
            for (T e : list)
                this.addOne(e);
        }

        public long count(Object elm) {
            return getOrDefault(elm, 0L);
        }

        public void add(T elm, long amount) {
            if (!this.containsKey(elm))
                put(elm, amount);
            else
                replace(elm, get(elm) + amount);
            if (this.count(elm) == 0)
                this.remove(elm);
        }

        public void addOne(T elm) {
            this.add(elm, 1);
        }

        public void removeOne(T elm) {
            this.add(elm, -1);
        }

        public void removeAll(T elm) {
            this.add(elm, -this.count(elm));
        }

        public static <T> Multiset<T> merge(Multiset<T> a, Multiset<T> b) {
            Multiset<T> c = new Multiset<>();
            for (T x : a.keySet())
                c.add(x, a.count(x));
            for (T y : b.keySet())
                c.add(y, b.count(y));
            return c;
        }
    }

    static class GraphBuilder {
        public static int[][] makeGraph(int NumberOfNodes, int NumberOfEdges, int[] from, int[] to,
                boolean undirected) {
            int[][] graph = new int[NumberOfNodes][];
            int[] outdegree = new int[NumberOfNodes];
            for (int i = 0; i < NumberOfEdges; i++) {
                outdegree[from[i]]++;
                if (undirected)
                    outdegree[to[i]]++;
            }
            for (int i = 0; i < NumberOfNodes; i++)
                graph[i] = new int[outdegree[i]];
            for (int i = 0; i < NumberOfEdges; i++) {
                graph[from[i]][--outdegree[from[i]]] = to[i];
                if (undirected)
                    graph[to[i]][--outdegree[to[i]]] = from[i];
            }
            return graph;
        }

        public static int[][][] makeGraphWithWeight(int NumberOfNodes, int NumberOfEdges, int[] from, int[] to,
                int[] weight, boolean undirected) {
            int[][][] graph = new int[NumberOfNodes][][];
            int[] outdegree = new int[NumberOfNodes];
            for (int i = 0; i < NumberOfEdges; i++) {
                outdegree[from[i]]++;
                if (undirected)
                    outdegree[to[i]]++;
            }
            for (int i = 0; i < NumberOfNodes; i++)
                graph[i] = new int[outdegree[i]][];
            for (int i = 0; i < NumberOfEdges; i++) {
                graph[from[i]][--outdegree[from[i]]] = new int[] { to[i], weight[i] };
                if (undirected)
                    graph[to[i]][--outdegree[to[i]]] = new int[] { from[i], weight[i] };
            }
            return graph;
        }

        public static int[][][] makeGraphWithEdgeInfo(int NumberOfNodes, int NumberOfEdges, int[] from, int[] to,
                boolean undirected) {
            int[][][] graph = new int[NumberOfNodes][][];
            int[] outdegree = new int[NumberOfNodes];
            for (int i = 0; i < NumberOfEdges; i++) {
                outdegree[from[i]]++;
                if (undirected)
                    outdegree[to[i]]++;
            }
            for (int i = 0; i < NumberOfNodes; i++)
                graph[i] = new int[outdegree[i]][];
            for (int i = 0; i < NumberOfEdges; i++) {
                graph[from[i]][--outdegree[from[i]]] = new int[] { to[i], i, 0 };
                if (undirected)
                    graph[to[i]][--outdegree[to[i]]] = new int[] { from[i], i, 1 };
            }
            return graph;
        }

        public static int[][][] makeGraphWithWeightAndEdgeInfo(int NumberOfNodes, int NumberOfEdges, int[] from,
                int[] to, int[] weight, boolean undirected) {
            int[][][] graph = new int[NumberOfNodes][][];
            int[] outdegree = new int[NumberOfNodes];
            for (int i = 0; i < NumberOfEdges; i++) {
                outdegree[from[i]]++;
                if (undirected)
                    outdegree[to[i]]++;
            }
            for (int i = 0; i < NumberOfNodes; i++)
                graph[i] = new int[outdegree[i]][];
            for (int i = 0; i < NumberOfEdges; i++) {
                graph[from[i]][--outdegree[from[i]]] = new int[] { to[i], weight[i], i, 0 };
                if (undirected)
                    graph[to[i]][--outdegree[to[i]]] = new int[] { from[i], weight[i], i, 1 };
            }
            return graph;
        }
    }

    static class DSU {
        private int n;
        private int[] parentOrSize;

        public DSU(int n) {
            this.n = n;
            this.parentOrSize = new int[n];
            java.util.Arrays.fill(parentOrSize, -1);
        }

        int merge(int a, int b) {
            if (!(0 <= a && a < n))
                throw new IndexOutOfBoundsException("a=" + a);
            if (!(0 <= b && b < n))
                throw new IndexOutOfBoundsException("b=" + b);

            int x = leader(a);
            int y = leader(b);
            if (x == y)
                return x;
            if (-parentOrSize[x] < -parentOrSize[y]) {
                int tmp = x;
                x = y;
                y = tmp;
            }
            parentOrSize[x] += parentOrSize[y];
            parentOrSize[y] = x;
            return x;
        }

        boolean same(int a, int b) {
            if (!(0 <= a && a < n))
                throw new IndexOutOfBoundsException("a=" + a);
            if (!(0 <= b && b < n))
                throw new IndexOutOfBoundsException("b=" + b);
            return leader(a) == leader(b);
        }

        int leader(int a) {
            if (parentOrSize[a] < 0) {
                return a;
            } else {
                parentOrSize[a] = leader(parentOrSize[a]);
                return parentOrSize[a];
            }
        }

        int size(int a) {
            if (!(0 <= a && a < n))
                throw new IndexOutOfBoundsException("" + a);
            return -parentOrSize[leader(a)];
        }

        java.util.ArrayList<java.util.ArrayList<Integer>> groups() {
            int[] leaderBuf = new int[n];
            int[] groupSize = new int[n];
            for (int i = 0; i < n; i++) {
                leaderBuf[i] = leader(i);
                groupSize[leaderBuf[i]]++;
            }
            java.util.ArrayList<java.util.ArrayList<Integer>> result = new java.util.ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                result.add(new java.util.ArrayList<>(groupSize[i]));
            }
            for (int i = 0; i < n; i++) {
                result.get(leaderBuf[i]).add(i);
            }
            result.removeIf(java.util.ArrayList::isEmpty);
            return result;
        }
    }

    static class ModIntFactory {
        private final ModArithmetic ma;
        private final int mod;

        private final boolean usesMontgomery;
        private final ModArithmetic.ModArithmeticMontgomery maMontgomery;

        private ArrayList<Integer> factorial;
        private ArrayList<Integer> factorial_inversion;

        public ModIntFactory(int mod) {
            this.ma = ModArithmetic.of(mod);
            this.usesMontgomery = ma instanceof ModArithmetic.ModArithmeticMontgomery;
            this.maMontgomery = usesMontgomery ? (ModArithmetic.ModArithmeticMontgomery) ma : null;
            this.mod = mod;

            this.factorial = new ArrayList<>();
            this.factorial_inversion = new ArrayList<>();
        }

        public ModInt create(long value) {
            if ((value %= mod) < 0)
                value += mod;
            if (usesMontgomery) {
                return new ModInt(maMontgomery.generate(value));
            } else {
                return new ModInt((int) value);
            }
        }

        private void prepareFactorial(int max) {
            factorial.ensureCapacity(max + 1);
            if (factorial.size() == 0)
                factorial.add(1);
            for (int i = factorial.size(); i <= max; i++) {
                factorial.add(ma.mul(factorial.get(i - 1), i));
            }
        }

        public ModInt factorial(int i) {
            prepareFactorial(i);
            return create(factorial.get(i));
        }

        public ModInt permutation(int n, int r) {
            if (n < 0 || r < 0 || n < r)
                return create(0);
            prepareFactorial(n);
            if (factorial_inversion.size() > n) {
                return create(ma.mul(factorial.get(n), factorial_inversion.get(n - r)));
            }
            return create(ma.div(factorial.get(n), factorial.get(n - r)));
        }

        public ModInt combination(int n, int r) {
            if (n < 0 || r < 0 || n < r)
                return create(0);
            prepareFactorial(n);
            if (factorial_inversion.size() > n) {
                return create(
                        ma.mul(factorial.get(n), ma.mul(factorial_inversion.get(n - r), factorial_inversion.get(r))));
            }
            return create(ma.div(factorial.get(n), ma.mul(factorial.get(r), factorial.get(n - r))));
        }

        public void prepareFactorialInv(int max) {
            prepareFactorial(max);
            factorial_inversion.ensureCapacity(max + 1);
            for (int i = factorial_inversion.size(); i <= max; i++) {
                factorial_inversion.add(ma.inv(factorial.get(i)));
            }
        }

        public int getMod() {
            return mod;
        }

        public class ModInt {
            private int value;

            private ModInt(int value) {
                this.value = value;
            }

            public int mod() {
                return mod;
            }

            public int value() {
                if (ma instanceof ModArithmetic.ModArithmeticMontgomery) {
                    return ((ModArithmetic.ModArithmeticMontgomery) ma).reduce(value);
                }
                return value;
            }

            public ModInt add(ModInt mi) {
                return new ModInt(ma.add(value, mi.value));
            }

            public ModInt add(ModInt mi1, ModInt mi2) {
                return new ModInt(ma.add(value, mi1.value)).addAsg(mi2);
            }

            public ModInt add(ModInt mi1, ModInt mi2, ModInt mi3) {
                return new ModInt(ma.add(value, mi1.value)).addAsg(mi2).addAsg(mi3);
            }

            public ModInt add(ModInt mi1, ModInt mi2, ModInt mi3, ModInt mi4) {
                return new ModInt(ma.add(value, mi1.value)).addAsg(mi2).addAsg(mi3).addAsg(mi4);
            }

            public ModInt add(ModInt mi1, ModInt... mis) {
                ModInt mi = add(mi1);
                for (ModInt m : mis)
                    mi.addAsg(m);
                return mi;
            }

            public ModInt add(long mi) {
                return new ModInt(ma.add(value, ma.remainder(mi)));
            }

            public ModInt sub(ModInt mi) {
                return new ModInt(ma.sub(value, mi.value));
            }

            public ModInt sub(long mi) {
                return new ModInt(ma.sub(value, ma.remainder(mi)));
            }

            public ModInt mul(ModInt mi) {
                return new ModInt(ma.mul(value, mi.value));
            }

            public ModInt mul(ModInt mi1, ModInt mi2) {
                return new ModInt(ma.mul(value, mi1.value)).mulAsg(mi2);
            }

            public ModInt mul(ModInt mi1, ModInt mi2, ModInt mi3) {
                return new ModInt(ma.mul(value, mi1.value)).mulAsg(mi2).mulAsg(mi3);
            }

            public ModInt mul(ModInt mi1, ModInt mi2, ModInt mi3, ModInt mi4) {
                return new ModInt(ma.mul(value, mi1.value)).mulAsg(mi2).mulAsg(mi3).mulAsg(mi4);
            }

            public ModInt mul(ModInt mi1, ModInt... mis) {
                ModInt mi = mul(mi1);
                for (ModInt m : mis)
                    mi.mulAsg(m);
                return mi;
            }

            public ModInt mul(long mi) {
                return new ModInt(ma.mul(value, ma.remainder(mi)));
            }

            public ModInt div(ModInt mi) {
                return new ModInt(ma.div(value, mi.value));
            }

            public ModInt div(long mi) {
                return new ModInt(ma.div(value, ma.remainder(mi)));
            }

            public ModInt inv() {
                return new ModInt(ma.inv(value));
            }

            public ModInt pow(long b) {
                return new ModInt(ma.pow(value, b));
            }

            public ModInt addAsg(ModInt mi) {
                this.value = ma.add(value, mi.value);
                return this;
            }

            public ModInt addAsg(ModInt mi1, ModInt mi2) {
                return addAsg(mi1).addAsg(mi2);
            }

            public ModInt addAsg(ModInt mi1, ModInt mi2, ModInt mi3) {
                return addAsg(mi1).addAsg(mi2).addAsg(mi3);
            }

            public ModInt addAsg(ModInt mi1, ModInt mi2, ModInt mi3, ModInt mi4) {
                return addAsg(mi1).addAsg(mi2).addAsg(mi3).addAsg(mi4);
            }

            public ModInt addAsg(ModInt... mis) {
                for (ModInt m : mis)
                    addAsg(m);
                return this;
            }

            public ModInt addAsg(long mi) {
                this.value = ma.add(value, ma.remainder(mi));
                return this;
            }

            public ModInt subAsg(ModInt mi) {
                this.value = ma.sub(value, mi.value);
                return this;
            }

            public ModInt subAsg(long mi) {
                this.value = ma.sub(value, ma.remainder(mi));
                return this;
            }

            public ModInt mulAsg(ModInt mi) {
                this.value = ma.mul(value, mi.value);
                return this;
            }

            public ModInt mulAsg(ModInt mi1, ModInt mi2) {
                return mulAsg(mi1).mulAsg(mi2);
            }

            public ModInt mulAsg(ModInt mi1, ModInt mi2, ModInt mi3) {
                return mulAsg(mi1).mulAsg(mi2).mulAsg(mi3);
            }

            public ModInt mulAsg(ModInt mi1, ModInt mi2, ModInt mi3, ModInt mi4) {
                return mulAsg(mi1).mulAsg(mi2).mulAsg(mi3).mulAsg(mi4);
            }

            public ModInt mulAsg(ModInt... mis) {
                for (ModInt m : mis)
                    mulAsg(m);
                return this;
            }

            public ModInt mulAsg(long mi) {
                this.value = ma.mul(value, ma.remainder(mi));
                return this;
            }

            public ModInt divAsg(ModInt mi) {
                this.value = ma.div(value, mi.value);
                return this;
            }

            public ModInt divAsg(long mi) {
                this.value = ma.div(value, ma.remainder(mi));
                return this;
            }

            @Override
            public String toString() {
                return String.valueOf(value());
            }

            @Override
            public boolean equals(Object o) {
                if (o instanceof ModInt) {
                    ModInt mi = (ModInt) o;
                    return mod() == mi.mod() && value() == mi.value();
                }
                return false;
            }

            @Override
            public int hashCode() {
                return (1 * 37 + mod()) * 37 + value();
            }
        }

        private static abstract class ModArithmetic {
            abstract int mod();

            abstract int remainder(long value);

            abstract int add(int a, int b);

            abstract int sub(int a, int b);

            abstract int mul(int a, int b);

            int div(int a, int b) {
                return mul(a, inv(b));
            }

            int inv(int a) {
                int b = mod();
                if (b == 1)
                    return 0;
                long u = 1, v = 0;
                while (b >= 1) {
                    int t = a / b;
                    a -= t * b;
                    int tmp1 = a;
                    a = b;
                    b = tmp1;
                    u -= t * v;
                    long tmp2 = u;
                    u = v;
                    v = tmp2;
                }
                if (a != 1) {
                    throw new ArithmeticException("divide by zero");
                }
                return remainder(u);
            }

            int pow(int a, long b) {
                if (b < 0)
                    throw new ArithmeticException("negative power");
                int r = 1;
                int x = a;
                while (b > 0) {
                    if ((b & 1) == 1)
                        r = mul(r, x);
                    x = mul(x, x);
                    b >>= 1;
                }
                return r;
            }

            static ModArithmetic of(int mod) {
                if (mod <= 0) {
                    throw new IllegalArgumentException();
                } else if (mod == 1) {
                    return new ModArithmetic1();
                } else if (mod == 2) {
                    return new ModArithmetic2();
                } else if (mod == 998244353) {
                    return new ModArithmetic998244353();
                } else if (mod == 1000000007) {
                    return new ModArithmetic1000000007();
                } else if ((mod & 1) == 1) {
                    return new ModArithmeticMontgomery(mod);
                } else {
                    return new ModArithmeticBarrett(mod);
                }
            }

            private static final class ModArithmetic1 extends ModArithmetic {
                int mod() {
                    return 1;
                }

                int remainder(long value) {
                    return 0;
                }

                int add(int a, int b) {
                    return 0;
                }

                int sub(int a, int b) {
                    return 0;
                }

                int mul(int a, int b) {
                    return 0;
                }

                int pow(int a, long b) {
                    return 0;
                }
            }

            private static final class ModArithmetic2 extends ModArithmetic {
                int mod() {
                    return 2;
                }

                int remainder(long value) {
                    return (int) (value & 1);
                }

                int add(int a, int b) {
                    return a ^ b;
                }

                int sub(int a, int b) {
                    return a ^ b;
                }

                int mul(int a, int b) {
                    return a & b;
                }
            }

            private static final class ModArithmetic998244353 extends ModArithmetic {
                private final int mod = 998244353;

                int mod() {
                    return mod;
                }

                int remainder(long value) {
                    return (int) ((value %= mod) < 0 ? value + mod : value);
                }

                int add(int a, int b) {
                    int res = a + b;
                    return res >= mod ? res - mod : res;
                }

                int sub(int a, int b) {
                    int res = a - b;
                    return res < 0 ? res + mod : res;
                }

                int mul(int a, int b) {
                    return (int) (((long) a * b) % mod);
                }
            }

            private static final class ModArithmetic1000000007 extends ModArithmetic {
                private final int mod = 1000000007;

                int mod() {
                    return mod;
                }

                int remainder(long value) {
                    return (int) ((value %= mod) < 0 ? value + mod : value);
                }

                int add(int a, int b) {
                    int res = a + b;
                    return res >= mod ? res - mod : res;
                }

                int sub(int a, int b) {
                    int res = a - b;
                    return res < 0 ? res + mod : res;
                }

                int mul(int a, int b) {
                    return (int) (((long) a * b) % mod);
                }
            }

            private static final class ModArithmeticMontgomery extends ModArithmeticDynamic {
                private final long negInv;
                private final long r2;

                private ModArithmeticMontgomery(int mod) {
                    super(mod);
                    long inv = 0;
                    long s = 1, t = 0;
                    for (int i = 0; i < 32; i++) {
                        if ((t & 1) == 0) {
                            t += mod;
                            inv += s;
                        }
                        t >>= 1;
                        s <<= 1;
                    }
                    long r = (1l << 32) % mod;
                    this.negInv = inv;
                    this.r2 = (r * r) % mod;
                }

                private int generate(long x) {
                    return reduce(x * r2);
                }

                private int reduce(long x) {
                    x = (x + ((x * negInv) & 0xffff_ffffl) * mod) >>> 32;
                    return (int) (x < mod ? x : x - mod);
                }

                @Override
                int remainder(long value) {
                    return generate((value %= mod) < 0 ? value + mod : value);
                }

                @Override
                int mul(int a, int b) {
                    return reduce((long) a * b);
                }

                @Override
                int inv(int a) {
                    return super.inv(reduce(a));
                }

                @Override
                int pow(int a, long b) {
                    return generate(super.pow(a, b));
                }
            }

            private static final class ModArithmeticBarrett extends ModArithmeticDynamic {
                private static final long mask = 0xffff_ffffl;
                private final long mh;
                private final long ml;

                private ModArithmeticBarrett(int mod) {
                    super(mod);
                    /**
                     * m = floor(2^64/mod) 2^64 = p*mod + q, 2^32 = a*mod + b => (a*mod + b)^2 =
                     * p*mod + q => p = mod*a^2 + 2ab + floor(b^2/mod)
                     */
                    long a = (1l << 32) / mod;
                    long b = (1l << 32) % mod;
                    long m = a * a * mod + 2 * a * b + (b * b) / mod;
                    mh = m >>> 32;
                    ml = m & mask;
                }

                private int reduce(long x) {
                    long z = (x & mask) * ml;
                    z = (x & mask) * mh + (x >>> 32) * ml + (z >>> 32);
                    z = (x >>> 32) * mh + (z >>> 32);
                    x -= z * mod;
                    return (int) (x < mod ? x : x - mod);
                }

                @Override
                int remainder(long value) {
                    return (int) ((value %= mod) < 0 ? value + mod : value);
                }

                @Override
                int mul(int a, int b) {
                    return reduce((long) a * b);
                }
            }

            private static class ModArithmeticDynamic extends ModArithmetic {
                final int mod;

                ModArithmeticDynamic(int mod) {
                    this.mod = mod;
                }

                int mod() {
                    return mod;
                }

                int remainder(long value) {
                    return (int) ((value %= mod) < 0 ? value + mod : value);
                }

                int add(int a, int b) {
                    int sum = a + b;
                    return sum >= mod ? sum - mod : sum;
                }

                int sub(int a, int b) {
                    int sum = a - b;
                    return sum < 0 ? sum + mod : sum;
                }

                int mul(int a, int b) {
                    return (int) (((long) a * b) % mod);
                }
            }
        }
    }

    static class Convolution {
        /**
         * Find a primitive root.
         *
         * @param m A prime number.
         * @return Primitive root.
         */
        private static int primitiveRoot(int m) {
            if (m == 2)
                return 1;
            if (m == 167772161)
                return 3;
            if (m == 469762049)
                return 3;
            if (m == 754974721)
                return 11;
            if (m == 998244353)
                return 3;

            int[] divs = new int[20];
            divs[0] = 2;
            int cnt = 1;
            int x = (m - 1) / 2;
            while (x % 2 == 0)
                x /= 2;
            for (int i = 3; (long) (i) * i <= x; i += 2) {
                if (x % i == 0) {
                    divs[cnt++] = i;
                    while (x % i == 0) {
                        x /= i;
                    }
                }
            }
            if (x > 1) {
                divs[cnt++] = x;
            }
            for (int g = 2;; g++) {
                boolean ok = true;
                for (int i = 0; i < cnt; i++) {
                    if (pow(g, (m - 1) / divs[i], m) == 1) {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                    return g;
            }
        }

        /**
         * Power.
         *
         * @param x Parameter x.
         * @param n Parameter n.
         * @param m Mod.
         * @return n-th power of x mod m.
         */
        private static long pow(long x, long n, int m) {
            if (m == 1)
                return 0;
            long r = 1;
            long y = x % m;
            while (n > 0) {
                if ((n & 1) != 0)
                    r = (r * y) % m;
                y = (y * y) % m;
                n >>= 1;
            }
            return r;
        }

        /**
         * Ceil of power 2.
         *
         * @param n Value.
         * @return Ceil of power 2.
         */
        private static int ceilPow2(int n) {
            int x = 0;
            while ((1L << x) < n)
                x++;
            return x;
        }

        /**
         * Garner's algorithm.
         *
         * @param c    Mod convolution results.
         * @param mods Mods.
         * @return Result.
         */
        private static long garner(long[] c, int[] mods) {
            int n = c.length + 1;
            long[] cnst = new long[n];
            long[] coef = new long[n];
            java.util.Arrays.fill(coef, 1);
            for (int i = 0; i < n - 1; i++) {
                int m1 = mods[i];
                long v = (c[i] - cnst[i] + m1) % m1;
                v = v * pow(coef[i], m1 - 2, m1) % m1;

                for (int j = i + 1; j < n; j++) {
                    long m2 = mods[j];
                    cnst[j] = (cnst[j] + coef[j] * v) % m2;
                    coef[j] = (coef[j] * m1) % m2;
                }
            }
            return cnst[n - 1];
        }

        /**
         * Pre-calculation for NTT.
         *
         * @param mod NTT Prime.
         * @param g   Primitive root of mod.
         * @return Pre-calculation table.
         */
        private static long[] sumE(int mod, int g) {
            long[] sum_e = new long[30];
            long[] es = new long[30];
            long[] ies = new long[30];
            int cnt2 = Integer.numberOfTrailingZeros(mod - 1);
            long e = pow(g, (mod - 1) >> cnt2, mod);
            long ie = pow(e, mod - 2, mod);
            for (int i = cnt2; i >= 2; i--) {
                es[i - 2] = e;
                ies[i - 2] = ie;
                e = e * e % mod;
                ie = ie * ie % mod;
            }
            long now = 1;
            for (int i = 0; i < cnt2 - 2; i++) {
                sum_e[i] = es[i] * now % mod;
                now = now * ies[i] % mod;
            }
            return sum_e;
        }

        /**
         * Pre-calculation for inverse NTT.
         *
         * @param mod Mod.
         * @param g   Primitive root of mod.
         * @return Pre-calculation table.
         */
        private static long[] sumIE(int mod, int g) {
            long[] sum_ie = new long[30];
            long[] es = new long[30];
            long[] ies = new long[30];

            int cnt2 = Integer.numberOfTrailingZeros(mod - 1);
            long e = pow(g, (mod - 1) >> cnt2, mod);
            long ie = pow(e, mod - 2, mod);
            for (int i = cnt2; i >= 2; i--) {
                es[i - 2] = e;
                ies[i - 2] = ie;
                e = e * e % mod;
                ie = ie * ie % mod;
            }
            long now = 1;
            for (int i = 0; i < cnt2 - 2; i++) {
                sum_ie[i] = ies[i] * now % mod;
                now = now * es[i] % mod;
            }
            return sum_ie;
        }

        /**
         * Inverse NTT.
         *
         * @param a     Target array.
         * @param sumIE Pre-calculation table.
         * @param mod   NTT Prime.
         */
        private static void butterflyInv(long[] a, long[] sumIE, int mod) {
            int n = a.length;
            int h = ceilPow2(n);

            for (int ph = h; ph >= 1; ph--) {
                int w = 1 << (ph - 1), p = 1 << (h - ph);
                long inow = 1;
                for (int s = 0; s < w; s++) {
                    int offset = s << (h - ph + 1);
                    for (int i = 0; i < p; i++) {
                        long l = a[i + offset];
                        long r = a[i + offset + p];
                        a[i + offset] = (l + r) % mod;
                        a[i + offset + p] = (mod + l - r) * inow % mod;
                    }
                    int x = Integer.numberOfTrailingZeros(~s);
                    inow = inow * sumIE[x] % mod;
                }
            }
        }

        /**
         * Inverse NTT.
         *
         * @param a    Target array.
         * @param sumE Pre-calculation table.
         * @param mod  NTT Prime.
         */
        private static void butterfly(long[] a, long[] sumE, int mod) {
            int n = a.length;
            int h = ceilPow2(n);

            for (int ph = 1; ph <= h; ph++) {
                int w = 1 << (ph - 1), p = 1 << (h - ph);
                long now = 1;
                for (int s = 0; s < w; s++) {
                    int offset = s << (h - ph + 1);
                    for (int i = 0; i < p; i++) {
                        long l = a[i + offset];
                        long r = a[i + offset + p] * now % mod;
                        a[i + offset] = (l + r) % mod;
                        a[i + offset + p] = (l - r + mod) % mod;
                    }
                    int x = Integer.numberOfTrailingZeros(~s);
                    now = now * sumE[x] % mod;
                }
            }
        }

        /**
         * Convolution.
         *
         * @param a   Target array 1.
         * @param b   Target array 2.
         * @param mod NTT Prime.
         * @return Answer.
         */
        public static long[] convolution(long[] a, long[] b, int mod) {
            int n = a.length;
            int m = b.length;
            if (n == 0 || m == 0)
                return new long[0];

            int z = 1 << ceilPow2(n + m - 1);
            {
                long[] na = new long[z];
                long[] nb = new long[z];
                System.arraycopy(a, 0, na, 0, n);
                System.arraycopy(b, 0, nb, 0, m);
                a = na;
                b = nb;
            }

            int g = primitiveRoot(mod);
            long[] sume = sumE(mod, g);
            long[] sumie = sumIE(mod, g);

            butterfly(a, sume, mod);
            butterfly(b, sume, mod);
            for (int i = 0; i < z; i++) {
                a[i] = a[i] * b[i] % mod;
            }
            butterflyInv(a, sumie, mod);
            a = java.util.Arrays.copyOf(a, n + m - 1);

            long iz = pow(z, mod - 2, mod);
            for (int i = 0; i < n + m - 1; i++)
                a[i] = a[i] * iz % mod;
            return a;
        }

        /**
         * Convolution.
         *
         * @param a   Target array 1.
         * @param b   Target array 2.
         * @param mod Any mod.
         * @return Answer.
         */
        public static long[] convolutionLL(long[] a, long[] b, int mod) {
            int n = a.length;
            int m = b.length;
            if (n == 0 || m == 0)
                return new long[0];

            int mod1 = 754974721;
            int mod2 = 167772161;
            int mod3 = 469762049;

            long[] c1 = convolution(a, b, mod1);
            long[] c2 = convolution(a, b, mod2);
            long[] c3 = convolution(a, b, mod3);

            int retSize = c1.length;
            long[] ret = new long[retSize];
            int[] mods = { mod1, mod2, mod3, mod };
            for (int i = 0; i < retSize; ++i) {
                ret[i] = garner(new long[] { c1[i], c2[i], c3[i] }, mods);
            }
            return ret;
        }

        /**
         * Convolution by ModInt.
         *
         * @param a Target array 1.
         * @param b Target array 2.
         * @return Answer.
         */
        public static java.util.List<ModIntFactory.ModInt> convolution(java.util.List<ModIntFactory.ModInt> a,
                java.util.List<ModIntFactory.ModInt> b) {
            int mod = a.get(0).mod();
            long[] va = a.stream().mapToLong(ModIntFactory.ModInt::value).toArray();
            long[] vb = b.stream().mapToLong(ModIntFactory.ModInt::value).toArray();
            long[] c = convolutionLL(va, vb, mod);

            ModIntFactory factory = new ModIntFactory(mod);
            return java.util.Arrays.stream(c).mapToObj(factory::create).collect(java.util.stream.Collectors.toList());
        }

        /**
         * Naive convolution. (Complexity is O(N^2)!!)
         *
         * @param a   Target array 1.
         * @param b   Target array 2.
         * @param mod Mod.
         * @return Answer.
         */
        public static long[] convolutionNaive(long[] a, long[] b, int mod) {
            int n = a.length;
            int m = b.length;
            int k = n + m - 1;
            long[] ret = new long[k];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ret[i + j] += a[i] * b[j] % mod;
                    ret[i + j] %= mod;
                }
            }
            return ret;
        }
    }

    static class ContestScanner {
        private final java.io.InputStream in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;

        private static final long LONG_MAX_TENTHS = 922337203685477580L;
        private static final int LONG_MAX_LAST_DIGIT = 7;
        private static final int LONG_MIN_LAST_DIGIT = 8;

        public ContestScanner(java.io.InputStream in) {
            this.in = in;
        }

        public ContestScanner() {
            this(System.in);
        }

        private boolean hasNextByte() {
            if (ptr < buflen) {
                return true;
            } else {
                ptr = 0;
                try {
                    buflen = in.read(buffer);
                } catch (java.io.IOException e) {
                    e.printStackTrace();
                }
                if (buflen <= 0) {
                    return false;
                }
            }
            return true;
        }

        private int readByte() {
            if (hasNextByte())
                return buffer[ptr++];
            else
                return -1;
        }

        private static boolean isPrintableChar(int c) {
            return 33 <= c && c <= 126;
        }

        public boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[ptr]))
                ptr++;
            return hasNextByte();
        }

        public String next() {
            if (!hasNext())
                throw new java.util.NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        public long nextLong() {
            if (!hasNext())
                throw new java.util.NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || '9' < b) {
                throw new NumberFormatException();
            }
            while (true) {
                if ('0' <= b && b <= '9') {
                    int digit = b - '0';
                    if (n >= LONG_MAX_TENTHS) {
                        if (n == LONG_MAX_TENTHS) {
                            if (minus) {
                                if (digit <= LONG_MIN_LAST_DIGIT) {
                                    n = -n * 10 - digit;
                                    b = readByte();
                                    if (!isPrintableChar(b)) {
                                        return n;
                                    } else if (b < '0' || '9' < b) {
                                        throw new NumberFormatException(
                                                String.format("%d%s... is not number", n, Character.toString(b)));
                                    }
                                }
                            } else {
                                if (digit <= LONG_MAX_LAST_DIGIT) {
                                    n = n * 10 + digit;
                                    b = readByte();
                                    if (!isPrintableChar(b)) {
                                        return n;
                                    } else if (b < '0' || '9' < b) {
                                        throw new NumberFormatException(
                                                String.format("%d%s... is not number", n, Character.toString(b)));
                                    }
                                }
                            }
                        }
                        throw new ArithmeticException(
                                String.format("%s%d%d... overflows long.", minus ? "-" : "", n, digit));
                    }
                    n = n * 10 + digit;
                } else if (b == -1 || !isPrintableChar(b)) {
                    return minus ? -n : n;
                } else {
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }

        public int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
                throw new NumberFormatException();
            return (int) nl;
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public long[] nextLongArray(int length) {
            long[] array = new long[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextLong();
            return array;
        }

        public long[] nextLongArray(int length, java.util.function.LongUnaryOperator map) {
            long[] array = new long[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsLong(this.nextLong());
            return array;
        }

        public int[] nextIntArray(int length) {
            int[] array = new int[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextInt();
            return array;
        }

        public int[][] nextIntArrayMulti(int length, int width) {
            int[][] arrays = new int[width][length];
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < width; j++)
                    arrays[j][i] = this.nextInt();
            }
            return arrays;
        }

        public int[] nextIntArray(int length, java.util.function.IntUnaryOperator map) {
            int[] array = new int[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsInt(this.nextInt());
            return array;
        }

        public double[] nextDoubleArray(int length) {
            double[] array = new double[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextDouble();
            return array;
        }

        public double[] nextDoubleArray(int length, java.util.function.DoubleUnaryOperator map) {
            double[] array = new double[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsDouble(this.nextDouble());
            return array;
        }

        public long[][] nextLongMatrix(int height, int width) {
            long[][] mat = new long[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextLong();
                }
            return mat;
        }

        public int[][] nextIntMatrix(int height, int width) {
            int[][] mat = new int[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextInt();
                }
            return mat;
        }

        public double[][] nextDoubleMatrix(int height, int width) {
            double[][] mat = new double[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextDouble();
                }
            return mat;
        }

        public char[][] nextCharMatrix(int height, int width) {
            char[][] mat = new char[height][width];
            for (int h = 0; h < height; h++) {
                String s = this.next();
                for (int w = 0; w < width; w++) {
                    mat[h][w] = s.charAt(w);
                }
            }
            return mat;
        }
    }

    static class ContestPrinter extends java.io.PrintWriter {
        public ContestPrinter(java.io.PrintStream stream) {
            super(stream);
        }

        public ContestPrinter() {
            super(System.out);
        }

        private static String dtos(double x, int n) {
            StringBuilder sb = new StringBuilder();
            if (x < 0) {
                sb.append('-');
                x = -x;
            }
            x += Math.pow(10, -n) / 2;
            sb.append((long) x);
            sb.append(".");
            x -= (long) x;
            for (int i = 0; i < n; i++) {
                x *= 10;
                sb.append((int) x);
                x -= (int) x;
            }
            return sb.toString();
        }

        @Override
        public void print(float f) {
            super.print(dtos(f, 20));
        }

        @Override
        public void println(float f) {
            super.println(dtos(f, 20));
        }

        @Override
        public void print(double d) {
            super.print(dtos(d, 20));
        }

        @Override
        public void println(double d) {
            super.println(dtos(d, 20));
        }

        public void printArray(int[] array, String separator) {
            int n = array.length;
            for (int i = 0; i < n - 1; i++) {
                super.print(array[i]);
                super.print(separator);
            }
            super.println(array[n - 1]);
        }

        public void printArray(int[] array) {
            this.printArray(array, " ");
        }

        public void printArray(int[] array, String separator, java.util.function.IntUnaryOperator map) {
            int n = array.length;
            for (int i = 0; i < n - 1; i++) {
                super.print(map.applyAsInt(array[i]));
                super.print(separator);
            }
            super.println(map.applyAsInt(array[n - 1]));
        }

        public void printArray(int[] array, java.util.function.IntUnaryOperator map) {
            this.printArray(array, " ", map);
        }

        public void printArray(long[] array, String separator) {
            int n = array.length;
            for (int i = 0; i < n - 1; i++) {
                super.print(array[i]);
                super.print(separator);
            }
            super.println(array[n - 1]);
        }

        public void printArray(long[] array) {
            this.printArray(array, " ");
        }

        public void printArray(long[] array, String separator, java.util.function.LongUnaryOperator map) {
            int n = array.length;
            for (int i = 0; i < n - 1; i++) {
                super.print(map.applyAsLong(array[i]));
                super.print(separator);
            }
            super.println(map.applyAsLong(array[n - 1]));
        }

        public void printArray(long[] array, java.util.function.LongUnaryOperator map) {
            this.printArray(array, " ", map);
        }

    }

    public static void safeSort(int[] array) {
        Integer[] temp = new Integer[array.length];
        for (int n = 0; n < array.length; n++) {
            temp[n] = array[n];
        }
        Arrays.sort(temp);
        for (int n = 0; n < array.length; n++) {
            array[n] = temp[n];
        }
    }

    public static void safeSort(long[] array) {
        Long[] temp = new Long[array.length];
        for (int n = 0; n < array.length; n++) {
            temp[n] = array[n];
        }
        Arrays.sort(temp);
        for (int n = 0; n < array.length; n++) {
            array[n] = temp[n];
        }
    }

    public static void safeSort(double[] array) {
        Double[] temp = new Double[array.length];
        for (int n = 0; n < array.length; n++) {
            temp[n] = array[n];
        }
        Arrays.sort(temp);
        for (int n = 0; n < array.length; n++) {
            array[n] = temp[n];
        }
    }

}