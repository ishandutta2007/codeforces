import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.FilterInputStream;
import java.io.BufferedInputStream;
import java.util.Random;
import java.io.InputStream;

/**
 * @author khokharnikunj8
 */

public class Main {
    public static void main(String[] args) {
        new Thread(null, new Runnable() {
            public void run() {
                new Main().solve();
            }
        }, "1", 1 << 26).start();
    }

    void solve() {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        ScanReader in = new ScanReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ELunarNewYearAndRedEnvelopes solver = new ELunarNewYearAndRedEnvelopes();
        solver.solve(1, in, out);
        out.close();
    }

    static class ELunarNewYearAndRedEnvelopes {
        public void solve(int testNumber, ScanReader in, PrintWriter out) {
            int n = in.scanInt();
            int m = in.scanInt();
            int k = in.scanInt();
            long[][] dp = new long[n + 2][m + 1];
            BSTCustom<Integer> bst = new BSTCustom<Integer>();
            for (int i = 1; i <= n; i++) bst.insert(i);
            int[][] pair = new int[k][4];
            for (int i = 0; i < k; i++) {
                pair[i][0] = in.scanInt();
                pair[i][1] = in.scanInt();
                pair[i][2] = in.scanInt();
                pair[i][3] = in.scanInt();
            }
            CodeHash.shuffle(pair);
            Arrays.sort(pair, (o1, o2) -> {
                if (o1[3] == o2[3]) return -o1[2] + o2[2];
                return -o1[3] + o2[3];
            });
            int[][] which = new int[n + 1][3];
            for (int i = 0; i <= n; i++) {
                which[i][0] = -1;
                which[i][1] = 0;
                which[i][2] = i;
            }
            for (int i = 0; i < k; i++) {
                long tt = bst.lower_bound(pair[i][0]);
                while (tt < bst.size()) {
                    int temp = bst.get(tt);
                    if (temp > pair[i][1]) break;
                    which[temp][0] = i;
                    which[temp][1] = pair[i][3];
                    which[temp][2] = pair[i][2];
                    bst.remove(temp);
                }
            }
            for (int i = 0; i <= n; i++) Arrays.fill(dp[i], Long.MAX_VALUE / 3);
            dp[0][0] = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= m; j++) {
                    dp[which[i][2]][j] = Math.min(dp[which[i][2]][j], dp[i - 1][j] + which[i][1]);
                    if (j + 1 <= m) dp[i][j + 1] = Math.min(dp[i][j + 1], dp[i - 1][j]);
                }
            }
            long ans = Long.MAX_VALUE;
            for (int i = 0; i <= m; i++) ans = Math.min(ans, dp[n][i]);
            out.println(ans);
        }

    }

    static class ScanReader {
        private byte[] buf = new byte[4 * 1024];
        private int index;
        private BufferedInputStream in;
        private int total;

        public ScanReader(InputStream inputStream) {
            in = new BufferedInputStream(inputStream);
        }

        private int scan() {
            if (index >= total) {
                index = 0;
                try {
                    total = in.read(buf);
                } catch (Exception e) {
                    e.printStackTrace();
                }
                if (total <= 0) return -1;
            }
            return buf[index++];
        }

        public int scanInt() {
            int integer = 0;
            int n = scan();
            while (isWhiteSpace(n)) n = scan();
            int neg = 1;
            if (n == '-') {
                neg = -1;
                n = scan();
            }
            while (!isWhiteSpace(n)) {
                if (n >= '0' && n <= '9') {
                    integer *= 10;
                    integer += n - '0';
                    n = scan();
                }
            }
            return neg * integer;
        }

        private boolean isWhiteSpace(int n) {
            if (n == ' ' || n == '\n' || n == '\r' || n == '\t' || n == -1) return true;
            else return false;
        }

    }

    static class BSTCustom<T extends Comparable<? super T>> {
        private Node<T> __root;
        private Node<T> __tempnode;
        private Node<T> __tempnode1;
        private long __size;
        private boolean __multi;

        public BSTCustom() {
            __root = null;
            __size = 0;
            __multi = false;

        }

        public BSTCustom(boolean __multi) {
            __root = null;
            __size = 0;
            this.__multi = __multi;
        }

        public long lower_bound(T data) {
            __tempnode = __root;
            long index = 0;
            while (__tempnode != null) {
                int _comparator = data.compareTo(__tempnode.data);
                if (_comparator < 0) {
                    __tempnode = __tempnode._left;
                } else if (_comparator > 0) {
                    index += (__tempnode.count + __tempnode._leftside);
                    __tempnode = __tempnode._right;
                } else {
                    index += (__tempnode._leftside);
                    break;
                }
            }
            return index;
        }

        private Node<T> remove(Node<T> temp, T data, long count) {
            if (temp == null) return temp;
            int _comparator = data.compareTo(temp.data);
            if (_comparator < 0) temp._left = remove(temp._left, data, count);
            else if (_comparator > 0) temp._right = remove(temp._right, data, count);
            else {
                if (__multi && count < temp.count && temp.count > 1) {
                    __size -= count;
                    temp.count -= count;
                } else {
                    __size -= temp.count;
                    if (temp._left == null && temp._right == null) return null;
                    else if (temp._left == null) return temp._right;
                    else if (temp._right == null) return temp._left;
                    else {
                        __tempnode = minValue(temp._right);
                        temp.data = __tempnode.data;
                        temp.count = __tempnode.count;
                        temp._right = remove(temp._right, __tempnode.data, __tempnode.count);
                        __size += temp.count;
                    }
                }
            }
            // for __leftside and _rightside count
            if (temp._left != null)
                temp._leftside = temp._left._leftside + temp._left._rightside + temp._left.count;
            else temp._leftside = 0;
            if (temp._right != null)
                temp._rightside = temp._right._leftside + temp._right._rightside + temp._right.count;
            else temp._rightside = 0;

            temp._height = Math.max(getheight(temp._left), getheight(temp._right)) + 1;
            //Balancing

            long diff = getDiff(temp);
            if (diff > 1) {
                if (getDiff(temp._left) >= 0) {
                    temp = rightRotate(temp);
                } else {
                    temp._left = leftRotate(temp._left);
                    temp = rightRotate(temp);
                }
            } else if (diff < -1) {
                if (getDiff(temp._right) <= 0) {
                    temp = leftRotate(temp);
                } else {
                    temp._right = rightRotate(temp._right);
                    temp = leftRotate(temp);
                }
            }
            return temp;
        }

        public T get(long index) {
            __tempnode = __root;
            long current = 0;
            while (__tempnode != null) {
                if (__tempnode._left == null) {
                    if (__tempnode.count + current > index) return __tempnode.data;
                    else {
                        current += __tempnode.count;
                        __tempnode = __tempnode._right;
                    }
                } else {
                    if (current + __tempnode._leftside > index) __tempnode = __tempnode._left;
                    else if (current + __tempnode._leftside + __tempnode.count > index)
                        return __tempnode.data;
                    else {
                        current += __tempnode.count + __tempnode._leftside;
                        __tempnode = __tempnode._right;
                    }

                }
            }
            return null;
        }

        private Node<T> minValue(Node<T> temp) {
            __tempnode = temp;
            while (__tempnode._left != null) __tempnode = __tempnode._left;
            return __tempnode;
        }

        public void insert(T data, long... count) {
            if (count.length == 0) __root = insert(__root, data, 1);
            else if (count[0] > 0) __root = insert(__root, data, count[0]);

        }

        public void remove(T data, long... count) {
            if (count.length == 0) __root = remove(__root, data, 1);
            else if (count[0] > 0) __root = remove(__root, data, count[0]);

        }

        private Node<T> insert(Node<T> temp, T data, long count) {
            if (temp == null) {
                if (__multi) {
                    __size += count;
                    return new Node<>(data, count);
                } else {
                    __size++;
                    return new Node<>(data);
                }
            }
            int _comparator = data.compareTo(temp.data);
            if (_comparator < 0) temp._left = insert(temp._left, data, count);
            else if (_comparator > 0) temp._right = insert(temp._right, data, count);
            else if (__multi) {
                __size += count;
                temp.count += count;
            }


            // for __leftside and _rightside count
            if (temp._left != null)
                temp._leftside = temp._left._leftside + temp._left._rightside + temp._left.count;
            else temp._leftside = 0;
            if (temp._right != null)
                temp._rightside = temp._right._leftside + temp._right._rightside + temp._right.count;
            else temp._rightside = 0;

            temp._height = Math.max(getheight(temp._left), getheight(temp._right)) + 1;
            //Balancing

            long diff = getDiff(temp);
            if (diff > 1) {
                if (data.compareTo(temp._left.data) < 0) {
                    temp = rightRotate(temp);
                } else if (data.compareTo(temp._left.data) > 0) {
                    temp._left = leftRotate(temp._left);
                    temp = rightRotate(temp);
                }
            } else if (diff < -1) {
                if (data.compareTo(temp._right.data) > 0) {

                    temp = leftRotate(temp);
                } else if (data.compareTo(temp._right.data) < 0) {
                    temp._right = rightRotate(temp._right);
                    temp = leftRotate(temp);
                }
            }
            return temp;

        }

        private Node<T> rightRotate(Node<T> temp) {
            __tempnode = temp._left;
            __tempnode1 = __tempnode._right;

            __tempnode._right = temp;
            temp._left = __tempnode1;

            //height updation
            temp._height = Math.max(getheight(temp._left), getheight(temp._right)) + 1;
            __tempnode._height = Math.max(getheight(__tempnode._left), getheight(__tempnode._right)) + 1;
            //count updation

            if (temp._left != null)
                temp._leftside = temp._left._leftside + temp._left._rightside + temp._left.count;
            else temp._leftside = 0;
            if (temp._right != null)
                temp._rightside = temp._right._leftside + temp._right._rightside + temp._right.count;
            else temp._rightside = 0;

            if (__tempnode._left != null)
                __tempnode._leftside = __tempnode._left._leftside + __tempnode._left._rightside + __tempnode._left.count;
            else __tempnode._leftside = 0;
            if (__tempnode._right != null)
                __tempnode._rightside = __tempnode._right._leftside + __tempnode._right._rightside + __tempnode._right.count;
            else __tempnode._rightside = 0;


            return __tempnode;
        }

        private Node<T> leftRotate(Node<T> temp) {
            __tempnode = temp._right;
            __tempnode1 = __tempnode._left;

            __tempnode._left = temp;
            temp._right = __tempnode1;

            //height updation
            temp._height = Math.max(getheight(temp._left), getheight(temp._right)) + 1;
            __tempnode._height = Math.max(getheight(__tempnode._left), getheight(__tempnode._right)) + 1;
            //count updation

            if (temp._left != null)
                temp._leftside = temp._left._leftside + temp._left._rightside + temp._left.count;
            else temp._leftside = 0;
            if (temp._right != null)
                temp._rightside = temp._right._leftside + temp._right._rightside + temp._right.count;
            else temp._rightside = 0;


            if (__tempnode._left != null)
                __tempnode._leftside = __tempnode._left._leftside + __tempnode._left._rightside + __tempnode._left.count;
            else __tempnode._leftside = 0;
            if (__tempnode._right != null)
                __tempnode._rightside = __tempnode._right._leftside + __tempnode._right._rightside + __tempnode._right.count;
            else __tempnode._rightside = 0;

            return __tempnode;
        }

        private long getDiff(Node<T> temp) {
            if (temp == null) return 0;
            return getheight(temp._left) - getheight(temp._right);
        }

        public long getheight(Node<T> temp) {
            if (temp == null) return 0;
            return temp._height;
        }

        public long size() {
            return this.__size;
        }

        private class Node<T> {
            T data;
            Node<T> _left;
            Node<T> _right;
            long _leftside;
            long _rightside;
            long _height;
            long count;

            public Node(T data) {
                this.data = data;
                this._left = null;
                this._right = null;
                this._leftside = 0;
                this._rightside = 0;
                this._height = 1;
                this.count = 1;
            }

            public Node(T data, long count) {
                this.data = data;
                this._left = null;
                this._right = null;
                this._leftside = 0;
                this._rightside = 0;
                this._height = 1;
                this.count = count;
            }

        }

    }

    static class CodeHash {
        public static void shuffle(int[][] ar) {
            Random rd = new Random(new Random().nextInt());
            for (int i = 0; i < ar.length; i++) {
                int index = rd.nextInt(ar.length);
                int[] temp = ar[i];
                ar[i] = ar[index];
                ar[index] = temp;
            }
        }

    }
}