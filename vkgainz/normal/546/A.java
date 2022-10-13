import java.util.*;

public class SoldierAndBananas{
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  int n = sc.nextInt();
  int w = sc.nextInt();
  int k = sc.nextInt();
  if (w>n*k*(k+1)/2){
   System.out.println(0);
  }
  else{
   System.out.println(n*k*(k+1)/2-w);
  }
 }
}