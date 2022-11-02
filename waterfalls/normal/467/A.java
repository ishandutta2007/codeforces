import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,caps
    int n = Integer.parseInt(f.readLine());
    int total = 0;
    for (int i=0;i<n;i++) {
      StringTokenizer st = new StringTokenizer(f.readLine());
      if (-Integer.parseInt(st.nextToken())+Integer.parseInt(st.nextToken())>=2) total+=1;
    }

    // write to out
    out.println(total);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}