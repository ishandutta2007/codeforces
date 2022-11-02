import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in N
    int N = Integer.parseInt(f.readLine());
    
    // write to out
    if (N%2==0) out.println("4 "+(N-4));
    if (N%2==1) out.println("9 "+(N-9));
    
    // cleanup
    out.close();
    System.exit(0);
  }
}