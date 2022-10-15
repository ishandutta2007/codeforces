import java.io.*;
import java.util.*;
 
public class F {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        int n = Integer.parseInt(reader.readLine());
        int[][] array = new int[n][n];
        array[0][0] = 8;
        array[0][1] = 9;
        array[0][2] = 1;
        array[0][3] = 13;
        array[1][0] = 3;
        array[1][1] = 12;
        array[1][2] = 7;
        array[1][3] = 5;
        array[2][0] = 0;
        array[2][1] = 2;
        array[2][2] = 4;
        array[2][3] = 11;
        array[3][0] = 6;
        array[3][1] = 10;
        array[3][2] = 15;
        array[3][3] = 14;
        int add = 16;
        for(int i = 0; i < n; i += 4){
            for(int j = 0; j < n; j += 4){
                if(i == 0 && j == 0){
                    continue;
                }
                array[i][j] = 8 + add;
                array[i][j + 1] = 9 + add;
                array[i][2 + j] = 1 + add;
                array[i][3 + j] = 13+ add;
                array[i + 1][j] = 3+ add;
                array[i + 1][1 + j] = 12+ add;
                array[i + 1][2 + j] = 7+ add;
                array[i + 1][3 + j] = 5+ add;
                array[i + 2][j] = 0+ add;
                array[i + 2][1 + j] = 2+ add;
                array[i + 2][2 + j] = 4+ add;
                array[i + 2][3 + j] = 11+ add;
                array[i + 3][j] = 6+ add;
                array[i + 3][1 + j] = 10+ add;
                array[i + 3][2 + j] = 15+ add;
                array[i + 3][3 + j] = 14+ add;
                add += 16;
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                writer.print(array[i][j] + " ");
            }
            writer.println("");
        }
        writer.close();
    }
}