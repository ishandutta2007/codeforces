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
    int m = Integer.parseInt(st.nextToken());
    
    // if not enough
    if (n<m) out.println(-1);
    else out.println((((n+1)/2-1)/m+1)*m);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}