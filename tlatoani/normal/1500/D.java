import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class TilesForBathroomLessMemory3Java8 {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int q = Integer.parseInt(tokenizer.nextToken());
        int[][] grid = new int[n + 1][n + 1];
        for (int y = 1; y <= n; y++) {
            tokenizer = new StringTokenizer(in.readLine());
            for (int x = 1; x <= n; x++) {
                grid[y][x] = Integer.parseInt(tokenizer.nextToken());
            }
        }
        int[][][] fromLeft = new int[n + 1][n + 1][q + 1];
        for (int y = 1; y <= n; y++) {
            for (int x = 1; x <= n; x++) {
                fromLeft[y][x][0] = x;
                int j = 1;
                for (int xp : fromLeft[y][x - 1]) {
                    if (grid[y][xp] != grid[y][x] && j <= q) {
                        fromLeft[y][x][j++] = xp;
                    }
                }
            }
        }
        int[][][] fromAbove = new int[n + 1][n + 1][q + 1];
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                fromAbove[y][x][0] = y;
                int j = 1;
                for (int yp : fromAbove[y - 1][x]) {
                    if (grid[yp][x] != grid[y][x] && j <= q) {
                        fromAbove[y][x][j++] = yp;
                    }
                }
            }
        }
        int[] answer = new int[n + 1];
        int[] lastSeen = new int[(n * n) + 1];
        int[] toClear = new int[2 * (q + 1) * (n + 1)];
        for (int d = -(n - 1); d <= n - 1; d++) {
            int[] amts = new int[n + 1];
            int currAMT = 0;
            int size = 0;
            int x2 = Math.max(1, 1 - d) - 1;
            for (int x1 = Math.max(1, 1 - d); x1 <= Math.min(n, n - d); x1++) {
                while (x2 <= Math.min(n, n - d) && currAMT <= q) {
                    x2++;
                    if (x2 > Math.min(n, n - d)) {
                        break;
                    }
                    for (int xp : fromLeft[x2 + d][x2]) {
                        if (xp != 0 && xp >= x1) {
                            int elem = grid[x2 + d][xp];
                            toClear[size++] = elem;
                            if (lastSeen[elem] > xp) {
                                continue;
                            } else if (lastSeen[elem] >= x1) {
                                amts[lastSeen[elem]]--;
                                currAMT--;
                            }
                            amts[xp]++;
                            currAMT++;
                            lastSeen[elem] = xp;
                        }
                    }
                    for (int yp : fromAbove[x2 + d][x2]) {
                        if (yp != 0 && yp - d >= x1) {
                            int elem = grid[yp][x2];
                            toClear[size++] = elem;
                            if (lastSeen[elem] > yp - d) {
                                continue;
                            } else if (lastSeen[elem] >= x1) {
                                amts[lastSeen[elem]]--;
                                currAMT--;
                            }
                            amts[yp - d]++;
                            currAMT++;
                            lastSeen[elem] = yp - d;
                        }
                    }
                }
                answer[x2 - x1]++;
                currAMT -= amts[x1];
            }
            for (int j = 0; j < size; j++) {
                lastSeen[toClear[j]] = 0;
            }
        }
        for (int s = n; s >= 1; s--) {
            answer[s - 1] += answer[s];
        }
        StringJoiner joiner = new StringJoiner(" ");
        for (int s = 1; s <= n; s++) {
            joiner.add("" + answer[s]);
        }
        System.out.println(joiner);
    }
}