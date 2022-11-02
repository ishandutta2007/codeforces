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
    outer:
    for (int t=0;t<n;t++) {
      StringTokenizer st = new StringTokenizer(f.readLine());
      long l = Long.parseLong(st.nextToken());
      long r = Long.parseLong(st.nextToken());
      
      // find binary reps
      int[] bin1 = new int[65];
      int[] bin2 = new int[65];
      for (int i=0;i<65;i++) {
        bin1[i] = (int) l&1;
        bin2[i] = (int) r&1;
        l = l>>1;
        r = r>>1;
      }
      
      // find longest prefix
      long ans = 0;
      int check = 64;
      while (bin1[check]==bin2[check]) {
        check-=1;
        if (check==-1) {
          out.println(ans);
          continue outer;
        }
        if (bin1[check]==1) ans|=((long) 1)<<check;
      }
      
      // check special case if r is it
      boolean ok = true;
      for (int i=0;i<=check;i++) if (bin2[i]!=1) ok = false;
      if (ok) out.println(ans+(((long) 1)<<(check+1))-1);
      else out.println(ans+(((long) 1)<<check)-1);
    }
    
    // cleanup
    out.close();
    System.exit(0);
  }
}