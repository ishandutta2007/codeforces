import java.util.*;
public class susbus{
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  int n = sc.nextInt();
  int[] bayus = new int[n];
  for (int i=0;i<n;i++)
  bayus[i]=sc.nextInt();
  int min=bayus[0];
  int max=0;
  for(int i=0;i<n;i++){
   if(bayus[i] <min) min=bayus[i];
   if(bayus[i]>max) max=bayus[i];
  }
  if(min!=max) System.out.println(n-numCounter(min,bayus)-numCounter(max,bayus));
  else System.out.println(n-numCounter(min,bayus));
 }
 public static int numCounter(int n,int[] nums){
  int count=0;
  for (int i=0;i<nums.length;i++)
   if(nums[i]==n) count++;
  return count;
 }
}