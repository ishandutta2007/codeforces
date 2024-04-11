import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,m,k,armies
    StringTokenizer st = new StringTokenizer(f.readLine());
    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());
    int k = Integer.parseInt(st.nextToken());
    int[] armies = new int[m];
    for (int i=0;i<m;i++) armies[i] = Integer.parseInt(f.readLine());
    int fedor = Integer.parseInt(f.readLine());
    
    // check each one
    int total = 0;
    for (int i=0;i<m;i++) {
      int dif = 0;
      int nF = fedor;
      for (int j=0;j<=n;j++) {
        if (armies[i]%2!=nF%2) dif+=1;
        armies[i] = armies[i]>>1;
        nF = nF>>1;
      }
      if (dif<=k) total+=1;
    }

    // write to out
    out.println(total);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}