import java.util.*;

public class theatresquare{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    long m = sc.nextInt();
    long n = sc.nextInt();
    long a = sc.nextInt();
    long x = (m-1)/a+1;
    long y = (n-1)/a+1;
    System.out.println(x*y);
  }
}