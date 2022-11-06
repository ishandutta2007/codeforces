import java.util.Arrays;
import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int M = sc.nextInt();
        int K = sc.nextInt();
        int[] D = new int[M];
        int[] S = new int[M];
        for (int i = 0; i < M; ++i) {
            D[i] = sc.nextInt();
        }
        for (int i = 0; i < M; ++i) {
            S[i] = sc.nextInt();
        }
        int time = 0;
        int fuel = S[0];
        for (int i = 0; ; ++i) {
            time += D[i];
            fuel -= D[i];
            if (fuel < 0) {
                int max = 0;
                for (int j = 0; j < i; ++j) {
                    max = Math.max(max, S[j]);
                }
                Arrays.sort(S, 0, i + 1);
                int count = (-fuel + S[i] - 1) / S[i];
                fuel += count * S[i];
                time += K * count;
            }
            if (i == M-1) break;
            fuel += S[i+1];
        }
        System.out.println(time);
    }
}