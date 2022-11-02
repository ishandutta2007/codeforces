import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in a
    BigInteger a = new BigInteger(f.readLine());
    
    // solve
    BigInteger l = a.subtract((BigInteger.TEN.pow(19).multiply(new BigInteger("900"))).mod(a));
    BigInteger r = l.add(BigInteger.TEN.pow(20).subtract(BigInteger.ONE));

    // write to out
    out.println(l.toString()+" "+r.toString());
    
    // cleanup
    out.close();
    System.exit(0);
  }
}