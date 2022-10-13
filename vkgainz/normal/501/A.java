import java.util.*;

public class susbus{
 public static void main(String[] args0){
  Scanner sc = new Scanner(System.in);
  int a = sc.nextInt();
  int b = sc.nextInt();
  int c = sc.nextInt();
  int d = sc.nextInt();
  int maxM = Math.max(3*a/10,a-a*c/250);
  int maxV = Math.max(3*b/10, b-b*d/250);
  if (maxM>maxV){
   System.out.println("Misha");
  }
  else if(maxM<maxV){
   System.out.println("Vasya");
  }
  else{
   System.out.println("Tie");
  }
  }

 }