import java.util.*;

public class susbus{
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  int n = sc.nextInt();
  String s = sc.next();
  int count=0;
  int remove=0;
  
  for (int i=0;i<s.length();i++){
   if (s.charAt(i) == 'x'){
    count++;
    if(count>2){
     remove++;
    }
   }
   else{
    count=0;
   }
  }
  System.out.println(remove);
 }
 
 
}