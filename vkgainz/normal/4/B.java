import java.util.*;
public class susbus{
   public static void main(String[] args) {
      Scanner sc =new Scanner(System.in);
      int n = sc.nextInt();
      int maxHours=sc.nextInt();
      int lowerBound=0;
      int upperBound=0;
      int [][] hours = new int[n][2];
      for(int i=0;i<n;i++){
         hours[i][0]=sc.nextInt();
         lowerBound+=hours[i][0];
         hours[i][1]=sc.nextInt();
         upperBound+=hours[i][1];
      }
      if(lowerBound > maxHours || upperBound<maxHours) {
         System.out.println("NO");
         return;
      }
      System.out.println("YES");
      int [] pointers = new int[n];
      int targetSum=0;
      for(int i=0;i<n;i++){
         pointers[i] = hours[i][0];
         targetSum+=pointers[i];
      }
      int currPointer = 0;
      while(targetSum != maxHours) {
         while(pointers[currPointer]<hours[currPointer][1]) {
            pointers[currPointer]++;
            targetSum++;
            if(targetSum==maxHours) {
               break;
            }
         }
         currPointer++;
      }
      for(int i=0;i<n;i++){
         System.out.println(pointers[i]);
      }
      
      
   }
}