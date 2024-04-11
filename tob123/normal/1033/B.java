import java.util.*;
import java.math.*;

public class B{
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for(int t=0; t<T; t++){
      BigInteger a = in.nextBigInteger(), b = in.nextBigInteger();
      BigInteger res = a.multiply(a).subtract(b.multiply(b));
      //System.out.println(res);
      if(res.isProbablePrime(1000000)){
        System.out.println("YES");
      }
      else{
        System.out.println("NO");
      }
    }
  }
}