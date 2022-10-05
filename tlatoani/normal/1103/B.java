import java.util.Scanner;

public class GameWithModulo {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.nextLine().equals("start")) {
            System.out.println("? 0 1");
            if (in.nextLine().equals("x")) {
                System.out.println("! 1");
                continue;
            }
            int lower;
            int upper;
            for (int b = 1;; b <<= 1) {
                System.out.println("? " + b + " " + (b << 1));
                if (in.nextLine().equals("x")) {
                    lower = b + 1;
                    upper = b << 1;
                    break;
                }
            }
            while (lower < upper) {
                int mid = (lower + upper) >> 1;
                System.out.println("? " + (lower - 1) + " " + mid);
                if (in.nextLine().equals("x")) {
                    upper = mid;
                } else {
                    lower = mid + 1;
                }
            }
            System.out.println("! " + upper);
        }
    }
}