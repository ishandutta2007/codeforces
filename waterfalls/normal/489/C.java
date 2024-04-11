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
    int m = Integer.parseInt(st.nextToken());
    int s = Integer.parseInt(st.nextToken());
    
    // find
    if (s>9*m || (s==0 && m>1)) out.println("-1 -1");
    else if (s==0 && m==1) out.println("0 0");
    else {
      String min = "";
      
      // find min
      int l = m;
      int ss = s;
      if (s<9*(l-1)) {
        min+="1";
        l-=1;
        s-=1;
        while (s<9*(l-1)) {
          min+="0";
          l-=1;
        }
      }
      if (s==9*l) l+=1;
      else if (l!=-1) min+=s%9;
      for (int i=0;i<l-1;i++) min+="9";
      out.print(min+" ");
      
      // find max
      min = "";
      l = m;
      s = ss;
      if (s<9*(l-1)) {
        while (s<9*(l-1)) {
          min+="0";
          l-=1;
        }
      }
      if (s==9*l) l+=1;
      else if (l!=-1) min+=s%9;
      for (int i=0;i<l-1;i++) min+="9";
      out.println(new StringBuilder(min).reverse().toString());
    }
    
    // cleanup
    out.close();
    System.exit(0);
  }
}