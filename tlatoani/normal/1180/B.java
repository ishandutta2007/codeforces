import java.util.Scanner;

public class NickAndArray {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] elems = new int[n];
        int max = Integer.MIN_VALUE;
        int maxIx = -1;
        for (int i = 0; i < n; i++) {
            elems[i] = scanner.nextInt();
            if (elems[i] < 0) {
                elems[i] = -elems[i] - 1;
            }
            if (elems[i] > max) {
                max = elems[i];
                maxIx = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i == maxIx && n % 2 == 1) {
                System.out.print(elems[i]);
            } else {
                System.out.print(-elems[i] - 1);
            }
            if (i == n - 1) {
                System.out.println();
            } else {
                System.out.print(" ");
            }
        }
    }
}