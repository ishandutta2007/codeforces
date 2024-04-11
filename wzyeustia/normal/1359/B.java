import java.io.InputStreamReader;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int x = scanner.nextInt();
            int y = scanner.nextInt();

            boolean better = y < x * 2;
            scanner.nextLine();
            int sumOfCost = 0;

            for (int j = 0; j < n; j++) {
                int cost = 0;
                String str = scanner.nextLine();

                int counter = 0;
                for (int k = 0; k < m; k++) {
                    if (str.charAt(k) == '.') {
                        counter++;
                    } else {
                        if (better) {
                            cost += y * (counter / 2) + x * (counter % 2);
                        } else {
                            cost += x * counter;
                        }
                        counter = 0;
                    }
                }

                if (counter > 0) {
                    if (better) {
                        cost += y * (counter / 2) + x * (counter % 2);
                    } else {
                        cost += x * counter;
                    }
                }
                sumOfCost += cost;
            }
            System.out.println(sumOfCost);
        }
    }
}