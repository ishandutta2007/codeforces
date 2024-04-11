import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        int[] F = new int[N + 1];

        ArrayList<ArrayList<Integer>> lists = new ArrayList<>(N + 1);
        boolean[] ok = new boolean[N + 1];
        for (int i = 0; i <= N; i++) {
            lists.add(new ArrayList<>());
        }
        for (int i = 1; i <= N; i++) {
            F[i] = sc.nextInt();
            lists.get(F[i]).add(i);
            if (i == F[i]) ok[i] = true;
        }
        ArrayList<Integer> idx = new ArrayList<>();
        for (int i = 1; i <= N; i++) {
            if (lists.get(i).isEmpty()) continue;
            if (!ok[i]) {
                System.out.println("-1");
                return;
            }
            idx.add(i);
        }
        int M = idx.size();
        System.out.println(M);
        int[] G = new int[N + 1];
        for (int i = 1; i <= M; i++) {
            for (Integer pos : lists.get(idx.get(i - 1))) {
                G[pos] = i;
            }
        }
        for (int i = 1; i < N; i++) {
            System.out.print(G[i] + " ");
        }
        System.out.println(G[N]);
        for (int i = 0; i < M - 1; i++) {
            System.out.print(idx.get(i) + " ");
        }
        System.out.println(idx.get(M- 1));
    }

}