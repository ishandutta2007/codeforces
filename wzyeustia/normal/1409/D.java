

import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int j = 0; j < t; j++) {
            long n = scanner.nextLong();
            long s = scanner.nextLong();

            long num = n;
            int count = 0;
            long sum = 0;
            long[] digit = new long[20];
            while (num > 0) {
                digit[count++] = num % 10;
                sum += digit[count - 1];
                num /= 10;
            }
            int countReserve = count;
            count = 0;
            while (sum > s) {
                sum -= digit[count] - 1;
                digit[count] = 0;
                digit[++count]++;
                while (digit[count] == 10) {
                    digit[count] = 0;
                    digit[++count]++;
                    sum -= 9;
                }
                //System.out.println(Arrays.toString(digit));
            }

            long result = 0;
            for (int i = countReserve; i >= 0; i--) {
                result = result * 10 + digit[i];
            }
            //System.out.println(Arrays.toString(digit));
            System.out.println(result - n);

        }
    }
}