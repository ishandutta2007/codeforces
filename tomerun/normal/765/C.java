import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println(solve());
    }

    static int solve() {
        int K = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();
        int L = Math.min(A, B);
        int H = Math.max(A, B);
        if (L < K) {
            if (H % K != 0) return -1;
            return H / K;
        } else {
            return H / K + L / K;
        }
    }
}