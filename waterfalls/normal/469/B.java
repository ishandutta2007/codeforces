import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in p,q,l,r
    StringTokenizer st = new StringTokenizer(f.readLine());
    int p = Integer.parseInt(st.nextToken());
    int q = Integer.parseInt(st.nextToken());
    int l = Integer.parseInt(st.nextToken());
    int r = Integer.parseInt(st.nextToken());
    boolean[] xOn = new boolean[1001+r];
    for (int i=0;i<p;i++) {
      st = new StringTokenizer(f.readLine());
      int from = Integer.parseInt(st.nextToken());
      int to = Integer.parseInt(st.nextToken());
      for (int j=from;j<=to;j++) xOn[j] = true;
    }
    int[][] yOn = new int[q][2];
    for (int i=0;i<q;i++) {
      st = new StringTokenizer(f.readLine());
      yOn[i] = new int[]{Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken())};
    }
    
    // bash all times
    int count = 0;
    loop:
    for (int i=l;i<=r;i++) {
      for (int j=0;j<q;j++) {
        for (int k=yOn[j][0];k<=yOn[j][1];k++) {
          if (xOn[k+i]) {
            count+=1;
            continue loop;
          }
        }
      }
    }

    // write to out
    out.println(count);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}