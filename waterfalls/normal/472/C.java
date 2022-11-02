import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader fi = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n
    int n = Integer.parseInt(fi.readLine());
    
    // names
    String[] firsts = new String[n];
    String[] lasts = new String[n];
    for (int i=0;i<n;i++) {
      StringTokenizer st = new StringTokenizer(fi.readLine());
      firsts[i] = st.nextToken();
      lasts[i] = st.nextToken();
    }
    
    // order
    int[] order = new int[n];
    StringTokenizer st = new StringTokenizer(fi.readLine());
    for (int i=0;i<n;i++) order[i] = Integer.parseInt(st.nextToken())-1;
    
    // check
    boolean ok = true;
    String prev = "";
    for (int i=0;i<n;i++) {
      String first = firsts[order[i]];
      String last = lasts[order[i]];
      boolean f = (first.compareTo(prev)>0);
      boolean l = (last.compareTo(prev)>0);
      if (!f && !l) {
        ok = false; 
        break;
      }
      if (f && !l) prev = first;
      if (l && !f) prev = last;
      if (f && l) {
        if (first.compareTo(last)<0) prev = first;
        else prev = last;
      }
    }

    // write to out
    if (ok) out.println("YES");
    else out.println("NO");
    
    // cleanup
    out.close();
    System.exit(0);
  }
}