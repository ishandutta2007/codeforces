import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      String s1 = sc.next();
      String s2 = sc.next();
      int numplus = numCounter(s1,'+')-numCounter(s2,'+');
      int numminus = numCounter(s1,'-')-numCounter(s2,'-');
      int numquestion = s2.length()-numCounter(s2,'+')-numCounter(s2,'-');
      if(numplus >=0 && numminus >=0){
         int nub = factorial(numplus+numminus);
         int noob = factorial(numplus)*factorial(numminus);
         double prob = nub*1.0/noob;
         System.out.println(prob/Math.pow(2,numplus+numminus));
      }
      else {
         System.out.println(0);
      }
      
   }
   public static int numCounter(String s, char let){
      int count=0;
      for (int i=0;i<s.length();i++){
         if(s.charAt(i) == let) count++;
      }
      return count;
   }
   public static int factorial(int n){
      if(n==0) return 1;
      else return n*factorial(n-1);
   }
}