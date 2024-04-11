import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc= new Scanner(System.in);
      String s = sc.next();
      int n =sc.nextInt();
      String [] bayus = new String[n];
      for (int i=0;i<n;i++) bayus[i] = sc.next();
      int pos=-1;
      Arrays.sort(bayus);
      for (int i=0;i<n;i++){
         if(bayus[i].length() >= s.length() && bayus[i].substring(0,s.length()).equals(s)) {
            pos=i;
            break;
         }
         
      }
      if(pos>-1) System.out.println(bayus[pos]);
      else System.out.println(s);

   }
}