import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class A {
    Scanner sc = new Scanner(System.in);
    
    void run() {
        int n = sc.nextInt();
        if (n == 1) {
            System.out.println("a");
            System.out.println("a");
            System.out.println("b");
            System.out.println("b");
        } else if (n % 2 == 0) {
            char[][] cs = new char[4][n];
            cs[0][0] = cs[0][1] = 'a';
            cs[1][0] = cs[2][0] = 'b';
            cs[3][0] = cs[3][1] = 'c';
            for (int i = 0; i < n / 2 - 1; i++) {
                cs[0][i * 2 + 2] = cs[0][i * 2 + 3] = (char)('a' + (3 + i * 4) % 26);
                cs[1][i * 2 + 1] = cs[1][i * 2 + 2] = (char)('a' + (3 + i * 4 + 1) % 26);
                cs[2][i * 2 + 1] = cs[2][i * 2 + 2] = (char)('a' + (3 + i * 4 + 2) % 26);
                cs[3][i * 2 + 2] = cs[3][i * 2 + 3] = (char)('a' + (3 + i * 4 + 3) % 26);
            }
            cs[1][n - 1] = cs[2][n - 1] = (char)('a' + (n * 2 - 1) % 26);
            for (int i = 0; i < 4; i++) {
                System.out.println(new String(cs[i]));
            }
        } else {
            char[][] cs = new char[4][n];
            cs[0][0] = cs[1][0] = 'a';
            for (int i = 0; i < n / 2; i++) {
                cs[0][i * 2 + 1] = cs[0][i * 2 + 2] = (char)('a' + (1 + i * 4) % 26);
                cs[1][i * 2 + 1] = cs[1][i * 2 + 2] = (char)('a' + (1 + i * 4 + 1) % 26);
                cs[2][i * 2] = cs[2][i * 2 + 1] = (char)('a' + (1 + i * 4 + 2) % 26);
                cs[3][i * 2] = cs[3][i * 2 + 1] = (char)('a' + (1 + i * 4 + 3) % 26);
            }
            cs[2][n - 1] = cs[3][n - 1] = (char)('a' + (n * 2 - 1) % 26);
            for (int i = 0; i < 4; i++) {
                System.out.println(new String(cs[i]));
            }
        }
    }
    
    void debug(Object...os) {
        System.err.println(deepToString(os));
    }
    
    public static void main(String[] args) {
        new A().run();
    }
}