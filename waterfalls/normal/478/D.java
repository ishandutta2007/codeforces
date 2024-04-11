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
    int r = Integer.parseInt(st.nextToken());
    int g = Integer.parseInt(st.nextToken());
    int h = (int) ((Math.sqrt(8*(r+g)+1)-1)/2+1e-8);
    
    // dp up
    int MOD = 1000000007;
    int[] last = new int[r+1];
    last[0] = 1;
    for (int i=1;i<=h;i++) {
      int[] next = new int[r+1];
      int go = Math.min(r,i*(i+1)/2);
      for (int j=0;j<=go;j++) {
        if (i*(i+1)/2-j<=g) next[j] = last[j];
        if (j>=i) next[j] = (next[j]+last[j-i])%MOD;
      }
      last = next;
    }
    
    // write to out
    int tot = 0;
    for (int i: last) tot = (tot+i)%MOD;
    out.println(tot);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}