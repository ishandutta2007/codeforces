import java.util.*;

public class twins{
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  int n = sc.nextInt();
  int [] coins = new int[n];
  for (int i=0;i<n;i++){
   coins[i] = sc.nextInt();
  }
  // sorts coins by increasing order
  Arrays.sort(coins);
  //find sum that you want
  int sum=0;
  for (int i=0;i<n;i++){
   sum=sum+coins[i];
  }
  long want = sum/2;
  int desire = 0;
  int count=0;
  for (int i=0;i<n;i++){
   desire+=coins[n-i-1];
   count++;
   if (desire >want){
    break;
   }
  }
  System.out.print(count);
 }
}