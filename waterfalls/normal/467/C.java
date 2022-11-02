import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,m,k,nums
    StringTokenizer st = new StringTokenizer(f.readLine());
    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());
    int k = Integer.parseInt(st.nextToken());
    int[] nums = new int[n];
    st = new StringTokenizer(f.readLine());
    for (int i=0;i<n;i++) nums[i] = Integer.parseInt(st.nextToken());
    
    // find sum for each interval beginning at i
    long[] sum = new long[n-m+1];
    for (int i=0;i<m;i++) sum[0]+=nums[i];
    for (int i=1;i<n-m+1;i++) sum[i] = sum[i-1]-nums[i-1]+nums[i-1+m];
    
    // dp with index of last interval+1, and num of interval
    long[][] total = new long[n+1][k+1];
    for (int i=m;i<=n;i++) for (int j=1;j<=k;j++) total[i][j] = Math.max(total[i-1][j],sum[i-m]+total[i-m][j-1]);
    
    // write to out
    out.println(total[n][k]);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}