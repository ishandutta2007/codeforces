import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), a = sc.nextInt(), b = sc.nextInt();
        int x[] = new int[n];
        for(int i = 0; i < n; ++i)
            x[i] = sc.nextInt();

        Arrays.sort(x);
        System.out.println(x[b]-x[b-1]);
    }
}