import java.io.*;
import java.util.*;

public class F {

    FastScanner in;
    PrintWriter out;

    List<Integer> op1, op2;

    void swap(int x, int y) {
        if (x == y) {
            return;
        }
        addOp(x, y);
        addOp(y, x);
        addOp(x, y);
    }

    void addOp(int x, int y) {
        op1.add(x);
        op2.add(y);
    }

    int[][] solve(int[] x, int[] y) {
        int[] initX = x;
        int[] initY = y;
        x = x.clone();
        y = y.clone();

        List<Integer> ans1 = new ArrayList<>();
        List<Integer> ans2 = new ArrayList<>();
        op1 = ans1;
        op2 = ans2;
        go(x);
        
        op1 = new ArrayList<>();
        op2 = new ArrayList<>();
        go(y);
        
        List<Integer> tmp1 = op1, tmp2 = op2;
        op1 = ans1;
        op2 = ans2;

        int size1 = 0, size2 = 0;
        while (size1 < x.length && x[size1] != 0){
            size1++;
        }
        while (size2 < y.length && y[size2] != 0) {
            size2++;
        }
        
        if (size2 > size1) {
            return null;
        }
        
        for (int i = 0; i < size2; i++) {
            for (int j = i; j < size1; j++) {
                int cur1 = x[i], cur2 = x[i] ^ x[j];
                cur1 ^= y[i];
                cur2 ^= y[i];
                
                if (cur1 < cur2) {
                    continue;
                } else {
                    addOp(i, j);
                    x[i] ^= x[j];
                }
            }
            if (x[i] != y[i]) {
                return null;
            }
        }

        for (int i = size2; i < size1; i++) {
            addOp(i, i);
            x[i] = 0;
        }
        
        
        Collections.reverse(tmp1);
        Collections.reverse(tmp2);

        ans1.addAll(tmp1);
        ans2.addAll(tmp2);

        int[][] ret = new int[2][ans1.size()];
        for (int i = 0; i < ans1.size(); i++) {
            ret[0][i] = ans1.get(i);
            ret[1][i] = ans2.get(i);
        }
        if (!check(ret, initX, initY)) {
            throw new AssertionError();
        }
        return ret;
    }
    
    boolean check(int[][] ret, int[] x, int[] y) {
        x = x.clone();
        for (int i = 0; i < ret[0].length; i++) {
            int i1 = ret[0][i], i2 = ret[1][i];
            x[i1] ^= x[i2];
        }
        return Arrays.equals(x, y);
    }

    private void go(int[] x) {
        int last = 0;
        for (int col = 30; col >= 0; col--) {
            int row = -1;
            for (int j = last; j < x.length; j++) {
                if ((x[j] & (1 << col)) != 0) {
                    row = j;
                    break;
                }
            }
            if (row == -1) {
                continue;
            }

            swap(last, row);
            {
                int tmp = x[last];
                x[last] = x[row];
                x[row] = tmp;
            }

            for (int i = 0; i < x.length; i++) {
                if (i == last) {
                    continue;
                }
                if ((x[i] & (1 << col)) != 0) {
                    addOp(i, last);
                    x[i] ^= x[last];
                }
            }

            last++;
        }
    }

    void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        int n = in.nextInt();
        int[] x = new int[n], y = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            y[i] = in.nextInt();
        }

        int[][] ans = solve(x, y);
        if (ans == null) {
            out.println(-1);
        } else {
            out.println(ans[0].length);
            for (int i = 0; i < ans[0].length; i++) {
                out.println((ans[0][i] + 1) + " " + (ans[1][i] + 1));
            }
        }
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
        new F().run();
    }
}