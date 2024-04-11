import java.io.*;
import java.util.*;

public class B {

    MyScanner in;
    PrintWriter out;
    final static String filename = "";

    class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner(String file) {
            try {
                br = new BufferedReader(new FileReader(file));
                st = new StringTokenizer("");
            } catch (FileNotFoundException e) {
                e.printStackTrace();
                System.exit(1);
            }
        }

        public MyScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
            st = new StringTokenizer("");
        }

        String nextToken() {
            try {
                while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(br.readLine());

            } catch (IOException e) {
                e.printStackTrace();
                System.exit(1);
            }

            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(this.nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(this.nextToken());
        }

        long nextLong() {
            return Long.parseLong(this.nextToken());
        }

        void close() throws IOException {
            br.close();
        }
    }

    int[] a;
    int n, k, m;
    boolean[][][] used;
    int[] dx = {0, 0, 0, 0, 1, -1};
    int[] dy = {0, 0, 1, -1, 0, 0};
    int[] dz = {1, -1, 0, 0, 0, 0};
    char[][][] c;
    
    boolean check(int x, int y, int z) {
        return (x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < k && !used[x][y][z] && c[x][y][z] != '#');
    }
    
    int dfs(int x, int y, int z) {
        int ans = 1;
        used[x][y][z] = true;
        for (int s = 0; s < 6; s++) 
            if (check(x + dx[s], y + dy[s], z + dz[s]))
                ans += dfs(x + dx[s], y + dy[s], z + dz[s]);
        
        return ans;
    }

    void solve() throws IOException {
        k = in.nextInt();
        n = in.nextInt();
        m = in.nextInt();
        c = new char[n][m][k];
        used = new boolean[n][m][k];
        for (int t = 0; t < k; t++) {
            for (int i = 0; i < n; i++) {
                String st = in.nextToken();
                for (int j = 0; j < m; j++) {
                    c[i][j][t] = st.charAt(j);
                }
            }
        }
        
        int x = in.nextInt() - 1;
        int y = in.nextInt() - 1;
        if (c[x][y][0] == '#')
            out.println(0);
        else
            out.println(dfs(x, y, 0));
    }

    void run() {
        try {
            in = new MyScanner(System.in);
            out = new PrintWriter(System.out);

            solve();

            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }

    }

    public static void main(String[] args) {
        new B().run();
    }

}