import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,heights (solve as going)
    int n = Integer.parseInt(f.readLine());
    long spent = 0;
    StringTokenizer st = new StringTokenizer(f.readLine());
    for (int i=0;i<n;i++) spent = Math.max(spent,Integer.parseInt(st.nextToken()));

    // write to out
    out.println(spent);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}