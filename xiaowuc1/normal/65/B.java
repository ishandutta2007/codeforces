import java.io.*;
public class B65 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] list = new int[n];
		for(int i = 0; i < n; i++)
			list[i] = Integer.parseInt(br.readLine());
		int[] ret = new int[n];
		int k = 0;
		for(int year = 1000; year <= 2011 && k < n; year++)		{
			if(match(year, list[k]))
				ret[k++] = year--;
		}
		if(k != n)
			System.out.println("No solution");
		else
			for(int x: ret)
				System.out.println(x);
	}
	public static boolean match(int a, int b)	{
		int ret = 0;
		while(a > 0)		{
			if(a%10 != b%10)
				ret++;
			a/=10;
			b/=10;
		}
		return ret <= 1;
	}
}