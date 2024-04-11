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
    int p = Integer.parseInt(st.nextToken())-1;
    char[] s = f.readLine().toCharArray();
    
    // check where ok
    int leftMost = n;
    int rightMost = -1;
    boolean[] ok = new boolean[n];
    for (int i=0;i<n;i++) {
      ok[i] = true;
      if (s[i]!=s[n-i-1]) {
        leftMost = Math.min(leftMost,i);
        if (i<n/2+n%2) rightMost = Math.max(rightMost,i);
        ok[i] = false;
      }
    }
    if (leftMost==n) {
      out.println("0");
      out.close();
      System.exit(0);
    }
    
    // find must
    int must = 0;
    for (int i=0;i<n/2+n%2;i++) if (!ok[i]) must+=Math.min((s[i]-s[n-i-1]+26)%26,(s[n-i-1]-s[i]+26)%26);
    
    // check movements
    if (p>=n/2+n%2) p = n-p-1;
    int min = Math.min(rightMost-leftMost+Math.abs(p-leftMost),rightMost-leftMost+Math.abs(rightMost-p));
    
    // write to out
    out.println(must+min);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}