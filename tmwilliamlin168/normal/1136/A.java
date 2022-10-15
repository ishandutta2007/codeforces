import java.util.*;
import java.lang.*;

public class Nastya_book
{
	public static void main(String []args)
	{
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[][]=new int[n][2];
		for(int i=0;i<n;i++)
		{
			a[i][0]=sc.nextInt();
			a[i][1]=sc.nextInt();
		}
		int k=sc.nextInt();
		int c=n;
		for(int i=0;i<n;i++)
		{
			if(k>=a[i][0] && k<=a[i][1])
			{
				break;
			}
			c--;
		}
		System.out.println(c);
	}
}