import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            int max = Integer.MAX_VALUE;
            boolean flag = false;
            int[] arr = new int[n];
            for (int j = 0; j < n; j++) {
                arr[j] = scanner.nextInt();
            }
            for (int j = 0; j < n; j++) {
                int k = arr[j];
                if (max <= k) {
                    //System.out.printf("%d %d\n", max, k);
                    flag = true;
                    break;
                } else {
                    //System.out.printf("%d %d\n", max, k);
                    max = k;
                }
            }
            if (flag) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}