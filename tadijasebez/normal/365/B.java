import java.util.*;
import java.io.*;

public class Main
{
      public static void main(String[] args)
      {
            Scanner sc=new Scanner(System.in);
            int n=sc.nextInt(),sol=0;
            
            int[] a=new int[n];
            int[] pre=new int[n];
            
            for(int i=0;i<n;i++) a[i]=sc.nextInt();
            for(int i=2;i<n;i++)
            {
                  pre[i]=pre[i-1]+1;
                  if(a[i]!=a[i-1]+a[i-2]) pre[i]=0;
                  sol=Math.max(sol,pre[i]);
            }
            
            System.out.println(Math.min(sol+2,n));
      }
}