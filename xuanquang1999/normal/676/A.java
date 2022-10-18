import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();

        int b[] = new int[n];

        int maxDist = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k)
                    b[k] = a[k];

                int t = b[i];
                b[i] = b[j];
                b[j] = t;

                int minInd = 0, maxInd = 0;
                for (int k = 1; k < n; ++k) {
                    if (b[k] > b[maxInd])
                        maxInd = k;
                    if (b[k] < b[minInd])
                        minInd = k;
                }

                maxDist = Math.max(maxDist, Math.abs(maxInd - minInd));
            }
        }

        System.out.println(maxDist);
    }
}