
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int k = scanner.nextInt();
            int num = ((k % 10) - 1) * 10;
            int count = 0;
            int sum = 0;
            while (k > 0) {
                k /= 10;
                count++;
                sum += count;
            }

            System.out.println(sum + num);
        }
    }
}