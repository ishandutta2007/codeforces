import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    private static int[] repSeq = {1, 4, 2, 6, 3, 5};
    private static int[] longerSeq = {1, 3, 6, 2, 4, 7, 9, 5, 8, 10};
    private static int[] shorterSeq = {6, 3, 1, 4, 2, 5};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            StringBuilder stringBuilder = new StringBuilder();
            while (n > 12) {
                for (int j = 0; j < 6; j++) {
                    stringBuilder.append(n - repSeq[j] + 1);
                    stringBuilder.append(" ");
                }
                n -= 6;
            }

            if (n > 10) {
                for (int j = 0; j < 6; j++) {
                    stringBuilder.append(n - repSeq[j] + 1);
                    stringBuilder.append(" ");
                }
                if (n == 12)
                    stringBuilder.append("6 3 5 1 4 2");
                else
                    stringBuilder.append("5 2 4 1 3");
            } else if (n > 6) {
                for (int j = 0; j < 10; j++) {
                    int num = n + 1 - longerSeq[j];
                    if (num > 0) {
                        stringBuilder.append(num);
                        stringBuilder.append(" ");
                    }
                }
            } else if (n == 2 || n == 3) {
                stringBuilder.append("-1");
            } else {
                for (int j = 0; j < 6; j++) {
                    if (shorterSeq[j] <= n) {
                        stringBuilder.append(shorterSeq[j]);
                        stringBuilder.append(" ");
                    }
                }
            }

            System.out.println(stringBuilder.toString());
        }
    }
}