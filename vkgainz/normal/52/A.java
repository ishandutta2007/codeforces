import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int [] bayus = new int[n];
      for (int i=0;i<n;i++) bayus[i] = sc.nextInt();
      
      int one = numOccur(1,bayus);
      int two = numOccur(2,bayus);
      int three = numOccur(3,bayus);
      int max1 = Math.max(one,two);
      int max2 = Math.max(max1,three);
      System.out.println(n-max2);
      
      
   }
   public static int numOccur(int n, int[] bayus){
      int count=0;
      for (int i=0;i<bayus.length;i++){
         if(bayus[i] == n) count++;
      }
      return count;
   }
}