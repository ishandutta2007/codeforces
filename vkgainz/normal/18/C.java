import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int [] bayus= new int[n];
      int sum=0;
      for (int i=0;i<n;i++){
      bayus[i] = sc.nextInt();
      sum+=bayus[i];
      }
      int count=0;
      int sumLeft=0;
      for (int i=0;i<n-1;i++){
       sumLeft+=bayus[i];
       if(sumLeft==sum-sumLeft) count++;
      }
      System.out.println(count);
         
   }
}