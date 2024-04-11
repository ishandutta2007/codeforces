import java.util.*;
import java.math.*;

public class Main{
  static long N, H;
  static BigInteger NB, TWO;

  static BigInteger sumUp(long x){
    BigInteger X = new BigInteger("" + x);
    return X.multiply(X.add(BigInteger.ONE)).divide(TWO);
  }

  static boolean pos(long r){
    BigInteger maximum;
    if(H >= r){
      maximum = sumUp(r);
    }
    else{
      BigInteger h = new BigInteger("" + ((r+H)/2));
      maximum = TWO.multiply(sumUp(h.longValueExact())).subtract(sumUp(H-1));
      if((r+H)%2 == 0){
        maximum = maximum.subtract(h);
      }
    }
    return maximum.compareTo(NB) >= 0;
  }

  public static void main(String[] args){
    Scanner s = new Scanner(System.in);
    N = s.nextLong();
    H = s.nextLong();
    NB = new BigInteger("" + N);
    TWO = BigInteger.ONE.add(BigInteger.ONE);

    long l=1, r=N+1;
    while(l != r){
      long m = (l+r)/2;
      if(pos(m)){
        r = m;
      }
      else{
        l = m+1;
      }
    }

    System.out.println(l);
  }
}