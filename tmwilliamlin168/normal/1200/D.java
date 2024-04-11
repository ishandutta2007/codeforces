import java.util.*;
import java.io.*;
public class A
{
      public static void main(String ar[]) throws Exception
      {
            BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
            String s1[]=br.readLine().split(" ");
            int n=Integer.parseInt(s1[0]);
            int k=Integer.parseInt(s1[1]);
            
            char c[][]=new char[n][n];
            for(int i=0;i<n;i++)
             c[i]=br.readLine().toCharArray();
            
            int p[][]=new int[n][2];
            int q[][]=new int[n][2];
            int a[][]=new int[n][n];
            int b[][]=new int[n][n];
            for(int i=0;i<n;i++)
            {
                q[i][0]=Integer.MAX_VALUE;
                q[i][1]=Integer.MIN_VALUE;
            }
            
            for(int j=0;j<n;j++)
            {
                  p[j][0]=Integer.MAX_VALUE;
                  p[j][1]=Integer.MIN_VALUE;
            }
            int S=0;
            for(int j=0;j<n;j++)
            {
                  for(int i=0;i<n;i++)
                  {
                        if(c[i][j]=='B')
                        {
                         p[j][0]=Math.min(p[j][0],i);
                         p[j][1]=Math.max(p[j][1],i);
                        }
                  }
            }
            
            for(int i=0;i<n;i++)
            {
                  for(int j=0;j<n;j++)
                  {
                        if(c[i][j]=='B')
                        {
                         q[i][0]=Math.min(q[i][0],j);
                         q[i][1]=Math.max(q[i][1],j);
                        }
                  }
            }
            
            for(int i=0;i<n;i++)
            {
                  if(q[i][0]==Integer.MAX_VALUE)
                   S++;
            }
            
            for(int j=0;j<n;j++)
            {
                  if(p[j][0]==Integer.MAX_VALUE)
                   S++;
            }
            
            for(int j=0;j<n;j++)
            {
                  for(int i=0;i<n;i++)
                  {
                        if(!(p[j][0]==Integer.MAX_VALUE) && i<=p[j][0] && p[j][1]<=i+k-1)
                         a[i][j]=1;
                  }
                 // System.out.println(ts[j]);
            }
            
            //System.out.println();
            for(int i=0;i<n;i++)
            {
                  for(int j=0;j<n;j++)
                  {
                        if(!(q[i][0]==Integer.MAX_VALUE) && j<=q[i][0] && q[i][1]<=j+k-1)
                         b[i][j]=1;
                  }
                 // System.out.println(ts1[i]);
            }
            
            int cc[][]=new int[n][n];
            int d[][]=new int[n][n];
            for(int i=0;i<n;i++)
            {
                  for(int j=n-1;j>=0;j--)
                   cc[i][j]=a[i][j];
                  for(int j=n-2;j>=0;j--)
                   a[i][j]+=a[i][j+1];
                  for(int j=n-2;j>=n-k;j--)
                  {
                        cc[i][j]=a[i][j];
                  }
                  
                  for(int j=n-k-1;j>=0;j--)
                  {
                        cc[i][j]=a[i][j]-a[i][j+k];
                  }
            }
            
            for(int j=0;j<n;j++)
            {
                  for(int i=n-1;i>=0;i--)
                   d[i][j]=b[i][j];
                  for(int i=n-2;i>=0;i--)
                   b[i][j]+=b[i+1][j];
                  for(int i=n-2;i>=n-k;i--)
                  {
                    d[i][j]=b[i][j];
                    
                  }
                  
                  for(int i=n-k-1;i>=0;i--)
                  {
                        d[i][j]=b[i][j]-b[i+k][j];
                  }
            }
            
            int max=0;
            
      /*      for(int i=0;i<n;i++)
             System.out.println(Arrays.toString(cc[i]));
            System.out.println();
            for(int i=0;i<n;i++)
             System.out.println(Arrays.toString(d[i]));     */
            
            for(int i=0;i+k-1<n;i++)
            {
                  for(int j=0;j+k-1<n;j++)
                  {
                        max=Math.max(max,S+cc[i][j]+d[i][j]);
                  }
            }
            
            System.out.println(max);
      }
}