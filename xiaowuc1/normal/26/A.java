import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
public class A {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int num = 0;
		for(int i = 1; i <= n; i++)
			if(almostprime(i))
				num++;
		System.out.println(num);
	}
	public static boolean almostprime(int x)	{
		int n = 0;
		for(int d = 2; d <= x; d++)	{
			if(prime(d) && x%d==0)
				n++;
		}
		return n == 2;
	}
	public static boolean prime(int x)	{
		if(x == 1)
			return false;
		if(x == 2)
			return true;
		if(x%2==0)
			return false;
		for(int d = 3; d <= Math.sqrt(x); d+=2)	{
			if(x%d==0)
				return false;
		}
		return true;
	}
}