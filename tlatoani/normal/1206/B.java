import java.util.Scanner;

public class MakeProductOne {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        long answer = 0;
        int sign = 1;
        for (int i = 0; i < n; i++) {
            long k = in.nextLong();
            answer += Math.abs(Math.abs(k) - 1);
            sign *= Math.signum(k);
        }
        if (sign == -1) {
            answer += 2L;
        }
        System.out.println(answer);
    }
}