import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in 
    int n = Integer.parseInt(f.readLine());
    int[][] exams = new int[n][2];
    for (int i=0;i<n;i++) {
      StringTokenizer st = new StringTokenizer(f.readLine());
      exams[i] = new int[]{Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken())};
    }
    
    // sort 
    Arrays.sort(exams,new Comparator<int[]>() {
      public int compare(int[] a, int[] b) {
        if ((new Integer(a[0])).compareTo(b[0])==0) return (new Integer(a[1])).compareTo(b[1]);
        return (new Integer(a[0])).compareTo(b[0]);
      }
    });
    
    // go through greedy
    int prev = -1;
    for (int i=0;i<n;i++) {
      if (exams[i][1]>=prev) prev = exams[i][1];
      else prev = exams[i][0];
    }
    out.println(prev);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}