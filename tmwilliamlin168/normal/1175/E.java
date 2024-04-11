import java.util.*;
import java.io.*;
import static java.lang.Math.*;
public class Main {
    static final long MOD = 1_000_000_007, INF = 1_000_000_000_000_000_000L;
    static final int INf = 1_000_000_000;
    static FastReader reader;
    static PrintWriter writer;
    public static void main(String[] args) {
        Thread t = new Thread(null, new O(), "Integer.MAX_VALUE", 100000000);
        t.start();
    }
    static class O implements Runnable {
        public void run() {
            try {
                magic();
            }
            catch (Exception e) {
                e.printStackTrace();
                System.exit(1);
            }
        }
    }
    static class FastReader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public FastReader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public FastReader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[1000000];
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ') c = read();
            boolean neg = (c == '-');
            if (neg) c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg) return -ret;
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ') c = read();
            boolean neg = (c == '-');
            if (neg) c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg) return -ret;
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ') c = read();
            boolean neg = (c == '-');
            if (neg) c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (c == '.') while ((c = read()) >= '0' && c <= '9') ret += (c - '0') / (div *= 10);
            if (neg) return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1) buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead) fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null) return;
            din.close();
        }
    }
    static int next[][];
    static void magic() throws IOException {
        reader = new FastReader();
        writer = new PrintWriter(System.out, true);
        int n = reader.nextInt(), q = reader.nextInt();
        next = new int[500001][20];
        int max_r_starting_at[] = new int[500001];
        int i,j,k,x;
        for(i=0;i<n;++i) {
            j = reader.nextInt();
            max_r_starting_at[j] = max(max_r_starting_at[j], reader.nextInt());
        }
        int max = 0;
        for(i=0;i<=500000;++i) {
            max = max(max, max_r_starting_at[i]);
            next[i][0] = max;
        }
        for(i=1;i<20;++i) {
            for(j=0;j<=500000;++j) {
                next[j][i] = next[next[j][i-1]][i-1];
            }
        }
        int low,high,mid,ans,y,fuck,from;
        StringBuilder fast = new StringBuilder();
        while(q-->0) {
            x = reader.nextInt();
            y = reader.nextInt();
            ans = -1;
            low = 1; high = n;
            while(low<=high) {
                mid = (low+high)>>1;
                from = x;
                for(fuck=0;fuck<20;++fuck) {
                    if((mid&(1<<fuck))!=0) {
                        from = next[from][fuck];
                    }
                }
                if(from>=y) {
                    ans = mid;
                    high = --mid;
                }
                else low = ++mid;
            }
            fast.append(ans);
            fast.append("\n");
        }
        writer.println(fast);
    }
}