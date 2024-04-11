import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            String[] data = br.readLine().split(" ");
            int n0 = Integer.parseInt(data[0]);
            int n1 = Integer.parseInt(data[1]);
            int n2 = Integer.parseInt(data[2]);

            StringBuilder stringBuilder = new StringBuilder();
            if (n1 > 0) {
                stringBuilder.append("0".repeat(Math.max(0, n0 + 1)));
                stringBuilder.append("1".repeat(Math.max(0, n2 + 1)));
                for (int j = 0; j < n1 - 1; j++)
                    stringBuilder.append(j % 2);
            } else {
                if (n0 > 0)
                    stringBuilder.append("0".repeat(Math.max(0, n0 + 1)));
                if (n2 > 0)
                    stringBuilder.append("1".repeat(Math.max(0, n2 + 1)));
            }
            System.out.println(stringBuilder.toString());
        }
    }
}