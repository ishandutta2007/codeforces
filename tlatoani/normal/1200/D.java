import java.util.Scanner;

public class WhiteLines2 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        in.nextLine();
        int[] lx = new int[n];
        int[] rx = new int[n];
        boolean[] rowHasBlack = new boolean[n];
        int[] ly = new int[n];
        int[] ry = new int[n];
        boolean[] columnHasBlack = new boolean[n];
        for (int x = 0; x < n; x++) {
            ly[x] = 0;
            ry[x] = n - 1;
        }
        for (int y = 0; y < n; y++) {
            lx[y] = 0;
            rx[y] = n - 1;
            String line = in.nextLine();
            for (int x = 0; x < n; x++) {
                if (line.charAt(x) == 'B') {
                    rowHasBlack[y] = true;
                    columnHasBlack[x] = true;
                    lx[y] = Math.max(lx[y], x - k + 1);
                    rx[y] = Math.min(rx[y], x);
                    ly[x] = Math.max(ly[x], y - k + 1);
                    ry[x] = Math.min(ry[x], y);
                }
            }
        }
        int initial = 0;
        for (int i = 0; i < n; i++) {
            if (!rowHasBlack[i]) {
                initial++;
            }
            if (!columnHasBlack[i]) {
                initial++;
            }
            //System.out.println("lx[" + i + "] = " + lx[i] + ", rx[" + i + "] = " + rx[i] + ", ly[" + i + "] = " + ly[i] + ", ry[" + i + "] = " + ry[i]);
        }
        int answer = initial;
        //System.out.println("initial" + initial);
        for (int y = 0; y <= n - k; y++) {
            int curr = initial;
            for (int x = 0; x < k; x++) {
                if (columnHasBlack[x] && ly[x] <= y && y <= ry[x]) {
                    curr++;
                }
            }
            int[] diffs = new int[n + 1];
            for (int yp = y; yp < y + k; yp++) {
                if (rowHasBlack[yp] && lx[yp] <= rx[yp]) {
                    diffs[lx[yp]]++;
                    diffs[rx[yp] + 1]--;
                }
            }
            curr += diffs[0];
            //System.out.println("y = " + y + ", x = 0, curr = " + curr);
            answer = Math.max(answer, curr);
            for (int x = 1; x <= n - k; x++) {
                curr += diffs[x];
                if (columnHasBlack[x - 1] && ly[x - 1] <= y && y <= ry[x - 1]) {
                    curr--;
                }
                if (columnHasBlack[x + k - 1] && ly[x + k - 1] <= y && y <= ry[x + k - 1]) {
                    curr++;
                }
                //System.out.println("y = " + y + ", x = " + x + ", curr = " + curr);
                answer = Math.max(answer, curr);
            }
        }
        System.out.println(answer);
    }
}