import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            String[] data = br.readLine().split(" ");
            int[] arr = new int[data.length];

            HashMap<Integer, Integer> hashMap = new HashMap<>();
            for (int j = 0; j < data.length; j++) {
                arr[j] = Integer.parseInt(data[j]);
                if (!hashMap.containsKey(arr[j]))
                    hashMap.put(arr[j], 1);
                else
                    hashMap.put(arr[j], hashMap.get(arr[j]) + 1);
            }

            int ans = 0;
            for (int num : hashMap.keySet()) {
                int start = 0, tail = 0, sum = 0;
                while (tail < arr.length) {
                    do {
                        if (tail >= arr.length)
                            break;
                        sum += arr[tail++];
                    } while (sum < num);

                    if (sum == num && tail - start >= 2) {
                        ans += hashMap.get(num);
                        break;
                    }

                    do {
                        sum -= arr[start++];
                    } while (sum > num);

                    if (sum == num && tail - start >= 2) {
                        ans += hashMap.get(num);
                        break;
                    }
                }
            }
            System.out.println(ans);
        }
    }
}