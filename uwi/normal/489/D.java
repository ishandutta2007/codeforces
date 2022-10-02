import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(br);
        short n = sc.nextShort();
        short edges = sc.nextShort();
        boolean incoming[][] = new boolean[n][n];
        short[][] out = new short[n][n];
        short[] size = new short[n];
        for (short i = 0; i < edges; i++) {
            short a = sc.nextShort();
            short b = sc.nextShort();
            a--;
            b--;
            out[a][size[a]++] = b;
            incoming[b][a] = true;
        }
        long answer = 0;
        // whoa!
        for (short j = 0; j < n; j++) {
            for (short i = 0; i < n; i++) {
                if (i != j) {
                    // i se j tak
                    int count = 0;
                    for (short k = 0; k < size[i]; k++) {// Integer k :
                                                            // graphs[i].out)
                                                            // {
                        short curArrValue = out[i][k];
                        if (incoming[j][curArrValue] && curArrValue != i
                                && curArrValue != j) {
                            count++;
                        }
                    }
                    if (count >= 2) {
                        answer = answer + (((count) * (count - 1)) / 2);

                    }
                }
            }
        }
        System.out.println(answer);
    }
}