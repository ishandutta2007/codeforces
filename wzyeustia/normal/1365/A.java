import java.io.InputStreamReader;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();

            boolean[] rows = new boolean[n];
            boolean[] columns = new boolean[m];

            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    int num = scanner.nextInt();
                    if (num == 1) {
                        rows[j] = true;
                        columns[k] = true;
                    }
                }
            }

            int numRows = 0;
            for (int j = 0; j < n; j++) {
                if (!rows[j])
                    numRows++;
            }

            int numCols = 0;
            for (int k = 0; k < m; k++) {
                if (!columns[k])
                    numCols++;
            }

            int decide = Math.min(numCols, numRows);

            if (decide % 2 == 1) {
                System.out.println("Ashish");
            } else {
                System.out.println("Vivek");
            }

        }

    }
}