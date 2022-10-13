import java.util.*;
public class susbus{
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  //order = chest biceps back
  int n = sc.nextInt();
  int [] exercise = new int[n];
  for (int i=0;i<n;i++){
   exercise[i] = sc.nextInt();
  }
  int chest = 0;
  for (int i=0;i<n;i+=3){
   chest+=exercise[i];
  }
  int biceps = 0;
  for (int i=1;i<n;i+=3){
   biceps+=exercise[i];
  }
  int back = 0;
  for (int i=2;i<n;i+=3){
   back+=exercise[i];
  }
  
  int max1 = Math.max(biceps,chest);
  int max2 = Math.max(back,max1);
  if (max2==biceps){
   System.out.println("biceps");
  }
  else if (max2 == chest){
   System.out.println("chest");
   
  }
  else{
   System.out.println("back");
  }
 }
}