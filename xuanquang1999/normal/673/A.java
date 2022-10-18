import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> a = new ArrayList<>();
        a.add(0);
        for(int i = 0; i < n; ++i)
            a.add(sc.nextInt());

        int ans = 0;
        for(int i = 0; i <= n; ++i) {
            ans = a.get(i)+15;
            if (i == n || a.get(i)+15 < a.get(i+1)) break;
        }

        System.out.println(Math.min(ans, 90));
    }
}