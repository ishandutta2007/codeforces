import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int m = sc.nextInt();
      int [][] plants = new int[m][2];
      for (int i=0;i<m;i++){
         plants[i][0] = sc.nextInt();
         plants[i][1] = sc.nextInt();
      }
      boolean isOk = true;
      boolean continues = true;
      if(plants[0][0] != 1) {
         System.out.println(1);
         System.out.println(0);
         isOk=false;
         continues=false;
      }
      if(continues) {
         for (int i=0;i<m-1;i++){
            if(plants[i][1] < plants[i+1][0]-1) {
               System.out.println(plants[i][1]+1);
               System.out.println(0);
               isOk = false;
               continues=false;
               break;
            }
            else if(plants[i][1] >=plants[i+1][0]){
               System.out.println(plants[i+1][0]);
               System.out.println(numOccur(plants[i+1][0],plants));
               isOk=false;
               continues=false;
               break;
            }
         }
      }
      if(plants[m-1][1] < n && continues) {
         System.out.println(plants[m-1][1]+1);
         System.out.println(0);
         isOk = false;
      }
      
      if(isOk) System.out.println("OK");
   }
   public static int numOccur(int n, int[][] nums){
      int count=0;
      for (int i=0;i<nums.length;i++)
      if(nums[i][0] <= n&& nums[i][1] >=n) count++;
      return count;
   }
}