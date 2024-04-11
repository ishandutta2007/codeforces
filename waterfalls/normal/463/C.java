import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,grid (only need diagonals,grid for intersection)
    int n = Integer.parseInt(f.readLine());
    long[] diagonalL = new long[2*n-1];
    long[] diagonalR = new long[2*n-1];
    long[][] grid = new long[n][n];
    for (int i=0;i<n;i++) {
      StringTokenizer st = new StringTokenizer(f.readLine());
      for (int j=0;j<n;j++) {
        long a = Long.parseLong(st.nextToken());
        diagonalL[i+j]+=a;
        diagonalR[i-j+n-1]+=a;
        grid[i][j] = a;
      }
    }
    
    // bash every square to see if better
    long bestW = 0;
    long bestB = 0;
    int xW = 0;
    int yW = 0;
    int xB = 1;
    int yB = 0;
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
        if ((i+j)%2==0) {
          long a = diagonalL[i+j]+diagonalR[i-j+n-1]-grid[i][j];
          if (a>bestW) {
            bestW = a;
            xW = i;
            yW = j;
          }
        } else {
          long a = diagonalL[i+j]+diagonalR[i-j+n-1]-grid[i][j];
          if (a>bestB) {
            bestB = a;
            xB = i;
            yB = j;
          }
        }
      }
    }
    
    // write to out
    out.println(bestW+bestB);
    out.println((xW+1)+" "+(yW+1)+" "+(xB+1)+" "+(yB+1));
    
    // cleanup
    out.close();
    System.exit(0);
  }
}