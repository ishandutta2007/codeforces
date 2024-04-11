import java.util.*;

public class Heist{
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  int n = sc.nextInt();
  int [] keyboards = new int[n];
  for (int i=0;i<n;i++){
   keyboards[i] = sc.nextInt();
  }
  // determine maximum
  int max = keyboards[0];
  for (int i=0;i<n;i++){
   if (keyboards[i] > max){
    max = keyboards[i];
   }
  }
  // determine minimum
  int min = keyboards[0];
  for (int i=0;i<n;i++){
   if (keyboards[i]<min){
    min=keyboards[i];
   }
  }
  System.out.print(max-min-(n-1));
 }
}