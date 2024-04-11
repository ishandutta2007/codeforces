
 import java.util.*;
public class MyClass {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        for(int n = scan.nextInt() ; n > 0; n--){
            long k = scan.nextLong() - 1, x = scan.nextInt() , ans = 9 * k + x;
            System.out.println(ans);
        }
    }
}