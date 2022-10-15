import java.io.*;
import java.util.*;
public class Main
{
	public static void main (String[] args) throws IOException
	{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine().trim());
        for(int t0=1;t0<=t;t0++)
        {
            /*int n=Integer.parseInt(br.readLine().trim());
            String s1[]=br.readLine().trim().split(" ");*/
            String s=br.readLine().trim();
            int n=s.length();
            int a[]=new int[26];
            String b="";
            String c="";
            for(int i=0;i<n;i++)
                a[(int)s.charAt(i)-97]++;
            int f=0,k=0,l=0;
            if(n==1)
            {
                System.out.println(s);
                continue;
            }
            for(int i=0;i<26;i+=2)
            {
                while(a[i]>0)
                {
                    b+=(char)(i+97);
                    k++;
                    a[i]--;
                }
            }
            for(int i=1;i<26;i+=2)
            {
                while(a[i]>0)
                {
                    c+=(char)(i+97);
                    l++;
                    a[i]--;
                }
            }
            if(l>0&&k>0&&(int)Math.abs(b.charAt(k-1)-c.charAt(0))==1)
                c=c+b;
            else
                c=b+c;
            for(int i=0;i<n-1;i++)
                if((int)Math.abs(c.charAt(i)-c.charAt(i+1))==1)
                    f=1;
            if(f==0)
                System.out.println(c);
		    else
		        System.out.println("No answer");
    		//System.out.println("Case #"+t0+": "+x1+" "+y1);
        }
	}	
}