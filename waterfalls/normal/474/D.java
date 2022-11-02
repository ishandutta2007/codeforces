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
    int t = Integer.parseInt(st.nextToken());
    int k = Integer.parseInt(st.nextToken());
    
    // dp up
    int[] dp = new int[100001];
    dp[0] = 1;
    for (int i=1;i<100001;i++) {
      dp[i] = dp[i-1];
      try { dp[i] = (dp[i]+dp[i-k])%1000000007; } catch (Exception e) {};
    }
    
    // find prefix sums
    int[] sums = new int[100001];
    sums[0] = dp[0];
    for (int i=1;i<100001;i++) {
      sums[i] = (sums[i-1]+dp[i])%1000000007;
    }
    
    // queries
    for (int i=0;i<t;i++) {
      st = new StringTokenizer(f.readLine());
      out.println((1000000007-sums[Integer.parseInt(st.nextToken())-1]+sums[Integer.parseInt(st.nextToken())])%1000000007);
    }
    
    // cleanup
    out.close();
    System.exit(0);
  }
}