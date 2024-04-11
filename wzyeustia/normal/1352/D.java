import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            String str = br.readLine();
            int n = Integer.parseInt(str);

            String[] data = br.readLine().split(" ");
            int[] size = new int[data.length];
            for (int j = 0; j < data.length; j++) {
                size[j] = Integer.parseInt(data[j]);
            }

            int a = 0, b = 0, moves = 0;
            int aPre = 0, bPre = 0;
            int aIndex = 0;
            int bIndex = data.length - 1;


            while (true) {
                aPre = 0;
                while (aIndex <= bIndex && aPre <= bPre) {
                    a += size[aIndex];
                    aPre += size[aIndex++];
                }
                moves++;
                if (aIndex > bIndex)
                    break;

                //System.out.printf("%d %d || ", a, b);

                bPre = 0;
                while (aIndex <= bIndex && aPre >= bPre) {
                    b += size[bIndex];
                    bPre += size[bIndex--];
                }
                moves++;
                if (aIndex > bIndex)
                    break;
                //System.out.printf("%d %d || ", a, b);
            }
            System.out.printf("%d %d %d\n", moves, a, b);

        }
    }
}