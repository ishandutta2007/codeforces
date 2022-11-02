import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            br.readLine();
            String[] data = br.readLine().split(" ");
            int[] arr = new int[data.length];
            for (int j = 0; j < data.length; j++) {
                arr[j] = Integer.parseInt(data[j]);
            }

            long maxSum = arr[0];
            int lastMax = arr[0];
            for (int j = 1; j < arr.length; j++) {
                if (Math.abs(arr[j - 1] + arr[j]) == Math.abs(arr[j - 1]) + Math.abs(arr[j])) {
                    if (arr[j] > lastMax) {
                        maxSum += arr[j] - lastMax;
                        lastMax = arr[j];
                    }
                } else {
                    maxSum += arr[j];
                    lastMax = arr[j];
                }
            }

            System.out.println(maxSum);
        }
    }
}