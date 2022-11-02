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
    int a = Integer.parseInt(st.nextToken());
    int b = Integer.parseInt(st.nextToken());
    int k = Integer.parseInt(st.nextToken());
    
    // setup a and b so 0<=a<b
    if (a>b) {
      a = n-a;
      b = n-b;
    } else {
      a-=1;
      b-=1;
    }
    
    // dp with prefix sums
    int MOD = 1000000007;
    int[] last = new int[b];
    int[] sums = new int[b+1];
    for (int i=0;i<b;i++) {
      last[i] = 1;
      sums[i] = i;
    }
    sums[b] = b;
    for (int i=0;i<k;i++) {
      int[] cur = new int[b];
      for (int j=0;j<b;j++) cur[j] = (int) (((long) sums[b]-sums[Math.max(0,2*j-b+1)]-last[j]+2*MOD)%MOD);
      int[] next = new int[b+1];
      for (int j=0;j<b;j++) next[j+1] = (next[j]+cur[j])%MOD;
      last = cur;
      sums = next;
    }
    
    // print
    out.println(last[a]);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}