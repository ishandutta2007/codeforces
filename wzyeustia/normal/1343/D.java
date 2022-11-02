import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class D {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            String[] str = br.readLine().split(" ");
            int key = Integer.parseInt(str[1]);
            String[] data = br.readLine().split(" ");
            int[] arr = new int[data.length];
            for (int j = 0; j < arr.length; j++)
                arr[j] = Integer.parseInt(data[j]);

            int[] change = new int[key * 2 + 1];
            change[2] = arr.length;
            for (int j = 0; j < arr.length / 2; j++) {
                int sum = arr[j] + arr[arr.length - j - 1];
                change[Math.min(arr[j], arr[arr.length - j - 1]) + 1]--;
                change[sum]--;
                if (sum != 2 * key)
                    change[sum + 1]++;

                int maxNum = Math.max(arr[j], arr[arr.length - j - 1]);
                if (maxNum < key)
                    change[maxNum + key + 1]++;
                //System.out.println(Arrays.toString(change));
            }

            int moves = change[2];
            int minMoves = moves;
            for (int j = 3; j < change.length; j++) {
                moves += change[j];
                if (moves < minMoves)
                    minMoves = moves;
            }

            System.out.println(minMoves);
        }
    }

}