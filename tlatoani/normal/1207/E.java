import java.util.Scanner;

public class XORGuessing {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("?");
        for (int i = 1; i <= 100; i++) {
            System.out.print(" " + i);
        }
        System.out.println();
        int answer = in.nextInt();
        answer -= answer & 127;
        System.out.print("?");
        for (int i = 1; i <= 100; i++) {
            System.out.print(" " + (i << 7));
        }
        System.out.println();
        answer += in.nextInt() & 127;
        System.out.println("! " + answer);
    }
}