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
    int m = Integer.parseInt(st.nextToken());
    
    // bash
    int socks = n;
    int day = 0;
    while (socks>0) {
      socks-=1;
      day+=1;
      if (day%m==0 && day!=0) socks+=1;
    }

    // write to out
    out.println(day);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}