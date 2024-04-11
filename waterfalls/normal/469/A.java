import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,p,q
    int n = Integer.parseInt(f.readLine());
    boolean[] passed = new boolean[n+1];
    StringTokenizer st = new StringTokenizer(f.readLine());
    int p = Integer.parseInt(st.nextToken());
    for (int i=0;i<p;i++) passed[Integer.parseInt(st.nextToken())] = true;
    st = new StringTokenizer(f.readLine());
    int q = Integer.parseInt(st.nextToken());
    for (int i=0;i<q;i++) passed[Integer.parseInt(st.nextToken())] = true;
    
    // check all
    boolean ok = true;
    for (int i=1;i<=n;i++) if (!passed[i]) ok = false;

    // write to out
    if (ok) out.println("I become the guy.");
    else out.println("Oh, my keyboard!");
    
    // cleanup
    out.close();
    System.exit(0);
  }
}