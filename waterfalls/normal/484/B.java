import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in 
    int max = 2000200;
    int n = Integer.parseInt(f.readLine());
    boolean[] nums = new boolean[max];
    StringTokenizer st = new StringTokenizer(f.readLine());
    for (int i=0;i<n;i++) nums[Integer.parseInt(st.nextToken())] = true;
    
    // bash (how does this run in time?)
    int[] before = new int[max];
    before[0] = 0;
    before[1] = 1;
    for (int i=2;i<max;i++) {
      if (nums[i-1]) before[i] = i-1;
      else before[i] = before[i-1];
    }
    int ans = 0;
    for (int i=1;i<max;i++) if (nums[i]) for (int j=2*i;j<max;j+=i) ans = Math.max(ans,before[j]%i);

    // write to out
    out.println(ans);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}