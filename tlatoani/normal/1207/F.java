import java.util.Scanner;

public class RemainderProblem3 {
    static final int SQRT = 708;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringBuilder builder = new StringBuilder();
        int[] array = new int[500001];
        int[][] sums = new int[SQRT][];
        for (int m = 1; m < SQRT; m++) {
            sums[m] = new int[m];
        }
        for (int q = in.nextInt(); q > 0; q--) {
            if (in.nextInt() == 1) {
                int x = in.nextInt();
                int y = in.nextInt();
                array[x] += y;
                for (int m = 1; m < SQRT; m++) {
                    sums[m][x % m] += y;
                }
            } else {
                int m = in.nextInt();
                int r = in.nextInt();
                if (m < SQRT) {
                    builder.append(sums[m][r]);
                    builder.append('\n');
                } else {
                    int res = 0;
                    for (int x = r; x <= 500000; x += m) {
                        res += array[x];
                    }
                    builder.append(res);
                    builder.append('\n');
                }
            }
        }
        System.out.print(builder);
    }
}