import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,m
    StringTokenizer st = new StringTokenizer(f.readLine());
    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());
    char[] horo = f.readLine().toCharArray();
    if (horo[0]==horo[horo.length-1]) {
      out.println("NO");
      out.close();
      System.exit(0);
    }
    char[] vert = f.readLine().toCharArray();
    if (vert[0]==vert[vert.length-1]) {
      out.println("NO");
      out.close();
      System.exit(0);
    }
    if ((horo[0]=='>' && vert[0]=='^') || (horo[0]=='<' && vert[0]=='v')) out.println("YES");
    else out.println("NO");
    
    // cleanup
    out.close();
    System.exit(0);
  }
}