import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,s,sugars,try each sugar
    StringTokenizer st = new StringTokenizer(f.readLine());
    int n = Integer.parseInt(st.nextToken());
    int s = Integer.parseInt(st.nextToken())*100;
    int max = 0;
    boolean made = false;
    for (int i=0;i<n;i++) {
      st = new StringTokenizer(f.readLine());
      int sugar = (Integer.parseInt(st.nextToken()))*100+Integer.parseInt(st.nextToken());
      if (sugar<=s) {
        made = true;
        max = Math.max(max,(s-sugar)%100);
      }
    }

    // write to out
    if (made) out.println(max);
    else out.println(-1);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}