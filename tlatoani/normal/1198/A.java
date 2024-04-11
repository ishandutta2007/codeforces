import java.util.Arrays;
import java.util.Scanner;

public class MP3 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int diskSize = in.nextInt() * 8;
        Integer[] sounds = new Integer[n];
        for (int i = 0; i < n; i++) {
            sounds[i] = in.nextInt();
        }
        Arrays.sort(sounds);
        int[] distinctVals = new int[n];
        int[] distinctAmt = new int[n];
        int k = -1;
        for (int i = 0; i < n; i++) {
            if (i == 0 || sounds[i] > sounds[i - 1]) {
                distinctVals[++k] = sounds[i];
                distinctAmt[k] = 1;
            } else {
                distinctAmt[k]++;
            }
        }
        k++;
        /*for (int i = 0; i < k; i++) {
            System.out.println("distinctVals[" + i + "] = " + distinctVals[i]);
            System.out.println("distinctAmts[" + i + "] = " + distinctAmt[i]);
        }*/
        //System.out.println("k = " + k);
        int answer = n;
        int currAmt = distinctAmt[0];
        for (int i = 0, j = 0; i < k; currAmt -= distinctAmt[i], i++) {
            while (j < i || (j < k - 1 && n * lg(j + 1 - i + 1) <= diskSize)) {
                j++;
                currAmt += distinctAmt[j];
            }
            //System.out.println("i = " + i + ", j = " + j + ", currAmt = " + currAmt);
            answer = Math.min(answer, n - currAmt);
        }
        System.out.println(answer);
    }

    static int lg(int n) {
        int res = 0;
        while (n > (1 << res)) {
            res++;
        }
        return res;
    }
}