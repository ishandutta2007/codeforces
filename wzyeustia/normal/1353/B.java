import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            String[] str = br.readLine().split(" ");
            int n = Integer.parseInt(str[0]);
            int k = Integer.parseInt(str[1]);

            String[] dataA = br.readLine().split(" ");
            int[] arrA = new int[dataA.length];
            for (int j = 0; j < dataA.length; j++)
                arrA[j] = Integer.parseInt(dataA[j]);

            String[] dataB = br.readLine().split(" ");
            int[] arrB = new int[dataB.length];
            for (int j = 0; j < dataB.length; j++)
                arrB[j] = Integer.parseInt(dataB[j]);

            Arrays.sort(arrA);
            Arrays.sort(arrB);


            for (int j = 0; j < k; j++) {
                if (arrA[j] < arrB[arrB.length - 1 - j])
                    arrA[j] = arrB[arrB.length - 1 - j];
            }

            int sum = 0;
            for (int value : arrA) sum += value;

            System.out.println(sum);
        }
    }
}