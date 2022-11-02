import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            ArrayList<Integer> arrayList = new ArrayList<>();
            int multiplier = 1;
            while (n != 0) {
                int lsb = n % 10;
                if (lsb != 0) {
                    arrayList.add(lsb * multiplier);
                }
                multiplier *= 10;
                n /= 10;
            }
            System.out.println(arrayList.size());
            for (int num : arrayList) {
                System.out.printf("%d ", num);
            }
            System.out.println();
        }
    }
}