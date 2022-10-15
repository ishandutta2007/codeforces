import java.util.*;
import java.lang.*;
import java.io.*;

public class Main
{
	
	static long gcd(long a, long b)
	{
		if(b == 0)
			return a;
		
		return gcd(b, a % b);
	}
	
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner e = new Scanner(System.in);
		
		long[] x = new long[300100];
		long[] p = new long[300100];
		
		int n = e.nextInt();
		int m = e.nextInt();
		
		for(int i = 1; i <= n; i++)
			x[i] = e.nextLong();
		
		for(int j = 1; j <= m; j++)
			p[j] = e.nextLong();
			
		if(n == 1)
		{
			System.out.println("YES");
			System.out.println(x[1] + " 1");
			return;
		}
		
		long _gcd = x[2] - x[1];
		for(int i = 3; i <= n; i++)
			_gcd = gcd(_gcd, x[i] - x[i - 1]);
		
		for(int j = 1; j <= m; j++)
		{
			if(_gcd % p[j] == 0)
			{
				System.out.println("YES");
				System.out.println(x[1] + " " + j);
				return;
			}
		}
		
		System.out.println("NO");
	}
}