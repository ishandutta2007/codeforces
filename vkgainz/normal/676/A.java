import java.util.*;
public class susbus{
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  int n = sc.nextInt();
  int[] richardpro=new int[n];
  for (int i=0;i<n;i++)
  richardpro[i]=sc.nextInt();
  int npos=locatePosition(n,richardpro);
  int opos=locatePosition(1,richardpro);
  int k1=Math.max(Math.abs(npos),Math.abs(npos-(n-1)));
  int k2=Math.max(k1,Math.abs(opos));
  int k3=Math.max(k2,Math.abs(opos-(n-1)));
  System.out.println(k3);
 }
 public static int locatePosition(int n,int[] nums){
  for (int i=0;i<nums.length;i++)
  if(nums[i]==n) return i;
  
  return -1;
 }
 
 
 
}