import java.io.*;
import java.util.*;
public class A12 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[][] grid = new boolean[3][3];
        for(int i = 0; i < 3; i++)  {
            String s = br.readLine();
            for(int j = 0; j < 3; j++)
                grid[i][j] = s.charAt(j) == '.';
        }
        boolean a = grid[0][0] ^ grid[2][2];
        boolean b = grid[0][1] ^ grid[2][1];
        boolean c = grid[0][2] ^ grid[2][0];
        boolean d = grid[1][0] ^ grid[1][2];
        if(a||b||c||d)      {
            System.out.println("NO");
        }
        else    {
            System.out.println("YES");
        }
    }
}