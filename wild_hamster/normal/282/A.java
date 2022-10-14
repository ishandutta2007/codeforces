import java.util.*;
import java.math.*;
public class azaza {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s;
        int i;
        int ans = 0;
        for (i = 0; i < n; i++)
        {
            s = sc.next();
            if (s.charAt(1) == '+')
                ans++;
            else
                ans--;
        }
        System.out.println(ans);

    }

}