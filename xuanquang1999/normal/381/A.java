import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int a[] = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();

        int l = 0, r = n-1, turn = 0;
        int score[] = new int[2];
        while (l <= r) {
            if (a[l] < a[r]) {
                score[turn] += a[r];
                --r;
            } else {
                score[turn] += a[l];
                ++l;
            }
            turn = 1-turn;
        }

        System.out.printf("%d %d\n", score[0], score[1]);
    }
}