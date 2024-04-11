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
    int a = Integer.parseInt(st.nextToken());
    int b = Integer.parseInt(st.nextToken());
    
    // add
    long mod = 1000000007;
    long sums = (((((long) (b-1))*b/2)%mod)*(b+1))%mod;
    long terms = (((((long) b)*(b-1)/2)%mod)*b)%mod;
    long ks = ((((long) a)*(a-1))/2)%mod;
    long sum = (((sums*a)%mod)+(ks*terms))%mod;

    // write to out
    out.println(sum);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}