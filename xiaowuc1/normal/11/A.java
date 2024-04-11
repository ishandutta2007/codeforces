import java.io.*;
import java.util.*;
public class A11 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		long curr = Integer.parseInt(st.nextToken());
		long ret = 0;
		while(st.hasMoreTokens())		{
			long now = Long.parseLong(st.nextToken());
			if(now > curr)		{
				curr = now;
			}
			else	{
				long diff = curr-now;
				diff /= d;
				diff++;
				curr = now + d*(diff);
				ret += diff;
			}
		}
		System.out.println(ret);
	}
}