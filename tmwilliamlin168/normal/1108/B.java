import java.util.*;
import java.io.*;
import java.lang.*;
public class Solution1
{
	public static void main(String args[])
	{
		Scanner x= new Scanner(System.in);
		int n=x.nextInt(),c=0;
		int a[]= new int[n];
		for(int i=0;i<n;i++)
		{
			a[i]=x.nextInt();
		}
		Arrays.sort(a);
		for(int i=n-2;i>-1;i--)
		{
			if(a[n-1]==a[n-2])
			{
				c=a[n-2];
				break;
			}
			if(a[n-1]%a[i]==0 && a[i]==a[i-1])
			{
				c=a[i];
				break;
			}
			if(a[n-1]%a[i]!=0)
			{
				c=a[i];
				break;
			}
		}
		System.out.println(a[n-1]+" "+c);
	}
}