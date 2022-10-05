import java.util.Arrays;
import java.util.Scanner;

public class Ropewalkers {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long[] poses = new long[3];
        for (int i = 0; i < 3; i++) {
            poses[i] = scanner.nextLong();
        }
        Arrays.sort(poses);
        long d = scanner.nextLong();
        long answer = Math.max(d - (poses[1] - poses[0]), 0) + Math.max(d - (poses[2] - poses[1]), 0);
        System.out.println(answer);
    }
}