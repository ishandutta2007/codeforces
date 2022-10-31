import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in 
    StringTokenizer st = new StringTokenizer(f.readLine());
    int m = Integer.parseInt(st.nextToken());
    int n = Integer.parseInt(st.nextToken());
    int[][] B = new int[m][n];
    for (int i=0;i<m;i++) {
      st = new StringTokenizer(f.readLine());
      for (int j=0;j<n;j++) B[i][j] = Integer.parseInt(st.nextToken());
    }
    
    // put
    int[][] A = new int[m][n];
    for (int i=0;i<m;i++) {
      for (int j=0;j<n;j++) {
        boolean both = true;
        for (int k=0;k<n;k++) if (B[i][k]==0) both = false;
        for (int k=0;k<m;k++) if (B[k][j]==0) both = false;
        if (both) A[i][j] = 1;
      }
    }
    
    // check
    boolean ok = true;
    for (int i=0;i<m;i++) {
      for (int j=0;j<n;j++) {
        if (A[i][j]==1) {
          for (int k=0;k<n;k++) if (B[i][k]==0) ok = false;
          for (int k=0;k<m;k++) if (B[k][j]==0) ok = false;
        }
        if (B[i][j]==1) {
          boolean found = false;
          for (int k=0;k<n;k++) if (A[i][k]==1) found = true;
          for (int k=0;k<m;k++) if (A[k][j]==1) found = true;
          if (!found) ok = false;
        }
      }
    }

    // write to out
    if (ok) {
      out.println("YES");
      for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) out.print(A[i][j]+" ");
        out.println();
      }
    } else out.println("NO");
    
    // cleanup
    out.close();
    System.exit(0);
  }
}