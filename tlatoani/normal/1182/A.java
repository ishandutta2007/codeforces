import java.util.Scanner;

public class FillingShapes {

    public static void main(String[] args) {
        long n = new Scanner(System.in).nextLong();
        if (n % 2 == 0) {
            System.out.println(1L << (n / 2));
        } else {
            System.out.println(0);
        }
    }
}