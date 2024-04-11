import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in 
    int a = Integer.parseInt(f.readLine());
    
    // check for 8's
    int ans = 0;
    outer:
    while (true) {
      a+=1;
      ans+=1;
      int b = Math.abs(a);
      while (b>0) {
        if (b%10==8) break outer;
        b/=10;
      }
    }
    
    // write to out
    out.println(ans);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}