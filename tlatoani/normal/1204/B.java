import java.util.Scanner;

public class MisloveHasLostAnArray {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int l = in.nextInt();
        int r = in.nextInt();
        System.out.print((1 << l) - 1 + n - l);
        System.out.print(' ');
        System.out.println((1 << r) - 1 + ((n - r) * (1 << (r - 1))));
    }
}