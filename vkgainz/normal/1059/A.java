import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int l = sc.nextInt();
      int a = sc.nextInt();
      int [][] bayus = new int[n][2];
      for (int i=0;i<n;i++){
         bayus[i][0] = sc.nextInt();
         bayus[i][1]=sc.nextInt();
      }
      if(n>0){
      int count=0;
      count+=findMul(bayus[0][0],a);
      for (int i=0;i<n-1;i++){
         count+=findMul(bayus[i+1][0]-(bayus[i][1]+bayus[i][0]),a);
      }
      count+=findMul(l-(bayus[n-1][1]+bayus[n-1][0]),a);
      System.out.println(count);
   }
   else System.out.println(l/a);
   }
   public static int findMul(int n,int a){
      return (n/a);
      
   }
}