import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,ints
    int n = Integer.parseInt(f.readLine());
    StringTokenizer st = new StringTokenizer(f.readLine());
    int[] nums = new int[n];
    long sum = 0;
    for (int i=0;i<n;i++) {
      nums[i] = Integer.parseInt(st.nextToken());
      sum+=nums[i];
    }
    
    // if not multiple of 3
    if (sum%3!=0) {
      out.println(0);
      out.close();
      System.exit(0);
    }
    
    // work from both sides finding points where ends are sum/3 (one side strictly, one not)
    int[] dpLeft = new int[n];
    int[] dpRight = new int[n];
    long cur = 0;
    for (int i=0;i<n-1;i++) {
      cur+=nums[i];
      if (cur==sum/3) dpLeft[i]+=1;
    }
    cur = 0;
    for (int i=n-1;i>1;i--) {
      cur+=nums[i];
      if (cur==sum/3) dpRight[i]+=1;
      dpRight[i-1] = dpRight[i];
    }
    
    // total is sum of products
    long total = 0;
    for (int i=0;i<n-2;i++) total+=dpLeft[i]*dpRight[i+2];

    // write to out
    out.println(total);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}