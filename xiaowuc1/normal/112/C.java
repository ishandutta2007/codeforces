import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		long x = Long.parseLong(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		
		int first = n-1;
		long second = y-(n-1);
		if(second <= 0)	{
			System.out.println(-1);
			return;
		}
		long prod = second*second + first;
		if(prod >= x)	{
			for(int i = 1; i <= n-1; i++)
				System.out.println(1);
			System.out.println(second);
		}
		else	{
			System.out.println(-1);
		}
	}
}