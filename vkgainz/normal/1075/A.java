import java.util.*;

public class susbus{
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  long n = sc.nextLong();
  long x = sc.nextLong();
  long y= sc.nextLong();
  long w = Math.max(x-1,y-1);
  long b = Math.max(Math.abs(x-n),Math.abs(y-n));
  if(w<=b)
  System.out.println("White");
  else
  System.out.println("Black");
 }
}