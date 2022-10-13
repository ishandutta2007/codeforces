import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int [] bayus = new int[4];
      for (int i=0;i<4;i++) {
         bayus[i] = sc.nextInt();
      }
      Arrays.sort(bayus);
      if(bayus[0]+bayus[1]>bayus[2] || bayus[1]+bayus[2]>bayus[3]){
         System.out.println("TRIANGLE");
      }
      else if(bayus[0]+bayus[1]<bayus[2] && bayus[1]+bayus[2]<bayus[3]){
         System.out.println("IMPOSSIBLE");
      }
      else System.out.println("SEGMENT");
   }
}