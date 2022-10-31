import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,a,b
    StringTokenizer st = new StringTokenizer(f.readLine());
    long n = Long.parseLong(st.nextToken());
    long a = Long.parseLong(st.nextToken());
    long b = Long.parseLong(st.nextToken());
    
    // area already big enough
    if (a*b>=6*n) {
      out.println(a*b);
      out.println(a+" "+b);
    } else {
      boolean aBig = true;
      if (a<b) {
        aBig = false;
        long t = a;
        a = b;
        b = t;
      }
      long min = Long.MAX_VALUE;
      long best = 0;
      for (long i=b;i<=Math.sqrt(6*n)+1;i++) {
        if ((6*n-1)/i+1>=a && min>i*((6*n-1)/i+1)) {
          min = i*((6*n-1)/i+1);
          best = i;
        }
      }
      out.println(min);
      if (aBig) out.println(((6*n-1)/best+1)+" "+best);
      else out.println(best+" "+((6*n-1)/best+1));
    }
    
    // cleanup
    out.close();
    System.exit(0);
  }
}