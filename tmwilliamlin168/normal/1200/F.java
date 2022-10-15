import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Set;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;
 
/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class TaskF {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] m = new int[n];
            int[] k = new int[n];
            int L = 2520;
            for (int i = 0; i < n; i++) {
                k[i] = in.nextInt();
                k[i] = (k[i] % L + L) % L;
            }
            int N = n * L;
            int[] nxt = new int[N];
            int[] num = new int[N];
            for (int i = 0; i < n; i++) {
                m[i] = in.nextInt();
                int[] adj = new int[m[i]];
                for (int j = 0; j < m[i]; j++) {
                    adj[j] = in.nextInt() - 1;
                }
 
                for (int p = 0; p < L; p++) {
                    int node = adj[(p + k[i]) % m[i]];
                    nxt[i * L + p] = node * L + (p + k[i]) % L;
                }
            }
 
            int[] vis = new int[N];
            int[] ind = new int[N];
            int c = 0;
            for (int i = 0; i < N; i++) {
                c++;
                if (vis[i] == 0) {
                    ArrayList<Integer> lst = new ArrayList<>();
                    Set<Integer> st = new HashSet<>();
                    int curr = i;
                    int pos = 0;
                    while (vis[curr] == 0) {
                        ind[curr] = pos++;
                        lst.add(curr);
                        vis[curr] = c;
                        curr = nxt[curr];
                    }
                    if (vis[curr] < c) {
                        for (int node : lst) num[node] = num[curr];
                    } else {
                        for (int p = ind[curr]; p < lst.size(); p++) st.add(lst.get(p) / L);
//                    System.out.println(i + " " + st.size());
                        for (int node : lst) num[node] = st.size();
                    }
                }
            }
 
            int q = in.nextInt();
            for (int j = 0; j < q; j++) {
                int x = in.nextInt() - 1;
                int y = (in.nextInt() % L + L) % L;
                out.println(num[x * L + y]);
            }
        }
 
    }
 
    static class OutputWriter {
        private final PrintWriter writer;
 
        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }
 
        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }
 
        public void println(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
            writer.print('\n');
        }
 
        public void close() {
            writer.close();
        }
 
    }
 
    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;
 
        public InputReader(InputStream stream) {
            this.stream = stream;
        }
 
        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }
 
        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }
 
        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
 
        }
 
    }
}