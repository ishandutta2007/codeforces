import java.util.*;
public class azaza {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextInt(), m = sc.nextInt(), a = sc.nextInt();
        System.out.println(((n+a-1)/a)*((m+a-1)/a));

    }

}