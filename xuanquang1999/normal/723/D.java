import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    static int dx[] = {-1, 0, 1, 0};
    static int dy[] = {0, 1, 0, -1};
    static int n, m, k, cellCnt;
    static StringBuilder[] sb;
    static boolean visited[][], onBoundary;

    static void DFS(int x, int y) {
        visited[x][y] = true;
        ++cellCnt;
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
            onBoundary = true;
        for (int dir = 0; dir < 4; ++dir) {
            int u = x + dx[dir], v = y + dy[dir];
            if (u >= 0 && u < n && v >= 0 && v < m && sb[u].charAt(v) == '.' && !visited[u][v])
                DFS(u, v);
        }
    }

    static void fill(int x, int y) {
        sb[x].setCharAt(y, '*');
        for (int dir = 0; dir < 4; ++dir) {
            int u = x + dx[dir], v = y + dy[dir];
            if (sb[u].charAt(v) == '.') fill(u, v);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);

        n = sc.nextInt();
        m = sc.nextInt();
        k = sc.nextInt();
        sb = new StringBuilder[n];
        for (int i = 0; i < n; ++i)
            sb[i] = new StringBuilder(sc.next());

        ArrayList<Lake> lakes = new ArrayList<>();

        visited = new boolean[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (sb[i].charAt(j) == '.' && !visited[i][j]) {
                    cellCnt = 0;
                    onBoundary = false;
                    DFS(i, j);
                    if (!onBoundary)
                        lakes.add(new Lake(cellCnt, i, j));
                }
            }
        }

        Collections.sort(lakes, Comparator.comparing(o -> o.compSz));

        int lakeCnt = lakes.size();
        cellCnt = 0;
        for(Lake lake: lakes) {
            if (lakeCnt == k)
                break;
            --lakeCnt;
            cellCnt += lake.compSz;
            fill(lake.x, lake.y);
        }

        pw.println(cellCnt);
        for(int i = 0; i < n; ++i)
            pw.println(sb[i].toString());
        pw.close();
    }

    static class Lake {
        int compSz, x, y;

        public Lake(int compSz, int x, int y) {
            this.compSz = compSz;
            this.x = x;
            this.y = y;
        }
    }
}