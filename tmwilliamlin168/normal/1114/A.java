import java.util.*;

public class A {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int x = scan.nextInt();
        int y = scan.nextInt();
        int z = scan.nextInt();
        int a = scan.nextInt();
        int b = scan.nextInt();
        int c = scan.nextInt();
        scan.close();

        if (x > a || y > ((a+b)-x) || z > ((a+b+c)-(x+y))) {
            System.out.println("No");
        }
        else System.out.println("Yes");
    }
}