import java.util.*;
import java.io.*;

public class String_Game
{
      public static void main(String[] args)
      {
            Scanner sc=new Scanner(System.in);
            String s=sc.next(),t=sc.next();
            int n=s.length(),m=t.length();
            int[] a=new int[n];
            int[] tme=new int[n];
            for(int i=0;i<n;i++)
            {
                  a[i]=sc.nextInt()-1;
                  tme[a[i]]=i;
            }
            int top=n,bot=1,mid,ans=0;
            while(top>=bot)
            {
                  mid=top+bot>>1;
                  int j=0;
                  for(int i=0;i<n;i++)
                  {
                        if(tme[i]<mid) continue;
                        if(j<m && s.charAt(i)==t.charAt(j)) j++;
                  }
                  if(j==m)
                  {
                        bot=mid+1;
                        ans=mid;
                  }
                  else top=mid-1;
            }
            System.out.println(ans);
      }
}