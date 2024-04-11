import java.io.*;
import java.util.*;
public class B20 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		long a = Integer.parseInt(st.nextToken());
		long b = Integer.parseInt(st.nextToken());
		long c = Integer.parseInt(st.nextToken());
		if(a==0)		{
			if(b==0)		{
				if(c==0)		{
					System.out.println(-1);
					return;
				}
				System.out.println(0);
				return;
			}
			System.out.println(1);
			System.out.println(1.0*-c/b);
			return;
		}
		long d = b*b-4*a*c;
		if(d < 0)	{
			System.out.println(0);
			return;
		}
		if(d == 0)		{
			System.out.println(1);
			System.out.println(-b/2./a);
			return;
		}
		System.out.println(2);
		if(a > 0)	{
			System.out.println((-b-Math.sqrt(d))/(2*a));
			System.out.println((-b+Math.sqrt(d))/(2*a));
		}
		else	{
			System.out.println((-b+Math.sqrt(d))/(2*a));
			System.out.println((-b-Math.sqrt(d))/(2*a));
		}
	}
}