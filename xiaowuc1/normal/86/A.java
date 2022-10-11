import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class AMain {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int min = Integer.parseInt(st.nextToken());
		int max = Integer.parseInt(st.nextToken());
		int len = Integer.toString(max).length();
		if(Integer.toString(min).length() != len)		{
			min = (int)Math.pow(10, len-1);
		}
		while(min + 100 < max)	{
			int a = (int)((2L*min+max)/3);
			int b = (int)((2L*max+min)/3);
			if(gen(a) < gen(b))	{
				min = a;
			}
			else	{
				max = b;
			}
		}
		int best = min;
		for(int i = min+1; i <= max; i++)	{
			if(gen(i) > gen(best))
				best = i;
		}
		System.out.println(gen(best));
		// 10^len
		// 10^(len+1)-1
		// min
		// max
		// 4999999
		// 5000000
	}
	public static long gen(int x)	{
		int length = Integer.toString(x).length();
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < length; i++)
			sb.append(9);
		long y = Long.parseLong(sb.toString())-x;
		return 1L*x*y;
	}
}