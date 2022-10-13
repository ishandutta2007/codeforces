import java.io.*;
import java.util.*;
public class B71 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int max = Integer.parseInt(st.nextToken());
		int p = Integer.parseInt(st.nextToken());
		int expect = n*max*p/100;
		int[] ret = new int[n];
		for(int i = 0; i < n; i++)		{
			if(expect >= max)		{
				ret[i] = max;
				expect -= max;
			}
			else	{
				ret[i] = expect;
				expect -= expect;
			}
		}
		for(int x: ret)
			System.out.print(x + " ");
	}
}