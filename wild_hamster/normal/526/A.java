import java.util.*;
import java.math.*;
public class azaza {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        int i,j;
        int flag = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 1; j < n; j++)
                if (i + 4*j < n)
            if (s.charAt(i) == '*' &&s.charAt(i+j) == '*' &&
                    s.charAt(i+2*j) == '*' &&s.charAt(i+3*j) == '*' &&
                    s.charAt(i+4*j) == '*')
                flag = 1;
        }
        if (flag == 1)
        System.out.println("yes");
        else
            System.out.println("no");

    }

}