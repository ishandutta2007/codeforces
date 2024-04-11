import java.util.Scanner;

public class TreeDiameter {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int c = 0; c < t; c++) {
            int n = scanner.nextInt();
            long answer = 0;
            for (int b = 0; b < 9; b++) {
                int amt1 = 0;
                for (int i = 1; i <= n; i++) {
                    if (((i >> b) & 1) == 0) {
                        amt1++;
                    }
                }
                if (amt1 == 0 || amt1 == n) {
                    continue;
                }
                System.out.print(amt1 + " " + (n - amt1));
                for (int i = 1; i <= n; i++) {
                    if (((i >> b) & 1) == 0) {
                        System.out.print(" " + i);
                    }
                }
                for (int i = 1; i <= n; i++) {
                    if (((i >> b) & 1) != 0) {
                        System.out.print(" " + i);
                    }
                }
                System.out.println();
                System.out.flush();
                long res = scanner.nextLong();
                if (res == -1) {
                    return;
                }
                answer = Math.max(answer, res);
            }
            System.out.println("-1 " + answer);
        }
    }
}