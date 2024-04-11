import java.util.*;
public class susbus{
   public static boolean containsSame(String [] s){
      for(int i=0;i<s.length;i++){
         for(int j=0;j<s[i].length();j++) {
            if(s[i].charAt(j) != s[i].charAt(0)) return false;
         }
      }
      return true;
   }
   public static boolean horizontal(String [] s){
      for(int i=1;i<s.length-1;i++){
         if(s[i].charAt(0)==s[i-1].charAt(0) || s[i].charAt(0) == s[i+1].charAt(0)) return false;
         
      }
      return true;
   }
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int m=  sc.nextInt();
      String [] s = new String[n];
      for(int i=0;i<n;i++) s[i]=sc.next();
      if(containsSame(s) && horizontal(s)) System.out.println("YES");
      else System.out.println("NO");
   }
}