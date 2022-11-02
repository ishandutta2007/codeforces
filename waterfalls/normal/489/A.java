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
    int[] nums = new int[n];
    StringTokenizer st = new StringTokenizer(f.readLine());
    for (int i=0;i<n;i++) nums[i] = Integer.parseInt(st.nextToken());
    
    // insertion sort
    out.println(n-1);
    for (int i=0;i<n-1;i++) {
      int where = i;
      for (int j=i;j<n;j++) if (nums[j]<nums[where]) where = j;
      out.println(i+" "+where);
      int tmp = nums[where];
      nums[where] = nums[i];
      nums[i] = tmp;
    }
    
    // cleanup
    out.close();
    System.exit(0);
  }
}