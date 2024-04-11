import java.util.*;

public class susbus{
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  int d1 = sc.nextInt();
  int d2 = sc.nextInt();
  int d3 = sc.nextInt();
  int min = Math.min(2*(d1+d2),d1+d2+d3);
  int min2 = Math.min(2*(d2+d3),min);
  int min3 = Math.min(2*(d1+d3), min2);
  System.out.println(min3);
 }
}