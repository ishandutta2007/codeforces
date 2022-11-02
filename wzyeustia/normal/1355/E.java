import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class E {

    // The correctness of binary search:
    // how to determine where is the best height?
    //

    private static long N, A, R, M;

    private static long calcCost(int index, int[] height) {
        int finalHeight = height[index];
        long NA = 0;
        for (int i = 0; i < index; i++)
            NA += finalHeight - height[i];
        long NR = 0;
        for (int i = index + 1; i < N; i++)
            NR += height[i] - finalHeight;

        long cost;
        if (NA > NR)
            cost = M * NR + A * (NA - NR);
        else
            cost = M * NA + R * (NR - NA);

        //System.out.printf("NA = %d, NR = %d\n", NA, NR);
        return cost;
    }

    private static long calcCostFromHeight(long finalHeight, int[] height) {
        long cost;
        long NA = 0, NR = 0;
        for (int i = 0; i < N; i++) {
            if (height[i] - finalHeight < 0)
                NA += finalHeight - height[i];
            else
                NR += height[i] - finalHeight;
        }

        if (NA > NR)
            cost = M * NR + A * (NA - NR);
        else
            cost = M * NA + R * (NR - NA);

        //System.out.printf("NA = %d, NR = %d\n", NA, NR);
        //System.out.print("averageCost = ");
        //System.out.println(averageCost);

        return cost;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        N = scanner.nextInt();
        A = scanner.nextInt();
        R = scanner.nextInt();
        M = scanner.nextInt();

        int[] height = new int[(int) N];
        long average = 0;
        for (int i = 0; i < N; i++) {
            height[i] = scanner.nextInt();
            average += height[i];
        }
        average /= N;
        Arrays.sort(height);

        // System.out.println(Arrays.toString(height));
        // System.out.println(average);

        int avgIndex = -1;
        for (int i = 0; i < N; i++) {
            if (average < height[i])
                break;
            avgIndex++;
        }


        //System.out.printf("avgIndex = %d\n", avgIndex);

        long totalCost = Long.MAX_VALUE;
        if (A == 0 || R == 0) {
            totalCost = 0;
        } else {
            if (M >= A + R) {
                // will not use move operation.
                // just find the best percentage.
                int index = (int) (N * R / (A + R));
                int finalHeight = height[index];
                long noMoveCost = 0;
                for (int i = 0; i < index; i++) {
                    noMoveCost += A * (finalHeight - height[i]);
                }
                for (int i = index + 1; i < N; i++) {
                    noMoveCost += R * (height[i] - finalHeight);
                }
                totalCost = Math.min(totalCost, noMoveCost);
            } else {
                if (M != 0) {
                    int Aindex = (int) ((N - 1) - A * N / M);
                    int Rindex = (int) (R * N / M);

                    //System.out.printf("Aindex = %d, Rindex = %d\n", Aindex, Rindex);

                    if (Aindex > avgIndex && Aindex < N) {
                        long ACost = calcCost(Aindex, height);
                        // System.out.print("ACost = ");
                        // System.out.println(ACost);
                        totalCost = Math.min(totalCost, ACost);
                    }

                    if (Rindex < avgIndex && Rindex >= 0) {
                        long RCost = calcCost(Rindex, height);
                        // System.out.print("RCost = ");
                        // System.out.println(RCost);
                        totalCost = Math.min(totalCost, RCost);
                    }
                }
                totalCost = Math.min(totalCost, calcCostFromHeight(average, height));
                totalCost = Math.min(totalCost, calcCostFromHeight(average + 1, height));


            }
        }


        System.out.println(totalCost);
    }
}