import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in 
    int a = Integer.parseInt(f.readLine());
    int b = Integer.parseInt(f.readLine());
    int c = Integer.parseInt(f.readLine());
    
    // find max
    int max = 0;
    max = Math.max(max,a+b+c);
    max = Math.max(max,a*b+c);
    max = Math.max(max,a+b*c);
    max = Math.max(max,(a+b)*c);
    max = Math.max(max,a*(b+c));
    max = Math.max(max,a*b*c);

    // write to out
    out.println(max);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}