import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,ints
    int n = Integer.parseInt(f.readLine());
    long[] ints = new long[n];
    StringTokenizer st = new StringTokenizer(f.readLine());
    for (int i=0;i<n;i++) {
      ints[i] = Long.parseLong(st.nextToken());
    }
    
    // sort, take large to small
    long total = 0L;
    Arrays.sort(ints);
    for (int i=n-1;i>=0;i--) total+=ints[i]*(i+2);
    total-=ints[n-1];

    // write to out
    out.println(total);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}