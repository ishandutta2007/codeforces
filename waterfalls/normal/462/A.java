import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,grid,solve
    int n = Integer.parseInt(f.readLine());
    int[][] grid = new int[n][n];
    int[][] sum = new int[n][n];
    for (int i=0;i<n;i++) {
      char[] line = f.readLine().toCharArray();
      for (int j=0;j<n;j++) {
        if (line[j]=='x') grid[i][j] = 0;
        else grid[i][j] = 1;
        
        // update left square
        if (j>0) {
          sum[i][j]+=grid[i][j-1];
          sum[i][j-1]+=grid[i][j];
          
          // if last row and left square fails: NO
          if (i==n-1 && sum[i][j-1]%2==1) {
            out.println("NO");
            out.close();
            System.exit(0);
          }
        }
        
        // update upper square
        if (i>0) {
          sum[i][j]+=grid[i-1][j];
          sum[i-1][j]+=grid[i][j];
          
          // if not last row and upper square fails: NO
          if (sum[i-1][j]%2==1) {
            out.println("NO");
            out.close();
            System.exit(0);
          }
        }
      }
    }
    
    // write yes,cleanup
    out.println("YES");
    out.close();
    System.exit(0);
  }
}