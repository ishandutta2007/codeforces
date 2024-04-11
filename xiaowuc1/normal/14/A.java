import java.io.*;
import java.util.*;
public class A14 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        char[][] grid = new char[r][c];
        for(int i = 0; i < grid.length; i++)
            grid[i] = br.readLine().toCharArray();
        int minR = r;
        int maxR = 0;
        int minC = c;
        int maxC = 0;
        for(int i = 0; i < grid.length; i++)        {
            for(int j = 0; j < grid[i].length; j++)     {
                if(grid[i][j] == '*')   {
                    minR = Math.min(minR, i);
                    maxR = Math.max(maxR, i);
                    minC = Math.min(minC, j);
                    maxC = Math.max(maxC, j);
                }
            }
        }
        for(int i = minR; i <= maxR; i++)       {
            for(int j = minC; j <= maxC; j++)       {
                System.out.print(grid[i][j]);
            }
            System.out.println();
        }
    }
}