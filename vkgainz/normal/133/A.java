import java.util.*;

public class soos{
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  String s = sc.next();
  int count =0;
  for (int i=0;i<s.length();i++){
   if (s.charAt(i) == 'H' || s.charAt(i) == 'Q' || s.charAt(i) == '9'){
    count++;
   }
  }
  if (count >=1){
   System.out.println("YES");
  }
  else {
   System.out.println("NO");
  }
  
 }
}