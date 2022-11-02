import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n
    int n = Integer.parseInt(f.readLine());
    
    // if n is less than 4, no, otherwise use a certain for even and odd
    if (n<4) out.println("NO");
    else if (n%2==0) {
      out.println("YES");
      out.println("1 * 2 = 2");
      out.println("3 * 2 = 6");
      out.println("4 * 6 = 24");
      for (int i=5;i<n;i+=2) {
        out.println((i+1)+" - "+i+" = 1");
        out.println("24 * 1 = 24");
      }
    } else if (n%2==1) {
      out.println("YES");
      out.println("5 * 4 = 20");
      out.println("20 + 3 = 23");
      out.println("23 + 2 = 25");
      out.println("25 - 1 = 24");
      for (int i=6;i<n;i+=2) {
        out.println((i+1)+" - "+i+" = 1");
        out.println("24 * 1 = 24");
      }
    }
    
    // cleanup
    out.close();
    System.exit(0);
  }
}