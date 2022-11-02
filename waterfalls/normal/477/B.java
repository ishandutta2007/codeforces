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
    int k = Integer.parseInt(st.nextToken());
    
    // print
    out.println((6*n-1)*k);
    for (int i=1;i<=n;i++) {
      out.print(((6*i-5)*k)+" ");
      out.print(((6*i-4)*k)+" ");
      out.print(((6*i-3)*k)+" ");
      out.print((6*i-1)*k);
      out.println();
    }
    
    // cleanup
    out.close();
    System.exit(0);
  }
}