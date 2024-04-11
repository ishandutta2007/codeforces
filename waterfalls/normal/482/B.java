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
    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());
    int[][] queries = new int[m][3];
    for (int i=0;i<m;i++) {
      st = new StringTokenizer(f.readLine());
      queries[i] = new int[]{Integer.parseInt(st.nextToken())-1,Integer.parseInt(st.nextToken())-1,
                            Integer.parseInt(st.nextToken())};
    }
    
    // sort by starting point
    Arrays.sort(queries,new Comparator<int[]>() {
      public int compare(int[] a, int[] b) {
        return (new Integer(a[0])).compareTo(b[0]);
      }
    });
    
    // for each bit set settings and check
    int[] arr = new int[n];
    for (int i=0;i<30;i++) {
      ArrayList<int[]> queriesY = new ArrayList<int[]>();
      ArrayList<int[]> queriesN = new ArrayList<int[]>();
      for (int j=0;j<m;j++) {
        if ((queries[j][2]&(1<<i))!=0) queriesY.add(new int[]{queries[j][0],queries[j][1]});
        else queriesN.add(new int[]{queries[j][0],queries[j][1]});
      }
      
      // make intervals disjoint and add ones
      int prev = 0;
      int[] nums = new int[n];
      for (int[] span: queriesY) {
        if (span[0]<prev) {
          if (span[1]<prev) continue;
          else for (int j=prev;j<=span[1];j++) nums[j] = 1;
        } else for (int j=span[0];j<=span[1];j++) nums[j] = 1;
        prev = span[1]+1;
      }
      
      // prefix sums
      int[] ones = new int[n+1];
      for (int j=1;j<=n;j++) ones[j] = ones[j-1]+nums[j-1];
      
      // check whether at least one 0 for each 0 interval
      for (int[] span: queriesN) {
        if (ones[span[1]+1]-ones[span[0]]==span[1]-span[0]+1) {
          out.println("NO");
          out.close();
          System.exit(0);
        }
      }
      
      // add to arr
      for (int j=0;j<n;j++) arr[j]+=nums[j]*(1<<i);
    }

    // write to out
    out.println("YES");
    for (int i=0;i<n;i++) {
      out.print(arr[i]);
      out.print(" ");
    }
    out.println();
    
    // cleanup
    out.close();
    f.close();
    System.exit(0);
  }
}