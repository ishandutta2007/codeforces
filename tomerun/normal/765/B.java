import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        char[] S = sc.next().toCharArray();
        char max = 'a' - 1;
        for (char c : S) {
            if (c > max + 1) {
                System.out.println("NO");
                return;
            }
            max = (char)Math.max(max, c);
        }
        System.out.println("YES");
    }

}