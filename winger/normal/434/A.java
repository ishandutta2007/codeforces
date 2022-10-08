import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author winger
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[m];
        for (int i = 0; i < m; ++i) {
            a[i] = in.nextInt() - 1;
        }
        ArrayList<Integer>[] ns = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            ns[i] = new ArrayList<Integer>();
        }
        long ans0 = 0;
        for (int i = 0; i < m; ++i) {
            if (i + 1 < m) {
                ans0 += Math.abs(a[i] - a[i + 1]);
                if (a[i] != a[i + 1]) {
                    ns[a[i]].add(a[i + 1]);
                }
            }
            if (i - 1 >= 0) {
                if (a[i] != a[i - 1]) {
                    ns[a[i]].add(a[i - 1]);
                }
            }
        }
        long ans = ans0;
        for (int i = 0; i < n; ++i) {
            if (ns[i].size() > 0) {
                Collections.sort(ns[i]);
                long v = ns[i].get(ns[i].size() / 2);
                long add = 0;
                for (int v1 : ns[i]) {
                    add += Math.abs(v - v1) - Math.abs(i - v1);
                }
                ans = Math.min(ans, ans0 + add);
            }
        }
        out.println(ans);
    }
}

class FastScanner {
        Reader in;
        StringBuilder sb = new StringBuilder();

        public FastScanner(InputStream in) {
            this.in = new InputStreamReader(in);
        }

        public FastScanner(String s) {
            this.in = new BufferedReader(new StringReader(s));
        }

        public String next() {
            try {
                sb.setLength(0);
                while (true) {
                    int c = in.read();
                    if (c == -1) {
                        return null;
                    }
                    if (" \n\r\t".indexOf(c) == -1) {
                        sb.append((char) c);
                        break;
                    }
                }
                while (true) {
                    int c = in.read();
                    if (c == -1 || " \n\r\t".indexOf(c) != -1) {
                        break;
                    }
                    sb.append((char) c);
                }
                return sb.toString();
            } catch (IOException e) {
                throw new AssertionError(e);
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

}