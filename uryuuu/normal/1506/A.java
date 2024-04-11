import java.util.*;
import java.sql.*;
import java.time.*;
import java.math.*;

public class Main
{
	public static void main(String args[]) 
	{
		Scanner cin=new Scanner(System.in);

		int t=cin.nextInt();
		while((t--)!=0)
		{
			long n,m,x;
			n=cin.nextLong();
			m=cin.nextLong();
			x=cin.nextLong();
			long r,c;
			r=(x-1l)/n+1l;
			c=(x-1l)%n+1l;
			long ans=(c-1l)*m+r;
			System.out.println(ans);
		}
		
	}
}