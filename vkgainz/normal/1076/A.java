import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      String s =sc.next();
      int index=n-1;
     for(int i=0;i<n-1;i++){
        if(s.substring(i,i+1).compareTo(s.substring(i+1,i+2))>0) {
        index=i;
        break;
        }
     }
      
      String result ="";
     
      // System.out.println(index);
      System.out.println(s.substring(0,index)+s.substring(index+1));
   }
}