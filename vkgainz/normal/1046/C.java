import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int k = sc.nextInt();
      int [] players = new int[n];
      int [] points = new int[n];
      for(int i=0;i<n;i++){
         players[i] = sc.nextInt();
         
      }
      for(int i=0;i<n;i++){
         points[i] = sc.nextInt();
      }
      int compare = players[k-1]+points[0];
      players[k-1] =0;
      Arrays.sort(players);
      int pointIndex = 1;
      int playerIndex = 1;
      int count =0;
      while(pointIndex<n){
         if(players[playerIndex]+points[pointIndex]<=compare){
            count++;
            playerIndex++;
            
         }
         
         pointIndex++;
      }
      System.out.println(n-count);
   }
}