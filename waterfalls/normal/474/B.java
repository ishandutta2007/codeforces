import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in 
    int n = Integer.parseInt(f.readLine());
    int[] piles = new int[n];
    int total = 0;
    StringTokenizer st = new StringTokenizer(f.readLine());
    for (int i=0;i<n;i++) {
      piles[i] = Integer.parseInt(st.nextToken());
      total+=piles[i];
    }
    int[] where = new int[total];
    int loc = 0;
    for (int i=0;i<n;i++) {
      for (int j=0;j<piles[i];j++) {
        where[loc] = i;
        loc+=1;
      }
    }
    
    // queries
    int m = Integer.parseInt(f.readLine());
    st = new StringTokenizer(f.readLine());
    for (int i=0;i<m;i++) out.println(where[Integer.parseInt(st.nextToken())-1]+1);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}