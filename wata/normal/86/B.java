import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class B {
    Scanner sc = new Scanner(System.in);
    
    int[] dx = {-1, 0, 0, 1}, dy = {0, -1, 1, 0};
    
    void run() {
        int n = sc.nextInt(), m = sc.nextInt();
        char[][] cs = new char[n][];
        for (int i = 0; i < n; i++) cs[i] = sc.next().toCharArray();
        int[] num = new int[n * m];
        fill(num, 1);
        int[][] to = new int[n][m];
        for (int i = 0; i < n; i++) fill(to[i], -1);
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (cs[i][j] == '.') to[i][j] = i * m + j;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) if (cs[i][j] == '.') {
                int x = -1;
                for (int d = 0; d < 4; d++) {
                    int i2 = i + dx[d], j2 = j + dy[d];
                    if (0 <= i2 && i2 < n && 0 <= j2 && j2 < m && cs[i2][j2] == '.') {
                        if (x < 0 || num[x] > num[to[i2][j2]]) {
                            x = to[i2][j2];
                        }
                    }
                }
                if (x < 0) {
                    System.out.println(-1);
                    return;
                }
                if (num[i * m + j] == 1) {
                    to[i][j] = x;
                    num[x]++;
                    if (num[x] >= 6) throw null;
                } else {
                    to[i][j] = i * m + j;
                }
            }
        }
        char[] id = new char[n * m];
        char[][] res = new char[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cs[i][j] == '.') {
                    int x = to[i][j];
                    if (id[x] > 0) res[i][j] = id[x];
                    else {
                        boolean[] used = new boolean[10];
                        for (int di = -4; di <= 4; di++) {
                            for (int dj = -4; dj <= 4; dj++) {
                                int i2 = i + di, j2 = j + dj;
                                if (0 <= i2 && i2 < n && 0 <= j2 && j2 < m && to[i2][j2] == x) {
                                    for (int d = 0; d < 4; d++) {
                                        int i3 = i2 + dx[d], j3 = j2 + dy[d];
                                        if (0 <= i3 && i3 < n && 0 <= j3 && j3 < m && to[i3][j3] >= 0 && id[to[i3][j3]] > 0) {
                                            used[id[to[i3][j3]] - '0'] = true;
                                        }
                                    }
                                }
                            }
                        }
                        for (int k = 0; k < 10; k++) if (!used[k]) {
                            id[x] = (char)('0' + k);
                            break;
                        }
                        if (id[x] == 0) throw null;
                        res[i][j] = id[x];
                    }
                } else {
                    res[i][j] = '#';
                }
            }
        }
        for (int i = 0; i < n; i++) System.out.println(res[i]);
    }
    
    void debug(Object...os) {
        System.err.println(deepToString(os));
    }
    
    public static void main(String[] args) {
        new B().run();
    }
}