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
    int a = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());
    
    // bash out
    boolean ok = true;
    for (int i=0;i<2*m;i++) {
      a = (2*a)%m;
      if (a%m==0) {
        out.println("Yes");
        ok = false;
        break;
      }
    }
    if (ok) out.println("No");
    
    // cleanup
    out.close();
    System.exit(0);
  }
}