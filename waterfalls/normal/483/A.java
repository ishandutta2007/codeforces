import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in 
    StringTokenizer st = new StringTokenizer(f.readLine());
    BigInteger l = new BigInteger(st.nextToken());
    BigInteger r = new BigInteger(st.nextToken());
    
    // write
    if (r.subtract(l).intValue()<2 || (r.subtract(l).intValue()==2 && r.mod(new BigInteger("2")).intValue()==1)) out.println(-1);
    else out.println(l.add(l.mod(new BigInteger("2"))).toString()+" "+l.add(l.mod(new BigInteger("2"))).add(new BigInteger("1")).toString()+" "+l.add(l.mod(new BigInteger("2"))).add(new BigInteger("2")).toString());
    
    // cleanup
    out.close();
    System.exit(0);
  }
}