import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class VasyaAndArray {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] facts = new int[m][3];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 3; j++) {
                facts[i][j] = in.nextInt();
            }
        }
        int[] array = new int[n + 1];
        array[0] = 0;
        for (int i = 1; i <= n; i++) {
            boolean mustBeSorted = false;
            for (int[] fact : facts) {
                if (fact[0] == 1 && fact[1] <= i - 1 && fact[2] >= i) {
                    mustBeSorted = true;
                    break;
                }
            }
            if (mustBeSorted) {
                array[i] = array[i - 1];
            } else {
                array[i] = array[i - 1] - 1;
            }
        }
        boolean valid = true;
        for (int[] fact : facts) {
            if (fact[0] == 0) {
                boolean isSorted = true;
                for (int i = fact[1] + 1; i <= fact[2]; i++) {
                    if (array[i] < array[i - 1]) {
                        isSorted = false;
                        break;
                    }
                }
                if (isSorted) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            out.println("YES");
            for (int i = 1; i < n; i++) {
                array[i] += 1 - array[n];
                out.print(array[i] + " ");
            }
            array[n] += 1 - array[n];
            out.println(array[n]);
        } else {
            out.println("NO");
        }
        out.flush();
    }
}