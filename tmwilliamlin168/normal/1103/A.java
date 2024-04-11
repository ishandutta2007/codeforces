import java.io.*;
import java.math.*;
import java.security.KeyStore.Entry;
import java.util.*;
public class my {
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);int ch=0,cv=0;
		String s=sc.nextLine();int n=s.length();
		for(int i=0;i<n;i++)
		{
			if(s.charAt(i)=='0' && cv==0)
			{
				cv=1;System.out.println("3 4");
			}
			else if(s.charAt(i)=='0' && cv==1)
			{
				cv=0;System.out.println("1 4");
			}
			else if(s.charAt(i)=='1' && ch==0)
			{
				ch=1;System.out.println("1 1");
			}
			else if(s.charAt(i)=='1' && ch==1)
			{
				ch=0;System.out.println("1 3");
			}
		}
	}
}