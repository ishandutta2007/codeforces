import java.util.*;
public class susbus{
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int k = sc.nextInt();
      int [] houses = new int[n];
      int max = 1;
      
      for(int i=0;i<n;i++){
         houses[i] = sc.nextInt();
      }
      int count = 1;
      for(int i=1;i<n;i++){
         
         if(houses[i] == houses[i-1]) {
         
            count=0;
         }
        count++;
       max = Math.max(max,count);
      }
      System.out.println(max);
   }
}