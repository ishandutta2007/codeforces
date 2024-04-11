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
    int k = Integer.parseInt(st.nextToken());
    
    // read in seqs and keep track of after
    boolean[][] after = new boolean[n][n];
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) if (i!=j) after[i][j] = true;
    int[] cur = new int[n];
    for (int s=0;s<k;s++) {
      cur = new int[n];
      st = new StringTokenizer(f.readLine());
      for (int i=0;i<n;i++) cur[i] = Integer.parseInt(st.nextToken())-1;
      for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) after[cur[j]][cur[i]] = false;
    }
    
    // dp to find longest
    int[] dp = new int[n];
    for (int i=0;i<n;i++) dp[i] = 1;
    for (int i=0;i<n;i++) for (int j=0;j<i;j++) if (after[cur[j]][cur[i]]) dp[i] = Math.max(dp[i],dp[j]+1);
    
    // write to out
    int max = 0;
    for (int i: dp) max = Math.max(max,i);
    out.println(max);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}