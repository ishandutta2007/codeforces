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
    int minX = Integer.MAX_VALUE;
    int maxX = Integer.MIN_VALUE;
    int minY = Integer.MAX_VALUE;
    int maxY = Integer.MIN_VALUE;
    for (int i=0;i<n;i++) {
      StringTokenizer st = new StringTokenizer(f.readLine());
      int x = Integer.parseInt(st.nextToken());
      int y = Integer.parseInt(st.nextToken());
      minX = Math.min(minX,x);
      maxX = Math.max(maxX,x);
      minY = Math.min(minY,y);
      maxY = Math.max(maxY,y);
    }
    
    // write to out
    out.println(((long) Math.max(maxX-minX,maxY-minY))*Math.max(maxX-minX,maxY-minY));
    
    // cleanup
    out.close();
    System.exit(0);
  }
}