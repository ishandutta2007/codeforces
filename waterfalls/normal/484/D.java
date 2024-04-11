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
    int[] c = new int[n];
    StringTokenizer st = new StringTokenizer(f.readLine());
    for (int i=0;i<n;i++) c[i] = Integer.parseInt(st.nextToken());
    
    // x+c[i] uses last num, y-c[i] starts new group
    long total = 0;
    long x = -c[0];
    long y = c[0];
    for (int i=0;i<n-1;i++) {
      x = Math.max(x,total-c[i+1]);
      y = Math.max(y,total+c[i+1]);
      total = Math.max(x+c[i+1],y-c[i+1]);
    }
    out.println(total);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}