import java.util.*;

public class susbus{
 public static void main(String[] args0){
  Scanner sc = new Scanner(System.in);
  int a = sc.nextInt();
  int b = sc.nextInt();
  int c = sc.nextInt();
  int min = Math.min(a,b/2);
  int min2 = Math.min(min,c/4);
  System.out.println(7*min2);
 }
}