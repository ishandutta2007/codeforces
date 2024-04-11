import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
public class A {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int max = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		for(int i = 2; i <= max; i++)	{
			if(isPrime(i))	{
				for(int j = i+1; j <= max; j++)	{
					if(!isPrime(j))
						continue;
					if(isPrime(i+j+1) && i+j+1 <= max)	{
						k--;
					}
					else if(isPrime(i+j) && i+j <= max)
						k--;
					break;
				}
			}
		}
		System.out.println(k <= 0 ? "YES" : "NO");
	}
	public static boolean isPrime(int x)	{
		if(x==2)
			return true;
		if(x%2==0)
			return false;
		for(int d = 3; d*d<=x; d += 2)
			if(x%d==0)
				return false;
		return true;
	}
}