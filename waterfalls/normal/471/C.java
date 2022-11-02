import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n
    long n = Long.parseLong(f.readLine());
    
    // find binary search for max height: 3/2*h^2+1/2*h
    int l = 0;
    int h = 1<<20;
    while (h-l>1) {
      int t = (l+h)/2;
      if (((long) 3)*t*(t+1)/2-h>n) h = t;
      else l = t;
    }
    l = l-((int) ((n+l)%3));

    // write to out
    out.println((l+2)/3);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}