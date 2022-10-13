import java.util.*;

public class susbus{
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  int x = sc.nextInt();
  int y = sc.nextInt();
  int z = sc.nextInt();
  int t1 = sc.nextInt();
  int t2 = sc.nextInt();
  int t3 = sc.nextInt();
  if (t1*(Math.abs(y-x)) < t2*Math.abs(z-x)+t2*Math.abs(y-x)+3*t3){
   System.out.println("NO");
  }
  else{
   System.out.println("YES");
  }
  
 }
}