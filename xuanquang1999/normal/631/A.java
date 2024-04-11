import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a[] = new int[n];
        int b[] = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = in.nextInt();
        for(int i = 0; i < n; ++i)
            b[i] = in.nextInt();

        int orA = 0, orB = 0;
        for(int i = 0; i < n; ++i) {
            orA |= a[i];
            orB |= b[i];
        }

        int ans = orA + orB;
        System.out.println(ans);
    }
}