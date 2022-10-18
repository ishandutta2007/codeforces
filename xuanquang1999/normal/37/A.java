import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();

        Arrays.sort(a);

        int maxHeight = 1, cntTower = 1, curHeight = 1;
        for(int i = 1; i < n; ++i) {
            if (a[i] == a[i-1])
                ++curHeight;
            else {
                curHeight = 1;
                ++cntTower;
            }
            maxHeight = Math.max(maxHeight, curHeight);
        }

        System.out.printf("%d %d\n", maxHeight, cntTower);
    }
}