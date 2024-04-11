import java.util.*;
import java.math.*;
public class azaza {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        int a[] = new int[100500];
        int i;
        for (i = 0; i < n; i++)
            a[i] = sc.nextInt();
        for (i = 0; i < n; i++)
            if (a[i] < a[m-1] || a[i] == 0)
                break;
        System.out.println(i);

    }

}