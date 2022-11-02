import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,diffs
    int n = Integer.parseInt(f.readLine());
    int[][] diffs = new int[n][2];
    StringTokenizer st = new StringTokenizer(f.readLine());
    for (int i=0;i<n;i++) diffs[i] = new int[]{Integer.parseInt(st.nextToken()),i+1};
    
    // find if two or more 2's, or a single 3
    Arrays.sort(diffs,new Comparator<int[]>() {
      public int compare(int[] a, int[] b) {
        return (new Integer(a[0])).compareTo(b[0]);
      }
    });
    boolean ok = false;
    int iTwoOne = -1;
    int iTwoTwo = -1;
    int iThree = -1;
    for (int i=0;i<n-1;i++) {
      // if three of this
      if (i<n-2 && diffs[i][0]==diffs[i+1][0] && diffs[i][0]==diffs[i+2][0]) {
        iThree = i;
        ok = true;
        break;
      }
      
      // if two of this
      if (diffs[i][0]==diffs[i+1][0]) {
        if (iTwoOne==-1) iTwoOne = i;
        else {
          iTwoTwo = i;
          ok = true;
          break;
        }
      }
    }

    // write to out
    if (ok) {
      out.println("YES");
      if (iThree==-1) {
        for (int i=0;i<n;i++) out.print(diffs[i][1]+" ");
        out.println();
        for (int i=0;i<n;i++) {
          if (i==iTwoOne) out.print(diffs[i+1][1]+" ");
          else if (i==iTwoOne+1) out.print(diffs[i-1][1]+" ");
          else out.print(diffs[i][1]+" ");
        } 
        out.println();
        for (int i=0;i<n;i++) {
          if (i==iTwoTwo) out.print(diffs[i+1][1]+" ");
          else if (i==iTwoTwo+1) out.print(diffs[i-1][1]+" ");
          else out.print(diffs[i][1]+" ");
        } 
      } else {
        for (int i=0;i<n;i++) out.print(diffs[i][1]+" ");
        out.println();
        for (int i=0;i<n;i++) {
          if (i==iThree) out.print(diffs[i+1][1]+" ");
          else if (i==iThree+1) out.print(diffs[i-1][1]+" ");
          else out.print(diffs[i][1]+" ");
        } 
        out.println();
        for (int i=0;i<n;i++) {
          if (i==iThree) out.print(diffs[i+2][1]+" ");
          else if (i==iThree+2) out.print(diffs[i-2][1]+" ");
          else out.print(diffs[i][1]+" ");
        } 
        out.println();
      }
    } else out.println("NO");
    
    // cleanup
    out.close();
    System.exit(0);
  }
}