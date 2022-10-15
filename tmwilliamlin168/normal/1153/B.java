import java.util.Scanner;
import java.util.*;
import java.lang.*; 
import java.util.regex.Pattern;
import java.text.DecimalFormat;
import java.util.stream.IntStream;
public class Main{    
public static void main(String[] args)
{     
Scanner scanner=new Scanner(System.in);
int n=scanner.nextInt();
int m=scanner.nextInt();
int h=scanner.nextInt();
int[] a=new int[m];
int[] b=new int[n];
int[][] x=new int[n][m];
for(int i=0;i<m;i++)
  a[i]=scanner.nextInt();
for(int i=0;i<n;i++)
  b[i]=scanner.nextInt();
for(int i=0;i<n;i++)
{
  for(int j=0;j<m;j++)
  {
    x[i][j]=scanner.nextInt();
    if(x[i][j]==1){
      if(a[j]<b[i])x[i][j]=a[j];
      else x[i][j]=b[i];
    }
  }
}
for(int i=0;i<n;i++)
{
  for(int j=0;j<m;j++)
  {
    System.out.printf("%d ",x[i][j]);
  }
  System.out.print("\n");
}
}
}