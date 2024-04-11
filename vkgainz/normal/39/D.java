import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int [][]bayus = new int[2][3];
      for (int r=0;r<2;r++){
         for (int l=0;l<3;l++) bayus[r][l]=sc.nextInt();
      }
      int count=0;
      for (int l=0;l<3;l++){
         if(bayus[0][l] != bayus[1][l]) count++;
      }
      if (count==3) System.out.println("NO");
      else System.out.println("YES");
   }
}