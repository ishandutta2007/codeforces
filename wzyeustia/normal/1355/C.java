import java.io.InputStreamReader;
import java.util.Scanner;

public class C {
    private static long A, B, C, D;

    private static long calcYZPairs(long delta) {
        int state = 0;
        if (C - B < delta)
            state++;
        if (D - C < delta)
            state++;

        switch (state) {
            case 0:
                return delta + 1;
            case 1:
                return Math.min(C - B + 1, D - C + 1);
            case 2:
                return D - B - delta + 1;
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        long[] boundary = new long[4];
        for (int i = 0; i < 4; i++)
            boundary[i] = scanner.nextInt();

        // C,C || C, C+1 /\ C-1, C || C, C+2 /\ C-1, C+1 /\ C-2, C ||
        // boundary: C - B < delta || D - C < delta
        // When no boundary, num of combination = delta + 1
        // When one boundary, num = smaller side.
        // When two boundary, num = D - B - delta + 1

        // for every pair of (y, z), corresponding num of x:
        // num of x = B - max(A, delta + 1)

        A = boundary[0];
        B = boundary[1];
        C = boundary[2];
        D = boundary[3];
        long sum = 0;
        for (long delta = 0; delta <= D - B; delta++) {
            long numOfYZPairs = calcYZPairs(delta);
            long numOfX = B - Math.max(A, delta + 1) + 1;
            long numOfCom = numOfX * numOfYZPairs;
            // System.out.printf("%d %d\n", numOfYZPairs, numOfX);
            if (numOfCom == 0)
                break;
            sum += numOfCom;
        }

        System.out.println(sum);
    }
}