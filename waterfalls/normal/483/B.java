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
    int c1 = Integer.parseInt(st.nextToken());
    int c2 = Integer.parseInt(st.nextToken());
    int x = Integer.parseInt(st.nextToken());
    int y = Integer.parseInt(st.nextToken());
    
    // binary search for a good v
    int low = 0;
    int high = Integer.MAX_VALUE;
    while (low+1<high) {
      int test = (int) (((long) low+high)/2);
      int cantGive = test/x/y;
      int give2 = test/x-cantGive;
      int give1 = test/y-cantGive;
      if (Math.max(0,c1-give1)+Math.max(0,c2-give2)<=test-cantGive-give1-give2) high = test;
      else low = test;
    }

    // write to out
    out.println(high);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}