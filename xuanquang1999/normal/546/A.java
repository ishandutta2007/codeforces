import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int k = in.nextInt(), n = in.nextInt(), w = in.nextInt();
        System.out.println(Math.max(0, w * (w + 1) / 2 * k - n));
    }
}