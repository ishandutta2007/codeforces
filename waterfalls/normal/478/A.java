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
    int total = 0;
    for (int i=0;i<5;i++) total+=Integer.parseInt(st.nextToken());
    
    // write to out
    if (total%5!=0 || total==0) out.println(-1);
    else out.println(total/5);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}