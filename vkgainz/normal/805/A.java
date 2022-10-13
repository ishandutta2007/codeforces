import java.util.*;
public class susbus{
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  long l = sc.nextInt();
  long r = sc.nextInt();
  if(l==r && l%2==1) System.out.println(l);
  else System.out.println(2);
 }
}