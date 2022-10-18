import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        int p = sc.nextInt(), k = sc.nextInt();;

        int a[] = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();
        int b[] = new int[m];
        for(int i = 0; i < m; ++i)
            b[i] = sc.nextInt();

        System.out.println((a[p-1] < b[m-k]) ? "YES" : "NO");
    }
}