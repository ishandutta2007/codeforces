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
    int k = Integer.parseInt(st.nextToken())-1;
    
    // write to out
    for (int i=0;i<k;i++) {
      if (i%2==0) out.print((n-i/2)+" ");
      else out.print((i+1)/2+" ");
    }
    if (k%2==0) for (int i=n-(k+1)/2;i>(k+1)/2;i--) out.print(i+" ");
    else for (int i=(k+1)/2;i<=n-(k+1)/2;i++) out.print(i+" ");
    out.println();
    
    // cleanup
    out.close();
    System.exit(0);
  }
}