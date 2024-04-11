import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
public class C {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		int f = gcd(c,d);
		c /= f;
		d /= f;
		int x = a/c;
		int y = b/d;
		int min = Math.min(x,y);
		if(min == 0)	{
			System.out.println("0 0");
			return;
		}
		System.out.println(c*min + " " + d*min);
	}
	public static int gcd(int a, int b)		{
		return a%b == 0 ? b : gcd(b,a%b);
	}
}