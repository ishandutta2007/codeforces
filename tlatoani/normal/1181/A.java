import java.util.Scanner;

public class ChungaChanga {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long x = scanner.nextLong();
        long y = scanner.nextLong();
        long z = scanner.nextLong();
        System.out.print((x + y) / z);
        System.out.print(" ");
        if ((x % z) + (y % z) == (x + y) % z) {
            System.out.println(0);
        } else {
            System.out.println(Math.min(z - (x % z), z - (y % z)));
        }
    }
}