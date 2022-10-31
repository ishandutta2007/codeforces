import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,p,s
    StringTokenizer st = new StringTokenizer(f.readLine());
    int n = Integer.parseInt(st.nextToken());
    int p = Integer.parseInt(st.nextToken());
    String s = f.readLine();
    
    // palindromes are either 2-length or 3-length
    // find first index changeable
    boolean found = false;
    int index;
    int c = 'a';
    loop:
    for (index=n-1;index>=0;index--) {
      for (c=((int) s.charAt(index))+1;c<97+p;c++) {
        // 2-length to left
        if (index>0 && ((char) c)==s.charAt(index-1)) continue;
        
        // 3-length to left
        if (index>1 && ((char) c)==s.charAt(index-2)) continue;
        
        found = true;
        break loop;
      }
    }
      
    // make rest of string
    String r = "";
    if (found) {
      r = s.substring(0,index)+(char) c;
      loop:
      for (index = index;index<s.length()-1;index++) {
        for (int next=97;next<97+p;next++) {
          // 2-length to left
          if (((char) next)==r.charAt(index)) continue;
          
          // 3-length to left
          if (index>0 && ((char) next)==r.charAt(index-1)) continue;
          
          r+=((char) next);
          continue loop;
        }
      }
    }
    
    // write to out
    if (found) out.println(r); 
    else out.println("NO");
      
    // cleanup
    out.close();
    System.exit(0);
  }
}