import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,cell
    int n = Integer.parseInt(f.readLine());
    String cell = f.readLine();
    int count = 0;
    for (int i=0;i<n;i++) {
      if (cell.charAt(i)=='1') count+=1;
      else break;
    }

    // write to out
    out.println(Math.min(count+1,n));
    
    // cleanup
    out.close();
    System.exit(0);
  }
}