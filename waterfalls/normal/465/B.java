import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,letters
    int n = Integer.parseInt(f.readLine());
    int moves = 0;
    boolean in = false;
    boolean noMore = false;
    StringTokenizer st = new StringTokenizer(f.readLine());
    for (int i=0;i<n;i++) {
      if (st.nextToken().charAt(0)=='1') {
        noMore = false;
        moves+=1;
        if (!in) in = true;
      } else {
        if (in) {
          in = false;
          moves+=1;
          noMore = true;
        }
      }
    }
    if (noMore) moves-=1;

    // write to out
    out.println(moves);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}