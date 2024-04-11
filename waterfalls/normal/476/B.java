import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in 
    char[] sent = f.readLine().toCharArray();
    char[] received = f.readLine().toCharArray();
    
    // find final poss
    int posS = 0;
    for (char c: sent) if (c=='+') posS+=1; else posS-=1;
    int posR = 0;
    int huh = 0;
    for (char c: received) if (c=='+') posR+=1; else if (c=='-') posR-=1; else huh+=1;
    
    // solve
    if (Math.abs(posS-posR)>huh || (Math.abs(posS-posR)-huh)%2==1) out.println(0);
    else out.println((double) 1.0*fact(huh)/fact((huh+Math.abs(posS-posR))/2)/fact((huh-Math.abs(posS-posR))/2)/Math.pow(2,huh));
    
    // cleanup
    out.close();
    System.exit(0);
  }
  
  // factorial
  static int fact(int n) {
    if (n==0) return 1;
    return n*fact(n-1);
  }
}