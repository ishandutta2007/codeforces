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
    int a1 = Integer.parseInt(st.nextToken());
    int b1 = Integer.parseInt(st.nextToken());
    st = new StringTokenizer(f.readLine());
    int a2 = Integer.parseInt(st.nextToken());
    int b2 = Integer.parseInt(st.nextToken());
    
    // try each number of 2/3's
    long size1 = (long) a1*b1;
    long size2 = (long) a2*b2;
    int min = Integer.MAX_VALUE;
    int best1 = 0;
    int best2 = 0;
    int count1 = 0;
    int count2 = 0;
    while (true) {
      long tsize1 = size1;
      count1 = 0;
      while (true) {
        long size = gcd(tsize1,size2);
        int twos = 0;
        long factor1 = tsize1/size;
        long factor2 = size2/size;
        if ((factor1&(factor1-1))==0 && (factor2&(factor2-1))==0) {
          twos = (int) Math.round(Math.log(factor1)/Math.log(2)+Math.log(factor2)/Math.log(2));
          if (min>count1+count2+twos) {
            min = count1+count2+twos;
            best1 = count1;
            best2 = count2;
          }
        }
        if (tsize1%3!=0) break;
        tsize1 = tsize1*2/3;
        count1+=1;
      }
      if (size2%3!=0) break;
      size2 = size2*2/3;
      count2+=1;
    }
    
    // print
    if (min==Integer.MAX_VALUE) out.println(-1);
    else {
      out.println(min);
      for (int i=0;i<best1;i++) {
        if (a1%3==0) a1 = a1*2/3;
        else b1 = b1*2/3;
      }
      for (int i=0;i<best2;i++) {
        if (a2%3==0) a2 = a2*2/3;
        else b2 = b2*2/3;
      }
      int twos = min-best1-best2;
      if ((long) a1*b1>(long) a2*b2) {
        for (int i=0;i<twos;i++) {
          if (a1%2==0) a1/=2;
          else b1/=2;
        }
      } else {
        for (int i=0;i<twos;i++) {
          if (a2%2==0) a2/=2;
          else b2/=2;
        }
      }
      out.println(a1+" "+b1);
      out.println(a2+" "+b2);
    }
    
    // cleanup
    out.close();
    System.exit(0);
  }
  
  static long gcd(long a, long b) {
    if (a==0) return b;
    else if (b==0) return a;
    else if (a>b) return gcd(b,a%b);
    else return gcd(a,b%a);
  }
}