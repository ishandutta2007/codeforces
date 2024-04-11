import java.util.Scanner;

public class ChooseTwoNumbers {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        for (int i = 0; i < 2; i++) {
            int a = 0;
            for (int n = in.nextInt(); n > 0; n--) {
                a = Math.max(a, in.nextInt());
            }
            System.out.print(a);
            if (i == 0) {
                System.out.print(" ");
            } else {
                System.out.println();
            }
        }
    }
}