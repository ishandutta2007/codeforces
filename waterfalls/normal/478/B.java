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
    long n = Long.parseLong(st.nextToken());
    long m = Long.parseLong(st.nextToken());
    
    // write to out
    out.println(((n%m)*(n/m)*(n/m+1)/2+(m-n%m)*(n/m)*(n/m-1)/2)+" "+((n-m+1)*(n-m)/2));
    
    // cleanup
    out.close();
    System.exit(0);
  }
}